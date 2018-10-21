/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:32:12 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/04 21:02:07 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct stat		*stat_buf_create(void)
{
	struct stat		*buf;

	buf = (struct stat *)malloc(sizeof(struct stat));
	if (!buf)
		malloc_error();
	return (buf);
}

char			*path_name(char f_name[256], char *d_name)
{
	char	*new;
	int		j;

	j = 0;
	new = malloc(sizeof(char) * ft_strlen(f_name) + ft_strlen(d_name) + 2);
	if (new == NULL)
		malloc_error();
	while (*d_name)
	{
		new[j] = *d_name;
		j++;
		d_name++;
	}
	if (new[j - 1] != '/')
	{
		new[j] = '/';
		j++;
	}
	new = path_name_side(f_name, new, j);
	return (new);
}

void			count_blocks_or_not(t_list **head, char lart[5], char *name)
{
	t_list		*current;
	quad_t		count;

	count = 0;
	if (name == NULL)
		return ;
	current = *head;
	if (lart && lart[1] != '1')
		remove_dot_files(head);
	while (current)
	{
		if (current->name)
			count = count + current->info->st_blocks;
		current = current->next;
	}
	if (lart && lart[0] == '0')
		printf("\n%s:\n", name);
	else
		printf("\n%s:\ntotal %lld\n", name, count);
}

char			*remove_path(char *path)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (path == NULL)
		return (NULL);
	while (path[i])
	{
		if (path[i] == '/' && path[i + 1] != '\0')
			count++;
		i++;
	}
	i = 0;
	if (count == 0)
		return (path);
	while (*path)
	{
		if (*path == '/')
			i++;
		path++;
		if (count == i)
			return (path);
	}
	return ("Error");
}

char			*crop_path(char *path)
{
	while (*path && (*path == '.' || *path == '/'))
		path++;
	return (path);
}
