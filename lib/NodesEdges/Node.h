#ifndef NODE_H
#define NODE_H

#include <string>
#include <list>
class Edge;

class Node
{
public:

	Node() : m_id(generateId()) { }

	Node(std::string id);

	const std::string& getID() const { return m_id; }

	std::list<Edge*>& getOutgoingEdges() { return m_outgoingEdges; }


private:

	static std::string generateId();

	std::string m_id;

	static int s_numInstances;

	std::list<Edge*> m_outgoingEdges;

};


#endif