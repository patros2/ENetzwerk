#include <stdio.h>
#include <iostream>

#include "widerstand.h"


double rs_wert = 0.0;
double ps_wert = 0.0;
double ms_wert = 0.0;

double w_rs(Graph netz)
{
    int typ;
    std::list<Node*> speicher = netz.getnodes();
    int i = 0;
    std::cout << "hier gehts rein" << std::endl;
	for (std::list<Node*>::iterator it = speicher.begin(); it != speicher.end(); it++)
	{
	    typ = (*it)->getType();
	    if (typ == 1)
            {
            i = i + 1;
            rs_wert += (*it)->getValue();
            std::cout << i << ".Wert: " << rs_wert << std::endl;
            }
	}


return rs_wert;
}

double w_ps(Graph netz)
{

std::list<Node*> speicher = netz.getnodes();
    int i = 0;
    double temp;
	for (std::list<Node*>::iterator it = speicher.begin(); it != speicher.end(); it++)
	{
	    i = i + 1;
		temp += 1/(*it)->getValue();

		std::cout << i << ".Wert: " << temp << std::endl;
	}
    ps_wert = 1/temp;


return ps_wert;
}

double w_ms(Graph* netz)
{

return ms_wert;
}


//test mit array
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

