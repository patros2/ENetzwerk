#include <stdio.h>
#include <iostream>

#include "spule.h"


double srs_wert = 0.0;
double sps_wert = 0.0;
double sms_wert = 0.0;

double s_rs(Graph netz)
{
    int typ = 0;
    double temp = 0;
    double temp1 = 0;
    std::list<Node*> speicher = netz.getnodes();
    int i = 0;
	for (std::list<Node*>::iterator it = speicher.begin(); it != speicher.end(); it++)
	{
	    typ = (*it)->getType();
	    if (typ == 3)
            {
            i = i + 1;
            temp1 = (*it)->getValue();
            temp += (*it)->getValue();
            srs_wert = temp;
            std::cout << i << ".Wert srs: " << temp1 << std::endl;
            }
	}


return srs_wert;
}

double s_ps(Graph netz)
{
    int typ;
    std::list<Node*> speicher = netz.getnodes();
    int i = 0;
    double temp=0;
    double temp1=0;
	for (std::list<Node*>::iterator it = speicher.begin(); it != speicher.end(); it++)
	{
	    typ = (*it)->getType();
	    if (typ == 3)
        {
            i = i + 1;
            temp1 = (*it)->getValue();
            temp += 1/(*it)->getValue();

            std::cout << i << ".Wert sps: " << temp1 << std::endl;
        }
	}
    sps_wert = 1/temp;


return sps_wert;
}

double s_ms(Graph* netz)
{

return sms_wert;
}

