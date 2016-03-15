#include <stdio.h>
#include "C:\Users\Ghostrider\Documents\GitHub\ENetzwerk\lib\NodesEdges\Node.h"
#include "C:\Users\Ghostrider\Documents\GitHub\ENetzwerk\lib\NodesEdges\Edge.h"
#include "C:\Users\Ghostrider\Documents\GitHub\ENetzwerk\lib\NodesEdges\Graph.h"


Node* a = new Node("a");
Node* b = new Node("b");
Node* c = new Node("c");
Node* d = new Node("d");
double wert = 0;

double berechnen(Node a, Node b, Node c, Node d){

    Node masche [2][2] = {{a,b},{c,d}};
    Node knoten [2][2] = {{a,b},{c,d}};



    for (int i=0;i<2;i++)
        {
        for (int j=0;j<5;j++)
            {
                printf("1 %d,%d,%f\n",i,j,wert);
                //wert = wert + masche [i][j];
            }
        }
    return wert;
    }

int main(void)
{

    //printf("%f\n",berechnen(1,2,3,4));


    return 0;
}

