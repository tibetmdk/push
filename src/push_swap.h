/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:12:31 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/16 13:16:51 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> 
# include <stdlib.h>
# include <stdarg.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack
{
	int				value;
	int				index;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				push_cost;
	int				cheapest;
	int				size;
	struct s_stack	*target_node;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	char		**buffer;
	int			*tab;
	int			tab_size;
	int			ra;
	int			rra;
	int			rb;
	int			rrb;
	t_stack		*stack_a;
	t_stack		*stack_b;
}					t_data;

t_stack	*find_cheapest(t_stack *stack);
t_stack	*find_max_in_stack(t_stack *stack);
t_stack	*find_min_in_stack(t_stack *stack);

int		number_is_valid(char *str);
int		*parse_input(t_data *data);
long	ft_atol(char *str);
int		ft_printf(const char *str, ...);
int		ft_strlen(const char *s);
int		get_stack_len(t_stack *stack);
int		stack_is_sorted(t_stack *stack);
int		get_index(t_stack *stack, int value);
int		find_max_under_value(t_stack *stack, int value);
int		find_min_on_value(t_stack *stack, int value);

char	*join_args(int ac, char **av);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(char const *s, int start, int len);
size_t	ft_strlcpy(char *destination, const char *source, size_t size);

void	turk_sort(t_data *data);
void	calculate_cost_a_to_b(t_data *data);
void	calc_cost_b(t_data *data);
void	quit(t_data *data, char flag);
void	free_stack(t_stack *stack);
void	reset_costs(t_data *data);
void	init_stacks(t_data *data);
void	ft_error(void);
void	sa(t_stack *stack_a, int print);
void	sb(t_stack *stack_b, int print);
void	pb(t_data *data, int print);
void	pa(t_data *data, int print);
void	ra(t_data *data, int print);
void	rb(t_data *data, int print);
void	rra(t_data *data, int print);
void	rrb(t_data *data, int print);
void	rr(t_data *data, int print);
void	rrr(t_data *data, int print);
#endif