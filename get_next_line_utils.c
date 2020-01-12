#include "get_next_line.h"

// (dst <--- src, dstsrc)

int	c_is_present(char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	cpy_before_c(char **dst, char *src, char c)
{
	int i;
	int ret;
	char *tmp;

	i = 0;
	while (src[i] != c && src[i])
		i++;
	ret = i;
	if ((!(tmp = malloc(sizeof(char) * i + 1))) ||
	src[i] != c)
		return (0);
	tmp[i] = '\0';
	i--;
	while (i >= 0)
	{
		tmp[i] = src[i];
		i--;
	}
	*dst = tmp;
	return (ret);
}

int	len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	str_join(char **dst, char *src)
{
	int i;
	char *tmp;
	char *tmp2;

	i = 0;
	if (!*dst)
		return (cpy_before_c(dst, src, '\0'));
	if (!(tmp = malloc(sizeof(char) * len(*dst) + len(src) + 1)))
		return (0);
	tmp2 = *dst;
	while (tmp2[i])
	{
		tmp[i] = tmp2[i];
		i++;
	}
	while (*src)
	{
		tmp[i] = *src;
		src++ && i++;
	}
	tmp[i] = '\0';
	*dst = tmp;
	//(!tmp2) ? free(tmp2) : 0;
	return (1);
}

int	check_ret(char **stack, char **line)
{
	int ret;
	char *tmp;

	ret = 0;
	if (c_is_present(*stack, ENDL))
	{
		ret = cpy_before_c(line, *stack, ENDL);
		tmp = *stack + 1 + ret;
		//free(*stack);
		*stack = tmp;
		return (1);
	}
	if (len(*stack))
	{
		ret = cpy_before_c(line, *stack, '\0');
		*stack = NULL;
		return (1);
	}
	return (0);
}
