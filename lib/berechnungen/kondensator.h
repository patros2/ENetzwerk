#ifndef KONDENSATOR_H_INCLUDED
#define KONDENSATOR_H_INCLUDED

#include "../NodesEdges/Graph.h"
#include <stdio.h>
#include <iostream>

double k_rs(Graph netz);

double k_ps(Graph netz);

double k_ms(Graph* netz);



#endif // KONDENSATOR_H_INCLUDED
