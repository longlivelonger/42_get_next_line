/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:34:35 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/02 16:04:11 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*create_buf(int size)
{
	char	*buf;
	int		i;

	if (size <= 0)
		return (0);
	buf = malloc((size + 1) * sizeof(*buf));
	if (buf != 0)
	{
		i = -1;
		while (++i < size + 1)
			buf[i] = '\0';
	}
	return (buf);
}

static void	shift_buf(char *buf, int offset)
{
	int	i;

	i = -1;
	if (offset < BUFFER_SIZE)
	{
		while (++i < (BUFFER_SIZE - offset))
			buf[i] = buf[i + offset];
		i--;
	}
	while (++i < BUFFER_SIZE)
		buf[i] = '\0';
}

static char	*append_buf(char *str, char *buf, int size)
{
	char	*result;
	char	*temp;
	int		i;

	if (size <= 0)
		return (str);
	i = 0;
	while (i < size && buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (++i > size)
		i = size;
	temp = ft_substr(buf, 0, i);
	shift_buf(buf, i);
	if (str == 0)
		return (temp);
	result = ft_strjoin(str, temp);
	free(str);
	free(temp);
	return (result);
}

static int	str_has_endl(char *str)
{
	if (str == 0)
		return (0);
	if (str[ft_strlen(str) - 1] == '\n')
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buf[4096] = {NULL};
	int			bytes;
	char		*str;

	str = 0;
	if (buf[fd] == 0)
		buf[fd] = create_buf(BUFFER_SIZE);
	if (buf[fd] == 0)
		return (0);
	bytes = 1;
	while (bytes > 0 && !str_has_endl(str))
	{
		bytes = BUFFER_SIZE;
		if (ft_strlen(buf[fd]) == 0)
			bytes = read(fd, buf[fd], BUFFER_SIZE);
		str = append_buf(str, buf[fd], bytes);
	}
	free_str_and_buf(&str, &(buf[fd]));
	return (str);
}
