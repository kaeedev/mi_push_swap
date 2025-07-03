/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbe <lalbe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:22:58 by lalbe             #+#    #+#             */
/*   Updated: 2025/07/03 17:25:16 by lalbe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str ++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str ++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str ++;
	}
	return (sign * result);
}
