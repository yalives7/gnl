// bu kod 17 ocakta yazilmisitr su an leaksiz sekilde benim tum dosyadaki ifadeleri okumamı sagliyor

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char *ft_fline(int fd, char *str)
{
    int bytes_read;
    char *tmp;
    tmp = malloc(BUFFER_SIZE + 1);
    if(!tmp)
    {
        free(str);
        return NULL;
    }
    while((bytes_read = read(fd,tmp,BUFFER_SIZE)) > 0)
    {
        tmp[bytes_read]= '\0';
        str = ft_strjoin(str,tmp);
    }
    free(tmp);
    return str;
    
}
char *ft_get_next_line(int fd)
{
    static char* fline;
    char *line;
    if(fd < 0 || BUFFER_SIZE <= 0)
    {
        free(fline);
        return NULL;
    }
    fline = ft_fline(fd,fline);
    if(!fline)
        return NULL;
    return fline;

}


int main()
{
    char *ptr;
    int fd = open("ehe.txt",O_RDONLY);
    ptr = ft_get_next_line(fd);
    printf("%s",ptr);
    free(ptr);

}
