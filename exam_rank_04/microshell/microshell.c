#include "microshell.h"

void	err(char *s)
{
	while (*s)
		write(2, s++, 1);
}

int	print_err(char *msg, char *key)
{
	err(msg);
	if (key)
		err(key);
	err("\n");
	return (1);
}

int	cd(char **token, int i)
{
	if (i != 2)
		return (print_err(BAD, NULL));
	else if (chdir(token[1]) == -1)
		return (print_err(DIR, token[1]));
	return (0);
}

int	exec(char **token, char **env, int i)
{
	int	fd[2];
	int	g_exit;
	int	has_pipe = token[i] && !strcmp(token[i], "|");

	if (has_pipe && pipe(fd) == -1)
		return (print_err(FAT, NULL));

	int pid = fork();
	if (pid == 0)
	{
		token[i] = NULL;
		if (has_pipe
			&& (dup2(fd[1], 1) == -1
			|| close(fd[0]) == -1
			|| close(fd[1]) == -1))
			return (print_err(FAT, NULL));
		execve(*token, token, env);
		return (print_err(EXE, *token));
	}
	waitpid(pid, &g_exit, 0);
	if (has_pipe
		&& (dup2(fd[0], 0) == -1
		|| close(fd[0]) == -1
		|| close(fd[1]) == -1))
		return (print_err(FAT, NULL));
	return (WEXITSTATUS(g_exit));
}

int main(int ac, char **token, char **env)
{
	int	i = 0;
	int	g_exit = 0;
	if (ac > 1)
	{
		while (token[i] && token[++i])
		{
			token += i;
			i = 0;
			while (token[i] && strcmp(token[i], "|") && strcmp(token[i], ";"))
				i++;
			if (!strcmp(*token, "cd"))
				g_exit = cd(token, i);
			else if (i)
				g_exit = exec(token, env, i);
		}
	}
	return (g_exit);
}
