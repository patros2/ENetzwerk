#include "Node.h"

#include <sstream>
#include <iomanip>
#include <cctype> // für isalnum() (siehe http://www.cplusplus.com/reference/cctype/isalnum/?kw=isalnum)

int Node::s_numInstances = 0;


std::string Node::generateId()
{
	std::stringstream s;
	s << "Node_" << std::setw(4) << std::setfill('0') << s_numInstances;
	return s.str();
}


Node::Node(std::string id, double value, int type) : m_id(id), m_value(value), m_type(type)
{
	s_numInstances += 1;
}

//Ergaenzungen

const double Node::generateValue()
{
    return 0;
}

const int Node::generateType()
{
    return 1;
}

const std::string Node::getName()
{
    switch(m_type)
    {
        case 1: m_name="Widerstand";        return m_name; break;
        case 2: m_name="Kondensator";       return m_name; break;
        case 3: m_name="Spule";             return m_name; break;
        case 4: m_name="Spannungsquelle";   return m_name; break;
    }

}
