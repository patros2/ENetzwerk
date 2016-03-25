#include <stdio.h>
#include <iostream>

#include "widerstand.h"


double wrs_wert = 0.0;
double wps_wert = 0.0;
double wms_wert = 0.0;

double w_rs(Graph netz)
{
    int typ = 0;
    double temp = 0;
    double temp1 = 0;
    std::list<Node*> speicher = netz.getnodes();
    int i = 0;
	for (std::list<Node*>::iterator it = speicher.begin(); it != speicher.end(); it++)
	{
	    typ = (*it)->getType();
	    if (typ == 1)
            {
            i = i + 1;
            temp1 = (*it)->getValue();
            temp += (*it)->getValue();
            wrs_wert = temp;
            std::cout << i << ".Wert wrs: " << temp1 << std::endl;
            }
	}


return wrs_wert;
}

double w_ps(Graph netz)
{
    int typ;
    std::list<Node*> speicher = netz.getnodes();
    int i = 0;
    double temp=0;
    double temp1=0;
	for (std::list<Node*>::iterator it = speicher.begin(); it != speicher.end(); it++)
	{
	    typ = (*it)->getType();
	    if (typ == 1)
        {
            i = i + 1;
            temp1 = (*it)->getValue();
            temp += 1/(*it)->getValue();

            std::cout << i << ".Wert wps: " << temp1 << std::endl;
        }
	}
    wps_wert = 1/temp;


return wps_wert;
}

double w_ms(Graph* netz)
{

return wms_wert;
}


//test mit array, wird vermutlich nicht gebraucht
/*
double berechnen(Node* a, Node* b, Node* c, Node* d){

    double wert = 0;
    double test = 0;
    int z = 0;
    std::string name;

    Node* masche [2][2] = {{a,b},{c,d}};
    Node* knoten [2][2] = {{a,b},{c,d}};


    for (int i=0;i<2;i++)
        {
        for (int j=0;j<2;j++)
            {
                z=z+1;
                test = masche[i][j]->getValue();
                name = masche[i][j]->getID();
                std::cout << z << " " << i << " " << j << " " << test << " " << name << std::endl;
                //printf("Lauf: %d, %d, %d, %f \n",z,i,j,test);
                //std::cout << name << std::endl;

            }
        }
    return wert;

}

*/
