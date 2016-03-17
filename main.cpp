#include <stdio.h>
#include <iostream>
#include <string>
#include <time.h>
#include <typeinfo>


#include <yaml-cpp/yaml.h>
#include <docopt/docopt.h>


#ifdef _WIN32
    //#include "C:\Users\Ghostrider\Documents\GitHub\ENetzwerk\lib\NodesEdges\Node.h"
    //#include "C:\Users\Ghostrider\Documents\GitHub\ENetzwerk\lib\NodesEdges\Edge.h"
    //#include "C:\Users\Ghostrider\Documents\GitHub\ENetzwerk\lib\NodesEdges\Graph.h"
    //arbeitsverzeichnis
    #include "D:\ENetzwerk\lib\NodesEdges\Node.h"
    #include "D:\ENetzwerk\\lib\NodesEdges\Edge.h"
    #include "D:\ENetzwerk\\lib\NodesEdges\Graph.h"
#else
    #include "./lib/NodesEdges/Node.h"
    #include "./lib/NodesEdges/Graph.h"
#endif

static const char USAGE[] =
R"(ENetzwerk
    Usage:
      ENetzwerk yaml [-f config.yaml]
      ENetzwerk berechnen 
      ENetzwerk (-h | --help)
      ENetzwerk --version
    Options:
      -h --help     Show this screen.
      --version     Show version.
)";



static const char VERSION[] = "ENetzwerk 0.2";



Node* a = new Node("Spannungsquelle", 1.9, 1);
Node* b = new Node("Kondesator", 3.5, 0);
Node* c = new Node("Spule", 1.5, 2);
Node* d = new Node("Widerstand", 2.0, 3);
double wert = 0;
double test = 0;
int z = 0;
std::string name;
double berechnen(Node* a, Node* b, Node* c, Node* d){

    Node* masche [2][2] = {{a,b},{c,d}};
    Node* knoten [2][2] = {{a,b},{c,d}};


    for (int i=0;i<2;i++)
        {

        for (int j=0;j<2;j++)
            {
                z=z+1;
                test = masche[i][j]->getValue();
                name = masche[i][j]->getID();
                printf("Lauf: %d, %d, %d, %f \n",z,i,j,test);
                std::cout << name << std::endl;
            return wert;
            }
        }
}

int main(int argc, const char** argv)
{
    std::map<std::string, docopt::value> args = docopt::docopt(USAGE, 
                                                  { argv + 1, argv + argc },
                                                  true,               // show help if requested
                                                  VERSION);  // version string

    if (args["berechnen"].isBool() && args["berechnen"].asBool() == true ){
      berechnen(a,b,c,d);

    //printf("%f\n",berechnen(1,2,3,4));

      printf("1\n");
      std::cout << a->getID() << " vom Typ " << a->getType() << " hat den Wert " << a->getValue() << std::endl;
      std::cout << b->getID() << " vom Typ " << b->getType() << " hat den Wert " << b->getValue() << std::endl;
      std::cout << c->getID() << " vom Typ " << c->getType() << " hat den Wert " << c->getValue() << std::endl;
      std::cout << d->getID() << " vom Typ " << d->getType() << " hat den Wert " << d->getValue() << std::endl;

    }


    //std::cout << args["yaml"] << std::endl;
    if (args["yaml"].isBool() && args["yaml"].asBool() == true ){
      YAML::Node config = YAML::LoadFile("config.yaml");


      if (config["name"]) {
        

        //std::cout << "Last logged in: " << paramter << "\n";

        std::cout << typeid(config["name"].as<std::string>()).name() << std::endl;
       // Node* node1  = new Node(config["name"].as<std::string>());
       // Node* node2 = new Node(config["name2"].as<std::string>());
        //Node* node3 = new Node(config["name3"].as<std::string>());

        //Graph g;
        //g.addNode(node1);
        //g.addNode(node2);
        //g.addNode(node3);
       
        //g.addEdge(new Edge(*node1, *node2));
        //g.addEdge(new Edge(*node1, *node3)); 
        //g.addEdge(new Edge(*node3, *node2)); 
       
        //std::cout << g.toString() << std::endl;
     
      }
    }

    return 0;
}

