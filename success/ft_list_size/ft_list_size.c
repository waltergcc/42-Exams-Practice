#include <stdio.h>
#include <stdlib.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
	int i = 0;
	t_list *curr;
	curr = begin_list;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
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

	l1->data = (void *)&a;
	l2->data = (void *)&b;
	l3->data = (void *)&c;

	l1->next = l2;
	l2->next = l3;
	l3->next = NULL;

	printf("List size: %d\n\n", ft_list_size(l1));
	curr = l1;
	while (curr)
	{
		printf("%d\n", *(int *)curr->data);
		curr = curr->next;
	}
	free(l1);
	free(l2);
	free(l3);
} */
