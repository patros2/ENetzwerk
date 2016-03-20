#include "../NodesEdges/Graph.h"

#ifndef WIDERSTAND_H_INCLUDED
#define WIDERSTAND_H_INCLUDED



double w_rs(Graph netz);

double w_ps(Graph netz);

double w_ms(Graph* netz);

double berechnen(Node* a, Node* b, Node* c, Node* d);






#endif // WIDERSTAND_H_INCLUDED
