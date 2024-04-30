/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:42:47 by tchalaou          #+#    #+#             */
/*   Updated: 2023/12/05 15:16:38 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p)
		p++;
	return (p - s);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (NULL);
	return ((char *)s);
}

char	*ft_strdup(const char *s)
{
	int		l;
	char	*r;

	l = ft_strlen(s);
	r = malloc(l + 1);
	if (!r)
		return (NULL);
	while (*s)
		*r++ = *s++;
	*r = 0;
	r -= l;
	return (r);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l;
	char	*s;

	l = ft_strlen(s1) + ft_strlen(s2);
	s = malloc(l + 1);
	if (!s)
		return (NULL);
	while (*s1)
		*s++ = *s1++;
	while (*s2)
		*s++ = *s2++;
	*s = 0;
	s -= l;
	return (s);
}
