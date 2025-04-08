#include "push_swap.h"

t_array get_array(char **args)
{
	t_array	array;
	
	array.size_top = 0;
	array.size_a = 0;
	while (args[array.size_top])
		array.size_top++;
	array.numbers = malloc(sizeof(int) * array.size_top);
	while (array.size_a < array.size_top)
	{
		array.numbers[array.size_top - array.size_a -1] = ft_atoi(args[array.size_a]);
		array.size_a++;
	}
	return (array);
}