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

    Node* e = new Node("Spannungsquelle", 1.9, 4);
    Node* f = new Node("Kondesator", 3.5, 2);
    Node* g = new Node("Spule", 1.5, 3);
    Node* h = new Node("Widerstand", 2.3, 1);

    Graph netz;
    netz.addNode(a);
    netz.addNode(b);
    netz.addNode(c);
    netz.addNode(d);

    Graph testn;
    testn.addNode(e);
    testn.addNode(f);
    testn.addNode(g);
    testn.addNode(h);

    std::cout << std::endl << "Das ist ein Wert aus Netz: \n" << netz.getNode() << std::endl;
/*
    Node* container[11] = { 0 };
    container[11] = netz.getNode();

    std::cout << "Das ist der 3. Wert aus Netz: "<< container[2]->getValue() << std::endl;
    std::cout << "Das ist der 1. Wert aus Netz: "<< container[0]->getValue() << std::endl;
    std::cout << "Das ist der 4. Wert aus Netz: "<< container[3]->getValue() << std::endl;
*/
    std::cout << std::endl << "Das ist das vollstaendige Netz: \n" << netz.toString2() << std::endl;

    //berechnen(a,b,c,d);
    std::cout << "Ende von berechnen, start von rs" << std::endl;
    std::cout << "Das Ergebnis der Reihenschaltung der Widerstaende aus testn ist: " << w_rs(testn) << std::endl;
    std::cout << "Das Ergebnis der Parallelschaltung der Widerstaende aus testn ist: " << w_ps(testn) << std::endl;

    //double as = netz.getNode()->getValue();
    //std::string ad = netz.getNode()->getName();

    //std::cout << "das ist : " << as << std::endl;
    //std::cout << "das ist : " << ad << std::endl;

    std::cout << std::endl << "1" << std::endl << std::endl;

    std::cout << a->getID() << " vom Typ " << a->getType() << " hat den Wert " << a->getValue() << " und ist ein/e " << a->getName() << std::endl;
    std::cout << b->getID() << " vom Typ " << b->getType() << " hat den Wert " << b->getValue() << " und ist ein/e " << b->getName() << std::endl;
    std::cout << c->getID() << " vom Typ " << c->getType() << " hat den Wert " << c->getValue() << " und ist ein/e " << c->getName() << std::endl;
    std::cout << d->getID() << " vom Typ " << d->getType() << " hat den Wert " << d->getValue() << " und ist ein/e " << d->getName() << std::endl;


    return 0;
}

