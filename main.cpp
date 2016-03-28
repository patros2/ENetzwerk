#include ".\lib\NodesEdges\Edge.h"
#include ".\lib\NodesEdges\Node.h"
#include ".\lib\NodesEdges\Graph.h"
#include ".\lib\berechnungen\widerstand.h"
#include ".\lib\berechnungen\kondensator.h"
#include "./lib/berechnungen/spule.h"
#include "./lib/berechnungen/netzanalyse.h"


int main(void)
{

    Node* a = new Node("SQ1", 5, 4);
    Node* b = new Node("K1", 3.5, 2);
    Node* c = new Node("SP1", 1.5, 3);
    Node* d = new Node("W1", 2.1, 1);

    Node* e = new Node("SQ2", 100, 4);
    Node* f = new Node("K2", 3.5, 2);
    Node* g = new Node("Sp2", 1.5, 3);
    Node* h = new Node("W2", 2.3, 1);
    Node* i = new Node("K3", 2.5, 2);
    Node* j = new Node("SP3", 1.9, 3);
    Node* k = new Node("W3", 1.5, 1);
    Node* l = new Node("W4", 1.7, 1);
    Node* m = new Node("W5", 2.7, 1);
    Node* n = new Node("SQ3", 100, 4);

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
    testn.addNode(i);
    testn.addNode(j);
    testn.addNode(k);
    testn.addNode(l);
    testn.addNode(m);

    //test für widerstaende in reihe
    Graph info;
    info.addNode(a);
    info.addNode(d);
    info.addNode(h);
    info.addNode(k);
    info.addNode(l);

    Edge* sw1 = new Edge (*a , *d);
    Edge* w1w2 = new Edge (*d , *h);
    Edge* w2w3 = new Edge (*h , *k);
    Edge* w3w4 = new Edge (*k , *l);
    Edge* w4s = new Edge (*l , *a);

    info.addEdge(sw1);
    info.addEdge(w1w2);
    info.addEdge(w2w3);
    info.addEdge(w3w4);
    info.addEdge(w4s);

    //test für beliebige anordnung von widerstaenden
    Graph test;
    test.addNode(a); //s
    test.addNode(d); //r1
    test.addNode(h); //r2
    test.addNode(k); //r3
    test.addNode(l); //r4

    Edge* sr1 = new Edge(*a, *d);
    Edge* r1r2 = new Edge(*d, *h);
    Edge* r1r3 = new Edge(*d, *k);
    Edge* r2r4 = new Edge(*h, *l);
    Edge* r3r4 = new Edge(*k, *l);
    Edge* r4s = new Edge(*l , *a);

    test.addEdge(sr1);
    test.addEdge(r1r2);
    test.addEdge(r1r3);
    test.addEdge(r2r4);
    test.addEdge(r3r4);
    test.addEdge(r4s);

    Edge* line1 = new Edge(*h,*k);
    Edge* line2 = new Edge(*f,*i);
    Edge* line3 = new Edge(*j,*k);
    Edge* line4 = new Edge(*e,*k);
    testn.addEdge(line1);
    testn.addEdge(line2);
    testn.addEdge(line3);
    testn.addEdge(line4);

    baue(info);
    std::cout << "info zuende......" << std::endl;
    //test edge mit spannung
    double t7 = spannung(test);
    test.setwert(4,t7);
    baue(test);
    std::cout << "raus" << std::endl;




    //Test edge mit analyse
    std::cout << "mal gucken " << pot(line1) << std::endl;
    std::cout << "mal gucken " << pot(line2) << std::endl;
    std::cout << "mal gucken " << pot(line3) << std::endl;
    std::cout << std::endl << "break break" << std::endl;
    //std::cout << std::endl << "Das ist ein Wert aus Netz: \n" << netz.getNode() << std::endl;
    /*
    Node* container[11] = { 0 };
    container[11] = netz.getNode();

    std::cout << "Das ist der 3. Wert aus Netz: "<< container[2]->getValue() << std::endl;
    std::cout << "Das ist der 1. Wert aus Netz: "<< container[0]->getValue() << std::endl;
    std::cout << "Das ist der 4. Wert aus Netz: "<< container[3]->getValue() << std::endl;
    */
    //std::cout << "Das ist das vollstaendige Netz: \n" << netz.toString2() << std::endl;

    std::cout << "start von w_rs" << std::endl;
    std::cout << "Das Ergebnis der Reihenschaltung der Widerstaende aus testn ist: " << w_rs(test) << " Ohm" << std::endl;
    std::cout << "Das Ergebnis der Parallelschaltung der Widerstaende aus testn ist: " << w_ps(test)  << " Ohm" << std::endl;

/*
    std::cout << "das neu mit getwert fuer 1:  " << test.getwert("4") << std::endl;
    std::cout << "das neu mit getwert fuer Widerstand:  " << test.getwert("Widerstan1d") << std::endl;
*/
//test widerstand
    std::cout << std::endl << "break" << std::endl;
    double t1 = w_rs(test);
    double t2 = w_ps(test);
    std::cout << "das ist der W_Wert des netzes gesetzt mit dem Wert aus wrs: " << test.setwert(1, t1) << " Ohm" << std::endl;
    std::cout << "das ist der W_Wert des netzes gesetzt mit dem Wert aus wps: " << test.setwert(1, t2) << " Ohm" << std::endl;

//test ob Strom berechnet wird
    double t8 = strom(test);
    test.setwert(5,t8);
    std::cout << "strom: " << strom(test) << std::endl;
    std::cout << std::endl <<"TEST Der Strom: " << test.getwert("5") << " Amper"  << std::endl;

//test kondensator
 /*   std::cout << std::endl << "break" << std::endl;
    double t3 = k_rs(test);
    double t4 = k_ps(test);
    std::cout << "das ist der K_Wert des netzes gesetzt mit dem Wert aus krs: " << test.setwert(2, t3) << " Farad" << std::endl;
    std::cout << "das ist der K_Wert des netzes gesetzt mit dem Wert aus kps: " << test.setwert(2, t4) << " Farad" << std::endl;
*/
//test ob Strom berechnet wird
    testn.setwert(1,0);
    testn.setwert(3,0);
    double t9 = strom(testn);
    testn.setwert(5,t9);

//test spule
/*  std::cout << std::endl << "break" << std::endl;
    double t5 = s_rs(test);
    double t6 = s_ps(test);
    std::cout << "das ist der S_Wert des netzes gesetzt mit dem Wert aus srs: " << test.setwert(3, t5) << " Henry" << std::endl;
    std::cout << "das ist der S_Wert des netzes gesetzt mit dem Wert aus sps: " << test.setwert(3, t6) << " Henry" << std::endl;
*/
    double t10 = leistung(test);
    test.setwert(6,t10);

//test gesamt netzwerk
    std::cout << std::endl << "break" << std::endl;
    std::cout << "Das Netzwerk hat:" << std::endl;
    std::cout << "Den Widerstand: " << test.getwert("1") << " Ohm"  << std::endl;
    std::cout << "Den Kondensator: " << test.getwert("2") << " Farad"  << std::endl;
    std::cout << "Die Spule: " << test.getwert("3") << " Henry"  << std::endl;
    std::cout << "Die Spannungsquelle: " << test.getwert("4") << " Volt"  << std::endl;
    std::cout << "Die Stromstaerke: " << test.getwert("5") << " Amper"  << std::endl;
    std::cout << "Die Leistung: " << test.getwert("6") << " Watt"  << std::endl;

    //double as = netz.getNode()->getValue();
    //std::string ad = netz.getNode()->getName();

    //std::cout << "das ist : " << as << std::endl;
    //std::cout << "das ist : " << ad << std::endl;
/*
    std::cout << std::endl << "1" << std::endl << std::endl;

    std::cout << a->getID() << " vom Typ " << a->getType() << " hat den Wert " << a->getValue() << " und ist ein/e " << a->getName() << std::endl;
    std::cout << b->getID() << " vom Typ " << b->getType() << " hat den Wert " << b->getValue() << " und ist ein/e " << b->getName() << std::endl;
    std::cout << c->getID() << " vom Typ " << c->getType() << " hat den Wert " << c->getValue() << " und ist ein/e " << c->getName() << std::endl;
    std::cout << d->getID() << " vom Typ " << d->getType() << " hat den Wert " << d->getValue() << " und ist ein/e " << d->getName() << std::endl;
*/

    return 0;
}

