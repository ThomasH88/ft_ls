/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:54:37 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/23 22:01:11 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	format_to_print(t_list **head, char lart[7], char *name)
{
	if (head == NULL || *head == NULL)
		return ;
	if (lart && lart[3] == '1' && lart[2] == '1')
		time_sort_rev_list(head);
	else if (lart && lart[2] == '1')
		sort_list_rev(head);
	else if (lart && lart[3] == '1')
		time_sort_list(head);
	else if (lart)
		sort_list(head);
	count_blocks_or_not(head, lart, name);
	print_list(head, lart, name);
	if (name && lart && lart[4] == '1')
		recursion(head, lart);
	delete_list(head);
}

void	add_files_to_list(t_list **head, char f_name[256], char *d_name)
{
	struct stat		*buf;
	char			*s;

	buf = stat_buf_create();
	s = path_name(f_name, d_name);
	lstat_error(lstat(s, buf));
	add_elem_back(head, s, buf);
}

void	files_in_dir_list(t_list **d_head, char lart[7])
{
	t_list			*d_current;
	t_list			*head;
	DIR				*dir;
	struct dirent	*sd;
	int				a;

	d_current = *d_head;
	while (d_current && d_current->name)
	{
		head = NULL;
		dir = opendir(d_current->name);
		a = opendir_error(dir, d_current->name);
		if (a)
		{
			while ((sd = readdir(dir)))
				add_files_to_list(&head, sd->d_name, d_current->name);
			format_to_print(&head, lart, d_current->name);
		}
		d_current = d_current->next;
		if (a)
			closedir(dir);
	}
}

void	handle_lists(t_list **e_head, t_list **f_head,
					t_list **d_head, char lart[7])
{
	print_error_list(e_head);
	delete_list(e_head);
	format_to_print(f_head, lart, NULL);
	if (*d_head == NULL)
		return ;
	if (lart[3] == '1' && lart[2] == '1')
		time_sort_rev_list(d_head);
	else if (lart[2] == '1')
		sort_list_rev(d_head);
	else if (lart[3] == '1')
		time_sort_list(d_head);
	else
		sort_list(d_head);
	files_in_dir_list(d_head, lart);
	delete_list(d_head);
}

void	ft_classify(t_list **head, char lart[7])
{
	t_list			*d_head;
	t_list			*f_head;
	t_list			*e_head;
	t_list			*current;
	struct stat		*b;

	d_head = NULL;
	f_head = NULL;
	e_head = NULL;
	current = *head;
	while (current)
	{
		b = stat_buf_create();
		if (lstat(current->name, b) == -1)
			add_elem_back(&e_head, current->name, b);
		else
		{
			if (S_ISDIR(b->st_mode) || (S_ISLNK(b->st_mode) && lart[0] == '0'))
				add_elem_back(&d_head, current->name, b);
			else
				add_elem_back(&f_head, current->name, b);
		}
		current = current->next;
	}
	handle_lists(&e_head, &f_head, &d_head, lart);
}
