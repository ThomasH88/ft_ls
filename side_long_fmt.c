/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_long_fmt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 23:16:53 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/23 20:39:23 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_everything(t_list **elem)
{
	if (elem && *elem)
	{
		free((*elem)->name);
		(*elem)->name = NULL;
		free((*elem)->info);
		(*elem)->info = NULL;
	}
	free(*elem);
	elem = NULL;
}

void	size_maj_n_min(struct stat *data)
{
	if (S_ISCHR(data->st_mode) || S_ISBLK(data->st_mode))
		b_printf(" %u, %u ", major(data->st_rdev), minor(data->st_rdev));
	else
		b_printf("%u ", data->st_size);
}

char	*path_name_side(char f_name[256], char *new, int j)
{
	int		i;

	i = 0;
	while (f_name[i])
	{
		new[j] = f_name[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}

void	sticky_bits(struct stat *data, int door)
{
	if (data->st_mode & S_ISUID && data->st_mode & S_IXUSR && door == 1)
		b_printf("s");
	else if (data->st_mode & S_ISUID && door == 1)
		b_printf("S");
	else if (data->st_mode & S_IXUSR && door == 1)
		b_printf("x");
	else if (door == 1)
		b_printf("-");
	if (data->st_mode & S_ISGID && data->st_mode & S_IXGRP && door == 2)
		b_printf("s");
	else if (data->st_mode & S_ISGID && door == 2)
		b_printf("S");
	else if (data->st_mode & S_IXGRP && door == 2)
		b_printf("x");
	else if (door == 2)
		b_printf("-");
	if (data->st_mode & S_ISVTX && data->st_mode & S_IXOTH && door == 3)
		b_printf("t  ");
	else if (data->st_mode & S_ISVTX && door == 3)
		b_printf("T  ");
	else if (data->st_mode & S_IXOTH && door == 3)
		b_printf("x  ");
	else if (door == 3)
		b_printf("-  ");
}
