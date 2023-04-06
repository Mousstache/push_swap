/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:31:03 by motroian          #+#    #+#             */
/*   Updated: 2023/02/16 21:50:51 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_new(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_gnl(int fd, int boolean)
{
	char			*str;
	static char		*position;
	char			*tmp;
	char			*ret;
	int				reader;

	reader = 1;
	if (boolean)
		return (free(position), NULL);
	str = malloc(sizeof(char) * (1 + 1));
	if (!str)
		return (NULL);
	while (!ft_strchr(position, '\n') && reader > 0)
	{
		reader = read(fd, str, 1);
		if (reader == -1)
			return (free(str), NULL);
		tmp = position;
		str[reader] = '\0';
		position = ft_realloc(tmp, str);
	}
	ret = ft_substr(position, 0, ft_new(position) + 1);
	tmp = position;
	position = ft_substr(tmp, ft_new(tmp) + 1, (ft_strlen(tmp) - ft_new(tmp)));
	return (free(tmp), free(str), ret);
}
