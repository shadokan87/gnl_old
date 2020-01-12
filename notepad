
#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char buff[BUFF_SIZE + 1];
	static char *stack[4094];
	int ret;
	int file;
	
	if (fd < 1 || line == NULL)
		return (-1);
	while ((file = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[file] = '\0';
		str_join(&stack[fd], buff);
		if ((ret = cpy_before_c(line, stack[fd], ENDL)))
		{	
			while (*stack[fd]++ != ENDL);
			return (1);
		}
	}
	if (!(!stack[fd]))
	{
		cpy_before_c(line, stack[fd], '\0');
		stack[fd] = NULL;
		return (1);
	}
	return (0);
}
