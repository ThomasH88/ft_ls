/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_long_fmt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 23:16:53 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/05 13:37:09 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	size_maj_n_min(struct stat *data)
{
	if (S_ISCHR(data->st_mode) || S_ISBLK(data->st_mode))
		printf(" %u, %u ", major(data->st_rdev), minor(data->st_rdev));
	else
		printf("%lld ", data->st_size);
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
