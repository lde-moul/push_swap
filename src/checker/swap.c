/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:25:18 by lde-moul          #+#    #+#             */
/*   Updated: 2017/05/02 15:54:43 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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

void		sa(t_stack **a, t_stack **b)
{
	(void)b;
	swap(a);
}

void		sb(t_stack **a, t_stack **b)
{
	(void)a;
	swap(b);
}

void		ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}
