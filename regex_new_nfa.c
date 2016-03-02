/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_new_nfa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:01:03 by jbyttner          #+#    #+#             */
/*   Updated: 2016/03/02 15:30:37 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"

t_nfa	*regex_new_nfa(void)
{
	t_nfa	*tmp;

	if (!(tmp = malloc(sizeof(t_nfa))))
		return (0);
	tmp->out1 = 0;
	tmp->out2 = 0;
	tmp->c = 0;
	tmp->type = REGEX_PASS;
	return (tmp);
}

void		regex_init_nfa(t_nfa *nfa, int c, t_nfatype type)
{
	nfa->c = c;
	nfa->type = type;
}

void		regex_split_nfa(t_nfa **in, t_nfa **next, t_nfa *out)
{
	t_nfa	*head;
	t_nfa	*tmp;

	if (!(head = regex_new_nfa()))
		return ;
	if (!(tmp = regex_new_nfa()))
	{
		free(head);
		return ;
	}
	regex_init_nfa(head, 0, REGEX_SPLIT);
	head->out1 = *in;
	head->out2 = tmp;
	(*next)->out1 = out;
	*in = head;
	*next = tmp;
}

/*void		regex_range_nfa(char range, t_nfa **tmp)
{
	t_nfa	*range_end;

	if (!(range_end = regex_new_nfa(range, REGEX_SINGLE)))
		return ;
	regex_split_nfa(tmp, &range_end);
	if (!(range_end = regex_new_nfa(0, REGEX_PASS)))
	{
		// TODO: Cleanup
		return ;
	}
	(*tmp)->out1->out1 = range_end;
	(*tmp)->out2->out2 = range_end;
	(*tmp)->type = REGEX_RANGE;
	*tmp = range_end;
}*/

void		regex_single_nfa(char **match, t_nfa **next)
{
	t_nfa		*out;
	t_nfa		*tmp;

	if (match[0][1] == '?' || match[0][1] == '*')
	{

		if ((out = regex_new_nfa()))
		{
			tmp = regex_new_nfa();
			// TODO: Add cleanup
		}

		regex_transfer_nfa(*next, tmp);

		(*next)->out1 = tmp;
		match += 1;

		tmp->out1 = out;

		(*next)->out2 = out;
		if (match[0][1] == '*')
			tmp->out2 = tmp;
		*next = out;
	}
	else
	{

		if (!(out = regex_new_nfa()))
			return ;
		(*next)->out1 = out;
		*next = out;
	}
}
