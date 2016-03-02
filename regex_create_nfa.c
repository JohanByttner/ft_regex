/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_create_nfa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 14:49:27 by jbyttner          #+#    #+#             */
/*   Updated: 2016/03/02 20:53:04 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"

t_nfa	*regex_create_nfa(char **match, t_nfa **in, t_nfa *out)
{
	t_nfa	*next;
	t_nfa	*tmp;
	char	c;

	next = *in;
	while ((c = *(*match)++))
	{
		printf("Parsing %c %p\n", c, *in);
		if (c == '(')
		{
			tmp = regex_new_nfa(); // TODO: Exit if memory error
			regex_create_nfa(match, &next, tmp);
			regex_single_nfa(match, &next);
		}
		else if (c == ')')
		{
			next->out1 = out;
			return (in);
		}
		/*else if (c == '-')
			regex_range_nfa(&tmp);*/
		else if (c == '|')
		{
			printf("In in %p\n", *in);
			regex_split_nfa(in, &next, out);
			printf("In out %p\n", *in, (*in)->type);
		}
		else
		{
			regex_init_nfa(next, c, REGEX_SINGLE);
			regex_single_nfa(match, &next);
		}
	}
	return (*in);
}
