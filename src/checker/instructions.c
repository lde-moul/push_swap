/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:17:16 by lde-moul          #+#    #+#             */
/*   Updated: 2017/06/12 15:41:21 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"
#include "instructions.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static const char			*g_instructions[] = {
	"sa",
	"sb",
	"ss",
	"pa",
	"pb",
	"ra",
	"rb",
	"rr",
	"rra",
	"rrb",
	"rrr",
};

static int					error(t_instructionlist *instructions)
{
	t_instructionlist	*next;

	while (instructions)
	{
		next = instructions->next;
		free(instructions);
		instructions = next;
	}
	return (0);
}

static int					add(t_instructionlist **list, t_instruction i)
{
	t_instructionlist *new;

	new = (t_instructionlist*)malloc(sizeof(t_instructionlist));
	if (!new)
		return (0);
	new->instruction = i;
	new->next = *list;
	*list = new;
	return (1);
}

static void					reverse(t_instructionlist **instructions)
{
	t_instructionlist *elem;
	t_instructionlist *next;
	t_instructionlist *prev;

	elem = *instructions;
	prev = NULL;
	while (elem)
	{
		next = elem->next;
		elem->next = prev;
		prev = elem;
		elem = next;
	}
	*instructions = prev;
}

static t_instruction		get_instruction(const char *s)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (!ft_strcmp(s, g_instructions[i]))
			return (i);
		i++;
	}
	return (ERR);
}

int							get_instructions(t_instructionlist **instructions)
{
	t_instruction		instruction;
	char				s[4];
	int					i;
	int					r;

	*instructions = NULL;
	while (1)
	{
		i = 0;
		while (i < 4 && (r = read(0, s + i, 1)) == 1 && s[i] != '\n')
			i++;
		if (!r)
			break ;
		if (i >= 4)
			return (error(*instructions));
		s[i] = '\0';
		if ((instruction = get_instruction(s)) == ERR)
			return (error(*instructions));
		if (!add(instructions, instruction))
			return (error(*instructions));
	}
	reverse(instructions);
	return (1);
}
