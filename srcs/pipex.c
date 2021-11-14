/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:52:28 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/14 23:52:31 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*find_p_line(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **paths)
{
	char	*ret;
	char	*tmp;
	int		i;

	if (cmd[0] == '/')
	{
		free_array(paths);
		return (ft_strdup(cmd));
	}
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		ret = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(ret, F_OK) != -1)
		{
			free_array(paths);
			return (ret);
		}
		free(ret);
		i++;
	}
	free_array(paths);
	return (NULL);
}

char	**get_cmd(char *av, char **envp)
{
	char	**cmd;
	char	**paths;

	cmd = ft_split(av, ' ');
	if (access(cmd[0], F_OK) == 0)
		return (cmd);
	paths = ft_split(find_p_line(envp), ':');
	if (paths == NULL)
	{
		ft_error("command not found: ", av, 1);
		free_array(cmd);
		return (NULL);
	}
	free(cmd[0]);
	cmd[0] = find_path(av, paths);
	if (cmd[0] == NULL)
	{
		free_array_not_first(cmd);
		ft_error("command not found: ", av, 1);
		return (NULL);
	}
	printf("cmd[0] = %s\n", cmd[0]);
	(void)envp;
	return (cmd);
}

void	pipex(int fd1, int fd2, char **av, char **envp)
{
	int		tube[2];
	char	**cmd1;
	char	**cmd2;

	pipe(tube);
	cmd1 = get_cmd(av[2], envp);
	cmd2 = get_cmd(av[3], envp);
	if (cmd1 != NULL && cmd2 != NULL)
	{
	}
	free_array(cmd1);
	free_array(cmd2);
	(void)fd1;
	(void)fd2;
}

int	main(int ac, char **av, char **envp)
{
	int	fd1;
	int	fd2;

	if (ac != 5)
		return (ft_error("expected 5 arguments, have ", ft_itoa(ac), 1));
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd1 < 0 || fd2 < 0)
		return (ft_error("could not open file", NULL, 1));
	pipex(fd1, fd2, av, envp);
	return (0);
}

/*
int		main(int ac, char **av, char **envp)
{
	printf("%s\n", find_p_line(envp));
	(void)ac;
	(void)av;
}*/
