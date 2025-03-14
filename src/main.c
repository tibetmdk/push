#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack *temp;
	temp = stack;
	while (temp)
	{
		ft_printf("%d\n", temp->value);
		temp = temp->next;
	}
}

int	main(int ac, char **av)
{
	t_data  *data;
	char    *joined_args;

	if (ac >= 2)
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
			return (1);
		joined_args = join_args(ac, av);
		if (!joined_args)
			return (free(data), 1);
		data->buffer = ft_split(joined_args, ' ');
		free(joined_args);
		if (!data->buffer)
			return (free(data), 1);
		if (parse_input(data) == 0)
			init_stacks(data);
		turk_sort(data);
		print_stack(data->stack_a);
		ft_printf("\n");
		print_stack(data->stack_b);
		if (!data->stack_b)
			ft_printf("stack_b is NULL");
		ft_printf("\n");
	}
}