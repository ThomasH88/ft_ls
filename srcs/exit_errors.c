/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:24:37 by tholzheu          #+#    #+#             */
/*   Updated: 2018/09/30 12:06:45 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

void	opendir_error(DIR *dir, char *name)
{
	if (dir == NULL)
	{
		printf("\n%s:\nb_ls: %s: %s\n", name, crop_path(name), strerror(errno));
		exit(EXIT_FAILURE);
	}
}
