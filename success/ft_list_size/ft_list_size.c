
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
	int i = 0;

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

	int a = 1;
	int b = 2;
	int c = 3;

	l1->data = (void *)&a;
	l2->data = (void *)&b;
	l3->data = (void *)&c;

	l1->next = l2;
	l2->next = l3;
	l3->next = NULL;

	printf("Size: %d\n", ft_list_size(l1));
 	curr = l1;
	while(curr)
	{
		printf("%d\n", *(int *)curr->data);
		curr = curr->next;
	}
} */