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


/*
 * Funcion para calcular el maximo entre dos numeros
 *  
 * */
 
int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  


/*
 *
 * */

int avl_create(
  list<float>    *in_number_list,
  avl_node       *new_root_node
  )
{
  
  struct avl_node* new_root = new_root_node; //sirve para inicializar
  for (auto &&value : *in_number_list)
  {
    avl_node* new_node =  new avl_node{NULL, NULL, NULL, value, 1};
    avl_node_add(new_root_node, new_node, new_root);
    // avl_balance(new_root_node, new_node, new_root);
    new_root_node = new_root;
  }
  
  return AVL_SUCCESS;
}


/*
 *
 * */

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


/*
 * Funcion que obtiene la altura de un nodo
 * */

int avl_get_height(
  struct avl_node  *&in_root
){
  if (in_root == NULL){
    return AVL_SUCCESS;
  }
  else
  {
    return in_root->height;
  }
}


/*
 *
 * */

int avl_get_balance(
  struct avl_node  *&in_root
){
  if (in_root == NULL){
    return AVL_SUCCESS;
  }
  else
  {
    return avl_get_height(in_root->lc_node) - avl_get_height(in_root->rc_node);
  }
}


/*
 *
 * */

int avl_rotate_left(
  struct avl_node  *&in_root,
  struct avl_node  *&new_root
){
	// Verificacion de parametro valido
	if (in_root == NULL){
		return AVL_INVALID_PARAM;
	}
	
	if (in_root == new_root){
		return AVL_INVALID_PARAM;
	}
	
  new_root = in_root->rc_node;
	struct avl_node* temp = new_root->lc_node;
	
	//Rotacion
	new_root->lc_node = in_root;
	in_root->rc_node = temp;
	
	//Alturas
	in_root->height = max(avl_get_height(in_root->rc_node), avl_get_height(in_root->lc_node)) + 1;
	new_root->height = max(avl_get_height(new_root->rc_node), avl_get_height(new_root->lc_node)) + 1;
	
	return AVL_SUCCESS;
}


/*
 *
 * */

int avl_rotate_right(
  struct avl_node  *&in_root,
  struct avl_node  *&new_root
){
	// Verificacion de parametro valido
	if (in_root == NULL){
		return AVL_INVALID_PARAM;
	}
	
	if (in_root == new_root){
		return AVL_INVALID_PARAM;
	}
	
	new_root = in_root->lc_node;
  struct avl_node* temp = new_root->rc_node;
	
  // Rotación
	new_root->rc_node = in_root;
	in_root->lc_node = temp;
	
	//Alturas
	in_root->height = max(avl_get_height(in_root->rc_node), avl_get_height(in_root->lc_node)) + 1;
	new_root->height = max(avl_get_height(new_root->rc_node), avl_get_height(new_root->lc_node)) + 1;
	
	return AVL_SUCCESS;
}


/*
 *Funcion balance
 * */

int avl_balance(
  struct avl_node  *&in_root,
  struct avl_node  *&new_node,
  struct avl_node  *&new_root
){
  // Caso no valido
  if(in_root == NULL){
    return AVL_NOT_FOUND;
  }
  
  // Actualiza altura.
  in_root->height = 1 + max(avl_get_height(in_root->lc_node),
                            avl_get_height(in_root->rc_node));

  //Se obtiene el balance
  int balance = avl_get_balance(in_root);

  if (balance > 1 && new_node->value < in_root->lc_node->value)
  {
    avl_rotate_right(in_root, new_root);
    in_root = new_root;
  }

  if (balance < -1 && new_node->value > in_root->rc_node->value)
  {
    avl_rotate_left(in_root, new_root);
    in_root = new_root;
  }

  if (balance > 1 && new_node->value > in_root->lc_node->value)
  {
    avl_rotate_left(in_root->lc_node, new_root);
    in_root->lc_node = new_root;
    avl_rotate_right(in_root, new_root);
    in_root = new_root;
  }

  if (balance < -1 && new_node->value < in_root->rc_node->value)
  {
    avl_rotate_right(in_root->rc_node, new_root);
    in_root->rc_node = new_root;
    avl_rotate_left(in_root, new_root);
    in_root = new_root;
  }
  
  return AVL_SUCCESS;

}


/*
 *
 * */

int avl_node_add(
  struct avl_node  *in_root,
  struct avl_node  *new_node,
  struct avl_node  *new_root
  ){
  if (new_node == NULL)
  {
    return AVL_INVALID_PARAM;
  }
  else if (new_node->value < in_root->value)
  {
    if (in_root->lc_node != NULL)
    {
      avl_node_add(in_root->lc_node, new_node, new_root);
      //avl_balance(in_root->lc_node, new_node, new_root);
    }
    else
    {
      in_root->lc_node          = new_node;
      in_root->lc_node->pc_node = in_root;
      //avl_balance(in_root, new_node, new_root);
    }
  }
  else if (new_node->value > in_root->value)
  {
    if (in_root->rc_node != NULL)
    {
      avl_node_add(in_root->rc_node, new_node, new_root);
      //avl_balance(in_root->rc_node, new_node, new_root);
    }
    else
    {
      in_root->rc_node          = new_node;
      in_root->rc_node->pc_node = in_root;
      //avl_balance(in_root, new_node, new_root);
    }
  }
  else
  {
    return AVL_INVALID_PARAM; // No agregar nodos con valores iguales.
  }
  return AVL_SUCCESS;
}


/*
 *
 * */

int avl_node_remove(
  struct avl_node *&in_root,
  struct avl_node *&node_to_remove,
  struct avl_node *&new_root)
{
  struct avl_node * temp;
  struct avl_node * parent = node_to_remove->pc_node;
  if(node_to_remove->lc_node == NULL && node_to_remove->rc_node == NULL){
    if(parent->lc_node == node_to_remove){
      parent->lc_node = NULL;
    }
    else
    {
      parent->rc_node = NULL;
    }
    delete node_to_remove;
  }
  else if(node_to_remove->lc_node == NULL)
  {
    temp = node_to_remove->rc_node;
    node_to_remove->value = temp->value;
    avl_node_remove(temp,temp,new_root);
  }
  else if(node_to_remove->rc_node == NULL)
  {
    temp = node_to_remove->lc_node;
    node_to_remove->value = temp->value;
    avl_node_remove(temp,temp,new_root);
  }
  else{
    avl_min_get(node_to_remove, &temp);
    node_to_remove->value = temp->value; 
    avl_node_remove(temp,temp,new_root);
  }

  return AVL_SUCCESS;
}


/*
 *
 * */

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
    if (in_root->lc_node == NULL)
    {
      return AVL_NOT_FOUND;
    } 
    else 
    {
      return avl_search(in_root->lc_node, num, found_node);
    }
  }
  else if (in_root->value < num)
  {
    if (in_root->rc_node == NULL)
    {
      return AVL_NOT_FOUND;
    }
    else 
    {
      return avl_search(in_root->rc_node, num, found_node);
    }
  }
  else
  {
    cout << "NULL" << " " << endl;
    *found_node = NULL;
    return AVL_NOT_FOUND;
  } 

}


/*
 *
 * */

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


/*
 *
 * */

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


/*
 *
 * */

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


/*
 *
 * */

int avl_print(
  struct avl_node  *in_root)
{
  avl_print_node("", in_root, false);
  return AVL_SUCCESS;
}
