#include "push_swap.h"
#include <stdio.h>

void	sort(t_array *array)
{
	if (array->size_a <= 3)
		final_sort(array);
	if (array->size_a == array->size_top)
		sort_init(array);
	else 
		push_easiest(array);
}

void	final_sort(t_array *array)
{
	int i;

	i = 0;
	while (i < array->size_top)
	{
		printf("%d ", array->numbers[array->size_top - i - 1]);
		i++;
	}
		
	exit(0);
}

void	push_easiest(t_array *array)
{
	t_operation op;

	op = get_easiest(array);
	apply_operation(op, array);
	if (op.ra_count >= 0 && op.rb_count >= 0)
	{
		if (op.ra_count > op.rb_count)
		{
			while (op.rb_count > 0)
			{
				write(1, "rr\n", 3);
				op.rb_count--;
				op.ra_count--;
			}
			while (op.ra_count > 0)
			{
				write(1, "ra\n", 3);
				op.ra_count--;
			}
		}
	}
	else if (op.ra_count < 0 && op.rb_count < 0)
	{
		if (op.ra_count > op.rb_count)
		{
			while (op.ra_count < 0)
			{
				write(1, "rrr\n", 4);
				op.ra_count++;
				op.rb_count++;
			}
			while (op.rb_count < 0)
			{
				write(1, "rrb\n", 4);
				op.rb_count++;
			}
		}
	}
	else if (op.ra_count >= 0 && op.rb_count < 0)
	{
		while (op.rb_count < 0)
		{
			write(1, "rrb\n", 4);
			op.rb_count++;
		}
		while (op.ra_count > 0)
		{
			write(1, "ra\"n", 3);
			op.ra_count--;
		}
	}
	else if (op.ra_count < 0 && op.rb_count >= 0)
	{
		while (op.ra_count < 0)
		{
			write(1, "rra\n", 4);
			op.ra_count++;
		}
		while (op.rb_count > 0)
		{
			write(1, "rb\n", 3);
			op.rb_count--;
		}
	}
	else
	{
		while (op.ra_count > 0)
		{
			write(1, "ra\n", 3);
			op.ra_count--;
		}
		while (op.rb_count > 0)
		{
			write(1, "rb\n", 3);
			op.rb_count--;
		}
	}
}

t_operation	get_easiest(t_array *array)
{
	t_operation op;

	op.a_index = 0;
	op.b_index = array->size_a;
	op.cost = -1;
	while (op.a_index < array->size_a)
	{
		if (array->numbers[op.a_index] > array->big_b || array->numbers[op.a_index] < array->low_b)
		{
			calc_cost(&op, op.a_index, array->big_b_index, array);
		}
		else
		{
			while (op.b_index < array->size_top)
			{
				if (array->numbers[op.a_index] > array->numbers[op.b_index]
					&& array->numbers[op.a_index] < array->numbers[op.b_index + 1])
					calc_cost(&op, op.a_index, op.b_index + 1, array);
				op.b_index++;
			}
			op.b_index--;
		}
		op.a_index++;
	}
	op.a_index--;
	return (op);
}

void	sort_init(t_array *array)
{
	array->size_a -= 2;
	array->size_b = 2;
	write (1, "pb\n", 3);
	write (1, "pb\n", 3);
	if (array->numbers[array->size_top - 1] > array->numbers[array->size_top - 2])
	{
		array->big_b = array->numbers[array->size_top - 1];
		array->big_b_index = array->size_top - 1;
		array->low_b = array->numbers[array->size_top - 2];
	}
	else
	{
		array->big_b = array->numbers[array->size_top - 2];
		array->big_b_index = array->size_top - 2;
		array->low_b = array->numbers[array->size_top - 1];
	}
}

void	calc_cost(t_operation *op, int a_index, int b_index, t_array *array)
{
	int ra_count;
	int rb_count;
	int cost;

	ra_count = array->size_a - a_index - 1;
	rb_count = b_index - array->size_a;
	if (ra_count < rb_count)
		cost = rb_count;
	else
		cost = ra_count;
	if (cost < op->cost || op->cost == -1)
	{
		op->cost = cost;
		op->ra_count = ra_count;
		op->rb_count = rb_count;
	}
	ra_count = a_index + 1;
	rb_count = array->size_top - b_index;
	if (ra_count < rb_count)
		cost = rb_count;
	else
		cost = ra_count;
	if (cost < op->cost)
	{
		op->cost = cost;
		op->ra_count = -ra_count;
		op->rb_count = -rb_count;
	}
	ra_count = array->size_a - a_index - 1;
	rb_count = array->size_top - b_index;
	cost = ra_count + rb_count;
	if (cost < op->cost)
	{
		op->cost = cost;
		op->ra_count = ra_count;
		op->rb_count = -rb_count;
	}
	ra_count = a_index + 1;
	rb_count = b_index - array->size_a;
	cost = ra_count + rb_count;
	if (cost < op->cost)
	{
		op->cost = cost;
		op->ra_count = -ra_count;
		op->rb_count = rb_count;
	}
}

void	apply_operation(t_operation op, t_array *array)
{
	int *tmp;

	tmp = malloc(sizeof(int) * op.a_index);
	ft_memcpy(tmp, array->numbers + op.a_index + 1, sizeof(int) * (array->size_a - op.a_index - 1));
	ft_memcpy(array->numbers, array->numbers + array->size_a - op.a_index -1, sizeof(int) * (op.a_index -1));
	ft_memcpy(array->numbers, tmp, sizeof(int) * (array->size_a - op.a_index - 1));
	free(tmp);
	tmp = malloc(sizeof(int) * op.b_index - array->size_a);
	ft_memcpy(tmp, array->numbers + op.b_index, sizeof(int) * (array->size_top - op.b_index));
	ft_memcpy(array->numbers + op.b_index, array->numbers + array->size_a, sizeof(int) * (op.b_index - array->size_a));
	ft_memcpy(array->numbers + array->size_a, tmp, sizeof(int) * (op.b_index - array->size_a));
	free(tmp);
	array->size_a --;
	array->size_b ++;
	write (1, "pb\n", 3);
	if (array->numbers[array->size_a] > array->big_b)
	{
		array->big_b = array->numbers[array->size_a];
		array->big_b_index = array->size_a;
	}
	else if (array->numbers[array->size_a] < array->low_b)
	{
		array->low_b = array->numbers[array->size_a];
		array->low_b_index = array->size_a;
	}
	else
		array->big_b_index += op.rb_count;
}