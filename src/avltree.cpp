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
#include <iostream>
#include <string>
#include <math.h>

int avl_create(
  list<float>    *in_number_list,
  avl_node       *new_root_node)
{
  for (auto &&value : *in_number_list)
  {
    avl_node* new_node =  new avl_node{NULL, NULL, NULL, value};
    avl_node_add(new_root_node, new_node, new_root_node);
  }
  
  return AVL_SUCCESS;
}

int free_avl_tree(
  struct avl_node  *&in_root
){
  if(in_root == NULL){
    return AVL_SUCCESS;
  }
  free_avl_tree(in_root->lc_node);
  free_avl_tree(in_root->rc_node);
  delete(in_root);
}

int avl_node_add(
  struct avl_node  *in_root,
  struct avl_node  *new_node,
  struct avl_node  *new_root
  ){
  if (new_root == NULL)
  {
    return AVL_INVALID_PARAM;
  }
  else if (new_node->value < in_root->value)
  {
    if (in_root->lc_node != NULL)
    {
      avl_node_add(in_root->lc_node, new_node, new_root);
    }
    else
    {
      in_root->lc_node          = new_node;
      in_root->lc_node->pc_node = in_root;
    }
  }
  else
  {
    if (in_root->rc_node != NULL)
    {
      avl_node_add(in_root->rc_node, new_node, new_root);
    }
    else
    {
      in_root->rc_node          = new_node;
      in_root->rc_node->pc_node = in_root;
    }
  }
  return AVL_SUCCESS;
}

int avl_rotate_left(
  struct avl_node  *&in_root,
  struct avl_node  *&new_root
){
  struct avl_node* temp = in_root->rc_node;
  if (in_root->pc_node != NULL){
    if( in_root->pc_node->rc_node->value == in_root->value ){
      in_root->pc_node->rc_node = temp;
    } 
    else{
      in_root->pc_node->lc_node = temp;
    }  
  }
  else{
    temp->pc_node = NULL;
  }
  in_root->pc_node       = temp;
  temp->lc_node->pc_node = in_root; 
  in_root->rc_node       = temp->lc_node;
  temp->lc_node          = in_root; 
  new_root               = temp;
  return AVL_SUCCESS;
}

int avl_rotate_right(
  struct avl_node  *&in_root,
  struct avl_node  *&new_root
){
  struct avl_node* temp = in_root->lc_node; 
  if (in_root->pc_node != NULL){
    if( in_root->pc_node->rc_node->value == in_root->value ){
      in_root->pc_node->rc_node = temp;
    } 
    else{
      in_root->pc_node->lc_node = temp;
    }  
  }
  else{
    temp->pc_node = NULL;
  }
  temp->rc_node->pc_node = in_root;  
  in_root->pc_node       = temp;          // temp = x
  in_root->lc_node       = temp->rc_node; // in_root = y      
  temp->rc_node          = in_root;       // temp->rc  = b
     
  new_root               = temp;
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
  struct avl_node *in_root,
  float            num,
  struct avl_node **found_node)
{
  if (in_root->value == num)
  {
    *found_node = in_root;
    return AVL_SUCCESS;
  }
  else if (in_root->value > num)
  {
    return avl_search(in_root->lc_node, num, found_node);
  }
  else if (in_root->value < num)
  {
    return avl_search(in_root->rc_node, num, found_node);
  }
  else
  {
    *found_node = NULL;
    return AVL_NOT_FOUND;
  } 

}

int avl_max_get(
  struct avl_node *in_root,
  struct avl_node **max_node)
{
  if (in_root == NULL)
  {
    *max_node = NULL;
    return AVL_NOT_FOUND;
  }
  else if (in_root->rc_node == NULL)
  {
    *max_node = in_root;
    return AVL_SUCCESS;
  }
  else
  {
    return avl_max_get(in_root->rc_node, max_node);
  }
}

int avl_min_get(
  struct avl_node *in_root,
  struct avl_node **min_node)
{
  if (in_root == NULL)
  {
    *min_node = NULL;
    return AVL_NOT_FOUND;
  }
  else if (in_root->lc_node == NULL)
  {
    *min_node = in_root;
    return AVL_SUCCESS;
  }
  else
  {
    return avl_min_get(in_root->lc_node, min_node);
  }
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

/*
Funcion balance
*/

int avl_balance(
  struct avl_node  *&in_root,
  struct avl_node  *&new_root
){
  // Caso no valido
  int altura;
  if(in_root == NULL){
    return AVL_NOT_FOUND;
  }

  altura = in_root->height;

  // Caso en que la altura este bien
  if (altura > -1 && altura < 1){
    return AVL_SUCCESS;
  }

  // Altura positiva
  else if (altura > 1){
    if (in_root->value < in_root->lc_node->value){
      avl_rotate_right(in_root, new_root);
    }

    else{
      avl_rotate_left(in_root, new_root);
      avl_rotate_right(in_root, new_root);
    }
    return AVL_SUCCESS;
  }
  
  // Altura positiva
  else{
    if (in_root->value > in_root->rc_node->value){
      avl_rotate_left(in_root, new_root);
    }

    else{
      avl_rotate_right(in_root, new_root);
      avl_rotate_left(in_root, new_root);
    }
    return AVL_SUCCESS;
  }
}