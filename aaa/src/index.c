/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:31:30 by atangil           #+#    #+#             */
/*   Updated: 2023/10/16 17:46:05 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Push_swap.h"

// scans the stacks and returns the next node that has the lowest data
static t_stack	*get_next_min(t_stack **stack)
{
	t_stack	*head;
	t_stack	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head -> index == -1)
				&& (!has_min || (head -> data) < (min -> data)))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

// distributes and asigns numbers to index values of 
// all nodes of the stack low to high
void	index_stack(t_stack **stack)
{
	t_stack	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}
