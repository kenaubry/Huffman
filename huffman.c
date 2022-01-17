
#include "huffman.h"

// SORT THE TREE TO HAVE THE TWO SMALLEST
// AND PUT THEM ON THE LEFT

t_node  *link_tree(t_node *node)
{
    return (node);
}

void    sort(t_node **firstnode, t_node *one, t_node *two)
{
    t_node *node = *firstnode;
    
    while (node)
    {
        if (node->right == one)
            node->right = one->right;
        if (node->right == two)
            node->right = two->right;
        node = node->right;
    }
    two->right = *firstnode;
    one->right = two;
    *firstnode = one;
}

// GET THE CHARACTER WITH THE SMALLEST OCCURENCE

t_node  *smallone(t_node *node)
{
    t_node  *smallone;

    smallone = node;
    while (node)
    {
        if (node->occur < smallone->occur)
            smallone = node;
        node = node->right;
    }
    return (smallone);
}

// GET THE SECOND CHARACTER WITH THE SMALLEST OCCURENCE 

t_node  *smalltwo(t_node *node)
{
    t_node  *smallest;
    t_node  *smalltwo;
    
    smallest = smallone(node);
    smalltwo = node;
    while (node)
    {
        if (smallest->occur == node->occur && node != smallest)
        {
            smalltwo = node;
            return (smalltwo);
        }
        if (smalltwo->occur > smallest->occur 
            && smalltwo->occur > node->occur)
            smalltwo = node;
        node = node->right;
    }
    return (smalltwo);
}

// PARSE THE STRING AND GET THE NUMBER OF OCCURENCE
// OF A CHARACTER WITH NBCHAR TO PUT IT INTO OUR
// STRUCTURE, WE RETURN THE NODES CREATED

t_node  *parsing(char *str)
{
    t_node *list;
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
    list = ft_lstnew(str[0], occur);
    while (str[i])
    {
        if (str[i] != letters[(int)str[i]])
        {
            occur = occurence(str[i], str);
            node = ft_lstnew(str[i], occur);
            ft_lstadd_back(&list, node);
            letters[(int)str[i]] = str[i];
        }
        i++;
    }
    sort(&list, smallone(list), smalltwo(list));
    return (list);
}

// PRINCIPAL FUNCTION

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
