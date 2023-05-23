#include <stdio.h>
#include <stdlib.h>
#include "list.h"
/* 
int ascending(int a, int b)
{
	return (a <= b);
}
 */
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int	tmp = 0;
	t_list *curr = lst;
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

	int a = -63;
	int b = 0;
	int c = -87;

	l1->data = a;
	l2->data = b;
	l3->data = c;

	l1->next = l2;
	l2->next = l3;
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
