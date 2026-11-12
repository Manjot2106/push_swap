/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:01:36 by msingh            #+#    #+#             */
/*   Updated: 2026/01/08 11:00:14 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

static char	*ft_str(char *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

static char	*ft_search(char *buffer, int fd)
{
	char	*sta;
	char	*line;
	ssize_t	rd;

	rd = 1;
	if (buffer)
		sta = ft_strdup(buffer);
	else
		sta = ft_strdup("");
	if (!sta)
		return (NULL);
	while (!ft_strchr(sta, '\n') && rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
			break ;
		buffer[rd] = '\0';
		sta = ft_join(sta, buffer);
		if (!sta)
			return (NULL);
	}
	line = ft_str(sta);
	if (!line || ft_strlen(line) < 1)
		return (free(line), free(sta), NULL);
	return (free(sta), line);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	buffer[BUFFER_SIZE + 1];
	int			i;
	int			j;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	j = 0;
	if (ft_strchr(buffer, '\n'))
	{
		while (buffer[i] != '\n')
			i++;
		while (buffer[i + 1])
		{
			buffer[j] = buffer[i + 1];
			i++;
			j++;
		}
		buffer[j] = '\0';
	}
	str = ft_search(buffer, fd);
	return (str);
}
