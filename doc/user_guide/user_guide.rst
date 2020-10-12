.. _avltree_user_guide-guia:

Guía de usuario para el AVL Tree
================================

En esta sección se detalla la forma básica de usar la estructura de datos AVL Tree
implementada. Para poder ver el código directamente se puede clonar del `repositorio`_ 
en Github:

.. _repositorio: https://github.com/wivill/ie0724_proyecto1

.. code-block:: console

    git clone https://github.com/wivill/ie0724_proyecto1.git #En caso de no tener usuario en Github.
    git clone git@github.com:wivill/ie0724_proyecto1.git #Si tiene usuario y llave SSH.
    

Al posicionarnos en el directorio principal del repositorio que contiene la estructura
de datos, nos encontramos con la siguiente estructura de directorios:

* **debug**: Este es un directorio para depuración.
* **doc**: Acá se tienen los archivos fuente para esta documentación.
* **docs_doxygen**: Documentación legacy generada mediante Doxygen de la estructura de datos.
* **include**: Acá se encuentran los header files de la estructura de datos.
* **src**: Acá está el código fuente propiamente del AVL Tree.
* **test**: Acá está el código fuente para el banco de pruebas de la estructura de datos.

Adicionalmente se tienen los siguientes archivos:

* **CMakeLists.txt**: Contiene las directivas para poder compilar la estructura de datos, pruebas y documentación usando CMake.
* **Dockerfile**: Receta de Docker para ejecutar pruebas sobre la estructura de datos en un workflow de Github.
* **docker-compose.test.yml**: Receta de Docker Compose para facilitar la creación de contenedores usando Dockerfiles como base.
* **LICENSE**: Licencia GPL3 incluída en el repositorio.
* **Makefile**: Receta para compilación de la estructura. Se pueden encontrar más detalles en la sección `Compilación de estructura de datos`_ 
* **README.md**: Incluye una pequeña descripción del proyecto, los autores, y enlaces a esta documentación y al repositorio en Github.


.. _avltree_user_guide-compilacion:

Compilación de estructura de datos
----------------------------------

Para poder compilar estructura de datos, correr el banco de pruebas o generar la documentación
manualmente se emplea el Makefile ubicado en la raíz del repositorio. Este Makefile contiene las
siguientes opciones:

* **default**: al llamar simplemente a make se genera el directorio build y el Makefile con CMake.
* **build**: Genera los ejecutables en build luego de generar el Makefile.
* **check**: Compila la estructura de datos y el banco de pruebas, luego lo ejecuta para ejercitar los métodos de la estructura de datos.
* **clean**: Elimina el directorio build junto con sus contenidos.
* **docs**: Genera manualmente la documentación del proyecto usando sphinx. El html resultante se encuentra en doc/_build/html.

En cada caso el uso del Makefile es bastante sencillo de acuerdo con la explicación anterior.

.. code-block:: console

    make
    make build
    make check
    make docs
    make clean

En este caso nos concierne particularmente el uso de make build y make check para compilar y probar
la estructura de datos.


.. _avltree_user_guide-struct:

Estructura de datos para un nodo del AVL Tree
---------------------------------------------

La definición del nodo para esta implementación se hace mediante un struct, tal y como
se muestra en el bloque de código:

.. code-block:: cpp

    struct avl_node {
        /* Puntero al nodo padre */
        struct avl_node *pc_node;  

        /** Puntero al nodo hijo izquierdo */
        struct avl_node *lc_node;

        /** Puntero al nodo hijo derecho */
        struct avl_node *rc_node;

        /** Número flotante asociado al nodo */
        float value;

        /* Altura */
        int height;
    };

Tal y como se puede apreciar, cada nodo contiene información referente a su relación con otros
nodos a través de los punteros al nodo padre, nodos hijos izquierdo y derecho, el valor asociado
a dicho nodo y que se usa como criterio para saber su ubicación en el árbol, y la altura que se
usa como criterio para balancear el árbol.

.. _avltree_user_guide-pruebas:

Pruebas y casos de uso
----------------------

Basándonos en las pruebas unitarias en el archivo test/main_test.cpp, se presentan
algunos casos de uso típicos para inicializar el AVL tree, buscar, agregar y eliminar 
nodos, entre otros posibles ejercicios para el uso de la estructura de datos. La mayoría
de los métodos retorna una bandera que se usa para evaluar si fue exitoso o no, por lo que
si se requiere una salida distinta se debe pasar como argumento de entrada y modificarlo
dentro del método.

Los códigos que retornan típicamente las funciones del AVL tree son:

.. code-block:: cpp

    enum avl_error_codes {
        AVL_SUCCESS       = 0,
        AVL_INVALID_PARAM = -1,
        AVL_OUT_OF_RANGE  = -2,
        AVL_TIMEOUT       = -3,
        AVL_NOT_FOUND     = -4,
    };

Creación del AVL tree
^^^^^^^^^^^^^^^^^^^^^

El siguiente bloque de código muestra cómo se genera una lista con valores tipo float
los cuales se emplean como llaves para cada nodo del árbol a construir. El árbol es creado
llamando al método avl_create que recibe como argumentos la lista y una estructura node con
su valor asociado y altura inicializada en 1.

.. code-block:: cpp

    #include <avltree.hpp>
    #include <list>

    using namespace std;

    int main(int argc, char const **argv)
    {
        // Creación de lista con elementos a agregar al árbol
        list<float> listaGanadora;
        listaGanadora.push_front(18.5);
        listaGanadora.push_front(13.99);
        listaGanadora.push_front(2.5);
        listaGanadora.push_front(16.0);
        listaGanadora.push_front(55.2);
        listaGanadora.push_front(42.69);
        listaGanadora.push_front(0.5);

        // Estructura base que será inicialmente la raíz del árbol
        struct avl_node* arbol = new avl_node{NULL, NULL, NULL, 11, 1};

        // Método para crear el árbol a partir de la lista y la raíz inicial
        avl_create(&listaGanadora, arbol);

        return 0;
    }


Agregar un nuevo nodo al AVL tree
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

El proceso para agregar un nodo nuevo una vez creado el árbol se hace llamando al método
avl_node_add, al cual se le debe pasar como argumento la raiz del árbol, una estructura node
con el valor del nuevo nodo a agregar y un struct que corresponde a la nueva raíz. Este puede
ir vacío pues se usará como recipiente para la nueva raíz a la hora de autobalancear el árbol.

.. code-block:: cpp

    // Crea estructura a partir de un nodo base y una lista 
    struct avl_node* arbol = new avl_node{NULL, NULL, NULL, 11, 1};
    avl_create(&listaGanadora, arbol);

    // Crea un nodo nuevo a agregar y un struct para la nueva raíz en caso de ser necesario
    struct avl_node* nuevo_nodo = new avl_node{NULL, NULL, NULL, 14};
    struct avl_node* nueva_raiz;
    avl_node_add(arbol, nuevo_nodo, nueva_raiz);


Buscar un nodo en el AVL tree
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

El proceso de búsqueda de un nodo particular se realiza mediante la función avl_search, el cual
recibe como argumentos la raíz del árbol, el valor del nodo a buscar, y la dirección a un struct
en el cual se almacena el nodo encontrado. El método retorna una confirmación de si encontró el
nodo o no.

.. code-block:: cpp

    // Valor a buscar en el árbol
    float valor_busqueda = 0.5;

    // Estructura que contendrá el nodo resultado de la búsqueda
    struct avl_node* busq;

    // Busca el nodo y evalúa si existe en el árbol o no.
    int status = avl_search(arbol, valor_busqueda, &busq);

    if (status == AVL_SUCCESS)
    {
        cout << "Encontré el nodo " << valor_busqueda << endl;
    } 
    else if (status == AVL_NOT_FOUND)
    {
        cout << "No encontré el nodo " << valor_busqueda << endl;
    }


Remover un nodo del AVL tree
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

De forma complementaria al proceso para agregar un nodo, para remover uno primero debemos
buscarlo en la estructura, y este resultado se usa como argumento para llamar al método 
avl_node_remove.

.. code-block:: cpp

    // Valor a buscar en el árbol
    float valor_busqueda = 0.5;

    // Estructura que contendrá el nodo resultado de la búsqueda
    struct avl_node* busq;

    // Estructura que contendrá la nueva raíz
    struct avl_node* nueva_raiz;

    // Busca el nodo y evalúa si existe en el árbol o no.
    int status = avl_search(arbol, valor_busqueda, &busq);

    if (status == AVL_SUCCESS)
    {
        cout << "Encontré el nodo " << valor_busqueda << endl;

        // Remueve el nodo del árbol
        avl_node_remove(arbol, busq, nueva_raiz);

    } else if (status == AVL_NOT_FOUND)
    {
        cout << "No encontré el nodo " << valor_busqueda << endl;
    }

Máximo y mínimo nodo del AVL tree
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

De forma similar al método avl_search, se requiere de una estructura nodo que almacene
el resultado en caso de ser exitoso. El método para obtener el nodo de máximo valor es
avl_max_get y para el mínimo se denomina avl_min_get. Ambos reciben como argumentos la raíz del árbol y la dirección a un struct
en el cual se almacena el nodo encontrado.

.. code-block:: cpp

    // Estructura que contendrá el nodo resultado de la búsqueda
    struct avl_node* max_busq;
    struct avl_node* min_busq;

    // Busca el nodo máximo y minimo
    avl_max_get(arbol, &max_busq);
    avl_min_get(arbol, &min_busq);

Imprimir un nodo o todo el AVL tree
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

El método avl_print puede usarse para obtener una validación visual de los métodos de búsqueda
de nodos presentados hasta ahora, así como para visualizar el árbol completo en la terminal. Este
método recibe como argumento únicamente un nodo el cual puede ser la raíz del árbol o un nodo
resultado.

.. code-block:: cpp

    // Valor a buscar en el árbol
    float valor_busqueda = 42.69;

    // Estructura que contendrá el nodo resultado de la búsqueda
    struct avl_node* max_busq;
    struct avl_node* min_busq;
    struct avl_node* busq;

    // Busca el nodo máximo y minimo
    avl_max_get(arbol, &max_busq);
    avl_min_get(arbol, &min_busq);
    avl_search(arbol, valor_busqueda, &busq);

    // Imprime el árbol y los resultados
    avl_print(arbol)
    avl_print(max_busq)
    avl_print(min_busq)
    avl_print(busq)
    
Los resultados se ven de forma similar al siguiente bloque:

.. code-block:: console

    # Árbol
    └──11
        ├──0.5
        │   └──2.5
        └──42.69
            ├──16
            └──55.2

    # Máximo
    └──55.2

    # Mínimo
    └──0.5

    # Nodo buscado
    └──42.69

