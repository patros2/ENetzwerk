#include "Node.h"

#include <sstream>
#include <iomanip>
#include <cctype> // für isalnum() (siehe http://www.cplusplus.com/reference/cctype/isalnum/?kw=isalnum)

int Node::s_numInstances = 0;


std::string Node::generateId()
{
	std::stringstream s;
	s << "Node_" << std::setw(1) << std::setfill('0') << s_numInstances;
	return s.str();
}


Node::Node(std::string id, double value, int type) : m_id(id), m_value(value), m_type(type)
{
	s_numInstances += 1;
}

//Ergaenzungen

double Node::generateValue()
{
    return 0;
}

int Node::generateType()
{
    return 1;
}

