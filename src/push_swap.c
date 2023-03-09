/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:33:56 by motroian          #+#    #+#             */
/*   Updated: 2023/02/04 19:13:31 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static
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

int	check_num(char *str)
{
	int i;
	
	i = 0;
	if (str[0] == '\0')
		return (0);
	if (str[0] == '-' || str[0] == '+')
	{
		i++;
		if (str[1] == '\0')
		return(0);
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_range(long int *tab, int size)
{
	int	i;
	int	j = 0;

	i = 0;
	while (i <= size - 1)
	{
		if (tab[i] > tab[i + 1])
			return(1);
		i++;
	}
	return (0);
}

int	parsing(char **av,int ac, t_data *data)
{
	int	i;
	int	j;
	int	k = 0;

	i = 1;
	j = 0;
	data->tab = calloc(sizeof(long int), ft_strlentab(av));
	if (!data->tab)
		return (0);
	decoupe_arg(data, av);
	data->len =  ft_strlentab(data->tableau) - 1;
	while (data->tableau[j])
	{
		if (check_num(data->tableau[j]) == 0)
			return (0);
		data->tab[j] = ft_atoi(data->tableau[j]);
		i++;
		j++;
	}
	if (check_int(data->tab, data->len) == 0)
		return (ft_printf("chien"), 0);
	if (check_double(data->tab, data->len) == 0)
		return (ft_printf("batard"), 0);
	if (check_range(data->tab, data->len) == 0)
		return (ft_printf("fou"), 0);
	return (1);
}

void	pushmintotop(t_data *data)
{
	t_list *tmp;

	int minimum = val_min(data);

	tmp = data->pile_a;
	while (data->pile_a->pos != minimum)
	{
		rotate_a(&data->pile_a);
	}
}

int	push_swap(char **str, int ac, t_data *data)
{
	int	i;
	t_list	*tmp;
	int	size;

	i = 0;
	if (parsing(str, ac, data) == 0)
		return (free(data->tab), ft_printf("error"), 0);
	ft_add(data);
	data->size_a = ft_lstsize(data->pile_a);
	ft_sort_int_tab(data->tab, data->size_a, data);
	pre_tri(data);
	size = ft_lstsize(data->pile_b);
	// size = 3;
	while (size != 0)
	{
		get_pos(data);
		ft_daron(data);
		ft_price(data);
		find_best(data);
		execute(data);
		size--;
	}
	pushmintotop(data);
	// rotate_a(&data->pile_a);
	// int r = val_min(data);
	// printf("minus %d\n", r);
	// put_top_b(data, data->pile_b->pos);
	// compteur(data);
	// if (data->len == 4)
	// 	tri_5(data);
	// if (data->len == 2)
	// 	tri_3(data);
	ft_printf("liste b :\n\n");
	aff_list(data->pile_b);
	ft_printf("liste a :\n\n");
	aff_list(data->pile_a);
	free(data->tab);
	free_list(data -> pile_a);
	free_list(data->pile_b);
	return (1);
}

int	main(int ac, char **av)
{
	t_data *data;
	int	i;
	
	data = ft_calloc(1, sizeof(t_data));
	if (ac > 1)
	{
		ft_printf("%d\n", push_swap(av, ac, data));
	}
	ft_printf("%d", data->nb);
	free(data);
	return (0);
}
