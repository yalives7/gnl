//bu benim ilk utilsim su an nulla kadar olan alan leaksiz sekilde alınıyor 

#include "get_next_line.h"

size_t ft_strlen(char *str)
{
    int i= 0;
    while(str[i]!='\0')
    i++;
    return(i);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	while (s1[++i] != '\0')
		new[i] = s1[i];
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}
void *ft_strchr(const char* s, int c)
{
int i;
unsigned char tmp;
tmp = (unsigned char)c;
i=0;
while(s[i])
{
    if(s[i] == tmp)
    {
        return(((char*)&s[i])); 
    }
   i++;
}
 return NULL;
}
