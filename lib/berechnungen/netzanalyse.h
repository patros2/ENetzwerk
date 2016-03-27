#ifndef NETZANALYSE_H_INCLUDED
#define NETZANALYSE_H_INCLUDED

#include "../NodesEdges/Graph.h"
#include "../NodesEdges/Edge.h"
#include "../NodesEdges/Node.h"
#include <stdio.h>
#include <iostream>
#include <utility>
#include <vector>

double pot(Edge* line);
double baue(Graph netz);
double spannung(Graph netz);
double strom(Graph netz);
double leistung(Graph netz);


#endif // NETZANALYSE_H_INCLUDED
