#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
    char c;
    int occur;
    struct s_node *left;
    struct s_node *right; 
}              t_node;

typedef struct s_table
{
    char c;
    int *code;
}              t_table;

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

t_node	*ft_lstnew(char c, int occur)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->c = c;
    new->occur = occur;
	new->left = NULL;
    new->right = NULL;
	return (new);
}

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->right)
		lst = lst->right;
	return (lst);
}

void	ft_lstadd_back(t_node **firstnode, t_node *new)
{
	t_node	*node;

	if (firstnode && *firstnode)
	{
		node = *firstnode;
		node = ft_lstlast(*firstnode);
		node->right = new;
		return ;
	}
	*firstnode = new;
}

t_node  *sort(t_node *node)
{
    int occur = INT_MAX;
    while (node->right)
    {
        if (node->occur < occur)
            occur = node->occur;
        node = node->right;
    }
    
    return (node);
}

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

t_node  *parsing(char *str)
{
    t_node *firstnode;
    t_node *node;
    char letters[255];
    int i = 1;
    int occur = 0;

    ft_bzero(letters, 255);
    letters[255] = '\0';
    if (!str)
        return (NULL);
    occur = occurence(str[0], str);
    letters[(int)str[0]] = str[0];
    firstnode = ft_lstnew(str[0], occur);
    while (str[i])
    {
        if (str[i] != letters[(int)str[i]])
        {
            occur = occurence(str[i], str);
            node = ft_lstnew(str[i], occur);
            ft_lstadd_back(&firstnode, node);
            letters[(int)str[i]] = str[i];
        }
        i++;
    }
    firstnode = sort(firstnode);
    return (firstnode);
}

t_node *huffman(char *str)
{
    int i;
    t_table *table;
    t_node  *node;
    int nbchar;

    nbchar = nb_char(str);

    i = 0;
    node = parsing(str);    
    return (node);
};


int main(void)
{
    t_node *lst;
    int i = 0;

    lst = huffman("salut sssssc kessssnza");
    while(lst->right)
    {
        printf("char = %c\n", lst->c);
        printf("occurence = %d\n", lst->occur);
        lst = lst->right;
    }
    return (0);
}













