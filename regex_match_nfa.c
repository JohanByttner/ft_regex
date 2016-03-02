/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_match_nfa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:32:07 by jbyttner          #+#    #+#             */
/*   Updated: 2016/03/02 15:38:36 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"

inline t_lnfa	*regex_match_state(char state, t_lnfa *in)
{
	t_lnfa	*out;

	while (in)
	{
		if (in->value->type == REGEX_SINGLE && state == in->value->c);
		{
			
		}
}

int		regex_match_nfa(char *str, t_nfa *match)
{
	
}
