/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:59:09 by lde-moul          #+#    #+#             */
/*   Updated: 2017/05/02 15:51:15 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

static void	rotate(t_stack **head)
{
	t_stack *tail;

	if (!(*head && (*head)->next))
		return ;
	tail = *head;
	while (tail->next)
		tail = tail->next;
	tail->next = *head;
	*head = (*head)->next;
	tail->next->next = NULL;
}

void		ra(t_stack **a, t_stack **b)
{
	(void)b;
	rotate(a);
}

void		rb(t_stack **a, t_stack **b)
{
	(void)a;
	rotate(b);
}

void		rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
