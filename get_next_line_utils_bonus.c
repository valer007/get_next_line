/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:51:34 by vmakarya          #+#    #+#             */
/*   Updated: 2025/02/12 21:51:35 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*copy;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	copy = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!copy)
		return (free(s1), NULL);
	i = 0;
	while (s1 && s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		copy[i++] = s2[j++];
	copy[i] = '\0';
	return (free(s1), copy);
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
