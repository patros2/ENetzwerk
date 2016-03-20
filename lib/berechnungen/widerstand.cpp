#include <stdio.h>
#include <iostream>

#include "widerstand.h"


double rs_wert = 0.0;
double ps_wert = 0.0;
double ms_wert = 0.0;

double w_rs(Graph netz)
{

    std::list<Node*> speicher = netz.getnodes();
    int i = 0;
	for (std::list<Node*>::iterator it = speicher.begin(); it != speicher.end(); it++)
	{
	    i = i + 1;
		rs_wert += (*it)->getValue();
		//std::cout << i << ".Wert: " << rs_wert << std::endl;
	}

/*
    double eingabe[255];
    int i;
    for (i=0;i<10;i++)
        {
            //summe der Widerstaende
            rs_wert =+ eingabe[i];

        }
*/
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

