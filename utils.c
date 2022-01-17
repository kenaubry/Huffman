#include "huffman.h"

// COUNT THE NUMBER OF THE DIFFERENTS CHARACTERS
// IN THE STRING

int     nb_char(char *str)
{
    char letter[255];
    int nbchar;
    int i;

    nbchar = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] != letter[(int)str[i]])
        {
            nbchar++;
            letter[(int)str[i]] = str[i];
        }
        i++;
    }
    return (nbchar);
}

// UTILITARY FUNCTION TO COUNT THE NUMBER OF
// OCCURENCE OF ONE CHARACTER

int occurence(char c, char *str)
{
    int occur = 0;
    int i = 0;

    while (str[i])
    {
        if (str[i] == c)
            occur++;
            i++;
    }
    return (occur);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_cpy;

	s_cpy = s;
	while (n--)
		*s_cpy++ = 0;
}