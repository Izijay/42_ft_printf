/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 02:16:13 by mdupuis           #+#    #+#             */
/*   Updated: 2021/07/05 12:31:11 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_input	ft_is_minus(t_input input)
{
	input.minus = 1;
	input.zero = 0;
	return (input);
}

t_input	ft_is_star(t_input input, va_list args)
{
	input.star = 1;
	input.width = va_arg(args, int);
	if (input.width < 0)
	{
		input.minus = 1;
		input.width *= -1;
		input.zero = 0;
	}
	return (input);
}

t_input	ft_is_dot(char *str, t_input *input, va_list args)
{
	if (input->dot != 0)
	{
		input->dot = 0;
		input->b_dot = 0;
	}
	else
	{
		input->b_dot = 1;
		input->i++;
		if (ft_check_type(str[input->i]))
			input->dot_exist = 0;
		if (str[input->i] == '*')
		{
			input->dot = va_arg(args, int);
			input->star = 1;
		}
		else
			while (ft_isdigit(str[input->i]))
				input->dot = (input->dot * 10) + ((int)str[input->i++] - 48);
	}
	if (str[input->i] == '.')
		input->i--;
	return (*input);
}

t_input	ft_is_nbr(char c, char d, t_input input, char *str)
{
	int		tmp;

	tmp = 0;
	if (input.width != 0 && !ft_isdigit(d))
	{
		if (d == '.')
			return (input);
		input.width = 0;
	}
	else if (input.width != 0)
	{
		tmp = input.i;
		while (ft_isdigit(str[input.i]))
			input.i--;
		if (str[input.i] == '.')
		{
			input.i = tmp;
			return (input);
		}
		input.i = tmp;
	}
	if (input.star == 1)
		input.width = 0;
	input.width = (input.width * 10) + (c - 48);
	return (input);
}
