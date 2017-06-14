/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:03:42 by lde-moul          #+#    #+#             */
/*   Updated: 2017/06/14 16:20:57 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rotate.h"
#include "reverse_rotate.h"
#include "push.h"

static int	max_value(t_stack *stack)
{
	int	n;

	if (!stack)
		return (0);
	n = stack->value;
	stack = stack->next;
	while (stack)
	{
		if (stack->value > n)
			n = stack->value;
		stack = stack->next;
	}
	return (n);
}

static int	value_distance(t_stack *stack, int value)
{
	int	n;

	n = 0;
	while (stack->value != value)
	{
		n++;
		stack = stack->next;
	}
	return (n);
}

void		sort_stack(t_stack **a, t_stack **b)
{
	int	distance;
	int	value;
	int	size;

	size = stack_size(*b);
	while (size)
	{
		value = max_value(*b);
		distance = value_distance(*b, value);
		if (distance <= size - distance)
			while ((*b)->value != value)
				rb(b);
		else
			while ((*b)->value != value)
				rrb(b);
		pa(a, b);
		size--;
	}
}
