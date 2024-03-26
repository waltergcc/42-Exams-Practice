#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/select.h>

#define WRONG	"Wrong number of arguments\n"
#define FATAL	"Fatal error\n"
#define ARRIVED	"server: client %d just arrived\n"
#define LEFT	"server: client %d just left\n"
#define CLTMSG	"client %d: %s"

static int			server, client, last, id, clients[16 * 4096];
char				str[97 * 4096], buff[96 * 4096];
fd_set				requests, readtime, sendtime;
struct sockaddr_in	servaddr, cli;
socklen_t			len = sizeof(cli);
ssize_t				r;

void exiterror(const char *msg)
{
	if (server > 2) close(server);
	write(2, msg, strlen(msg));
	exit(1);
}

void sendresponses(const int ownfd)
{
	for (int fd = 2; fd <= last; ++fd)
	{
		if (fd != ownfd && FD_ISSET(fd, &sendtime))
			if (send(fd, str, strlen(str), 0) < 0) exiterror(FATAL);
	}
	bzero(&str, sizeof(str));
}

int main(int ac, char **av)
{
	if (ac != 2) exiterror(WRONG);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(av[1]));

	server = socket(AF_INET, SOCK_STREAM, 0);
	if (server < 0) exiterror(FATAL);
	if ((bind(server, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) exiterror(FATAL);
	if (listen(server, 10) != 0) exiterror(FATAL);

	FD_ZERO(&requests);
	FD_SET(server, &requests);
	last = server;

	while (1)
	{
		readtime = sendtime = requests;
		if (select(last + 1, &readtime, &sendtime, 0, 0) < 0) continue;

		if (FD_ISSET(server, &readtime))
		{
			client = accept(server, (struct sockaddr *)&cli, &len);
			if (client < 0) exiterror(FATAL);

			sprintf(str, ARRIVED, id);
			clients[client] = id++;
			FD_SET(client, &requests);
			sendresponses(client);
			last = last > client ? last : client;
			continue;
		}

		for (int fd = 2; fd <= last; ++fd)
		{
			if (FD_ISSET(fd, &readtime))
			{
				bzero(&buff, sizeof(buff));
				r = 1;
				while (r == 1 && buff[strlen(buff) - 1] != '\n') r = recv(fd, buff + strlen(buff), 1, 0);
				if (r <= 0)
				{
					sprintf(str, LEFT, clients[fd]);
					FD_CLR(fd, &requests);
					close(fd);
				}
				else
				{
					sprintf(str, CLTMSG, clients[fd], buff);
				}
				sendresponses(fd);
			}
		}
	}
}
