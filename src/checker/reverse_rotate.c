/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:22:12 by lde-moul          #+#    #+#             */
/*   Updated: 2017/05/02 15:50:59 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

static void	reverse_rotate(t_stack **head)
{
	t_stack *newtail;

	if (!(*head && (*head)->next))
		return ;
	newtail = *head;
	while (newtail->next->next)
		newtail = newtail->next;
	newtail->next->next = *head;
	*head = newtail->next;
	newtail->next = NULL;
}

void		rra(t_stack **a, t_stack **b)
{
	(void)b;
	reverse_rotate(a);
}

void		rrb(t_stack **a, t_stack **b)
{
	(void)a;
	reverse_rotate(b);
}

void		rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
