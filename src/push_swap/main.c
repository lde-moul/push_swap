/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:27:39 by lde-moul          #+#    #+#             */
/*   Updated: 2017/05/29 15:45:07 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unsorted_stack.h"
#include "instructions.h"
#include <stdlib.h>
#include <unistd.h>

static void	free_all(t_stack *a, t_stack *b)
{
	t_stack				*next_stack;

	while (a)
	{
		next_stack = a->next;
		free(a);
		a = next_stack;
	}
	while (b)
	{
		next_stack = b->next;
		free(b);
		b = next_stack;
	}
}

static int	error(t_stack *stack)
{
	t_stack	*next;

	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
	write(1, "Error\n", 6);
	return (1);
}

int			main(int argc, char **argv)
{
	t_stack				*a;
	t_stack				*b;

	if (!(a = get_unsorted_stack(argc, argv)))
		return (error(NULL));
	b = NULL;
	get_instructions(&a, &b);
	free_all(a, b);
	return (0);
}
