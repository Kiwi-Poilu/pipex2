#include "../include/pipex.h"

char	*ft_strdup(const char *s)
{
	int i;
	char *ret;


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
