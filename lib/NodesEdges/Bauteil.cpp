#include "Bauteil.h"


Bauteil::Bauteil(std::string id, double value, int type, int conntect_to)
{
  Node(id, value, type );
  m_conntect_to = conntect_to;
}
