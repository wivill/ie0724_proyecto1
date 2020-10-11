

#include <list>
#include <string>
using namespace std;

/**
 * @file avltree.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-08-31
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/**
 * Códigos de error
 */
enum avl_error_codes {
  AVL_SUCCESS       = 0,
  AVL_INVALID_PARAM = -1,
  AVL_OUT_OF_RANGE  = -2,
  AVL_TIMEOUT       = -3,
  AVL_NOT_FOUND     = -4,
  // Pueden añadir más
};

/**
 * Struct que define un nodo de la estructura de datos
 */
struct avl_node {
  /** Puntero al nodo padre */
  struct avl_node *pc_node;  

  /** Puntero al nodo hijo izquierdo */
  struct avl_node *lc_node;

  /** Puntero al nodo hijo derecho */
  struct avl_node *rc_node;

  /** Número flotante asociado al nodo */
  float value;

  /** Altura **/
  int height;
};


/**
 * max
 * Retorna el valor mayor de entre los argumentos recibidos.
 *
 * @param [in]  a  primer argumento a comparar
 * @param [in]  b  segundo argumnento a comparar
 *
 * @returns     a  un entero mayor que b
 * @returns     b  un entero mayor que a
 *
 */
int max(
  int a,
  int b);

/**
 * avl_create
 * Toma una lista de números flotantes, y crea la estructura de datos deseada.
 * Retorna el nodo raíz del árbol.
 *
 * @param [in]  in_number_list es la lista de números flotantes de entrada
 * @param [out] new_root_node  es el puntero al nodo raíz del árbol creado
 *
 * @returns error_code         un código de error indicando el éxito o error
 *                             de la función
 */
int avl_create(
  list<float>     *in_number_list,
  struct avl_node *new_root_node
);


/**
 * free_avl_tree
 * Tome un árbol y limpia la memoria asignada de forma recursiva.
 *
 * @param [in]  in_root es el puntero a la raíz del árbol.
 *
 * @returns error_code         un código de error indicando el éxito o error
 *                             de la función
 */
int free_avl_tree(
  struct avl_node  *&in_root
);

/**
 * avl_get_height
 * Tome un nodo y retorna la altura. Si es NULL retorna 0
 *
 * @param [in]  in_root es el puntero a la raíz del árbol.
 *
 * @returns error_code         un código de error indicando el éxito o error
 *                             de la función
 * @returns in_root->height    altura del nodo.
 */
int avl_get_height(
  struct avl_node  *&in_root
);

/**
 * avl_get_balance
 * Retorna la altura del nodo actual respecto a la altura de sus hijos.
 *
 * @param [in]  in_root es el puntero a la raíz del árbol.
 *
 * @returns error_code         un código de error indicando el éxito o error
 *                             de la función
 * @returns height             Resta de las alturas de los nodos hijo derecho e izquierdo.
 */
int avl_get_balance(
  struct avl_node  *&in_root
);

/**
 * avl_rotate_left
 * Realiza una rotación hacia la izquierda en el AVL tree.
 *
 * @param [in]  in_root   es el nodo raíz original del árbol
 * @param [out] new_root  es el puntero al nuevo nodo raíz del árbol
 *
 * @returns error_code    un código de error indicando el éxito o error
 *                        de la función
 */
int avl_rotate_left(
  struct avl_node  *&in_root,
  struct avl_node  *&new_root
);

/**
 * avl_rotate_right
 * Realiza una rotación hacia la derecha en el AVL tree.
 *
 * @param [in]  in_root   es el nodo raíz original del árbol
 * @param [out] new_root  es el puntero al nuevo nodo raíz del árbol
 *
 * @returns error_code    un código de error indicando el éxito o error
 *                        de la función
 */
int avl_rotate_right(
  struct avl_node  *&in_root,
  struct avl_node  *&new_root
);

/**
 * avl_balance
 * Realiza comparaciones y actualizaciones de altura para balancear
 * el árbol.
 *
 * @param [in]  in_root   es el nodo raíz original del árbol
 * @param [in]  new_node  es el nodo con el número flotante por insertar
 * @param [out] new_root  es el puntero al nuevo nodo raíz del árbol
 *
 * @returns error_code    un código de error indicando el éxito o error
 *                        de la función
 */
int avl_balance(
  struct avl_node  *&in_root,
  struct avl_node  *&new_node,
  struct avl_node  *&new_root
);

/**
 * avl_node_add
 * Toma un nodo y lo inserta en la estructura de datos.
 * Una nueva raíz puede ser obtenida.
 *
 * @param [in]  in_root   es el nodo raíz original del árbol
 * @param [in]  new_node  es el nodo con el número flotante por insertar
 * @param [out] new_root  es el puntero al nuevo nodo raíz del árbol
 *
 * @returns error_code    un código de error indicando el éxito o error
 *                        de la función
 */
int avl_node_add(
  struct avl_node  *in_root,
  struct avl_node  *new_node,
  struct avl_node  *new_root
);

/**
 * avl_node_remove
 * Toma un nodo arbitrario, lo busca y lo elimina de la estructura de datos.
 * Da error si el nodo no pertenece al árbol.
 *
 * @param [in]  in_root        es el nodo raíz original del árbol
 * @param [in]  node_to_remove es el nodo por eliminar
 * @param [out] new_root       es el puntero al nuevo nodo raíz del árbol
 *
 * @returns error_code         un código de error indicando el éxito o error
 *                             de la función
 */
int avl_node_remove(
  struct avl_node *&in_root,
  struct avl_node *&node_to_remove,
  struct avl_node *&new_root);


/**
 * avl_search
 * Toma un número flotante, lo busca y se devuelve el nodo al que pertenece.
 * Si existieran varios nodos con el mismo valor, se devuelve cualquiera.
 * Da error si el valor no existe en ningún nodo.
 *
 * @param [in]  in_root        es el nodo raíz original del árbol
 * @param [in]  num            es el número flotante por buscar
 * @param [out] found_node     es el nodo encontrado que contiene el valor
 *
 * @returns error_code         un código de error indicando el éxito o error
 *                             de la función
 */
int avl_search(
  struct avl_node *in_root,
  float            num,
  struct avl_node **found_node);


/**
 * avl_max_get
 * Se obtiene el nodo que contenga el valor máximo en todo el árbol.
 *
 * @param [in]  in_root   es el nodo raíz original del árbol
 * @param [out] max_node  es el nodo encontrado que contiene el valor máximo
 *
 * @returns error_code    un código de error indicando el éxito o error
 *                        de la función
 */
int avl_max_get(
  struct avl_node *in_root,
  struct avl_node **max_node);


/**
 * avl_min_get
 * Se obtiene el nodo que contenga el valor mínimo en todo el árbol.
 *
 * @param [in]  in_root   es el nodo raíz original del árbol
 * @param [out] min_node  es el nodo encontrado que contiene el valor mínimo
 *
 * @returns error_code    un código de error indicando el éxito o error
 *                        de la función
 */
int avl_min_get(
  struct avl_node *in_root,
  struct avl_node **min_node);

/**
 * avl_print_node
 * Se obtiene el nodo que contenga el valor mínimo en todo el árbol.
 *
 * @param [in]  prefix  es el prefijo para poder acomodar e imprimir el árbol.
 * @param [in]  in_root es el nodo raíz original del árbol
 * @param [in]  isLeft  booleano para decidir si se está imprimiendo un nodo a la derecha o a la izquierda
 *
 * @returns error_code    un código de error indicando el éxito o error
 *                        de la función
 */
int avl_print_node(
  const string&     prefix,
  struct avl_node  *in_root,
  bool              isLeft);

/**
 * avl_print
 * Se imprime el árbol en terminal.
 *
 * @param [in]  in_root   es el nodo raíz original del árbol
 *
 * @returns error_code    un código de error indicando el éxito o error
 *                        de la función
 */
int avl_print(
  struct avl_node  *in_root);

