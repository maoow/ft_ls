/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 13:59:21 by cbinet            #+#    #+#             */
/*   Updated: 2017/03/14 15:59:54 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define ACTFILE flags->dir->files
# define NEXTFILE flags->dir->files->next
# include <sys/types.h>
# include <dirent.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include "ft_printf/includes/ft_printf.h"
# include <sys/stat.h>
# include <unistd.h>

typedef struct	s_files
{
	char			*name;
	char			*color;
	char			type;
	char			ctype;
	int				perm;
	long			links;
	char			*uid;
	char			*gid;
	long long		size;
	long			time;
	char			*link;
	int				id;
	struct s_files	*next;
}				t_files;

typedef struct	s_dir
{
	DIR				*actual;
	bool			used;
	bool			real;
	char			*path;
	long			blocks;
	long			time;
	char			*error;
	struct s_dir	*next;
	t_files			*files;
}				t_dir;

typedef struct	s_ls_flags
{
	int		namew;
	int		linksw;
	int		uidw;
	int		gidw;
	int		sizew;
	t_dir	*dir;
	bool	l;
	bool	rr;
	bool	right;
	bool	a;
	bool	r;
	bool	gg;
	bool	f;
	bool	u;
	bool	t;
	bool	error;
	bool	first;
	bool	option;
	char	*name;
}				t_ls_flags;
void			ft_display(t_ls_flags *flags);
void			ft_lssort(t_ls_flags *flags);
t_dir			*ft_lsdiruntab(t_dir ***list, size_t size);
void			ft_displsusage(char *str, t_ls_flags *flags);
void			ft_getlsflags(char *str, t_ls_flags *flags);
void			ft_freefile(t_files **tmp);
void			ft_freedir(t_ls_flags *flags, t_dir **tmp);
t_dir			**ft_lsdirrev(t_dir **list, size_t size);
void			ft_initlsflags(t_ls_flags *flags, char *str);
void			ft_setlsflags(char *str, t_ls_flags *flags);
void			ft_setpath(char *str, t_ls_flags *flags);
void			ft_initwidths(t_ls_flags *flags);
char			**ft_getminwidth(t_ls_flags *flags);
void			ft_adddir(t_ls_flags *flags, struct dirent *directory);
bool			ft_setllsfiles(t_ls_flags *flags, t_files *tmp,
				struct dirent *directory);
bool			ft_setlsfiles(t_ls_flags *flags, struct dirent *directory);
size_t			ft_dirlen(t_ls_flags *flags);
void			ft_freefile(t_files **tmp);
void			ft_setlsgenerals(t_files *tmp, struct stat stats,
		t_ls_flags *flags, struct dirent *directory);
t_dir			**ft_lsdirtab(t_ls_flags *flags, size_t size);
t_dir			**ft_lstsortdir(t_dir **list, size_t size);
void			ft_lssortdir(t_ls_flags *flags);
t_dir			**ft_lsnsortdir(t_dir **list, size_t size);
t_files			*ft_lsuntab(t_files ***list, size_t size);
t_files			**ft_lstab(t_ls_flags *flags, size_t size);
void			ft_browsedir(t_ls_flags *flags, struct dirent *directory);
bool			ft_addfile(char *str, t_ls_flags *flags);
bool			ft_isdirectory(t_ls_flags *flags);
#endif
