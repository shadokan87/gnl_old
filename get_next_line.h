#ifndef GET_NEXT_LINE_H
 #define GET_NEXT_LINE_H

 #define BUFF_SIZE 40
 #define ENDL '\n'

 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/uio.h>
 #include <stdlib.h>
 #include <fcntl.h>
#include "Memd/mem.h"

int	get_next_line(int fd, char **line);
int	cpy_before_c(char **dst, char *src, char c);
int	str_join(char **dst, char *sr);
int	c_is_present(char *str, char c);
int	check_ret(char **stack, char **line);

#endif
