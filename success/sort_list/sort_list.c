#include <stdio.h>
#include <stdlib.h>
#include "list.h"
/* 
int ascending(int a, int b)
{
	return (a <= b);
} */

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int temp;
	t_list *curr = lst;

	while (lst->next)
	{
		if (cmp(lst->data, lst->next->data) == 0)
		{
			temp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = temp;
			lst = curr;
		}
		else
			lst = lst->next;
	}
	lst = curr;
	return (lst);
}
/* 
int	main(void)
{
	t_list	*l1 = (t_list *)malloc(sizeof(t_list));
	t_list	*l2 = (t_list *)malloc(sizeof(t_list));
	t_list	*l3 = (t_list *)malloc(sizeof(t_list));
	t_list	*l4 = (t_list *)malloc(sizeof(t_list));
	t_list	*l5 = (t_list *)malloc(sizeof(t_list));
	t_list	*l6 = (t_list *)malloc(sizeof(t_list));
	t_list	*curr;

	l1->data = 2;
	l2->data = -1;
	l3->data = 7;
	l4->data = -13;
	l5->data = 13;
	l6->data = 0;

	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;
	l6->next = NULL;

	curr = sort_list(l1, &ascending);
	while (curr)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
} */
