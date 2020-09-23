#include <avltree.hpp>
#include <iostream>
#include <string>

int avl_create(
  list<float>    *in_number_list,
  avl_node       *new_root_node)
{

  for (auto &&value : *in_number_list)
  {
    avl_node* new_node =  new avl_node{NULL, NULL, value};
    avl_node_add(new_root_node, new_node, new_root_node);
  }
  
  return AVL_SUCCESS;
}

int avl_node_add(
  struct avl_node  *in_root,
  struct avl_node  *new_node,
  struct avl_node  *new_root)
{
  if (new_root == NULL)
  {
    cout << "INVALID";
    return AVL_INVALID_PARAM;
  }
  else if (new_node->value < in_root->value)
  {
    if (in_root->lc_node != NULL)
    {
      cout << "recursivo left" << endl;
      avl_node_add(in_root->lc_node, new_node, new_root);
    }
    else
    {
      cout << "left " << new_node->value << " value " << in_root->value << endl;
      in_root->lc_node = new_node;
    }
  }
  else
  {
    if (in_root->rc_node != NULL)
    {
      cout << "recursivo right" << endl;
      avl_node_add(in_root->rc_node, new_node, new_root);
    }
    else
    {
      cout << "right " << new_node->value << " value " << in_root->value << endl;
      in_root->rc_node = new_node;
    }
  }
  
  return AVL_SUCCESS;
}

int avl_node_remove(
  struct avl_node  in_root,
  struct avl_node  node_to_remove,
  struct avl_node *new_root)
{
  return AVL_SUCCESS;
}

int avl_search(
  struct avl_node  in_root,
  float                      num,
  struct avl_node *found_node)
{
  return AVL_SUCCESS;
}

int avl_max_get(
  struct avl_node  in_root,
  struct avl_node *max_node)
{
  return AVL_SUCCESS;
}

int avl_min_get(
  struct avl_node  in_root,
  struct avl_node *min_node)
{
  return AVL_SUCCESS;
}

int avl_print_node(
  const string&     prefix,
  struct avl_node  *in_root,
  bool              isLeft
  )
{
  if (in_root != NULL)
  {
    cout << prefix;
    cout << ( isLeft ? "├──" : "└──" );
    cout << in_root->value << endl;

    avl_print_node( prefix + (isLeft ? "│   " : "    "), in_root->lc_node, true );
    avl_print_node( prefix + (isLeft ? "│   " : "    "), in_root->rc_node, false );
  }
  
  return AVL_SUCCESS;
}

int avl_print(
  struct avl_node  *in_root)
{
  avl_print_node("", in_root, false);
  return AVL_SUCCESS;
}
