/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:46:11 by lde-moul          #+#    #+#             */
/*   Updated: 2017/06/14 18:34:39 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_stack.h"
#include "sort_stack.h"
#include "rotate.h"
#include "reverse_rotate.h"
#include "push.h"
#include "swap.h"

static int	stack_sorted(t_stack *stack)
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

static int	get_operators_for_pivots(int size, int pivots)
{
	int	split_operators;
	int	sort_operators;
	int	pivot_size;

	pivot_size = size / pivots;
	split_operators = size * (pivots + 1) / 2;
	sort_operators = (pivot_size - 1) * pivot_size / 2 / 3;
	sort_operators = (sort_operators + pivot_size) * pivots;
	return (split_operators + sort_operators);
}

static int	get_best_pivots(int size)
{
	int	best_pivots;
	int	min_operators;
	int	operators;
	int	pivots;

	best_pivots = 1;
	min_operators = 0x7fffffff;
	pivots = 1;
	while (pivots <= size)
	{
		operators = get_operators_for_pivots(size, pivots);
		if (operators < min_operators)
		{
			best_pivots = pivots;
			min_operators = operators;
		}
		pivots++;
	}
	return (best_pivots);
}

static void	sort_short_stack(t_stack **a, t_stack **b)
{
	if (stack_size(*a) > 3)
		split_stack(a, b, 2, 1);
	if (stack_size(*a) == 3)
	{
		if ((*a)->value > (*a)->next->value
		&& (*a)->value > (*a)->next->next->value)
			ra(a);
		else if ((*a)->next->value > (*a)->value
		&& (*a)->next->value > (*a)->next->next->value)
			rra(a);
	}
	if (stack_size(*a) >= 2 && (*a)->value > (*a)->next->value
	&& stack_size(*b) >= 2 && (*b)->value < (*b)->next->value)
		ss(a, b);
	else if (stack_size(*a) >= 2 && (*a)->value > (*a)->next->value)
		sa(a);
	else if (stack_size(*b) >= 2 && (*b)->value < (*b)->next->value)
		sb(b);
	while (*b)
		pa(a, b);
}

void		get_instructions(t_stack **a, t_stack **b)
{
	int	pivots;
	int	size;

	if (stack_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size > 5)
	{
		pivots = get_best_pivots(size);
		split_stack(a, b, pivots, pivots);
		sort_stack(a, b);
	}
	else
		sort_short_stack(a, b);
}
