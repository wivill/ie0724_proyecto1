/**
 * @file main_test.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-08-31
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <gtest/gtest.h>
#include <avltree.hpp>
#include <list>

using namespace std;

/*
Test positivo para avl_create
*/

TEST(avl_create, positive){
    int status;
    list<float> listaGanadora;
    listaGanadora.push_front(17);
    listaGanadora.push_front(16);
    listaGanadora.push_front(15);
    listaGanadora.push_front(14);
    listaGanadora.push_front(13);
    listaGanadora.push_front(12);
    //listaGanadora.push_front(0.5);

    struct avl_node *nombre = new avl_node{NULL, NULL, NULL, 11, 1};
    // struct avl_node *nombre;
    // struct avl_node *node_fin = new avl_node{NULL, NULL, NULL, 11, 1};
    status = avl_create(&listaGanadora, nombre);
    avl_print(nombre);

    ASSERT_EQ(status, AVL_SUCCESS);
}


///*
//Test positivo para avl_create
//*/

//TEST(avl_print, positive){
    //int status;
    //list<float> listaGanadora;
    //listaGanadora.push_front(18.5);
    //listaGanadora.push_front(13.99);
    //listaGanadora.push_front(2.5);
    //listaGanadora.push_front(16.0);
    //listaGanadora.push_front(55.2);
    //listaGanadora.push_front(42.69);
    //listaGanadora.push_front(0.5);

    //struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};
    //struct avl_node* raiz_fin = new avl_node{NULL, NULL, NULL, 11, 1};
    //avl_create(&listaGanadora, nombre, raiz_fin);

    //status = avl_print(raiz_fin);

    //ASSERT_EQ(status, AVL_SUCCESS);
//}

///*
//Test negativo para avl_node_add. Probando condición para new_root == NULL
//*/

//TEST(avl_node_add, negative){
    //int status;
    //list<float> listaGanadora;
    //listaGanadora.push_front(18.5);
    //listaGanadora.push_front(13.99);
    //listaGanadora.push_front(2.5);
    //listaGanadora.push_front(16.0);
    //listaGanadora.push_front(55.2);
    //listaGanadora.push_front(42.69);
    //listaGanadora.push_front(0.5);

    //struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};
    //avl_create(&listaGanadora, nombre);
    //avl_print(nombre);

    //struct avl_node* nuevo_nodo = new avl_node{NULL, NULL, NULL, 14, 1};
    //status = avl_node_add(nombre, nuevo_nodo, NULL);
    //ASSERT_EQ(status, AVL_INVALID_PARAM);
//}

///*
//Test positivo para avl_node_add. Agregando nodo 14.
//*/

//TEST(avl_node_add, positive){
    //int status;
    //list<float> listaGanadora;
    //listaGanadora.push_front(18.5);
    //listaGanadora.push_front(13.99);
    //listaGanadora.push_front(2.5);
    //listaGanadora.push_front(16.0);
    //listaGanadora.push_front(55.2);
    //listaGanadora.push_front(42.69);
    //listaGanadora.push_front(0.5);

    //struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};
    //avl_create(&listaGanadora, nombre);
    //avl_print(nombre);

    //struct avl_node* nuevo_nodo = new avl_node{NULL, NULL, NULL, 14};
    //status = avl_node_add(nombre, nuevo_nodo, nombre);
    //avl_print(nombre);

    //ASSERT_EQ(status, AVL_SUCCESS);
//}

///*
//Test positivo para avl_rotate_left.
//*/

//TEST(avl_rotate_left, positive){
    //int status;
    //list<float> listaGanadora;
    //listaGanadora.push_front(18.5);
    //listaGanadora.push_front(13.99);
    //listaGanadora.push_front(2.5);
    //listaGanadora.push_front(16.0);
    //listaGanadora.push_front(55.2);
    //listaGanadora.push_front(42.69);
    //listaGanadora.push_front(0.5);

    //struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};
    //avl_create(&listaGanadora, nombre);
    //cout << "Árbol original" << endl;
    //avl_print(nombre);
    //struct avl_node* new_root;
    //cout << "Rotando izquierda" << endl;
    //status = avl_rotate_left(nombre, new_root);
    //avl_print(new_root);
    //cout << "Árbol original desp" << endl;
    //avl_print(nombre);

    //ASSERT_EQ(status, AVL_SUCCESS);
//}

///*
//Test positivo para avl_rotate_right.
//*/

//TEST(avl_rotate_right, positive){
    //int status;
    //list<float> listaGanadora;
    //listaGanadora.push_front(18.5);
    //listaGanadora.push_front(13.99);
    //listaGanadora.push_front(2.5);
    //listaGanadora.push_front(16.0);
    //listaGanadora.push_front(55.2);
    //listaGanadora.push_front(42.69);
    //listaGanadora.push_front(0.5);

    //struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};
    //avl_create(&listaGanadora, nombre);
    //cout << "Árbol original" << endl;
    //avl_print(nombre);
    //cout << "Rotando derecha" << endl;
    //status = avl_rotate_right(nombre, nombre);
    //avl_print(nombre);

    //ASSERT_EQ(status, AVL_SUCCESS);
//}

///*
//Test positivo para avl_search
//*/

//TEST(avl_search, positive){
    //int status;
    //list<float> listaGanadora;
    //listaGanadora.push_front(18.5);
    //listaGanadora.push_front(13.99);
    //listaGanadora.push_front(2.5);
    //listaGanadora.push_front(16.0);
    //listaGanadora.push_front(55.2);
    //listaGanadora.push_front(42.69);
    //listaGanadora.push_front(0.5);


    //struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};

    //avl_create(&listaGanadora, nombre);
    //cout << "Imprimiendo árbol original" << endl;
    //avl_print(nombre);
    
    //struct avl_node* busq;
    //status = avl_search(nombre, 18.5, &busq);
    //cout << "Imprimiendo nodo del search" << endl;
    //avl_print(busq);
    //ASSERT_EQ(status, AVL_SUCCESS);
//}

///*
//Test negativo para avl_search, con un parámetro inválido para valor buscado
//*/

//TEST(avl_search, negative){
    //int status;
    //list<float> listaGanadora;
    //listaGanadora.push_front(18.5);
    //listaGanadora.push_front(13.99);
    //listaGanadora.push_front(2.5);
    //listaGanadora.push_front(16.0);
    //listaGanadora.push_front(55.2);
    //listaGanadora.push_front(42.69);
    //listaGanadora.push_front(0.5);


    //struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};

    //avl_create(&listaGanadora, nombre);
    //cout << "Imprimiendo árbol original" << endl;
    //avl_print(nombre);

    //struct avl_node* busq;
    //status = avl_search(nombre, 0.6, &busq);
    //cout << "Imprimiendo nodo del search" << endl;
    //avl_print(busq);
    //ASSERT_EQ(status, AVL_NOT_FOUND);    
//}

///*
//Test positivo free_avl_tree
//*/

//TEST(free_avl_tree, positive){
    //int status;
    //list<float> listaGanadora;
    //listaGanadora.push_front(18.5);
    //listaGanadora.push_front(13.99);
    //listaGanadora.push_front(2.5);
    //listaGanadora.push_front(16.0);
    //listaGanadora.push_front(55.2);
    //listaGanadora.push_front(42.69);
    //listaGanadora.push_front(0.5);

    //struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};

    //avl_create(&listaGanadora, nombre);
    //status = free_avl_tree(nombre);

    //ASSERT_EQ(status, AVL_SUCCESS);    
//}




///*
//Test positivo balance
//*/

//TEST(avl_balance, positive_right){
    //int status;
    //list<float> listaGanadora;
    //listaGanadora.push_front(18.5);
    //listaGanadora.push_front(19);
    //listaGanadora.push_front(20);
    //listaGanadora.push_front(21);
    //listaGanadora.push_front(22);
    //listaGanadora.push_front(23);
    //listaGanadora.push_front(24);

    //struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};

    //status = avl_create(&listaGanadora, nombre);
    
    //cout << "Imprimiendo árbol" << endl;
    //avl_print(nombre);

    //ASSERT_EQ(status, AVL_SUCCESS);    
//}

//TEST(avl_balance, positive_left){
    //int status;
    //list<float> listaGanadora;
    //listaGanadora.push_front(18.5);
    //listaGanadora.push_front(8);
    //listaGanadora.push_front(7);
    //listaGanadora.push_front(6);
    //listaGanadora.push_front(5);
    //listaGanadora.push_front(4);
    //listaGanadora.push_front(3);

    //struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};

    //status = avl_create(&listaGanadora, nombre);
    
    //cout << "Imprimiendo árbol" << endl;
    //avl_print(nombre);

    //ASSERT_EQ(status, AVL_SUCCESS);    
//}

///*
//Test positivo max_get
//*/

//TEST(avl_max_get, positive){
    //int status;
    //list<float> listaGanadora;
    //listaGanadora.push_front(18.5);
    //listaGanadora.push_front(13.99);
    //listaGanadora.push_front(2.5);
    //listaGanadora.push_front(16.0);
    //listaGanadora.push_front(55.2);
    //listaGanadora.push_front(42.69);
    //listaGanadora.push_front(0.5);


    //struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};

    //avl_create(&listaGanadora, nombre);
    //struct avl_node* max;
    //status = avl_max_get(nombre, &max);
    //ASSERT_EQ(status, AVL_SUCCESS);    
//}

///*
//Test positivo min_get
//*/

//TEST(avl_min_get, positive){
    //int status;
    //list<float> listaGanadora;
    //listaGanadora.push_front(18.5);
    //listaGanadora.push_front(13.99);
    //listaGanadora.push_front(2.5);
    //listaGanadora.push_front(16.0);
    //listaGanadora.push_front(55.2);
    //listaGanadora.push_front(42.69);
    //listaGanadora.push_front(0.5);


    //struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};

    //avl_create(&listaGanadora, nombre);
    //struct avl_node* min;
    //status = avl_min_get(nombre, &min);
    //ASSERT_EQ(status, AVL_SUCCESS);    
//}

///*
//Test positivo para avl_node_remove. Removiendo nodo hoja
//*/

//TEST(avl_node_remove, positive1){
    //int status;
    //list<float> listaGanadora;
    //listaGanadora.push_front(18.5);
    //listaGanadora.push_front(13.99);
    //listaGanadora.push_front(2.5);
    //listaGanadora.push_front(16.0);
    //listaGanadora.push_front(55.2);
    //listaGanadora.push_front(42.69);
    //listaGanadora.push_front(0.5);


    //struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};
    //avl_create(&listaGanadora, nombre);
    //cout << "Imprimiendo árbol original" << endl;
    //avl_print(nombre);

    //struct avl_node* busq;
    //avl_search(nombre, 2.5, &busq);
    //cout << "Imprimiendo árbol del search" << endl;
    //avl_print(busq);

    //status = avl_node_remove(nombre, busq, nombre);
    //cout << "Imprimiendo árbol sin nodo 2.5" << endl;
    //avl_print(nombre);

    //ASSERT_EQ(status, AVL_SUCCESS);
//}

///*
//Test positivo para avl_node_remove. Removiendo nodo intermedio
//*/

//TEST(avl_node_remove, positive2){
    //int status;
    //list<float> listaGanadora;
    //listaGanadora.push_front(18.5);
    //listaGanadora.push_front(13.99);
    //listaGanadora.push_front(2.5);
    //listaGanadora.push_front(16.0);
    //listaGanadora.push_front(55.2);
    //listaGanadora.push_front(42.69);
    //listaGanadora.push_front(0.5);


    //struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};
    //avl_create(&listaGanadora, nombre);
    //cout << "Imprimiendo árbol original" << endl;
    //avl_print(nombre);

    //struct avl_node* busq;
    //avl_search(nombre, 16, &busq);
    //cout << "Imprimiendo árbol del search" << endl;
    //avl_print(busq);

    //status = avl_node_remove(nombre, busq, nombre);
    //cout << "Imprimiendo árbol sin nodo 16" << endl;
    //avl_print(nombre);

    //ASSERT_EQ(status, AVL_SUCCESS);
//}

int main(int argc, char const **argv)
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

