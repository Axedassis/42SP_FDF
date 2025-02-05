/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:25:23 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/05 14:57:27 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	word_count(char **split);
static int	process_line(char *str, int fd, int expected_cnt);
static int	process_first_line(int fd, int *cnt);
static int	process_remaining_lines(int fd, int cnt);

int	file_format(const char *path_file)
{
	int	fd;
	int	cnt;

	fd = open(path_file, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	if (process_first_line(fd, &cnt) == -1)
		return (-1);
	if (process_remaining_lines(fd, cnt) == -1)
		return (-1);
	close(fd);
	return (0);
}

static int	word_count(char **split)
{
	int		nbr;
	int		i;

	nbr = 0;
	i = 0;
	while (split[i])
	{
		if (*split[i] == '\n')
			i++;
		else
		{
			i++;
			nbr++;
		}
	}
	return (nbr);
}

static int	process_line(char *str, int fd, int expected_cnt)
{
	char	**split;
	int		cnt_tmp;

	split = ft_split(str, ' ');
	if (!split)
	{
		free(str);
		close(fd);
		ft_printf("Split map to verify columns fail\n");
		return (-1);
	}
	cnt_tmp = word_count(split);
	free_split(split);
	if (cnt_tmp != expected_cnt)
	{
		free(str);
		close(fd);
		return (-1);
	}
	free(str);
	return (0);
}

static int	process_first_line(int fd, int *cnt)
{
	char	*str;
	char	**split;

	str = get_next_line(fd);
	if (!str)
	{
		close(fd);
		ft_printf("Empty map\n");
		return (-1);
	}
	split = ft_split(str, ' ');
	if (!split)
	{
		free(str);
		close(fd);
		ft_printf("Split map to verify columns fail\n");
		return (-1);
	}
	*cnt = word_count(split);
	free_split(split);
	free(str);
	return (0);
}

static int	process_remaining_lines(int fd, int cnt)
{
	char	*str;

	str = get_next_line(fd);
	while (str != NULL)
	{
		if (process_line(str, fd, cnt) == -1)
			return (-1);
		str = get_next_line(fd);
	}
	return (0);
}
