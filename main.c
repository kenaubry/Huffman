#include "huffman.h"

int main(void)
{
    t_node *lst;
    int i = 0;

    lst = huffman("bonjour tout le mondeb");
    while(lst->right)
    {
        printf("char = %c\n", lst->c);
        printf("occurence = %d\n", lst->occur);
        lst = lst->right;
    }
    return (0);
}