#ifndef BAUTEIL_H
#define BAUTEIL_H

#include "Node.h"
#include <string>

class Bauteil : public Node
{

public:
 Bauteil(
        std::string id,
        double value, 
        int type,
        int root, 
        int conntect_to
        );

 int getConnection(){ return m_conntect_to;}
 int getRoot(){ return m_root;}


private:
   int m_conntect_to;
   int m_root;
    
};

#endif
