/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:19:13 by jbyttner          #+#    #+#             */
/*   Updated: 2016/03/02 20:53:11 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"

int		main(void)
{
	char	*str = "4";
	char	*match = "((123)|4)*5?";
	t_nfa	*in;
	t_nfa	*out;

	in = regex_new_nfa();
	out = regex_new_nfa();
	out->type = REGEX_MATCH;
	regex_create_nfa(&match, &in, out);
	printf("exit %p %p\n", in->out1, in);
	printf("Match == %d\n", regex_match_nfa(str, in));
}
