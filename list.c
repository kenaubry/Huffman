#include "huffman.h"

// CREATE A NEW NODE IN THE LIST

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

// GOES TO THE LAST NODE

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->right)
		lst = lst->right;
	return (lst);
}

// ADD A NEW NODE TO THE END OF THE LIST

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