/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:40:17 by arpereir          #+#    #+#             */
/*   Updated: 2025/05/20 15:45:32 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new_string;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_string = malloc(s1_len + s2_len + 1);
	if (!new_string)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		new_string[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		new_string[i++] = s2[j++];
	new_string[i] = '\0';
	free(s1);
	return (new_string);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s || ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
