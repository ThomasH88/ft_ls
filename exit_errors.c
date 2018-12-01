/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:24:37 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/23 21:51:27 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	malloc_error(void)
{
	perror(NULL);
	exit(EXIT_FAILURE);
}

void	lstat_error(int nb)
{
	if (nb == -1)
		perror("lstat error");
}

int		rdlnk_error(ssize_t size)
{
	if (size == -1)
	{
		perror("\nreadlink error");
		return (-1);
	}
	return (1);
}

int		opendir_error(DIR *dir, char *name)
{
	if (dir == NULL)
	{
		b_printf("\n%s:\nft_ls: %s: %s\n", name,
				crop_path(name), strerror(errno));
		return (0);
	}
	return (1);
}
