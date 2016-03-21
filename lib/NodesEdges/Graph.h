#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <string>

#include "Node.h"
#include "Edge.h"


class Graph
{

public:

	void addNode(Node* pNode);

	void addEdge(Edge* pEdge);

	void deleteNode(Node* pNode);

	void deleteEdge(Edge* pEdge);

	std::string toString();

    std::string toString2();

	virtual ~Graph();

    //std::list<Node*> getNode();
    Node* getNode();

    const std::list<Node*> getnodes() const { return m_nodes; }

    const double getwid() const {return m_widerstand;}
    const double getspa() const {return m_spannung;}
    const double getind() const {return m_induktivitaet;}
    const double getkap() const {return m_kapazitaet;}
    const double getstrom() const {return m_stromstaerke;}



private:


	std::list<Edge*> m_edges;
    std::list<Node*> m_nodes;

    double m_widerstand = 1;
    double m_spannung = 2;
    double m_induktivitaet = 3;
    double m_kapazitaet = 4;
    double m_stromstaerke = 5;
};


#endif
