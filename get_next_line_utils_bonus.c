/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:38:26 by ljourand          #+#    #+#             */
/*   Updated: 2021/11/10 14:48:34 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	length;

	if (!str)
		return (0);
	length = 0;
	while (str[length])
	{
		length++;
	}
	return (length);
}

char	*ft_strdup(const char *src)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (src[i])
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	j = -1;
	while (src[++j])
		str[j] = src[j];
	str[i] = 0;
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	int		len1;
	int		len2;
	int		i;

	if (!s1)
		return (ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	output = malloc(len1 + len2 + 1);
	if (!output)
		return (0);
	i = 0;
	while (i < len1)
	{
		output[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		output[i] = s2[i - len1];
		i++;
	}
	output[i] = 0;
	return (output);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	i;

	if (!s || len == 0 || start > ft_strlen(s))
		return (0);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	output = malloc(len + 1);
	if (!output)
		return (0);
	output[len] = 0;
	i = 0;
	while (i < len && start + i < ft_strlen(s))
	{
		output[i] = s[start + i];
		i++;
	}
	return (output);
}
