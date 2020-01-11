
#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char buff[BUFF_SIZE + 1];
	static char *stack[4094];
	static int ret;
	static int file;
	
	if (fd < 1 || line == NULL)
		return (-1);
	file = !file ? read(fd, buff, BUFF_SIZE) : file;
	buff[file] = '\0';
	while (!c_is_present(stack[fd], ENDL) && file)
	{
		(file) ? str_join(&stack[fd], buff) : 0;
		file = read(fd, buff, BUFF_SIZE);
		buff[file] = '\0';
	}
	ret = cpy_before_c(line, stack[fd], file ? ENDL : '\0');
	stack[fd] = file ? stack[fd] + ret : stack[fd];
	printf("%s", stack[fd]);
	return (0);
}

int	main(int argc, char **argv)
{
	int fd;
	char *line;
	int ret;

	fd = open(argv[1], O_RDONLY);
	ret = get_next_line(fd, &line);
	//ret = get_next_line(fd, &line);
}
