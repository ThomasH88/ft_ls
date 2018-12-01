/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:21:01 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/23 21:46:19 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		recursion(t_list **head, char lart[7])
{
	t_list			*cur;
	t_list			*new;
	char			*tmp;

	if (head == NULL)
		return ;
	cur = *head;
	new = NULL;
	while (cur)
	{
		if (S_ISDIR(cur->info->st_mode) ||
			(S_ISLNK(cur->info->st_mode) && lart[0] == '0'))
		{
			tmp = remove_path(cur->name);
			if (tmp && ((ft_strcmp(tmp, ".") && ft_strcmp(tmp, ".."))))
			{
				add_elem_back(&new, cur->name, cur->info);
				files_in_dir_list(&new, lart);
				free(new);
				new = NULL;
			}
		}
		cur = cur->next;
	}
}
