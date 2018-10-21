/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:53:54 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/05 14:02:42 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	info_swap(t_list *l1, t_list *l2)
{
	char			*temp;
	struct stat		*tmp;

	temp = l1->name;
	tmp = l1->info;
	l1->name = l2->name;
	l1->info = l2->info;
	l2->name = temp;
	l2->info = tmp;
}

void	sort_list(t_list **head)
{
	t_list			*current;
	int				swap;

	swap = 1;
	while (swap)
	{
		swap = 0;
		current = *head;
		while (current->next)
		{
			if (ft_strcmp(current->name, current->next->name) > 0 && (swap = 1))
				info_swap(current, current->next);
			current = current->next;
		}
	}
}

void	sort_list_rev(t_list **head)
{
	t_list			*current;
	int				swap;

	swap = 1;
	while (swap)
	{
		swap = 0;
		current = *head;
		while (current->next)
		{
			if (ft_strcmp(current->name, current->next->name) < 0 && (swap = 1))
				info_swap(current, current->next);
			current = current->next;
		}
	}
}

void	time_sort_list(t_list **head)
{
	t_list			*c;
	int				swap;

	swap = 1;
	while (swap)
	{
		swap = 0;
		c = *head;
		while (c->next)
		{
			if (c->next->info->st_mtime - c->info->st_mtime > 0 && (swap = 1))
				info_swap(c, c->next);
			else if (c->next->info->st_mtime - c->info->st_mtime == 0 &&
	c->next->info->st_mtimespec.tv_nsec - c->info->st_mtimespec.tv_nsec > 0
					&& (swap = 1))
				info_swap(c, c->next);
			else if (c->next->info->st_mtime - c->info->st_mtime == 0 &&
	c->next->info->st_mtimespec.tv_nsec - c->info->st_mtimespec.tv_nsec == 0
					&& ft_strcmp(c->name, c->next->name) > 0 && (swap = 1))
				info_swap(c, c->next);
			c = c->next;
		}
	}
}

void	time_sort_rev_list(t_list **head)
{
	t_list			*c;
	int				swap;

	swap = 1;
	while (swap)
	{
		swap = 0;
		c = *head;
		while (c->next)
		{
			if (c->next->info->st_mtime - c->info->st_mtime < 0 && (swap = 1))
				info_swap(c, c->next);
			else if (c->next->info->st_mtime - c->info->st_mtime == 0 &&
	c->next->info->st_mtimespec.tv_nsec - c->info->st_mtimespec.tv_nsec < 0
					&& (swap = 1))
				info_swap(c, c->next);
			else if (c->next->info->st_mtime - c->info->st_mtime == 0 &&
	c->next->info->st_mtimespec.tv_nsec - c->info->st_mtimespec.tv_nsec == 0
					&& ft_strcmp(c->name, c->next->name) < 0 && (swap = 1))
				info_swap(c, c->next);
			c = c->next;
		}
	}
}
