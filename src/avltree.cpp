/**
 * @file avltree.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-08-31
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <avltree.hpp>

int avl_create(
  list<float>    *in_number_list,
  avl_node       *new_root_node)
{

  for (auto &&value : *in_number_list)
  {
    avl_node new_node = {NULL, NULL, value};
    avl_node_add(*new_root_node, new_node, new_root_node);
  }
  
  return AVL_SUCCESS;
}

int avl_node_add(
  struct avl_node  in_root,
  struct avl_node  new_node,
  struct avl_node *new_root)
{
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

int avl_print(
  struct avl_node  in_root)
{
  return AVL_SUCCESS;
}

