#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

//ft_strjoin.c
char	*ft_strjoin(char *s1, char *s2);

//ft_split.c
char	**ft_split(char *s, char c);
void 	free_array(char **str);
void free_array_not_first(char **str);

//utils. c
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *str);
int		ft_error(char *error_message, char *optional, int ret);
char	*ft_itoa(int n);

//utils2.c
char	*ft_strdup(const char *s);

#endif