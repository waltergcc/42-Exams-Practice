#include <stdio.h>
#include <stdlib.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
	t_list *curr;
	int	size = 0;

	curr = begin_list;
	while (curr)
	{
		size++;
		curr = curr->next;
	}
	return (size);
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

	l1->data = (void *)&a;
	l1->next = l2;
	l2->data = (void *)&b;
	l2->next = l3;
	l3->data = (void *)&c;
	l3->next = NULL;

	curr = l1;
	int size = ft_list_size(l1);
	printf("Size: %d\n", size);
	while (curr)
	{
		printf("%d\n", *(int *)curr->data);
		curr = curr->next;
	}
	free(l1);
	free(l2);
	free(l3);
} */