/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:42:13 by gbump             #+#    #+#             */
/*   Updated: 2021/04/19 20:18:28 by gbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	search(const char *a)
{
	int	i;

	i = 0;
	while (a[i] && a[i] != '\n')
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		j;
	char	*str1;

	i = 0;
	while (str[i])
		i++;
	str1 = (char *)malloc(sizeof(*str1) * (i + 1));
	if (!str1)
		return (NULL);
	j = 0;
	while (j < i)
	{
		str1[j] = str[j];
		j++;
	}
	str1[j] = '\0';
	return (str1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		b;
	int		c;
	char	*d;

	if (!s1)
		return (ft_strdup((char *)s2));
	b = ft_strlen((char *)s1);
	c = ft_strlen((char *)s2);
	d = (char *)malloc(sizeof(char) * (b + c + 1));
	if (!d)
		return (NULL);
	c = 0;
	while (s1[c])
	{
		d[c] = s1[c];
		c++;
	}
	c = 0;
	while (s2[c])
	{
		d[b++] = s2[c++];
	}
	d[b] = '\0';
	free((char *)s1);
	return (d);
}

int	findn(char *remind)
{
	int	i;

	i = 0;
	if (!remind)
		return (0);
	while (remind[i])
	{
		if (remind[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
