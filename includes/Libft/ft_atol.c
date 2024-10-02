/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 02:46:32 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/10/02 07:06:04 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	check_overflow(long result, int sign, int digit)
{
	if (sign == 1 && (result > LONG_MAX / 10 || (result == LONG_MAX / 10
				&& digit > LONG_MAX % 10)))
		return (1);
	else if (sign == -1 && ((result > (LONG_MAX + sign) / 10)
			|| (result == (LONG_MAX + sign) / 10 && digit > LONG_MAX % 10 + 1)))
		return (-1);
	return (0);
}

const char	*skip_whitespace(const char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

int	extract_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	else if (**str == '+')
	{
		(*str)++;
	}
	return (sign);
}

long	parse_digits(const char *str, int sign)
{
	long	result;
	int		digit;
	int		overflow;

	result = 0;
	while (ft_isdigit(*str))
	{
		digit = *str - '0';
		overflow = check_overflow(result, sign, digit);
		if (overflow == 1)
			return (LONG_MAX);
		else if (overflow == -1)
			return (LONG_MIN);
		result = result * 10 + digit;
		str++;
	}
	return (result);
}

long	ft_atol(const char *str)
{
	int	sign;

	str = skip_whitespace(str);
	sign = extract_sign(&str);
	return (parse_digits(str, sign) * sign);
}
