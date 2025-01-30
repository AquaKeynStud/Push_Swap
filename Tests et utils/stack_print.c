#include <stdio.h>

int	c_d(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		nb *= -1;
	while (nb / 10)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void print_stack(t_stack *stack, char *name)
{
    t_node *current;

    if (!stack || !stack->top)
    {
        printf("Stack is empty.\n");
        return;
    }
    current = stack->top;
    printf("%s%13s\n", "valeur", "index");
    while (current)
    {
        printf("  %d", current->value);
		for (int i = 0; i < 3 + (11 - c_d(current->value)); i++)
			printf(" ");
		printf("%d\n", current->index);
        current = current->next;
    }
    printf("___________________\n");
    printf("%10s\n", name);
}