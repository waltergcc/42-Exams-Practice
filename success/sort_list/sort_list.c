
// #include <stdio.h>
// #include <stdlib.h>
#include "list.h"
/* 
int ascending(int a, int b)
{
	return (a <= b);
}
 */
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *curr;
	int tmp = 0;

	curr = lst;
	while (lst->next)
	{
		if (cmp(lst->data, lst->next->data) == 0)
		{
			tmp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp;
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

	l1->data = 1;
	l2->data = -5;
	l3->data = 0;

	l1->next = l2;
	l2->next = l3;
	l3->next = NULL;

/* 	curr = l1;
	while(curr)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
	curr = sort_list(l1, &ascending);
	while(curr)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
}
 */