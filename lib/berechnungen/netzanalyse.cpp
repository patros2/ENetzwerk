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
