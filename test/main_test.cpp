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

TEST(TestName, insert_element){
    
    
    list<float> listaGanadora;
    listaGanadora.push_front(18.5);
    listaGanadora.push_front(13.99);
    listaGanadora.push_front(2.5);
    listaGanadora.push_front(16.0);
    listaGanadora.push_front(55.2);
    listaGanadora.push_front(42.69);
    listaGanadora.push_front(0.5);


    struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11};

    avl_create(&listaGanadora, nombre);
    avl_print(nombre);
   

    struct avl_node* min_node;
    avl_min_get(nombre, &min_node);
    cout << min_node->value << " MIN"<< endl;
    
    struct avl_node* max_node;
    avl_max_get(nombre, &max_node);
    cout << max_node->value << " MAX"<< endl;

    
    struct avl_node* search_node;
    avl_search(nombre, 11, &search_node);
    cout << "search "<< search_node->value << endl;

    struct avl_node* new_root;
    avl_rotate_left(search_node,new_root);
    avl_print(new_root);

    cout << "sdfsdf" << endl;
    free_avl_tree(nombre);

}

/*
Test positivo para avl_search
*/

TEST(positive_avl_search, avl_search){
    int status;
    list<float> listaGanadora;
    listaGanadora.push_front(18.5);
    listaGanadora.push_front(13.99);
    listaGanadora.push_front(2.5);
    listaGanadora.push_front(16.0);
    listaGanadora.push_front(55.2);
    listaGanadora.push_front(42.69);
    listaGanadora.push_front(0.5);


    struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11};

    avl_create(&listaGanadora, nombre);
    struct avl_node* busq;
    //struct avl_node* busq = new avl_node{NULL, NULL, NULL, 1};
    //avl_create(NULL, busq);
    status = avl_search(nombre, 18.5, &busq);
    ASSERT_EQ(status, AVL_SUCCESS);
}

/*
Test negativo 1 para avl_search, con un parámetro inválido para found_node
*/

/*

TEST(negative1_avl_search, avl_search){
    int status;
    list<float> listaGanadora;
    listaGanadora.push_front(18.5);
    listaGanadora.push_front(13.99);
    listaGanadora.push_front(2.5);
    listaGanadora.push_front(16.0);
    listaGanadora.push_front(55.2);
    listaGanadora.push_front(42.69);
    listaGanadora.push_front(0.5);


    struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11};

    avl_create(&listaGanadora, nombre);
    status = avl_search(nombre, 5, NULL);
    ASSERT_EQ(status, AVL_OUT_OF_RANGE);
}
*/

/*
Test negativo 2 para avl_search, con un parámetro inválido para valor buscado
*/

TEST(negative2_avl_search, avl_search){
    int status;
    list<float> listaGanadora;
    listaGanadora.push_front(18.5);
    listaGanadora.push_front(13.99);
    listaGanadora.push_front(2.5);
    listaGanadora.push_front(16.0);
    listaGanadora.push_front(55.2);
    listaGanadora.push_front(42.69);
    listaGanadora.push_front(0.5);


    struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11};

    avl_create(&listaGanadora, nombre);
    struct avl_node* busq;
    status = avl_search(nombre, 0.5, &busq);
    ASSERT_EQ(status, AVL_NOT_FOUND);    
}



/*
Test positivo free_avl_tree
*/

TEST(positive_free_avl_tree, free_avl_tree){
    int status;
    list<float> listaGanadora;
    listaGanadora.push_front(18.5);
    listaGanadora.push_front(13.99);
    listaGanadora.push_front(2.5);
    listaGanadora.push_front(16.0);
    listaGanadora.push_front(55.2);
    listaGanadora.push_front(42.69);
    listaGanadora.push_front(0.5);


    struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11};

    avl_create(&listaGanadora, nombre);
    status = free_avl_tree(nombre);
    ASSERT_EQ(status, AVL_SUCCESS);    
}


/*
Test positivo max_get
*/

TEST(positive_avl_max_get, avl_max_get){
    int status;
    list<float> listaGanadora;
    listaGanadora.push_front(18.5);
    listaGanadora.push_front(13.99);
    listaGanadora.push_front(2.5);
    listaGanadora.push_front(16.0);
    listaGanadora.push_front(55.2);
    listaGanadora.push_front(42.69);
    listaGanadora.push_front(0.5);


    struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11};

    avl_create(&listaGanadora, nombre);
    struct avl_node* max;
    status = avl_max_get(nombre, &max);
    ASSERT_EQ(status, AVL_SUCCESS);    
}

/*
Test positivo min_get
*/

TEST(positive_avl_min_get, avl_min_get){
    int status;
    list<float> listaGanadora;
    listaGanadora.push_front(18.5);
    listaGanadora.push_front(13.99);
    listaGanadora.push_front(2.5);
    listaGanadora.push_front(16.0);
    listaGanadora.push_front(55.2);
    listaGanadora.push_front(42.69);
    listaGanadora.push_front(0.5);


    struct avl_node* nombre = new avl_node{NULL, NULL, NULL, 11};

    avl_create(&listaGanadora, nombre);
    struct avl_node* min;
    status = avl_min_get(nombre, &min);
    ASSERT_EQ(status, AVL_SUCCESS);    
}



int main(int argc, char const **argv)
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

