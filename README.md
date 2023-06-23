# arvore-avl
Este código é referente a árvore AVL, sua estrutura e algumas explicações importante!

A altura é a quantidade de arestas(níveis) da raíz até suas folhas, 
e o fator de balanço é a altura da subárvore esquerda - a altura da subárvore direita.

Desta forma: 

Imagine está árvore 

    60 (nível/altura 4)
      \
        61  (nível/altura 3)
           \ 
             62 (nível/altura 2)
                \
                  63 (nível/altura 1)

Está árvore está totalmente desbalanceada.
Uma árvore é dita balanceada quando ela respeita a seguinte regra:

Quando o fator de balanço é:
0, -1 ou 1 a árvore está balanceada!
< -1 ou > 1 a árvore está desbalanceada!

Para descobrir o fator de balanço nós nos atentamos a seguinte fórmula.
FB = alturadaSubárvoreESQ - alturadaSubárvoreDIR.

Primeiros descobrimos a altura das subárvores observando seus níveis, depois fazemos o cálculo de fator de balanço!

Vamos fazer o FB na árvore apresentada:


    60 (nível/altura 4)
      \
        61  (nível/altura 3)
           \ 
             62 (nível/altura 2)
                \
                  63 (nível/altura 1)

Sabendo disto, fazemos o seguinte:


    60 (nível/altura 4) FB = -3
      \
        61  (nível/altura 3) FB = -2
           \ 
             62 (nível/altura 2) FB = -1
                \
                  63 (nível/altura 1) FB = 0

 Quando não temos nenhum filho no lado esquerdo, dizemos que este filho é 0, de maneira sequencial de baixo pra cima vamos fazer:

 FB: 0 - 1 = -1
 FB: 0 - 2 = -2 (61)
 FB: 0 - 3 = -3
 FB: 0 - 4 = -4

 Apartir do 61 sabemos que a árvore desbalanceou!
 Logo, identificamos que será necessário fazer uma rotação à esquerda da árvore para balancear, observamos o 61 e vemos como fazer.

 Por fatores de organização vamos começar de novo:

    60 (nível/altura 3) FB: -2 
      \
        61  (nível/altura 2) FB: -1
           \ 
             62 (nível/altura 1) FB = 0

pegamos 61 e fazemos a rotação, onde 61 se torna a raíz e 60 seu filho esquerdo:

      61
     /  \
  60      62 


fazemos novamente o cálculo de fator de balanço:

60 FB = 0
61 FB = 0
62 FB = 0
                  
