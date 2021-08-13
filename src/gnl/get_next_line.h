/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:53:55 by gbump             #+#    #+#             */
/*   Updated: 2021/04/19 20:30:57 by gbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(const char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		findn(char *remind);
char	*check_remind(char *remind);
char	*check_line(char *remind);
int		get_next_line(int fd, char **line);
int		search(const char *a);
#endif
