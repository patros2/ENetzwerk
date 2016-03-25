#include <stdio.h>
#include <iostream>

#include "kondensator.h"


double krs_wert = 0.0;
double kps_wert = 0.0;
double kms_wert = 0.0;



double k_rs(Graph netz)
{
    int typ;
    std::list<Node*> speicher = netz.getnodes();
    int i = 0;
    double temp = 0;
    double temp1 = 0;
	for (std::list<Node*>::iterator it = speicher.begin(); it != speicher.end(); it++)
	{
	    typ = (*it)->getType();
	    if (typ == 2)
        {
            i = i + 1;
            temp1 = (*it)->getValue();
            temp += 1/(*it)->getValue();

            std::cout << i << ".Wert krs: " << temp1 << std::endl;
        }
	}
    krs_wert = 1/temp;


return krs_wert;
}

double k_ps(Graph netz)
{
    int typ = 0;
    double temp = 0;
    double temp1 = 0;
    std::list<Node*> speicher = netz.getnodes();
    int i = 0;
	for (std::list<Node*>::iterator it = speicher.begin(); it != speicher.end(); it++)
	{
	    typ = (*it)->getType();
	    if (typ == 2)
            {
            i = i + 1;
            temp1 = (*it)->getValue();
            temp += (*it)->getValue();
            kps_wert = temp;
            std::cout << i << ".Wert kps: " << temp1 << std::endl;
            }
	}


return kps_wert;
}

double k_ms(Graph* netz)
{

return kms_wert;
}
