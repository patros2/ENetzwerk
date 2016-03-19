#include <stdio.h>
#include <iostream>

#include ".\lib\NodesEdges\Edge.h"
#include ".\lib\NodesEdges\Node.h"
#include ".\lib\NodesEdges\Graph.h"
#include ".\lib\berechnungen\widerstand.h"

int main(void)
{

    Node* a = new Node("Spannungsquelle", 1.9, 4);
    Node* b = new Node("Kondesator", 3.5, 2);
    Node* c = new Node("Spule", 1.5, 3);
    Node* d = new Node("Widerstand", 2.1, 1);

    Graph netz;
    netz.addNode(a);
    netz.addNode(b);
    netz.addNode(c);
    netz.addNode(d);


    std::cout << "Das ist Netz2: \n" << netz.getNode() << std::endl;

    std::cout << "Das ist Netz: \n" << netz.toString2() << std::endl;

    berechnen(a,b,c,d);

    double as = netz.getNode()->getValue();

    std::cout << "das ist : " << as << std::endl;

    std::cout << std::endl << "1" << std::endl << std::endl;

    std::cout << a->getID() << " vom Typ " << a->getType() << " hat den Wert " << a->getValue() << " und ist ein/e " << a->getName() << std::endl;
    std::cout << b->getID() << " vom Typ " << b->getType() << " hat den Wert " << b->getValue() << " und ist ein/e " << b->getName() << std::endl;
    std::cout << c->getID() << " vom Typ " << c->getType() << " hat den Wert " << c->getValue() << " und ist ein/e " << c->getName() << std::endl;
    std::cout << d->getID() << " vom Typ " << d->getType() << " hat den Wert " << d->getValue() << " und ist ein/e " << d->getName() << std::endl;


    return 0;
}

