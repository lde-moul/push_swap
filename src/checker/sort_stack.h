/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:18:22 by lde-moul          #+#    #+#             */
/*   Updated: 2017/04/14 18:03:00 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_STACK_H
# define SORT_STACK_H

# include "stack.h"
# include "instructions.h"

void	sort_stack(t_stack **a, t_stack **b, t_instructionlist *instructions);
int		stack_sorted(t_stack *stack);

#endif
