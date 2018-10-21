/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_fmt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:43:18 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/01 22:10:00 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		print_file_type(struct stat *data)
{
	if (S_ISBLK(data->st_mode))
		printf("b");
	else if (S_ISCHR(data->st_mode))
		printf("c");
	else if (S_ISDIR(data->st_mode))
		printf("d");
	else if (S_ISLNK(data->st_mode))
	{
		printf("l");
		return (1);
	}
	else if (S_ISSOCK(data->st_mode))
		printf("s");
	else if (S_ISFIFO(data->st_mode))
		printf("p");
	else if (S_ISREG(data->st_mode))
		printf("-");
	else
		perror(NULL);
	return (0);
}

void	print_perm(struct stat *data)
{
	printf((data->st_mode & S_IRUSR) ? "r" : "-");
	printf((data->st_mode & S_IWUSR) ? "w" : "-");
	printf((data->st_mode & S_IXUSR) ? "x" : "-");
	printf((data->st_mode & S_IRGRP) ? "r" : "-");
	printf((data->st_mode & S_IWGRP) ? "w" : "-");
	printf((data->st_mode & S_IXGRP) ? "x" : "-");
	printf((data->st_mode & S_IROTH) ? "r" : "-");
	printf((data->st_mode & S_IWOTH) ? "w" : "-");
	printf((data->st_mode & S_IXOTH) ? "x" : "-");
	printf("  ");
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

void	print_long_fmt(struct stat *data, char *name)
{
	struct passwd	*pw;
	struct group	*gr;
	struct stat		buf;
	int				a;
	char			s[4096];

	buf = *data;
	init_s(s);
	a = print_file_type(data);
	print_perm(data);
	printf("%d", data->st_nlink);
	pw = getpwuid(data->st_uid);
	gr = getgrgid(data->st_gid);
	printf(" %s  %s  ", pw->pw_name, gr->gr_name);
	size_maj_n_min(data);
	printf("%s %s", trim_time(ctime(&buf.st_mtime)), remove_path(name));
	if (a)
	{
		if (rdlnk_error(readlink(name, s, 4096)) == -1)
			return ;
		printf(" -> %s\n", s);
	}
	else
		printf("\n");
}
