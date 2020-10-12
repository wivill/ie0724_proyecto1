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

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

/*
Test positivo para avl_create
*/

TEST(avl_create, positive){
    int status;
    list<float> lista;
    lista.push_front(17);
    lista.push_front(16);
    lista.push_front(15);
    lista.push_front(14);
    lista.push_front(13);
    lista.push_front(12);
    //lista.push_front(0.5);

    struct avl_node *nombre = new avl_node{NULL, NULL, NULL, 11, 1};
    status = avl_create(&lista, nombre);

    ASSERT_EQ(status, AVL_SUCCESS);
}


/*
Test positivo para print
*/

TEST(avl_print, positive){
    int status;
    list<float> lista;
    lista.push_front(18.5);
    lista.push_front(13.99);
    lista.push_front(2.5);
    lista.push_front(16.0);
    lista.push_front(55.2);
    lista.push_front(42.69);
    lista.push_front(0.5);

    struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};
    avl_create(&lista, nombre);
  
    status = avl_print(nombre);

    ASSERT_EQ(status, AVL_SUCCESS);
}


/*
Test negativo para avl_node_add. Probando condición para new_root == NULL
*/

TEST(avl_node_add, negative){
    int status;
    list<float> lista;
    lista.push_front(18.5);
    lista.push_front(13.99);
    lista.push_front(2.5);
    lista.push_front(16.0);
    lista.push_front(55.2);
    lista.push_front(42.69);
    lista.push_front(0.5);

    struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};
    avl_create(&lista, nombre);
    avl_print(nombre);

    struct avl_node* nuevo_nodo = new avl_node{NULL, NULL, NULL, 11, 1};
    status = avl_node_add(nombre, nuevo_nodo, nuevo_nodo);
    ASSERT_EQ(status, AVL_INVALID_PARAM);
}


/*
Test positivo para avl_node_add. Agregando nodo 14.
*/
TEST(avl_node_add, positive){
    int status;
    list<float> lista;
    lista.push_front(18.5);
    lista.push_front(13.99);
    lista.push_front(2.5);
    lista.push_front(16.0);
    lista.push_front(55.2);
    lista.push_front(42.69);
    lista.push_front(0.5);

    struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};
    avl_create(&lista, nombre);
    avl_print(nombre);

    struct avl_node* nuevo_nodo = new avl_node{NULL, NULL, NULL, 14};
    status = avl_node_add(nombre, nuevo_nodo, nombre);
    avl_print(nombre);

    ASSERT_EQ(status, AVL_SUCCESS);
}


/*
Test positivo para avl_rotate_left.
*/
TEST(avl_rotate_left, positive){
    int status;
    list<float> lista;
    lista.push_front(18.5);
    lista.push_front(13.99);
    lista.push_front(2.5);
    lista.push_front(16.0);
    lista.push_front(55.2);
    lista.push_front(42.69);
    lista.push_front(0.5);

    struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};
    avl_create(&lista, nombre);
    cout << "Árbol original" << endl;
    avl_print(nombre);
    
    struct avl_node* new_root;
    cout << "Rotando izquierda" << endl;
    status = avl_rotate_left(nombre, new_root);
    avl_print(nombre);

    ASSERT_EQ(status, AVL_SUCCESS);
}


///*
//Test positivo para avl_rotate_right.
//*/
TEST(avl_rotate_right, positive){

    int status;
    list<float> lista;
    lista.push_front(18.5);
    lista.push_front(13.99);
    lista.push_front(2.5);
    lista.push_front(16.0);
    lista.push_front(55.2);
    lista.push_front(42.69);
    lista.push_front(0.5);

    struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};
    avl_create(&lista, nombre);
    cout << "Árbol original" << endl;
    avl_print(nombre);
    
    struct avl_node* new_root;
    cout << "Rotando derecha" << endl;
    status = avl_rotate_right(nombre, new_root);
    avl_print(nombre);

    ASSERT_EQ(status, AVL_SUCCESS);
}


/* /*
Test positivo para avl_search
*/
TEST(avl_search, positive){

    int status;
    list<float> lista;
    lista.push_front(18.5);
    lista.push_front(13.99);
    lista.push_front(2.5);
    lista.push_front(16.0);
    lista.push_front(55.2);
    lista.push_front(42.69);
    lista.push_front(0.5);

    struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};

    avl_create(&lista, nombre);
    cout << "Imprimiendo árbol original" << endl;
    avl_print(nombre);

    struct avl_node* busq;
    status = avl_search(nombre, 55.2, &busq);
    cout << "Imprimiendo nodo del search" << endl;
    avl_print(busq);
    ASSERT_EQ(status, AVL_SUCCESS);  
}


/*
Test negativo para avl_search, con un parámetro inválido para valor buscado
*/
TEST(avl_search, negative){
    int status;
    list<float> lista;
    lista.push_front(18.5);
    lista.push_front(13.99);
    lista.push_front(2.5);
    lista.push_front(16.0);
    lista.push_front(55.2);
    lista.push_front(42.69);
    lista.push_front(0.5);

    struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};

    avl_create(&lista, nombre);
    cout << "Imprimiendo árbol original" << endl;
    avl_print(nombre);

    struct avl_node* busq;
    status = avl_search(nombre, 0.6, &busq);
    cout << "Imprimiendo nodo del search" << endl;
    avl_print(busq);
    ASSERT_EQ(status, AVL_NOT_FOUND);    
}


/*
Test positivo free_avl_tree
*/
TEST(free_avl_tree, positive){
    int status;
    list<float> lista;
    lista.push_front(18.5);
    lista.push_front(13.99);
    lista.push_front(2.5);
    lista.push_front(16.0);
    lista.push_front(55.2);
    lista.push_front(42.69);
    lista.push_front(0.5);


    struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};

    avl_create(&lista, nombre);
    status = free_avl_tree(nombre);

    ASSERT_EQ(status, AVL_SUCCESS);    
}


/*
Test positivo balance
*/

TEST(avl_balance, positive){
    int status;
    list<float> lista;
    lista.push_front(18.5);
    lista.push_front(19);
    lista.push_front(20);
    lista.push_front(21);
    lista.push_front(22);
    lista.push_front(23);
    lista.push_front(24);

    struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};

    avl_create(&lista, nombre);

    struct avl_node* temp;
    struct avl_node* nuevo_nodo = new avl_node{NULL, NULL, NULL, 19};
    status = avl_balance(nombre, nuevo_nodo, temp);
    
    cout << "Imprimiendo árbol" << endl;
    avl_print(nombre);

    ASSERT_EQ(status, AVL_SUCCESS);    
}


/*
Test positivo max_get
*/
TEST(avl_max_get, positive){
    int status;
    list<float> lista;
    lista.push_front(18.5);
    lista.push_front(13.99);
    lista.push_front(2.5);
    lista.push_front(16.0);
    lista.push_front(55.2);
    lista.push_front(42.69);
    lista.push_front(0.5);


    struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};

    avl_create(&lista, nombre);
    struct avl_node* max;
    status = avl_max_get(nombre, &max);
    ASSERT_EQ(status, AVL_SUCCESS);    
}

/*
Test positivo min_get
*/

TEST(avl_min_get, positive){
    int status;
    list<float> lista;
    lista.push_front(18.5);
    lista.push_front(13.99);
    lista.push_front(2.5);
    lista.push_front(16.0);
    lista.push_front(55.2);
    lista.push_front(42.69);
    lista.push_front(0.5);


    struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};

    avl_create(&lista, nombre);
    struct avl_node* min;
    status = avl_min_get(nombre, &min);
    ASSERT_EQ(status, AVL_SUCCESS);    
}

/*
Test positivo para avl_node_remove. Removiendo nodo hoja
*/

TEST(avl_node_remove, positive1){
    int status;
    list<float> lista;
    lista.push_front(18.5);
    lista.push_front(13.99);
    lista.push_front(2.5);
    lista.push_front(16.0);
    lista.push_front(55.2);
    lista.push_front(42.69);
    lista.push_front(0.5);


    struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};
    avl_create(&lista, nombre);
    cout << "Imprimiendo árbol original" << endl;
    avl_print(nombre);

    struct avl_node* busq;
    avl_search(nombre, 2.5, &busq);
    cout << "Imprimiendo árbol del search" << endl;
    avl_print(busq);

    status = avl_node_remove(nombre, busq, nombre);
    cout << "Imprimiendo árbol sin nodo 2.5" << endl;
    avl_print(nombre);

    ASSERT_EQ(status, AVL_SUCCESS);
}

/*
Test positivo para avl_node_remove. Removiendo nodo intermedio
*/

TEST(avl_node_remove, positive2){
    int status;
    list<float> lista;
    lista.push_front(18.5);
    lista.push_front(13.99);
    lista.push_front(2.5);
    lista.push_front(16.0);
    lista.push_front(55.2);
    lista.push_front(42.69);
    lista.push_front(0.5);


    struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};
    avl_create(&lista, nombre);
    cout << "Imprimiendo árbol original" << endl;
    avl_print(nombre);

    struct avl_node* busq;
    avl_search(nombre, 16, &busq);
    cout << "Imprimiendo árbol del search" << endl;
    avl_print(busq);

    status = avl_node_remove(nombre, busq, nombre);
    cout << "Imprimiendo árbol sin nodo 16" << endl;
    avl_print(nombre);

    ASSERT_EQ(status, AVL_SUCCESS);
} 

TEST(avl_node_add, complexity){

    ofstream fichero;

    fichero.open("fichero.csv", ios::app);
    
    srand(time(NULL));

    for (size_t i = 0; i < 100; i++)
    {
        int status;
        clock_t t0, t1;
        list<float> lista;
        
        int random      = 100 + rand() % 99900;
        for (size_t i = 0; i < random; i++)
        {
            double r =  (rand() % 10000) * ((double)rand() / (double) INT32_MAX);
            lista.push_back(r);
        }
        
        struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11, 1};
        avl_create(&lista, nombre);
        struct avl_node* nuevo_nodo = new avl_node{NULL, NULL, NULL, 15000, 1};
        
        auto start = std::chrono::system_clock::now();
        avl_node_add(nombre, nuevo_nodo, nuevo_nodo);
        auto end = std::chrono::system_clock::now();

        std::chrono::duration<float,std::milli> duration = end - start;
        fichero << random  << "," <<  duration.count() << endl;
    }
    
    fichero.close();
}



int main(int argc, char const **argv)
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

