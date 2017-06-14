/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:25:18 by lde-moul          #+#    #+#             */
/*   Updated: 2017/06/14 16:24:28 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <unistd.h>

static void	swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	if (!(first = *stack))
		return ;
	if (!(second = first->next))
		return ;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void		sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void		sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void		ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
