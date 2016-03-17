#include <stdio.h>
#include <iostream>

#include ".\lib\NodesEdges\Edge.h"
#include ".\lib\NodesEdges\Node.h"
#include ".\lib\NodesEdges\Graph.h"


Node* a = new Node("Spannungsquelle", 1.9, 4);
Node* b = new Node("Kondesator", 3.5, 2);
Node* c = new Node("Spule", 1.5, 3);
Node* d = new Node("Widerstand", 2.0, 1);

double wert = 0;
double test = 0;
int z = 0;
std::string name;
double berechnen(Node* a, Node* b, Node* c, Node* d){

    Node* masche [2][2] = {{a,b},{c,d}};
    Node* knoten [2][2] = {{a,b},{c,d}};


    for (int i=0;i<2;i++)
        {
        for (int j=0;j<2;j++)
            {
                z=z+1;
                test = masche[i][j]->getValue();
                name = masche[i][j]->getID();
                printf("Lauf: %d, %d, %d, %f \n",z,i,j,test);
                std::cout << name << std::endl;

            }
        }
    return wert;
}

int main(void)
{


    berechnen(a,b,c,d);
    //printf("%f\n",berechnen(1,2,3,4));

    printf("1\n");
    std::cout << a->getID() << " vom Typ " << a->getType() << " hat den Wert " << a->getValue() << " und ist ein/e " << a->getName() << std::endl;
    std::cout << b->getID() << " vom Typ " << b->getType() << " hat den Wert " << b->getValue() << " und ist ein/e " << b->getName() << std::endl;
    std::cout << c->getID() << " vom Typ " << c->getType() << " hat den Wert " << c->getValue() << " und ist ein/e " << c->getName() << std::endl;
    std::cout << d->getID() << " vom Typ " << d->getType() << " hat den Wert " << d->getValue() << " und ist ein/e " << d->getName() << std::endl;


    return 0;
}

