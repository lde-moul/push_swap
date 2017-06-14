/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:59:09 by lde-moul          #+#    #+#             */
/*   Updated: 2017/05/02 16:25:44 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <unistd.h>

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

void		ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void		rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}
