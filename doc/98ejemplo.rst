.. _ejemplo:

*******
Ejemplo
*******

subtitle
########

subsubtitle
***********

.. _docgen-etiqueta:

section
=======

subsection
----------

subsubsection
^^^^^^^^^^^^^

subsubsection
~~~~~~~~~~~~~~~~

Texto normal estilo loren ipsum y una referencia a sintaxis :cite:`rstsyntax`

Ahora una imagen con una etiqueta para referenciarla :ref:`docgen-fig00` y de
igual forma una referencia a una sección :ref:`docgen-etiqueta`.

.. _docgen-fig00:

.. figure:: img/linuxsteps/ssh_gitlab.png
  :align: center
  :width: 100 px
  :alt: Imagen de ejemplo.

  Imagen de ejemplo.

Listas
------

* This is a bulleted list.
* It has two items, the second
  item uses two lines. (note the indentation)

1. This is a numbered list.
2. It has two items too.

#. This is a numbered list.
#. It has two items too.

Cuadro simple
-------------

+---------+---------+-----------+
| 1       |  2      |  3        |
+---------+---------+-----------+

Cuadro más elaborado
--------------------

+------------+------------+-----------+
| Header 1   | Header 2   | Header 3  |
+============+============+===========+
| body row 1 | column 2   | column 3  |
+------------+------------+-----------+
| body row 2 | Cells may span columns.|
+------------+------------+-----------+
| body row 3 | Cells may  | - Cells   |
+------------+ span rows. | - contain |
| body row 4 |            | - blocks. |
+------------+------------+-----------+

Cuadro alternativo
------------------

=====  =====  ======
   Inputs     Output
------------  ------
  A      B    A or B
=====  =====  ======
False  False  False
True   False  True
=====  =====  ======

Cuadro estilo Látex
-------------------

.. tabularcolumns:: |l|c|p{5cm}|

+--------------+---+-----------+
|  simple text | 2 | 3         |
+--------------+---+-----------+

Cuadro convertido con pandocl
-----------------------------

.. code-block:: console

  pandoc -o tabla.rst tabla.tex

.. code-block:: latex

  \documentclass{article}

  \begin{document}
  \begin{table*}[h!]
  \caption{Lista de equipos}
  \label{T:equipos}
  \begin{center}
  \begin{tabular}{| c | c | c | c |}
  \hline
  \textbf{Equipo}& \textbf{Marca} & \textbf{Modelo} & \textbf(Placa)\\
  \hline
  Osciloscopio digital & Tektronix & TDS1001B &280683 \\
  Generador de seÃ±ales & Agilent & 33210A & 343474 \\
  Fuente DC & Keysight  & E3630A &387850 \\
  MultÃ­metro & Agilent & 34405A & 329742 \\
  \hline
  \end{tabular}
  \end{center}
  \end{table*}
  \end{document}

====================  =========  ========  ======
Equipo                Marca      Modelo    Placa
--------------------  ---------  --------  ------
Osciloscopio digital  Tektronix  TDS1001B  280683
Generador de señales  Agilent    33210A    343474
Fuente DC             Keysight   E3630A    387850
Multímetro            Agilent    34405A    329742
====================  =========  ========  ======



.. table:: Lista de Componentes para el circuito octavador

   ============= ============== ========= =================================== ========================
    **Cantidad** **Componente** **Sigla** **Valor Nominal**    **Tolerancia** **Valor Real**          
   ============= ============== ========= =================================== ========================
   1             LM741          OP7       -                     -              -                       
   1             Resistor       R1        560 k\ :math:`\Omega` 5 %            587.62k\ :math:`\Omega` 
   1             Resistor       R2        18 k\ :math:`\Omega`  5 %            17.65k\ :math:`\Omega`  
   1             Resistor       R3        10 k\ :math:`\Omega`  5 %            10.157k\ :math:`\Omega` 
   1             Resistor       R4        2.2 M\ :math:`\Omega` 5 %            2.2039M\ :math:`\Omega` 
   1             Resistor       R5        160 k\ :math:`\Omega` 5 %            156.40k\ :math:`\Omega` 
   1             Resistor       R6        6.2 k\ :math:`\Omega` 5 %            6.801k\ :math:`\Omega`  
   1             Resistor       R7        10 k\ :math:`\Omega`  5 %            9.9758k\ :math:`\Omega` 
   1             Resistor       R8        68 k\ :math:`\Omega`  5 %            69.222k\ :math:`\Omega` 
   1             Resistor       R9        68 k\ :math:`\Omega`  5 %            68.168k\ :math:`\Omega` 
   1             Resistor       R10       10 k\ :math:`\Omega`  5 %            9.9687k\ :math:`\Omega` 
   1             Resistor       R11       22 k\ :math:`\Omega`  5 %            22.4015k\ :math:`\Omega`
   1             Resistor       R12       22 k\ :math:`\Omega`  5 %            21.62k\ :math:`\Omega`  
   1             Resistor       R13       47 k\ :math:`\Omega`  5 %            47.70k\ :math:`\Omega`  
   1             Capacitor      C1        100 :math:`\mu F`     -              94.5\ :math:`\mu F`     
   1             Capacitor      C2        47                    -              46                      
   1             Capacitor      C3        47                    -              48                      
   1             Capacitor      C4        47                    -              47                      
   1             Capacitor      C5        100                   -              0.1 :math:`\mu F`       
   1             Diodo          D1        1N915                 -              -                       
   1             Diodo          D2        1N915 -               -                                      
   1             Transistor     Q1        2N5088                -              -                       
   1             Transistor     Q2        2N3906                -              -                       
   1             Transistor     Q3        2N5088                -              -                       
   ============= ============== ========= =================================== ========================

.. table:: Lista de Componentes para el filtro pasa bajos

   ============= ============== ========= ================================= ========================
    **Cantidad** **Componente** **Sigla** **Valor Nominal**  **Tolerancia** **Valor Real**          
   ============= ============== ========= ================================= ========================
   1             LM741          OP3       -                   -              -                       
   1             Resistor       R16       1 K\ :math:`\Omega` 5 %            1,0796 K\ :math:`\Omega`
   1             Resistor       R17       1 K\ :math:`\Omega` 5%             1,0698 K\ :math:`\Omega`
   1             Resistor       R18       1 K\ :math:`\Omega` 5%             1,0521 K\ :math:`\Omega`
   1             Capacitor      C7        330 nF              -              342 nF                  
   1             Capacitor      C8        330 nF              -              342 nF                  
   ============= ============== ========= ================================= ========================

.. table:: Lista de Componentes para el primer filtro pasa banda

   ============= ============== ========= =================================== =========================
    **Cantidad** **Componente** **Sigla** **Valor Nominal**    **Tolerancia** **Valor Real**           
   ============= ============== ========= =================================== =========================
   1             LM741          OP4       -                     -              -                        
   1             Resistor       R19       1 K\ :math:`\Omega`   5 %            0,99731 K\ :math:`\Omega`
   1             Resistor       R20       2,2 K\ :math:`\Omega` 5%             2,0112 K\ :math:`\Omega` 
   1             Resistor       R21       1 K\ :math:`\Omega`   5%             1,0464 K\ :math:`\Omega` 
   1             Resistor       R22       2,2 K\ :math:`\Omega` 5%             2,0067 K\ :math:`\Omega` 
   1             Resistor       R23       1 K\ :math:`\Omega`   5%             1,059 K\ :math:`\Omega`  
   1             Capacitor      C9        100 nF                -              100,1 nF                 
   1             Capacitor      C10       56 nF                 -              56,6 nF                  
   1             Capacitor      C11       56 nF                 -              60,6 nF                  
   1             Capacitor      C12       100 nF                -              98,4 nF                  
   ============= ============== ========= =================================== =========================

.. table:: Lista de Componentes para el segundo filtro pasa banda

   ============= ============== ========= ================================= =========================
    **Cantidad** **Componente** **Sigla** **Valor Nominal**  **Tolerancia** **Valor Real**           
   ============= ============== ========= ================================= =========================
   1             LM741          OP5       -                   -              -                        
   1             LM741          OP6       -                   -              -                        
   1             Resistor       R24       1 K\ :math:`\Omega` 5 %            1,0569 K\ :math:`\Omega` 
   1             Resistor       R25       1 K\ :math:`\Omega` 5%             1,0657 K\ :math:`\Omega` 
   1             Resistor       R26       1 K\ :math:`\Omega` 5%             1,0730 K\ :math:`\Omega` 
   1             Resistor       R27       1 K\ :math:`\Omega` 5%             1,069 K\ :math:`\Omega`  
   1             Resistor       R28       1 K\ :math:`\Omega` 5%             0,80980 K\ :math:`\Omega`
   1             Capacitor      C13       8,2 nF              -              8,52 nF                  
   1             Capacitor      C14       8,2 nF              -              8,79 nF                  
   1             Capacitor      C15       68 nF               -              75,0 nF                  
   1             Capacitor      C16       68 nF               -              71,6 nF                  
   ============= ============== ========= ================================= =========================

.. table:: Lista de Componentes para el circuito sumador

   ============= ============== ========= ================================= =========================
    **Cantidad** **Componente** **Sigla** **Valor Nominal**  **Tolerancia** **Valor Real**           
   ============= ============== ========= ================================= =========================
   1             LM741          OP7       -                   -              -                        
   1             Resistor       R29       1 K\ :math:`\Omega` 5 %            0.9998 K\ :math:`\Omega` 
   1             Resistor       R30       1 K\ :math:`\Omega` 5%             0.99193 K\ :math:`\Omega`
   1             Resistor       R31       1 K\ :math:`\Omega` 5%             0.99136 K\ :math:`\Omega`
   1             Resistor       R32       1 K\ :math:`\Omega` 5%             - K\ :math:`\Omega`      
   1             Potenciómetro  Pot       1 K\ :math:`\Omega` -              - K\ :math:`\Omega`      
   ============= ============== ========= ================================= =========================

.. table:: Lista de Componentes para el vúmetro

   ============= ============== ========= =================================== =========================
    **Cantidad** **Componente** **Sigla** **Valor Nominal**    **Tolerancia** **Valor Real**           
   ============= ============== ========= =================================== =========================
   1             LM331          PLL1      -                     -              -                        
   1             LM331          PLL2      -                     -              -                        
   1             LM331          PLL3      -                     -              -                        
   1             LM3915         CI1       -                     -              -                        
   1             LM3915         CI2       -                     -              -                        
   1             LM3915         CI3       -                     -              -                        
   1             Resistor       R33       100 K\ :math:`\Omega` 5 %            99.987 K\ :math:`\Omega` 
   1             Resistor       R34       100 K\ :math:`\Omega` 5 %            102.532 K\ :math:`\Omega`
   1             Resistor       R35       100 K\ :math:`\Omega` 5 %            98.754 K\ :math:`\Omega` 
   1             Resistor       R36       6.8 K\ :math:`\Omega` 5 %            98.754 K\ :math:`\Omega` 
   1             Resistor       R36       6.8 K\ :math:`\Omega` 5 %            98.754 K\ :math:`\Omega` 
   1             Resistor       R36       6.8 K\ :math:`\Omega` 5 %            98.754 K\ :math:`\Omega` 
   1             Potenciómetro  Pot2      1 K\ :math:`\Omega`   -              - K\ :math:`\Omega`      
   1             Potenciómetro  Pot3      10 K\ :math:`\Omega`  -              - K\ :math:`\Omega`      
   1             Potenciómetro  Pot4      50 K\ :math:`\Omega`  -              - K\ :math:`\Omega`      
   ============= ============== ========= =================================== =========================