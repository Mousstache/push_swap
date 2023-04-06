/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mak.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:15:57 by motroian          #+#    #+#             */
/*   Updated: 2023/02/12 17:25:56 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BUFFER_SIZE 42

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_data
{
	long int		*tab;
	char			**tableau;
	int				mediane;
	int				mediane5;
	int				top;
	int				size_a;
	int				size_b;
	int				nb;
	int				index_min;
	struct s_list	*pile_a;
	struct s_list	*pile_b;
	int				len;
}	t_data;

typedef struct s_list
{
	int				valeur;
	int				index;
	int				daron;
	int				pos;
	int				coup;
	int				coup_b;
	int				coup_a;
	struct s_list	*next;
}	t_list;

typedef struct s_countmoves
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
}	t_countmoves;

int			check_int(char *str);
int			check_double(long int *tab, int ac);
int			check_range(long int *tab, int size);
int			check_num(char *str);
long int	ft_atoi(char *str);
void		ft_add(t_data *data);
t_list		*ft_lstnew(int nb, int index);
void		aff_list(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		copy_list(t_data *data);
void		*list_init(t_data *data);
t_list		*ft_lstlast(t_list *lst);
void		push_a(t_data *data);
void		push_b(t_data *data);
void		swap_a(t_data *data);
void		swap_b(t_data *data);
void		rotate_a(t_list **pile_a);
void		rotate_b(t_list **pile_a);
void		reverse_a(t_list **pile_a);
void		reverse_b(t_list **pile_b);
void		new_ss(t_data *data);
void		rr(t_data *data);
void		rrr(t_data *data);
long int	*ft_sort_int_tab(long int *tab, int size, t_data *data);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		*list_init(t_data *data);
int			ft_lstsize(t_list *lst);
void		tri_3(t_data *data);
void		pre_tri(t_data *data);
char		**decoupe_arg(char **av, int i);
int			ft_strlentab(char **av);
void		tri_5(t_data *data);
void		compteur(t_data *data);
void		ft_daron(t_data *data);
void		get_pos(t_data *data);
void		put_top_a(t_data *data, int pos);
void		put_top_b(t_data *data, int pos);
void		ft_price(t_data *data);
int			find_best(t_data *data);
void		execute(t_data *data);
int			val_min(t_data *data);
void		free_all(char **tab);
void		pushmintotop(t_data *data);
void		rotate_aa(t_list **pile_a);
void		rotate_bb(t_list **pile_b);
int			ft_mediane(long int *tab, t_data *data, int size);
int			val_max(t_data *data);
void		free_list(t_list *lst);
void		new_push_a(t_data *data);
void		new_push_b(t_data *data);
void		new_swap_a(t_data *data);
void		new_swap_b(t_data *data);
void		new_rotate_a(t_list **pile_a);
void		new_rotate_b(t_list **pile_a);
void		new_reverse_a(t_list **pile_a);
void		new_reverse_b(t_list **pile_b);
void		new_rr(t_data *data);
void		new_rrr(t_data *data);
int			parsing(char **av, t_data *data);
char		*ft_gnl(int fd, int boolean);
void		free_exit(t_data *data);

#endif
