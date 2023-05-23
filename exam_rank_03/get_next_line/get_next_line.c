#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int strlen_at(char *s, char c)
{
	int i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int have_newline(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char *ft_strncpy(char *dst, char *src, int n)
{
	int i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char *ft_strjoin(char *prev, char *curr)
{
	int i = strlen_at(prev, '\0');
	int j = strlen_at(curr, '\0');
	int size = i + j + 1;

	if (!prev && !curr)
		return (NULL);

	char *merge = (char *)malloc(sizeof(char) * size);
	if (!merge)
		return (NULL);
	if (prev)
		ft_strncpy(merge, prev, i);
	ft_strncpy(merge + i, curr, j);
	free (prev);
	return (merge);
}

char *get_keep(char *buffer)
{
	int i = strlen_at(buffer, '\0');
	int j = strlen_at(buffer, '\n');
	int size = i - j + 1;

	if (!buffer[j])
	{
		free (buffer);
		return (NULL);
	}

	char *keep = (char *)malloc(sizeof(char) * size);
	if (!keep)
		return (NULL);
	j++;
	ft_strncpy(keep, buffer + j, size);
	free (buffer);
	return (keep);
}

char *get_line(char *buffer)
{
	int j = strlen_at(buffer, '\n');
	if (buffer[j] == '\n')
		j++;
	char *line = (char *)malloc(sizeof(char) * (j + 1));
	if (!line)
		return (NULL);
	ft_strncpy(line, buffer, j);
	return (line);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char *line;
	char curr[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	curr[0] = '\0';
	int bytes = 1;
	while (!have_newline(curr) && bytes != 0)
	{
		bytes = read(fd, curr, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		curr[bytes] = '\0';
		buffer = ft_strjoin(buffer, curr);
	}
	line = get_line(buffer);
	buffer = get_keep(buffer);
	if (!line[0])
	{
		free (line);
		return (NULL);
	}
	return (line);
}
/* 
int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	char *line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free (line);
		line = get_next_line(fd);
	}
	close (fd);
} */