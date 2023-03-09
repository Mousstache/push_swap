/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:15:57 by motroian          #+#    #+#             */
/*   Updated: 2023/01/16 19:25:58 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

typedef struct s_data
{
	long int *tab;
	struct s_list *pile_a;
	struct s_list *pile_b;
	int len;
	
} t_data;

typedef struct s_list
{
	int valeur;
	int index;
	struct s_list *next;
} t_list;

void ft_add(t_data *data);
t_list	*ft_lstnew(int nb, int index);
void	swap_a(t_list *pile_a);
void	aff_list(t_list *lst);

#endif
