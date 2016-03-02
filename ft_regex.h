/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 14:56:18 by jbyttner          #+#    #+#             */
/*   Updated: 2016/03/02 20:40:56 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REGEX_H
# define FT_REGEX_H
# include <stdlib.h>
# include <stdio.h> //TODO: Remove after testing

typedef enum		e_nfatype
{
	REGEX_PASS,
	REGEX_SINGLE,
	REGEX_SPLIT,
	REGEX_OUT,
	REGEX_RANGE,
	REGEX_MATCH
}					t_nfatype;

typedef struct		s_nfa
{
	t_nfatype		type;
	int				c;
	struct s_nfa	*out1;
	struct s_nfa	*out2;
}					t_nfa;

typedef struct		s_lnfa
{
	t_nfa			*value;
	struct s_lnfa	*next;
}					t_lnfa;

void				regex_transfer_nfa(t_nfa *old, t_nfa *current);

void				regex_single_nfa(char **match, t_nfa **next);

t_nfa				*regex_new_nfa(void);

void				regex_init_nfa(t_nfa *nfa, int c, t_nfatype type);

void				regex_split_nfa(t_nfa **in, t_nfa **next, t_nfa *out);

void				regex_single_nfa(char **match, t_nfa **next);

t_nfa				*regex_create_nfa(char **match, t_nfa **in, t_nfa *out);

#endif
