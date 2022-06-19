/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:07:04 by sisyreet          #+#    #+#             */
/*   Updated: 2022/06/19 12:54:29 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int				i;
	long long int	k;
	int				minus;

	i = 0;
	k = 0;
	minus = 1;
	while ((str[i] > 8 && str[i] < 14) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = 1 * (-1);
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		k = k * 10 + (str[i++] - '0');
		if (k > 2147483647)
			return (0);
		if (k < 0)
			return (0);
	}
	return (k * minus);
}
