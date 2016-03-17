#ifndef NODE_H
#define NODE_H

#include <string>
#include <list>
class Edge;

class Node
{
public:

	Node() : m_id(generateId()), m_value(generateValue()), m_type(generateType()) { }

	Node(std::string id, double value, int type);

	const std::string& getID() const { return m_id; }

	std::list<Edge*>& getOutgoingEdges() { return m_outgoingEdges; }

	//Ergaenzungen
	const double getValue() const { return m_value; }

	const int getType() const { return m_type; }

	const std::string getName();


private:

	static std::string generateId();

	std::string m_id;

	static int s_numInstances;

	std::list<Edge*> m_outgoingEdges;

	//Ergaenzungen
	const double generateValue();

	double m_value;

	const int generateType();

	int m_type;

	std::string m_name;


};


#endif
