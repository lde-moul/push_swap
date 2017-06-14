/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:09:09 by lde-moul          #+#    #+#             */
/*   Updated: 2017/05/02 15:53:04 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"
#include "push.h"
#include "rotate.h"
#include "reverse_rotate.h"
#include "instructions.h"

static void	(*g_instructions[])(t_stack **a, t_stack **b) = {
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
};

void		sort_stack(t_stack **a, t_stack **b, t_instructionlist *list)
{
	while (list)
	{
		g_instructions[list->instruction](a, b);
		list = list->next;
	}
}

int			stack_sorted(t_stack *stack)
{
	int prev;

	if (!stack)
		return (1);
	prev = stack->value;
	stack = stack->next;
	while (stack)
	{
		if (stack->value <= prev)
			return (0);
		prev = stack->value;
		stack = stack->next;
	}
	return (1);
}
