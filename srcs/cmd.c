/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:48:50 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/15 18:48:57 by sobouatt         ###   ########.fr       */
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

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		ret = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(ret, X_OK) != -1)
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
	char	*res;

	cmd = ft_split(av, ' ');
	if (access(cmd[0], X_OK) == 0)
		return (cmd);
	paths = ft_split(find_p_line(envp), ':');
	if (paths == NULL)
	{
		ft_error("command not found: ", av, 1);
		free_array(cmd);
		return (NULL);
	}
	res = find_path(cmd[0], paths);
	if (res == NULL)
	{
		free_array_not_first(cmd);
		ft_error("command not found: ", av, 1);
		return (NULL);
	}
	free(cmd[0]);
	cmd[0] = res;
	return (cmd);
}
