/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:12:09 by lde-moul          #+#    #+#             */
/*   Updated: 2017/06/14 17:23:00 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_STACK_H
# define SPLIT_STACK_H

# include "stack.h"

void	split_stack(t_stack **a, t_stack **b, int pivots, int pivots_to_put);

#endif
