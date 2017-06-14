/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:08:10 by lde-moul          #+#    #+#             */
/*   Updated: 2017/06/14 17:22:47 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rotate.h"
#include "reverse_rotate.h"
#include "push.h"
#include <unistd.h>
#include <stdlib.h>

static int	*stack_to_array(t_stack *stack)
{
	int	*array;
	int	size;
	int	i;

	size = stack_size(stack);
	array = (int*)malloc(size * sizeof(int));
	if (!array)
	{
		write(2, "Out of memory\n", 14);
		exit(1);
	}
	i = 0;
	while (stack)
	{
		array[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (array);
}

static void	sort_array(int *array, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	value_distance(t_stack *stack, int median, int *dist, int *value)
{
	*dist = 0;
	while (stack && stack->value > median)
	{
		(*dist)++;
		stack = stack->next;
	}
	if (stack)
		*value = stack->value;
}

static void	split_median(t_stack **a, t_stack **b, int median)
{
	int	distance;
	int	value;
	int	size;

	size = stack_size(*a);
	value_distance(*a, median, &distance, &value);
	if (distance <= size - distance)
		while ((*a)->value != value)
			ra(a);
	else
		while ((*a)->value != value)
			rra(a);
	while (distance != size)
	{
		while ((*a)->value > median)
			ra(a);
		if ((*a)->value <= median)
		{
			pb(a, b);
			size--;
		}
		value_distance(*a, median, &distance, &value);
	}
}

void		split_stack(t_stack **a, t_stack **b, int pivots, int pivots_to_put)
{
	int	size;
	int	median;
	int	*sorted_values;
	int	i;

	size = stack_size(*a);
	sorted_values = stack_to_array(*a);
	sort_array(sorted_values, size);
	i = 1;
	while (i <= pivots_to_put)
	{
		median = sorted_values[size * i / pivots - 1];
		split_median(a, b, median);
		i++;
	}
	free(sorted_values);
}
