
#include "huffman.h"


t_node  *link_tree(t_node *one, t_node *two)
{
    t_node *branch;

    branch = ft_lstnew(127, one->occur + two->occur);
    branch->next = two->next;
    two->next = NULL;
    one->next = NULL;
    branch->left = one;
    branch->right = two;
    return (branch);
}

// SORT THE TREE TO HAVE THE TWO SMALLEST
// AND PUT THEM ON THE LEFT

void    sort(t_node **firstnode, t_node *one, t_node *two)
{
    t_node *node = *firstnode;
    
    while (node)
    {
        if (node->next == one)
            node->next = one->next;
        if (node->next == two)
            node->next = two->next;
        node = node->next;
    }
    two->next = *firstnode;
    one->next = two;
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
        node = node->next;
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
        node = node->next;
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
    node = parsing(str);
    while (node->next)
    {
        sort(&node, smallone(node), smalltwo(node));
        node = link_tree(node, node->next);
    }
    return (node);
};
