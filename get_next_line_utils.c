/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 22:58:31 by aberdal           #+#    #+#             */
/*   Updated: 2026/02/28 18:00:02 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char    *ft_strchr(const char *s,int c)
{
    unsigned char   ch;

    ch = (unsigned char)c;
    while(*s)
    {
        if((unsigned char)*s == ch)
            return ((char *)s);
        s++;
    }
    if (ch == '\0')
        return((char *)s);
    return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		p = malloc(1);
		if (!p)
			return (NULL);
		p[0] = '\0';
		return (p);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < len)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[j])
		s[i++] = s2[j++];
	s[i] = '\0';
	return (s);
}
