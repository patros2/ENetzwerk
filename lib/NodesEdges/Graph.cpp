#include "Graph.h"


//-------------------------------------------------------------------------------------------------

Graph::~Graph()
{
    //rausgenommen, da sonst bei testnetz graph, nen fehler passiert
    /*
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
*/
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
std::string Graph::toString2()
{
	std::string result;

	for (std::list<Node*>::iterator it = m_nodes.begin(); it != m_nodes.end(); it++)
	{
		result += (*it)->getID() + "\n";
	}

	return result;
}

//-------------------------------------------------------------------------------------------------
//Prototyp, kann vermutlich weg
Node* Graph::getNode()
{
    printf("WAS?");
    Node* result[255];
    int i = 0;
    printf("\nWelcome to GetNode: \n");
//    std::cout << std::endl << "Welcome to GetNode: " << std::endl;
    for (std::list<Node*>::iterator it = m_nodes.begin(); it != m_nodes.end(); it++)
	{
	    i =+1;
		result[i] = (*it);
		printf("%f\n",result[i]->getValue());
	}
    printf("%s\n",typeid(result[7]).name() );
    return *result;
}

//-------------------------------------------------------------------------------------------------
double Graph::getwert(std::string was)
{
double wert;
if (was == "Widerstand" | was == "widerstand" | was == "1" | was == "W" | was == "w")
    {
        wert = m_widerstand;
    }
else if (was == "Kapazitaet" | was == "kapazitaet" | was == "2" | was == "K" | was == "k")
    {
        wert = m_kapazitaet;
    }
else if (was == "Induktivitaet" | was == "induktivitaet" | was == "3" | was == "SP" | was == "sp")
    {
        wert = m_induktivitaet;
    }
else if (was == "Spannung" | was == "spannung" | was == "4" | was == "SQ" | was == "sq")
    {
        wert = m_spannung;
    }
else if (was == "Stromstaerke" | was == "stromstaerke" | was == "5" | was == "S" | was == "s")
    {
        wert = m_stromstaerke;
    }
else if (was == "Leistung" | was == "leistung" | was == "6" | was == "L" | was == "l")
    {
        wert = m_leistung;
    }
else
    {
        wert = 0;
    }
return wert;
}
//-------------------------------------------------------------------------------------------------
double Graph::setwert(int was, double wert)
{
    switch(was)
    {
        case 1: m_widerstand = wert; break;
        case 2: m_kapazitaet = wert; break;
        case 3: m_induktivitaet = wert; break;
        case 4: m_spannung = wert; break;
        case 5: m_stromstaerke = wert; break;
        case 6: m_leistung = wert; break;
    }
    return wert;
}
