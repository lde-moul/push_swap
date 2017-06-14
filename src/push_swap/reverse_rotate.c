/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:22:12 by lde-moul          #+#    #+#             */
/*   Updated: 2017/05/02 16:26:39 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <unistd.h>

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

void		rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void		rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}
