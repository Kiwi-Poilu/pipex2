/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:37:22 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/15 18:37:23 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_array_not_first(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != NULL || i == 0)
		free(str[i++]);
	free(str);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*ret;

	ret = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = s[i];
	return (ret);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_error(char *error_message, char *optional, int ret)
{
	write(STDERR_FILENO, error_message, ft_strlen(error_message));
	if (optional != NULL)
		write(STDERR_FILENO, optional, ft_strlen(optional));
	write(STDERR_FILENO, "\n", 1);
	return (ret);
}
