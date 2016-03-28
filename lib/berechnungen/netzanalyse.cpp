#include "netzanalyse.h"

double pot(Edge* line)
{
    std::cout << "start netzanalyse" << std::endl;
    double ausgabe = 0;

    double temp = 0;
    double temp1 = 0;
    Node start = line->getSrcNode();
    Node ende = line->getDstNode();
    int typ = start.getType();
    std::cout << "wert: " << start.getValue() << std::endl;
    std::cout << "wert: " << ende.getValue() << std::endl;
    if (typ == 1)
        {
            ausgabe = start.getValue() + ende.getValue();
        }
    else if (typ == 2)
        {
            temp = 1/start.getValue();
            temp1 = 1/ende.getValue();
            ausgabe = 1/(temp+temp1);
        }

    return ausgabe;
}

double baue (Graph netz)
{
    std::list<Node*> speicher_n = netz.getnodes();
    std::list<Edge*> speicher_e = netz.getedges();
    Node typ;
    Node typ2;
    int temp;

    for (std::list<Node*>::iterator it = speicher_n.begin(); it != speicher_n.end(); it++)
        {
            temp = (*it)->getType();

        }


    for (std::list<Edge*>::iterator it = speicher_e.begin(); it != speicher_e.end(); it++)
        {
            typ = (*it)->getDstNode();
            typ2 = (*it)->getSrcNode();
            std::cout << "das ist aus baue: " << (*it)->toString() << " T " << typ.getValue() << " nach " << typ2.getValue() << std::endl;
        }
        return 0;
}


double spannung(Graph netz)
{
    std::list<Node*> speicher_n = netz.getnodes();
    int temp;

    double spannung = 0;
    for (std::list<Node*>::iterator it = speicher_n.begin(); it != speicher_n.end(); it++)
        {
            temp = (*it)->getType();
            if ( temp == 4 )
            {
                spannung =+ (*it)->getValue();
                netz.setwert(4, spannung);
            }
        }
        return spannung;
}

double strom(Graph netz)
{
    double strom = 0;
    double wid = netz.getwert("1");
    double kap = netz.getwert("2");
    double ind = netz.getwert("3");
    double spa = netz.getwert("4");

    //SQ und Spule
    if  (wid == 0 && kap == 0)
        {
            std::cout << "treffer" << std::endl;
        }
    //SQ und Kondensator
    else if (wid == 0 && ind == 0)
        {
            strom = (kap*spa);
        }
    //SQ und Widerstand
    else if (kap == 0 && ind == 0)
        {
            strom = spa / wid;
        }

    //returnwert bleibt nicht, daher nochmaliges setzen in der main
    return netz.setwert(5,strom);
}

double leistung(Graph netz)
{
    double spa = netz.getwert("4");
    double strom = netz.getwert("5");
    double leistung = spa * strom;
    return leistung;
}
