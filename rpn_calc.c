#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
/*
int ft_num_count(char *s)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= 0 && s[i] <= 9)
			count++;
		i++;
	}
	return (count);
}
*/
int is_operand(char c)
{
	return (c == '-' || c == '/' || c == '+'
	|| c == '*' || c == '%');
}

int error_check(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (!(s[i] == ' ' || s[i] =='*' || s[i] == '/' ||
		s[i] =='%' || s[i] == '-' || s[i] == '+' ||
		(s[i] >= '0' && s[i] <= '9')))
			return (1);
		i++;
	}
	return (0);
}

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void rpn_calc(char *s)
{	
	if (error_check(s) == 1)
		printf("Error\n");
	int nb;
	int x;
	int *num_count;

	num_count = (int *)malloc(sizeof(int) * ft_strlen(s));
	nb = 0;
	x = 0;
	while (*s != '\0')
	{
		if (*s >= '0' && *s <= '9')
		{
			nb = atoi(s);
			num_count[x] = nb;
			x++;
			while (*s >= '0' && *s <= '9' && *s)
				s++;
		}

		if ((is_operand(*s) == 1) && x > 1)
		{
			if (*s == '+')
				nb = num_count[x - 2] + num_count[x - 1];
			if (*s == '-')
				nb = num_count[x - 2] - num_count[x - 1];
			if (*s == '/')
				nb = num_count[x - 2] / num_count[x - 1];
			if (*s == '*')
				nb = num_count[x - 2] * num_count[x - 1];
			if (*s == '%')
				nb = num_count[x - 2] % num_count[x - 1];
			x -= 2;
			num_count[x] = nb;
			x++;
		}
		if (!(*s >= '0' && *s <= '9') && *s)
			s++;
	}
	printf("%d\n", nb);
}

int main(int ac, char **av)
{
	if (ac == 2)
		rpn_calc(av[1]);
	else
		printf("Error\n");
	return (0);
}