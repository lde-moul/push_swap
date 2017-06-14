/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsorted_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:54:24 by lde-moul          #+#    #+#             */
/*   Updated: 2017/05/11 16:28:16 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
#include <stdlib.h>

static t_stack	*error(t_stack *stack, char **numbers, int i)
{
	t_stack	*next;

	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
	while (numbers[i])
		free(numbers[i++]);
	free(numbers);
	return (NULL);
}

static int		push(t_stack **stack, int n)
{
	t_stack *new;

	new = (t_stack*)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->value = n;
	new->next = *stack;
	*stack = new;
	return (1);
}

static void		reverse(t_stack **stack)
{
	t_stack *elem;
	t_stack *next;
	t_stack *prev;

	elem = *stack;
	prev = NULL;
	while (elem)
	{
		next = elem->next;
		elem->next = prev;
		prev = elem;
		elem = next;
	}
	*stack = prev;
}

static int		invalid(t_stack *stack, char *s, int n)
{
	while (*s)
	{
		if (!(ft_isdigit(*s) || *s == '-' || *s == '+'))
			return (1);
		s++;
	}
	while (stack)
	{
		if (stack->value == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_stack			*get_unsorted_stack(int argc, char **argv)
{
	t_stack	*stack;
	char	**numbers;
	int		n;
	int		i;
	int		j;

	stack = NULL;
	i = 0;
	while (i < argc - 1)
	{
		numbers = ft_strsplit(argv[i + 1], ' ');
		j = 0;
		while (numbers[j])
		{
			n = ft_atoi(numbers[j]);
			if (invalid(stack, numbers[j], n) || !push(&stack, n))
				return (error(stack, numbers, j));
			free(numbers[j]);
			j++;
		}
		free(numbers);
		i++;
	}
	reverse(&stack);
	return (stack);
}
