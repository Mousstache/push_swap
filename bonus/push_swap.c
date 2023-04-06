/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:33:56 by motroian          #+#    #+#             */
/*   Updated: 2023/02/17 18:20:43 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *lst)
{
	t_list	*ptr;
	t_list	*tmp;

	ptr = lst;
	while (ptr)
	{
		tmp = ptr -> next;
		free(ptr);
		ptr = tmp;
	}
}

int	parsing(char **av, t_data *data)
{
	int	j;

	j = -1;
	data->tab = malloc(sizeof(long int) * ft_strlentab(av));
	if (!data->tab)
		return (0);
	data->tableau = decoupe_arg(av, 0);
	if (!data->tableau)
		return (0);
	data->len = ft_strlentab(data->tableau);
	while (data->tableau[++j])
	{
		if (check_num(data->tableau[j]) == 0)
			return (ft_putstr_e("error\n"), 0);
		if (check_int(data->tableau[j]) == 0)
			return (ft_putstr_e("error\n"), 0);
		data->tab[j] = ft_atoi(data->tableau[j]);
	}
	if (check_double(data->tab, data->len) == 0)
		return (ft_putstr_e("error\n"), 0);
	if (check_range(data->tab, data->len) == 0)
		return (ft_putstr_e("error\n"), 0);
	return (1);
}

void	algo(t_data *data)
{
	int	size;

	pre_tri(data);
	size = ft_lstsize(data->pile_b);
	while (size != 0)
	{
		get_pos(data);
		ft_daron(data);
		ft_price(data);
		execute(data);
		size--;
	}
	pushmintotop(data);
}

int	push_swap(char **str, t_data *data)
{
	if (parsing(str, data) == 0)
		return (ft_printf("error\n"), 0);
	ft_add(data);
	data->size_a = ft_lstsize(data->pile_a);
	ft_sort_int_tab(data->tab, data->size_a, data);
	if (data->len == 4)
		tri_5(data);
	else if (data->len == 1)
	{
		if (data->pile_a->next->valeur < data->pile_a->valeur)
			swap_a(data);
	}
	else if (data->len == 2)
		tri_3(data);
	else
		algo(data);
	return (1);
}
