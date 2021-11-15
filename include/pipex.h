/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:52:25 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/15 18:52:31 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

//ft_strjoin.c
char	*ft_strjoin(char *s1, char *s2);

//ft_split.c
char	**ft_split(char *s, char c);
void	free_array(char **str);
void	free_array_not_first(char **str);

//cmd.c
char	*find_p_line(char **envp);
char	*find_path(char *cmd, char **paths);
char	**get_cmd(char *av, char **envp);

//utils. c
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *str);
int		ft_error(char *error_message, char *optional, int ret);

//utils2.c
char	*ft_strdup(const char *s);

#endif
