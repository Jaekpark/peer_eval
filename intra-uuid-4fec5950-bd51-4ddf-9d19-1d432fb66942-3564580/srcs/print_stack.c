/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:43:13 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/10 03:12:18 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_print(t_node *a, t_node *b)
{
	print_stack_a(a);
	print_stack_b(b);
}

void		print_stack_a(t_node *a)
{
	if (a != NULL)
	{
		ft_printf("| ");
		print_node(a);
		ft_printf(" |");
	}
	else if (a == NULL)
		ft_printf("| {      } (      ) [      ] |");
}

void		print_stack_b(t_node *b)
{
	if (b != NULL)
	{
		ft_printf(" | ");
		print_node(b);
		ft_printf(" |\n");
	}
	else if (b == NULL)
		ft_printf(" | {      } (      ) [      ] |\n");
}

int			print_two_stack(t_sort *s)
{
	t_node *a_tmp;
	t_node *b_tmp;

	a_tmp = s->a->top;
	b_tmp = s->b->top;
	if (!s)
		return (-1);
	print_header();
	while (1)
	{
		do_update(s);
		if (a_tmp == NULL && b_tmp == NULL)
			return (print_last(s));
		do_print(a_tmp, b_tmp);
		if (a_tmp != NULL && a_tmp->prev != NULL)
			a_tmp = a_tmp->prev;
		else if (a_tmp != NULL && a_tmp->prev == NULL)
			a_tmp = NULL;
		if (b_tmp != NULL && b_tmp->prev != NULL)
			b_tmp = b_tmp->prev;
		else if (b_tmp != NULL && b_tmp->prev == NULL)
			b_tmp = NULL;
	}
}
