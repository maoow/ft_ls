/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 13:59:21 by cbinet            #+#    #+#             */
/*   Updated: 2017/01/19 18:48:08 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

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
	char			type;
	int				permissions;
	long			links;
	char			*uid;
	char			*gid;
	long long		size;
	long			timestamp;
	struct s_files	next;
}				t_files;

typedef struct	s_dir
{
	DIR				*actual;
	char			*path;
	struct s_dir	*next;
	t_files			*files;
}				t_dir;

typedef struct	s_ls_flags
{
	t_dir	*dir;
	bool	l;
	bool	R;
	bool	a;
	bool	r;
	bool	t;
	bool	error;
	bool	first;
}				t_ls_flags;
void	ft_display(t_ls_flags *flags);
#endif
