/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:35:19 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/10/14 20:41:11 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (s[size] != 0)
		size++;
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	if (s == 0)
		return (0);
	size = len;
	if (len + start > ft_strlen(s))
		size = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		size = 0;
	str = malloc((size + 1) * sizeof(*str));
	if (str == 0)
		return (0);
	i = -1;
	while (++i < size && s[start + i] != '\0')
		str[i] = s[start + i];
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	char	*str;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = 0;
	while (s1[s1_len] != '\0')
		s1_len++;
	s2_len = 0;
	while (s2[s2_len] != '\0')
		s2_len++;
	str = malloc((s1_len + s2_len + 1) * sizeof(*str));
	if (str == 0)
		return (0);
	i = -1;
	while (++i < s1_len)
		str[i] = s1[i];
	i--;
	while (++i < (s1_len + s2_len))
		str[i] = s2[i - s1_len];
	str[s1_len + s2_len] = '\0';
	return (str);
}

void	free_str_and_buf(char **str, char **buf)
{
	if (ft_strlen(*buf) == 0)
	{
		free(*buf);
		*buf = 0;
	}
	if (str != 0 && *str != 0 && ft_strlen(*str) == 0)
	{
		free(*str);
		*str = 0;
	}
}
