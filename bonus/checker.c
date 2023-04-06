/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:24:52 by motroian          #+#    #+#             */
/*   Updated: 2023/02/16 23:23:42 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_check(t_data *data)
{
	t_list	*tmp;
	int		comp;

	comp = data->pile_a->valeur;
	tmp = data->pile_a;
	while (tmp)
	{
		if (tmp->valeur < comp)
		{
			ft_printf("KO\n");
			free_exit(data);
		}
		comp = tmp->valeur;
		tmp = tmp->next;
	}
	if (!data->pile_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	mouv_read_1(t_data *data, char *str)
{
	if (ft_strcmp(str, "ra\n") == 0)
		new_rotate_a(&data->pile_a);
	else if (ft_strcmp(str, "rb\n") == 0)
		new_rotate_b(&data->pile_b);
	else if (ft_strcmp(str, "rra\n") == 0)
		new_reverse_a(&data->pile_a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		new_reverse_b(&data->pile_b);
	else if (ft_strcmp(str, "sa\n") == 0)
		new_swap_a(data);
	else if (ft_strcmp(str, "sb\n") == 0)
		new_swap_b(data);
}

void	mouv_read(t_data *data, char *str)
{
	if ((ft_strcmp(str, "ra\n") == 0) || (ft_strcmp(str, "rb\n") == 0)
		|| (ft_strcmp(str, "rra\n") == 0) || (ft_strcmp(str, "rrb\n") == 0)
		|| (ft_strcmp(str, "sa\n") == 0) || (ft_strcmp(str, "sb\n") == 0))
		mouv_read_1(data, str);
	else if (ft_strcmp(str, "pa\n") == 0)
		new_push_a(data);
	else if (ft_strcmp(str, "pb\n") == 0)
		new_push_b(data);
	else if (ft_strcmp(str, "rr\n") == 0)
		new_rr(data);
	else if (ft_strcmp(str, "rrr\n") == 0)
		new_rrr(data);
	else if (ft_strcmp(str, "ss\n") == 0)
		new_ss(data);
	else
	{
		if (ft_strlen(str) == 0)
			tri_check(data);
		else
			ft_printf("KO\n");
		free(str);
		ft_gnl(1, 1);
		free_exit(data);
	}
}

int	checker(t_data *data, char **av)
{
	char	*str;

	if (parsing(av, data) == 0)
		return (0);
	ft_add(data);
	str = ft_gnl(0, 0);
	while (str)
	{
		mouv_read(data, str);
		free(str);
		str = ft_gnl(0, 0);
		if (!str || !*str)
			break ;
	}
	free(str);
	ft_gnl(1, 1);
	tri_check(data);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (0);
	if (ac > 1)
		checker(data, av);
	if (data->tab)
		free(data->tab);
	free_list(data -> pile_a);
	free_list(data->pile_b);
	free_all(data->tableau);
	free(data);
}
