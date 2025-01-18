//dosyanın adi get_next_line_bonus.c olcak
#include "get_next_line.h"
#include <unistd.h>
static char * ft_next_line(char *fline)
{
    int i= 0;
    int control = 1;
    size_t ptrlen = ft_strlen(fline);
    char *tmp;
    int j = 0;

    while(fline[i] != '\0')
    {
        if(fline[i] == '\n')
        {
            control = 0;
            int tmplen = ptrlen - i;
            tmp = malloc(tmplen);
            if(!tmp)
            {
                free(fline);
                return NULL;
            }
            while( j < tmplen)
            {
                i++;
                tmp[j] = fline[i];
                j++;
            }
            tmp[j] = '\0';
            break;
        }
        i++;
    }
    if(!ft_strchr(fline,'\n'))
    {
        free(fline);
        return NULL;
    }
    free(fline);
    return tmp;

}

static char *ft_line(char *fline)
{
    char *tmp;
    int control = 1;
   size_t tmplen;
   int i= 0;
   int j = 0;
   while(fline[i] != '\0')
   {
    if(fline[i] == '\n')
    {
            control = 0;
            tmplen=i+1;
            break;
    }
        i++;
   }
   if(control = 1)
    tmplen = i;
    tmp = malloc(tmplen);
    if(!tmp)
        {
            free(fline);
            return NULL;
        }
    while(j < tmplen + 1)
    {
        tmp[j] = fline[j];
        j++;
    }
    tmp[j]='\0';
    return tmp;
}
static char *ft_fulline(int fd, char *fline)
{
    int bytes_read;
    char *tmp;
    tmp = malloc(BUFFER_SIZE + 1);
    if(!tmp)
    {
        free(fline);
        return NULL;
    }
    while((bytes_read = read(fd,tmp,BUFFER_SIZE)) > 0)
    {
        tmp[bytes_read]= '\0';
        fline = ft_strjoin(fline,tmp);
    }
    free(tmp);
    return fline;
    
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
    fline = ft_fulline(fd,fline);
    if(!fline)
        return NULL; 
    line = ft_line(fline);
    fline = ft_next_line(fline);
    return line;

}
