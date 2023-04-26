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
	t_list *curr;
	int	temp;

	curr = lst;
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
	t_list *l1 = (t_list *)malloc(sizeof(t_list));
	t_list *l2 = (t_list *)malloc(sizeof(t_list));
	t_list *l3 = (t_list *)malloc(sizeof(t_list));
	t_list *curr;

	int a = 1;
	int b = 56;
	int c = -68;

	l1->data = a;
	l1->next = l2;
	l2->data = b;
	l2->next = l3;
	l3->data = c;
	l3->next = NULL;

	curr = sort_list(l1, &ascending);
	while (curr)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
	free(l1);
	free(l2);
	free(l3);
} */