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


private:


	std::list<Edge*> m_edges;
    std::list<Node*> m_nodes;
};


#endif
