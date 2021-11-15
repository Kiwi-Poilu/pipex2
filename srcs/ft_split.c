/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:35:28 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/15 18:35:30 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_array(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != NULL)
		free(str[i++]);
	free(str);
}

int	w_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

int	wc_count(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			words++;
		i++;
	}
	return (words);
}

char	**fill(char const *s, char c, char **str, int words)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	while (++i < words)
	{
		while (*s == c)
			s++;
		len = w_len(s, c);
		str[i] = malloc(sizeof(char) * (len + 1));
		if (!str[i])
			return (NULL);
		j = 0;
		while (j < len)
			str[i][j++] = *s++;
		str[i][j] = '\0';
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char *s, char c)
{
	char	**str;
	int		words;

	if (!s)
		return (NULL);
	words = wc_count(s, c);
	str = malloc((words + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str = fill(s, c, str, words);
	return (str);
}
