/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 20:55:29 by aberdal           #+#    #+#             */
/*   Updated: 2026/02/28 17:59:53 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <stdlib.h>
#include <unistd.h>

//______GET_NEXT_LİNE_________//
char *get_next_line(int fd);

//______GET_NEXT_LİNE_UTİLS___//
char    *ft_strchr(const char *s,int c);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif