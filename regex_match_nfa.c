/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_match_nfa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:32:07 by jbyttner          #+#    #+#             */
/*   Updated: 2016/03/02 20:53:08 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"

static inline void	regex_state_new_frag(t_nfa *value, t_lnfa **head,
		t_lnfa **tail)
{
	t_lnfa	*t1;
	t_lnfa	*t2;

	t1 = 0;
	t2 = 0;
	printf("Frag start\n");
	if (value->out1)
	{
		if (!(t1 = malloc(sizeof(t_lnfa))))
			return ;
		t1->value = value->out1;
	}
	if (value->out2)
	{
		if (!(t2 = malloc(sizeof(t_lnfa))))
		{
			if (t1)
				free(t1);
			return ;
		}
		t2->value = value->out2;
	}
	printf("Frag middle\n");
	if (t1)
	{
		(*tail)->next = t1;
		*tail = (*tail)->next;
	}
	if (t2)
	{
		(*tail)->next = t2;
		*tail = (*tail)->next;
	}
	if (!(*head))
		*head = *tail;
	printf("Frag end\n");
}

static inline t_lnfa	*regex_match_nfa_states(char state, t_lnfa *in)
{
	t_lnfa	*head;
	t_lnfa	*tail;
	t_lnfa	*tmp;
	t_nfa	*v;

	head = 0;
	while (in && (v = in->value))
	{
		printf("State main loop %p %d %d, %d\n", v, v->type, REGEX_SINGLE, (char)(v->c));
		if (v->type == REGEX_SINGLE && v->c == state)
		{
			printf("Single match for %c\n", state);
			regex_state_new_frag(v, &head, &tail);
		}
		else if (v->type == REGEX_PASS || v->type == REGEX_SPLIT)
		{
			printf("Regex pass\n");
			regex_state_new_frag(v, &head, &tail);
		}
		else if (v->type == REGEX_MATCH)
		{
			printf("Match for this\n");
			v->out1 = v;
			regex_state_new_frag(v, &head, &tail);
			return (head);
		}
		printf("Exiting state main %p\n", in);
		tmp = in;
		in = in->next;
		free(tmp);
		printf("exiting loop %p\n", in);
	}
	return (head);
}

int			regex_nfa_find_match(t_lnfa *ptr)
{
	printf("Checking victory\n");
	while (ptr)
	{
		if (ptr->value->type == REGEX_MATCH)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int		regex_match_nfa(char *str, t_nfa *match)
{
	char	c;
	t_lnfa	*ptr;
	t_lnfa	*tmp;

	if (!(ptr = malloc(sizeof(t_lnfa))))
		return (0);
	ptr->value = match;
	ptr->next = 0;
	while ((c = *str++))
	{
		printf("%c main loop\n", c);
		if ((ptr = regex_match_nfa_states(c, ptr)))
		{
			printf("State head\n");
			if (regex_nfa_find_match(ptr)) // TODO: Free match string
				return (1);
		}
		else
			return (0);
	}
	return (0);
}
