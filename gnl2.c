//oldukca iyi bir yerde seg yiyior ama o sorunda cozulursa full bitmis olacak gibi

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
char * ft_next_line(char *ptr)
{
    int i= 0;
    size_t ptrlen = ft_strlen(ptr);
    char *tmp;
    int j = 0;

    while(ptr[i] != '\0')
    {
        if(ptr[i] == '\n')
        {
            int tmplen = ptrlen - i;
            tmp = malloc(tmplen);
            if(!tmp)
            {
                free(ptr);
                return NULL;
            }
            while( j < tmplen)
            {
                i++;
                tmp[j] = ptr[i];
                j++;
            }
            tmp[j] = '\0';
            break;
        }
        i++;
    }
    if(ptr[0] == '\0')
    {
        free(ptr);
        return NULL;
    }
    free(ptr);
    return tmp;

}

char *ft_line(char *str)
{
    char *tmp;
    int control = 1;
   size_t tmplen;
   int i= 0;
   int j = 0;
   while(str[i] != '\0')
   {
    if(str[i] == '\n')
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
            free(str);
            return NULL;
        }
    while(j < tmplen)
    {
        tmp[j] = str[j];
        j++;
    }
    tmp[j]='\0';
    printf("\n\ntmpnin degeri %s\n\n",tmp);
    return tmp;
}
char *ft_fulline(int fd, char *str)
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
    fline = ft_fulline(fd,fline);
    if(!fline)
        return NULL;
     printf("\nfline fulllinedan sonraki degeri  %s\n",fline);   
    line = ft_line(fline);
    fline = ft_next_line(fline);
    printf("\nfline next linedan sonraki %s\n",fline);
    return line;

}


int main()
{
    char *ptr;
    int fd = open("ehe.txt",O_RDONLY);
    ptr = ft_get_next_line(fd);
    printf("%s",ptr);
    free(ptr);
    char *ptr1= ft_get_next_line(fd);
    printf("%s",ptr1);
    free(ptr1);
     char *ptr2= ft_get_next_line(fd);
    printf("%s",ptr2);
    free(ptr2);

}
