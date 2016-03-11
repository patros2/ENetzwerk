#ifndef EDGE_H
#define EDGE_H

#include <string>

#include "Node.h"


class Edge
{
public:

	Edge(Node& rSrc, Node& rDst) : m_srcNode(rSrc), m_dstNode(rDst)  {  }

	std::string toString() { return m_srcNode.getID() + " -> " + m_dstNode.getID(); }

	Node& getSrcNode() { return m_srcNode; }
	Node& getDstNode() { return m_dstNode; }


private:

	Node& m_srcNode;
	Node& m_dstNode;

};


#endif