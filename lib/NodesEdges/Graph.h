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

	virtual ~Graph();


private:

	std::list<Node*> m_nodes;
	std::list<Edge*> m_edges;

};


#endif