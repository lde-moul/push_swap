/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:35:01 by lde-moul          #+#    #+#             */
/*   Updated: 2017/05/02 15:46:27 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	push(t_stack **dst, t_stack **src)
{
	t_stack *moved;

	if (!(moved = *src))
		return ;
	*src = moved->next;
	moved->next = *dst;
	*dst = moved;
}

void		pa(t_stack **a, t_stack **b)
{
	push(a, b);
}

void		pb(t_stack **a, t_stack **b)
{
	push(b, a);
}
