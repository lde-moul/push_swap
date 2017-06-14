/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:27:39 by lde-moul          #+#    #+#             */
/*   Updated: 2017/05/24 15:40:54 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unsorted_stack.h"
#include "instructions.h"
#include "sort_stack.h"
#include <stdlib.h>
#include <unistd.h>

static void	free_all(t_stack *a, t_stack *b, t_instructionlist *instructions)
{
	t_stack				*next_stack;
	t_instructionlist	*next_instruction;

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
	while (instructions)
	{
		next_instruction = instructions->next;
		free(instructions);
		instructions = next_instruction;
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
	t_instructionlist	*instructions;

	if (argc == 1)
		return (0);
	if (!(a = get_unsorted_stack(argc, argv)))
		return (error(NULL));
	if (!get_instructions(&instructions))
		return (error(a));
	b = NULL;
	sort_stack(&a, &b, instructions);
	write(1, stack_sorted(a) && !b ? "OK\n" : "KO\n", 3);
	free_all(a, b, instructions);
	return (0);
}
