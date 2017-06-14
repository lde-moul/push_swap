/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:53:04 by lde-moul          #+#    #+#             */
/*   Updated: 2017/05/24 15:47:00 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

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
	RRR,
	ERR
}					t_instruction;

typedef struct		s_instructionlist
{
	t_instruction				instruction;
	struct s_instructionlist	*next;
}					t_instructionlist;

int					get_instructions(t_instructionlist **instructions);

#endif
