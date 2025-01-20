
#include "get_next_line.h"
static int	buffer_len(char *static_str)
{
	int	i;

	if (!static_str)
		return (-1);
	i = 0;
	while (static_str[i] != '\0' && static_str[i] != '\n')
		i++;
	if (static_str[i] == '\0')
		return (-1);
	return (i);
}
static char *read_buffer(int fd,char *static_str)
{
	char *tmp;
	int bytes_read;
	tmp=malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (buffer_len(static_str) == -1)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read == 0)
		{
			break;
		}
		if (bytes_read < 0)
		{
			free(tmp);
			free(static_str);
			static_str = NULL;
			return (NULL);
		}
		tmp[bytes_read] = '\0';
		static_str = ft_strjoin(static_str, tmp);
	}
	free(tmp);
	return (static_str);

}

static char	*extract_line(char *static_str)
{
	char	*new_str;
	int		pos;

	if (!static_str)
		return (NULL);
	pos = buffer_len(static_str);
	if (pos == -1)
		return (ft_strdup(static_str));
	new_str = (char *)malloc((pos + 2) * sizeof(char));
	if (!new_str)
		return (NULL);
	int i = 0;
	while (static_str[i] != '\n')
	{
		new_str[i] = static_str[i];
		i++;
	}
	new_str[i] = '\n';
	new_str[i + 1] = '\0';
	return (new_str);
}

static char	*update_buffer(char *static_str)
{
	int	static_str_len;
	int	pos;
	char *buffer;
	if (!static_str)
		return (NULL);
	static_str_len = (int)ft_strlen(static_str);
	pos = buffer_len(static_str);
	if (pos == -1 || ((static_str_len - pos) == 1))
		return (free(static_str), NULL);
	buffer= ft_strdup(static_str + pos + 1);
	free((char *)static_str);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*static_str[4096];
	char		*newline;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_str[fd] = read_buffer(fd, static_str[fd]);
	newline = extract_line(static_str[fd]);
	static_str [fd]= update_buffer(static_str[fd]);
	return (newline);
}
/*
int main()
{
    int fd;
    char *line;
    int i;
    i =0;
    fd = open("test.txt", O_RDWR | O_CREAT);
    //printf("the FD is : %d\n",fd);
    while(line)
    {
        line = get_next_line(fd);
        printf("%s",line);
    }
    return (0);
}
*/
