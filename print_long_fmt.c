/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_fmt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:43:18 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/23 08:44:11 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		print_file_type(struct stat *data)
{
	if (S_ISBLK(data->st_mode))
		b_printf("b");
	else if (S_ISCHR(data->st_mode))
		b_printf("c");
	else if (S_ISDIR(data->st_mode))
		b_printf("d");
	else if (S_ISLNK(data->st_mode))
	{
		b_printf("l");
		return (1);
	}
	else if (S_ISSOCK(data->st_mode))
		b_printf("s");
	else if (S_ISFIFO(data->st_mode))
		b_printf("p");
	else if (S_ISREG(data->st_mode))
		b_printf("-");
	else
		perror(NULL);
	return (0);
}

void	print_perm(struct stat *data)
{
	b_printf((data->st_mode & S_IRUSR) ? "r" : "-");
	b_printf((data->st_mode & S_IWUSR) ? "w" : "-");
	sticky_bits(data, 1);
	b_printf((data->st_mode & S_IRGRP) ? "r" : "-");
	b_printf((data->st_mode & S_IWGRP) ? "w" : "-");
	sticky_bits(data, 2);
	b_printf((data->st_mode & S_IROTH) ? "r" : "-");
	b_printf((data->st_mode & S_IWOTH) ? "w" : "-");
	sticky_bits(data, 3);
}

char	*trim_time(char *time)
{
	int		i;

	i = 4;
	while (i--)
		time++;
	time[12] = '\0';
	return (time);
}

void	init_s(char s[4096])
{
	int		i;

	i = 0;
	while (i < 4096)
	{
		s[i] = '\0';
		i++;
	}
}

void	print_long_fmt(struct stat *data, char *name, char *door)
{
	struct passwd	*pw;
	struct group	*gr;
	int				a;
	char			s[4096];

	init_s(s);
	a = print_file_type(data);
	print_perm(data);
	b_printf("%d", data->st_nlink);
	pw = getpwuid(data->st_uid);
	gr = getgrgid(data->st_gid);
	b_printf(" %s  %s  ", pw->pw_name, gr->gr_name);
	size_maj_n_min(data);
	if (door)
		b_printf("%s %s", trim_time(ctime(&data->st_mtime)), remove_path(name));
	else
		b_printf("%s %s", trim_time(ctime(&data->st_mtime)), name);
	if (a)
	{
		if (rdlnk_error(readlink(name, s, 4096)) == -1)
			return ;
		b_printf(" -> %s\n", s);
	}
	else
		b_printf("\n");
}
