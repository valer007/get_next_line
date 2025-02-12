#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = malloc(ft_strlen(s) + 1);
	if (!copy)
		return (NULL);
	while (i < ft_strlen(s))
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*copy;

	if (!s1 && !s2)
		return (NULL);
	copy = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char*));
	if (!copy)
		return (NULL);
	i = -1;
	j = -1;
	while (s1 && s1[++i])
		copy[i] = s1[i];
	i++;
	while (s2 && s2[++j])
		copy[i++] = s2[j];
	copy[i] = '\0';
	free(s1);
	return (copy);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	max_size;
	size_t	size;
	char	*copy;
	size_t	i;

	if (!s)
		return (NULL);
	max_size = ft_strlen(s);
	if (start >= max_size)
		return (ft_strdup(""));
	size = max_size - start;
	if (size > len)
		size = len;
	copy = malloc(size + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = s[start + i];
		i++;
	}
	copy[size] = '\0';
	return (copy);
}