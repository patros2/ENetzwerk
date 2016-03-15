#include <stdio.h>
#include <iostream>
<<<<<<< HEAD
//#include "C:\Users\Ghostrider\Documents\GitHub\ENetzwerk\lib\NodesEdges\Node.h"
//#include "C:\Users\Ghostrider\Documents\GitHub\ENetzwerk\lib\NodesEdges\Edge.h"
//#include "C:\Users\Ghostrider\Documents\GitHub\ENetzwerk\lib\NodesEdges\Graph.h"
//arbeitsverzeichnis
#include "H:\ENetzwerk-patrick\lib\NodesEdges\Node.h"
#include "H:\ENetzwerk-patrick\lib\NodesEdges\Edge.h"
#include "H:\ENetzwerk-patrick\lib\NodesEdges\Graph.h"

Node* a = new Node("Spannungsquelle", 1.9, 1);
Node* b = new Node("Kondesator", 3.5, 0);
Node* c = new Node("Spule", 1.5, 2);
Node* d = new Node("Widerstand", 2.0, 3);
double wert = 0;
double test = 0;
int z = 0;
std::string name;
double berechnen(Node* a, Node* b, Node* c, Node* d){

    Node* masche [2][2] = {{a,b},{c,d}};
    Node* knoten [2][2] = {{a,b},{c,d}};
=======
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
>>>>>>> patrick



    for (int i=0;i<2;i++)
        {
<<<<<<< HEAD
        for (int j=0;j<2;j++)
            {
                z=z+1;
                test = masche[i][j]->getValue();
                name = masche[i][j]->getID();
                printf("Lauf: %d, %d, %d, %f \n",z,i,j,test);
                std::cout << name << std::endl;
=======
        for (int j=0;j<5;j++)
            {
                printf("1 %d,%d,%f\n",i,j,wert);
>>>>>>> patrick
                //wert = wert + masche [i][j];
            }
        }
    return wert;
    }

int main(void)
{

<<<<<<< HEAD
    berechnen(a,b,c,d);
=======
    //printf("%f\n",berechnen(1,2,3,4));
>>>>>>> patrick
    printf("1\n");
    std::cout << a->getID() << " vom Typ " << a->getType() << " hat den Wert " << a->getValue() << std::endl;
    std::cout << b->getID() << " vom Typ " << b->getType() << " hat den Wert " << b->getValue() << std::endl;
    std::cout << c->getID() << " vom Typ " << c->getType() << " hat den Wert " << c->getValue() << std::endl;
    std::cout << d->getID() << " vom Typ " << d->getType() << " hat den Wert " << d->getValue() << std::endl;

    return 0;
}

