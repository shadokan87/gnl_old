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
			return (i);
		i++;
	}
	return (c == '\0' ? i : 0);
}

char	*ft_strndup(char *str, int len)
{
	char *ret;
	int i;

	i = 0;
	if (!(ret = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len && str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
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
	{
		*dst = ft_strndup(src, c_is_present(src, '\0'));
		return (1);
	}
	if (!(tmp = malloc(sizeof(char) * c_is_present(*dst, '\0') + c_is_present(src, '\0') + 1)))
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
	return (1);
}

int	check_ret(char **stack, char **line)
{
	int ret;
	char *tmp;

	if ((ret = c_is_present(*stack, ENDL)))
	{
		*line = ft_strndup(*stack, ret);
		tmp = *stack + ret + 1;
		*stack = tmp;
		return (1);
	}
	else if ((ret = c_is_present(*stack, '\0')))
	{
		*line = ft_strndup(*stack, ret);
		*stack = NULL;
		return (1);
	}
	return (0);
}
