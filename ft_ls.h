/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 20:05:30 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/23 21:46:14 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include <errno.h>

typedef struct		s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	char			*name;
	struct stat		*info;
}					t_list;

void				chinit(char s[5]);
void				set_flags(char *s, char lart[5]);
t_list				*ft_create_elem(char *s, struct stat *data);
void				add_elem_back(t_list **head, char *s, struct stat *data);
t_list				*delete_list(t_list **head);
void				remove_dot_files(t_list **head);
void				print_list(t_list **head, char lart[5], char *door);
void				print_rev_list(t_list **head, char lart[5], char *door);
void				print_error_list(t_list **head);
void				format_to_print(t_list **head, char lart[5], char *name);
void				ft_classify(t_list **head, char lart[5]);
void				handle_lists(t_list **e_head, t_list **f_head,
									t_list **d_head, char lart[5]);
void				files_in_dir_list(t_list **head, char lart[5]);
void				add_files_to_list(t_list **head, char f_name[256],
										char *d_name);
int					print_file_type(struct stat *data);
void				print_perm(struct stat *data);
char				*trim_time(char *time);
void				init_s(char s[4096]);
void				print_long_fmt(struct stat *data, char *name, char *door);
void				size_maj_n_min(struct stat *data);
void				sticky_bits(struct stat *data, int door);
char				*path_name_side(char f_name[256], char *new, int j);
void				info_swap(t_list *l1, t_list *l2);
void				sort_list(t_list **head);
void				sort_list_rev(t_list **head);
void				time_sort_list(t_list **head);
void				time_sort_rev_list(t_list **head);
struct stat			*stat_buf_create(void);
char				*path_name(char f_name[256], char *d_name);
void				count_blocks_or_not(t_list **head, char lart[5],
										char *name);
char				*remove_path(char *path);
char				*crop_path(char *path);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlen(const char *s);
void				free_everything(t_list **elem);
char				*ft_strdup(const char *s1);
void				malloc_error(void);
void				lstat_error(int nb);
int					rdlnk_error(ssize_t size);
int					opendir_error(DIR *dir, char *name);

void				recursion(t_list **head, char lart[7]);

#endif
