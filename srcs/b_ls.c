/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 16:09:03 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/05 13:40:14 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	chinit(char lart[5])
{
	int		i;

	i = 0;
	while (i < 4)
	{
		lart[i] = '0';
		i++;
	}
	lart[i] = '\0';
}

void	set_flags(char *s, char lart[5])
{
	s++;
	while (*s)
	{
		if (*s == 'l')
			lart[0] = '1';
		else if (*s == 'a')
			lart[1] = '1';
		else if (*s == 'r')
			lart[2] = '1';
		else if (*s == 't')
			lart[3] = '1';
		else
		{
			printf("b_ls: illegal option -- %c\n", *s);
			printf("usage: b_ls [-alrt] [file ...]\n");
			exit(EXIT_FAILURE);
		}
		s++;
	}
}

int		main(int argc, char **argv)
{
	char	lart[5];
	int		i;
	t_list	*head;

	i = 0;
	chinit(lart);
	while (++i < argc && argv[i][0] == '-' &&
			!(argv[i][1] == '-' && argv[i][2] == '\0'))
		set_flags(argv[i], lart);
	if (argv[i] && (argv[i][1] == '-' && argv[i][2] == '\0'))
		i++;
	if (argv[i] == NULL)
		head = ft_create_elem(ft_strdup("."), NULL);
	else
		head = ft_create_elem(ft_strdup(argv[i]), NULL);
	while (++i < argc)
		add_elem_back(&head, ft_strdup(argv[i]), NULL);
	sort_list(&head);
	ft_classify(&head, lart);
	return (0);
}
