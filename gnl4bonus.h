//bu bonusun h halidir 
#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 3000
#endif
#include <stdlib.h>
size_t ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_strchr( char *s, int c);
char	*ft_get_next_line(int fd);
#endif
