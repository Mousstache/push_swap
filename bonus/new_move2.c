/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_move2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:07:10 by motroian          #+#    #+#             */
/*   Updated: 2023/02/16 21:33:22 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_rrr(t_data *data)
{
	if (!data->pile_a || !data->pile_b)
		return ;
	new_reverse_a(&data->pile_a);
	new_reverse_b(&data->pile_b);
}

void	new_ss(t_data *data)
{
	if (!data->pile_a || !data->pile_b)
		return ;
	new_swap_a(data);
	new_swap_b(data);
}

void	free_exit(t_data *data)
{
	if (data->tab)
		free(data->tab);
	free_list(data -> pile_a);
	free_list(data->pile_b);
	free_all(data->tableau);
	free(data);
	exit(1);
}
