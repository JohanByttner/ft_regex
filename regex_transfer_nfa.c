/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_transfer_nfa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:08:13 by jbyttner          #+#    #+#             */
/*   Updated: 2016/03/02 15:38:48 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"

void	regex_transfer_nfa(t_nfa *old, t_nfa *current)
{
	current->out1 = old->out1;
	current->out2 = old->out2;
	regex_init_nfa(current, old->c, old->type);
	regex_init_nfa(old, 0, REGEX_SPLIT);
}
