/*
** free.c for PSU_2016_minishell2 in /home/nikola/delivery/PSU_2016_minishell2
**
** Made by nikola.tomic@epitech.eu
** Login   <nikola@epitech.net>
**
** Started on  Tue Apr 04 14:10:06 2017 nikola.tomic@epitech.eu
** Last update Sun May 21 10:07:58 2017 
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "routine.h"

void	free_tab(char **tab)
{
  int	i;

  if (tab != NULL)
    {
      i = 0;
      while (tab[i] != NULL)
	free(tab[i++]);
      free(tab);
    }
}

void		free_alias(t_list_al *alias)
{
  t_alias	*tmp;
  t_alias	*elem;

  free_tab(alias->file);
  elem = alias->first;
  while (elem)
    {
      tmp = elem;
      elem = elem->next;
      if (tmp->cmd != NULL)
	free(tmp->cmd);
      if (tmp->alias != NULL)
	free(tmp->alias);
      free(tmp);
    }
  alias->first = NULL;
  alias->last = NULL;
}

void		free_list(t_list *list)
{
  t_list	*tmp;

  while (list)
    {
      tmp = list;
      list = list->next;
      if (tmp->var)
	free(tmp->var);
      free(tmp);
    }
}

void	free_tree(t_btree *tree)
{
  if (tree != NULL)
    {
      if (tree->left)
	free_tree(tree->left);
      if (tree->right)
	free_tree(tree->right);
      if (tree->cmd && *tree->cmd)
	free(tree->cmd);
      if (tree->pp)
	{
	  if (tree->parent && tree->parent->pp &&
	      tree->parent->pp == tree->pp)
	    tree->parent->pp = NULL;
	  free(tree->pp);
	  tree->pp = NULL;
	}
      free(tree);
    }
}

void		free_tcomp(t_comp *str)
{
  free(str->start);
  free(str->end);
  free(str->new);
}
