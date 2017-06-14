/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 13:18:26 by lde-moul          #+#    #+#             */
/*   Updated: 2017/05/02 17:08:46 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include "stack.h"

typedef enum		e_instruction
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}					t_instruction;

typedef struct		s_instructionlist
{
	t_instruction				instruction;
	struct s_instructionlist	*next;
}					t_instructionlist;

void				get_instructions(t_stack **a, t_stack **b);

#endif
