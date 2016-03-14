#include "Graph.h"


//-------------------------------------------------------------------------------------------------

Graph::~Graph()
{

	for (std::list<Node*>::iterator it = m_nodes.begin(); it != m_nodes.end(); it++)
	{
		//Node* currentNode = *it;
		//delete currentNode;
		delete *it;
	}

	for (std::list<Edge*>::iterator it = m_edges.begin(); it != m_edges.end(); it++)
	{
		delete *it;
	}

}


//-------------------------------------------------------------------------------------------------

void Graph::addNode(Node* pNode)
{
	m_nodes.push_back(pNode);
}


//-------------------------------------------------------------------------------------------------

void Graph::addEdge(Edge* pEdge)
{
	m_edges.push_back(pEdge);
	pEdge->getSrcNode().getOutgoingEdges().push_back(pEdge);
}


//-------------------------------------------------------------------------------------------------

void Graph::deleteNode(Node* pNode)
{
	for (std::list<Edge*>::iterator it = m_edges.begin(); it != m_edges.end(); )
	{
		Edge* pCurrentEdge = *it;

		// der Node ist Source-Node der aktuellen Kante
		if (&pCurrentEdge->getSrcNode() == pNode)
		{
			it = m_edges.erase(it);
			delete pCurrentEdge;
		}
		// der Node ist Destination-Node der aktuellen Kante
		else if (&pCurrentEdge->getDstNode() == pNode)
		{
			pCurrentEdge->getSrcNode().getOutgoingEdges().remove(pCurrentEdge);
			it = m_edges.erase(it);
			delete pCurrentEdge;
		}
		// nichts tun, weiter zum nächsten Element
		else
		{
			it++;
		}
	}

	m_nodes.remove(pNode);
	delete pNode;

}


//-------------------------------------------------------------------------------------------------

void Graph::deleteEdge(Edge* pEdge)
{
	pEdge->getSrcNode().getOutgoingEdges().remove(pEdge);
	m_edges.remove(pEdge);
	delete pEdge;
}


//-------------------------------------------------------------------------------------------------

std::string Graph::toString()
{
	std::string result;

	for (std::list<Edge*>::iterator it = m_edges.begin(); it != m_edges.end(); it++)
	{
		result += (*it)->toString() + "\n";
	}

	return result;
}


//-------------------------------------------------------------------------------------------------
