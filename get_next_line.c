/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:09:47 by tchalaou          #+#    #+#             */
/*   Updated: 2023/12/05 15:24:35 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_next_buffer(char **bu, char **ln)
{
	char	*nl;
	char	*new;
	char	*tmp;

	nl = ft_strchr(*bu, '\n');
	new = NULL;
	if (nl && *(nl + 1))
	{
		new = ft_strdup(nl + 1);
		*(nl + 1) = 0;
	}
	if (!*ln)
		*ln = ft_strdup(*bu);
	else
	{
		tmp = ft_strjoin(*ln, *bu);
		free(*ln);
		*ln = tmp;
	}
	free(*bu);
	*bu = new;
	return (!!nl);
}

static void	read_next_line(int fd, char **bu, char **ln)
{
	ssize_t	br;

	while (1)
	{
		*bu = malloc(BUFFER_SIZE + 1);
		if (!*bu)
			break ;
		br = read(fd, *bu, BUFFER_SIZE);
		if (br < 1)
		{
			free(*bu);
			*bu = NULL;
			break ;
		}
		*(*bu + br) = 0;
		if (get_next_buffer(bu, ln))
			break ;
		if (br != BUFFER_SIZE)
			break ;
	}
}

char	*get_next_line(int fd)
{
	static char	*bu;
	char		*ln;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	ln = NULL;
	if (bu && get_next_buffer(&bu, &ln))
		return (ln);
	bu = NULL;
	read_next_line(fd, &bu, &ln);
	return (ln);
}
