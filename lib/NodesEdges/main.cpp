#include <iostream>

#include "Node.h"
#include "Graph.h"


#include <typeinfo>


int main()
{
        std::string Test = "Berlin";
       
        std::cout << typeid(Test).name() << std::endl;

	Node* node_berlin = new Node(Test);
	Node* node_frankfurt = new Node("Frankfurt");
	Node* node_hamburg = new Node("Hamburg");

	Graph g;
	g.addNode(node_berlin);
	g.addNode(node_frankfurt);
	g.addNode(node_hamburg);

	g.addEdge(new Edge(*node_berlin, *node_frankfurt));
	g.addEdge(new Edge(*node_frankfurt, *node_hamburg));
	g.addEdge(new Edge(*node_berlin, *node_hamburg));

	std::cout << g.toString() << std::endl;

	return 0;
}



