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

    listaGanadora.push_front(2.5);
    listaGanadora.push_front(16.0);
    listaGanadora.push_front(55.2);
    listaGanadora.push_front(42.69);
    listaGanadora.push_front(0.5);

    struct avl_node nombre = {NULL, NULL, 0.0};
    
    avl_create(&listaGanadora, &nombre);
    avl_print(nombre);
}

int main(int argc, char const **argv)
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
