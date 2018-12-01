/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 20:11:14 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/23 21:50:12 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	chinit(char lart[7])
{
	int		i;

	i = 0;
	while (i < 6)
	{
		lart[i] = '0';
		i++;
	}
	lart[i] = '\0';
}

void	set_flags(char *s, char lart[7])
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
		else if (*s == 'R')
			lart[4] = '1';
		else
		{
			b_printf("ft_ls: illegal option -- %c\n", *s);
			b_printf("usage: ft_ls [-Ralrt] [file ...]\n");
			exit(EXIT_FAILURE);
		}
		s++;
	}
}

int		main(int argc, char **argv)
{
	char	lart[7];
	int		i;
	t_list	*head;

	i = 0;
	chinit(lart);
	while (++i < argc && (argv[i][0] == '-' && argv[i][1] != '\0') &&
			!(argv[i][1] == '-' && argv[i][2] == '\0'))
		set_flags(argv[i], lart);
	if (argv[i] && (argv[i][1] == '-' && argv[i][2] == '\0'))
		i++;
	if (argv[i] == NULL && (lart[5] = '1'))
		head = ft_create_elem(ft_strdup("."), NULL);
	else
		head = ft_create_elem(ft_strdup(argv[i]), NULL);
	if (argv[i + 1] == NULL)
		lart[5] = '1';
	while (++i < argc)
		add_elem_back(&head, ft_strdup(argv[i]), NULL);
	sort_list(&head);
	ft_classify(&head, lart);
	return (0);
}
