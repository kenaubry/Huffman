#ifndef HUFFMAN_H
# define HUFFMAN_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
    char c;
    int occur;
    struct s_node *left;
    struct s_node *right; 
    struct s_node *next; 
}              t_node;

typedef struct s_table
{
    char c;
    int *code;
}              t_table;

// HUFFMAN
t_node *huffman(char *str);
t_node  *parsing(char *str);
void    sort(t_node **firstnode, t_node *one, t_node *two);
t_node  *smallone(t_node *node);
t_node  *smalltwo(t_node *node);

// UTILS
int     nb_char(char *str);
int occurence(char c, char *str);
void	ft_bzero(void *s, size_t n);

// LIST
t_node	*ft_lstnew(char c, int occur);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_back(t_node **firstnode, t_node *new);

#endif