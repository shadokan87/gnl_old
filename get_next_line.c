
#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char buff[BUFF_SIZE + 1];
	static char *stack[4094];
	static int file;
	
	if (fd < 1 || line == NULL)
		return (-1);
	while (!(c_is_present(stack[fd], ENDL)))
	{
	file = read(fd, buff, BUFF_SIZE);
	buff[file] = '\0';
	str_join(&stack[fd], buff);
	if (file == 0)
		break ;
	}
	return (check_ret(&stack[fd], line));
}

/*
int	main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	char *line;
	int ret;


	get_next_line(fd, &line);
	printf("%s", line);
}*/
