/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:54:37 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/05 13:40:22 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	format_to_print(t_list **head, char lart[5], char *name)
{
	if (*head == NULL)
		return ;
	if (lart && lart[3] == '1')
		time_sort_list(head);
	else if (lart)
		sort_list(head);
	count_blocks_or_not(head, lart, name);
	if (lart && lart[2] == '1')
	{
		print_rev_list(head, lart);
	}
	else
	{
		print_list(head, lart);
	}
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

void	files_in_dir_list(t_list **d_head, char lart[5])
{
	t_list			*d_current;
	t_list			*head;
	DIR				*dir;
	struct dirent	*sd;

	d_current = *d_head;
	while (d_current && d_current->name)
	{
		head = NULL;
		opendir_error((dir = opendir(d_current->name)), d_current->name);
		while ((sd = readdir(dir)))
			add_files_to_list(&head, sd->d_name, d_current->name);
		format_to_print(&head, lart, d_current->name);
		d_current = d_current->next;
		closedir(dir);
	}
}

void	handle_lists(t_list **e_head, t_list **f_head,
					t_list **d_head, char lart[5])
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

void	ft_classify(t_list **head, char lart[5])
{
	t_list			*d_head;
	t_list			*f_head;
	t_list			*e_head;
	t_list			*current;
	struct stat		*buf;

	d_head = NULL;
	f_head = NULL;
	e_head = NULL;
	current = *head;
	while (current)
	{
		buf = stat_buf_create();
		if (lstat(current->name, buf) == -1)
			add_elem_back(&e_head, current->name, buf);
		else
		{
			if (S_ISDIR(buf->st_mode))
				add_elem_back(&d_head, current->name, buf);
			else
				add_elem_back(&f_head, current->name, buf);
		}
		current = current->next;
	}
	handle_lists(&e_head, &f_head, &d_head, lart);
}
