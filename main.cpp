#include <stdio.h>
#include <iostream>
#include "C:\Users\Ghostrider\Documents\GitHub\ENetzwerk\lib\NodesEdges\Node.h"
#include "C:\Users\Ghostrider\Documents\GitHub\ENetzwerk\lib\NodesEdges\Edge.h"
#include "C:\Users\Ghostrider\Documents\GitHub\ENetzwerk\lib\NodesEdges\Graph.h"


Node* a = new Node();
Node* b = new Node();
Node* c = new Node();
Node* d = new Node("d", 2.0, 3);
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
    printf("1\n");
    std::cout << a->getID() << " vom Typ " << a->getType() << " hat den Wert " << a->getValue() << std::endl;
    std::cout << b->getID() << " vom Typ " << b->getType() << " hat den Wert " << b->getValue() << std::endl;
    std::cout << c->getID() << " vom Typ " << c->getType() << " hat den Wert " << c->getValue() << std::endl;
    std::cout << d->getID() << " vom Typ " << d->getType() << " hat den Wert " << d->getValue() << std::endl;

    return 0;
}

