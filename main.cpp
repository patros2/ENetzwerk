#include ".\lib\NodesEdges\Edge.h"
#include ".\lib\NodesEdges\Node.h"
#include ".\lib\NodesEdges\Graph.h"
#include ".\lib\berechnungen\widerstand.h"
#include ".\lib\berechnungen\kondensator.h"
#include "./lib/berechnungen/spule.h"
#include "./lib/berechnungen/netzanalyse.h"


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
    Node* i = new Node("Kondesator", 2.5, 2);
    Node* j = new Node("Spule", 1.9, 3);
    Node* k = new Node("Widerstand", 1.7, 1);

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

    Edge* line1 = new Edge(*h,*k);
    Edge* line2 = new Edge(*f,*i);
    testn.addEdge(line1);
    testn.addEdge(line2);

    //Test edge mit analyse
    std::cout << "mal gucken " << pot(line1) << std::endl;
    std::cout << "mal gucken " << pot(line2) << std::endl;
    std::cout << std::endl << "break break" << std::endl;
    //std::cout << std::endl << "Das ist ein Wert aus Netz: \n" << netz.getNode() << std::endl;
    /*
    Node* container[11] = { 0 };
    container[11] = netz.getNode();

    std::cout << "Das ist der 3. Wert aus Netz: "<< container[2]->getValue() << std::endl;
    std::cout << "Das ist der 1. Wert aus Netz: "<< container[0]->getValue() << std::endl;
    std::cout << "Das ist der 4. Wert aus Netz: "<< container[3]->getValue() << std::endl;
    */
    std::cout << "Das ist das vollstaendige Netz: \n" << netz.toString2() << std::endl;

    std::cout << "start von w_rs" << std::endl;
    std::cout << "Das Ergebnis der Reihenschaltung der Widerstaende aus testn ist: " << w_rs(testn) << " Ohm" << std::endl;
    std::cout << "Das Ergebnis der Parallelschaltung der Widerstaende aus testn ist: " << w_ps(testn)  << " Ohm" << std::endl;


    std::cout << "das neu mit getwert fuer 1:  " << testn.getwert("3") << std::endl;
    std::cout << "das neu mit getwert fuer Widerstand:  " << testn.getwert("Widerstan1d") << std::endl;

//test widerstand
    std::cout << std::endl << "break" << std::endl;
    double t1 = w_rs(testn);
    double t2 = w_ps(testn);
    std::cout << "das ist der W_Wert des netzes gesetzt mit dem Wert aus wrs: " << testn.setwert(1, t1) << " Ohm" << std::endl;
    std::cout << "das ist der W_Wert des netzes gesetzt mit dem Wert aus wps: " << testn.setwert(1, t2) << " Ohm" << std::endl;
//test kondensator
    std::cout << std::endl << "break" << std::endl;
    double t3 = k_rs(testn);
    double t4 = k_ps(testn);
    std::cout << "das ist der K_Wert des netzes gesetzt mit dem Wert aus krs: " << testn.setwert(2, t3) << " Farad" << std::endl;
    std::cout << "das ist der K_Wert des netzes gesetzt mit dem Wert aus kps: " << testn.setwert(2, t4) << " Farad" << std::endl;

//test spule
    std::cout << std::endl << "break" << std::endl;
    double t5 = s_rs(testn);
    double t6 = s_ps(testn);
    std::cout << "das ist der S_Wert des netzes gesetzt mit dem Wert aus srs: " << testn.setwert(3, t5) << " Henry" << std::endl;
    std::cout << "das ist der S_Wert des netzes gesetzt mit dem Wert aus sps: " << testn.setwert(3, t6) << " Henry" << std::endl;


//test gesamt netzwerk
    std::cout << std::endl << "break" << std::endl;
    std::cout << "Das Netzwerk hat:" << std::endl;
    std::cout << "Den Widerstand: " << testn.getwert("1") << " Ohm"  << std::endl;
    std::cout << "Den Kondensator: " << testn.getwert("2") << " Farad"  << std::endl;
    std::cout << "Die Spule: " << testn.getwert("3") << " Henry"  << std::endl;
    std::cout << "Die Spannungsquelle: " << testn.getwert("4") << " Volt"  << std::endl;
    std::cout << "Die Stromstaerke: " << testn.getwert("5") << " Amper"  << std::endl;

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

