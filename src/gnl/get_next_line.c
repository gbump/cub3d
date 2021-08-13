/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:43:46 by gbump             #+#    #+#             */
/*   Updated: 2021/04/19 20:15:19 by gbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_remind(char *remind)
{
	char	*tmp;
	int		i;
	int		j;

	i = search(remind);
	j = 0;
	if (!remind)
	{
		free(remind);
		return (0);
	}
	if (!remind[i])
	{
		free(remind);
		return (0);
	}
	tmp = (char *)malloc(sizeof(char) * ((ft_strlen(remind) - i) + 1));
	if (!tmp)
		return (0);
	while (remind[i])
		tmp[j++] = remind[++i];
	tmp[j] = '\0';
	free(remind);
	return (tmp);
}

char	*check_line(char *remind)
{
	int		i;
	char	*tmp;

	i = search(remind);
	if (!remind)
	{
		free(remind);
		return (0);
	}
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (0);
	i = 0;
	while (remind[i] && remind[i] != '\n')
	{
		tmp[i] = remind[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int	get_next_line(int fd, char **line)
{
	char			buf[2];
	static char		*remind;
	int				byte;

	byte = 1;
	if (fd < 0 || line == NULL)
		return (-1);
	while (!findn(remind) && byte != 0)
	{
		byte = read(fd, buf, 1);
		if (byte == -1)
			return (-1);
		buf[byte] = '\0';
		remind = ft_strjoin(remind, buf);
	}
	*line = check_line(remind);
	remind = check_remind(remind);
	if (byte != 0)
		return (1);
	else
		return (0);
}
