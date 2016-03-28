#include "netzanalyse.h"
//rechnet aus einer edge beide knoten zusammen
double pot(Edge* line, int typ)
{
    //std::cout << "start netzanalyse" << std::endl;
    double ausgabe = 0;

    double temp = 0;
    double temp1 = 0;
    Node start = line->getSrcNode();
    Node ende = line->getDstNode();
    int bt = start.getType();
    //std::cout << "wert: " << start.getValue() << std::endl;
    //std::cout << "wert: " << ende.getValue() << std::endl;
    //typ=reihenschaltung , bauteil=widerstand oder spule
    if (typ == 1 && (bt == 1|| bt == 3))
        {
            ausgabe = start.getValue() + ende.getValue();
        }
    //typ=reihenschaltung , bauteil = kondensator
    else if (typ == 1 && bt == 2)
        {
            temp = 1/start.getValue();
            temp1 = 1/ende.getValue();
            ausgabe = 1/(temp+temp1);
        }
    //typ = parallelschaltung , bauteil = widerstand oder spule
    else if (typ == 2 && (bt == 1||bt == 3))
        {
            temp = 1/start.getValue();
            temp1 = 1/ende.getValue();
            ausgabe = 1/(temp+temp1);
        }
    //typ = parallelschaltung , bauteil = kondesantor
    else if (typ == 2 && bt == 2)
        {
            ausgabe = start.getValue() + ende.getValue();
        }

    return ausgabe;
}

double baue (Graph netz)
{
    std::list<Node*> speicher_n = netz.getnodes();
    std::list<Edge*> speicher_e = netz.getedges();
    Node src,src2;
    Node dst,dst2;
    std::string src_n, src2_n;
    std::string dst_n, dst2_n;
    int temp = 99;
    int i = 0;
    int tiefe = 0;
    std::vector<std::pair<Edge*, int>> vec;
    std::vector<std::pair<Edge*, int>> vec_fertig;
    std::cout << "setze alle edges mit sq am anfang auf tiefe 0" << std::endl;
    for (std::list<Edge*>::iterator it = speicher_e.begin(); it != speicher_e.end(); it++)
        {
            dst = (*it)->getDstNode();
            src = (*it)->getSrcNode();
            Edge* lane = (*it);
            temp = src.getType();
            std::cout << "typ: " << src.getType() << std::endl;
            if (temp == 4)
                {
                    tiefe = 0;
                }

            vec.push_back(std::pair<Edge*, int>(lane, tiefe));
            double a = vec[0].first->getDstNode().getValue();
            std::cout << "Edge: " << vec[i].first <<" Tiefe: "<<vec[i].second<<std::endl;
            std::cout << "das ist aus baue: " << (*it)->toString() << " T " << src.getValue() << " nach " << dst.getValue() << std::endl;
            i = i+1;
        }

    std::cout << "bearbeite edges mit tiefe 0" << std::endl;
    for (std::vector<std::pair<Edge*, int>>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        tiefe = (*it).second;
        src = (*it).first->getSrcNode();
        dst = (*it).first->getDstNode();
        src_n = src.getName();
        dst_n = dst.getName();
        Edge* lane;
        if(tiefe == 0)
            {
                std::cout << "es ist ein: " << src.getName() << " und ein " << dst.getName() << std::endl;

            for (std::vector<std::pair<Edge*, int>>::iterator it = vec.begin(); it != vec.end(); it++)
                {
                    src2 = (*it).first->getSrcNode();
                    dst2 = (*it).first->getDstNode();
                    src2_n = src2.getName();
                    dst2_n = dst2.getName();
                    //std::cout << "problem?" << std::endl;
                    if (dst_n == src2_n)
                        {
                            lane = (*it).first;

                      //      std::cout << "test?" << std::endl;
                            vec_fertig.push_back(std::pair<Edge*, int>(lane, tiefe+1));
                        }
                }
            }
        std::cout << "drin " << tiefe << std::endl;
    }

i=0;
std::cout << "letztes" << std::endl;
for (std::vector<std::pair<Edge*, int>>::iterator it = vec_fertig.begin(); it != vec_fertig.end(); it++)
    {
        tiefe = (*it).second;
        src = (*it).first->getSrcNode();
        dst = (*it).first->getDstNode();
        src_n = src.getName();
        dst_n = dst.getName();
        Edge* lane;
        if(tiefe == 1)
            {
                std::cout << "es ist ein: " << src.getName() << " und ein " << dst.getName() << std::endl;
            }
    }
    return 0;
}


double spannung(Graph netz)
{
    std::list<Node*> speicher_n = netz.getnodes();
    int temp;

    double spannung = 0;
    double spannung_temp = 0;
    for (std::list<Node*>::iterator it = speicher_n.begin(); it != speicher_n.end(); it++)
        {
            temp = (*it)->getType();
            if ( temp == 4 )
            {
                spannung_temp = (*it)->getValue();
                spannung = spannung + spannung_temp;
                netz.setwert(4, spannung);
                std::cout << "drin " << spannung << std::endl;
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
            strom = spa/ind;
        }
    //SQ und Kondensator
    else if (wid == 0 && ind == 0)
        {

            strom = kap*spa;
        }
    //SQ und Widerstand
    else if (kap == 0 && ind == 0)
        {
            strom = spa/wid;
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

double gesamtwert(Graph netz)
{
    int temp;
    double temp2;
    double wert;
    std::list<Node*>nodes = netz.getnodes();
    for (std::list<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++)
        {
            temp = (*it)->getType();
            if (temp == 1 || temp == 2 || temp == 3)
            {
                temp2 = (*it)->getValue();
                wert = temp2;
            }
        }

    return wert;
}

//
int gesamttyp(Graph netz)
{
    int temp;

    int wert;
    std::list<Node*>nodes = netz.getnodes();
    for (std::list<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++)
        {
            temp = (*it)->getType();
            if (temp == 1 || temp == 2 || temp == 3)
            {
                wert = temp;
            }
        }

    return wert;
}
