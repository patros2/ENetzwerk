#include <stdio.h>
#include <iostream>
#include <string>
#include <time.h>
#include <typeinfo>
#include <deque>

#include "./lib/yaml-cpp-master/include/yaml-cpp/yaml.h" 
#include "./lib/docopt.cpp-master/docopt.h" 
#include "./lib/NodesEdges/Node.h" 
#include "./lib/NodesEdges/Graph.h"

using namespace std;




static const char USAGE[] =
R"(ENetzwerk
    Usage:
      ENetzwerk yaml 
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
 //  Node* knoten [2][2] = {{a,b},{c,d}};


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
return 0;
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

      Graph g;
      
      if (config.IsMap()){
	    std::cout << "Map: True" << std::endl;
      }
      if (config.IsScalar()){
	    std::cout << "Scalar: True" << std::endl;
      }
      if (config.IsSequence()){
	    std::cout << "Scalar: True" << std::endl;
      }
      //

 
        deque<Node*> network;
      // going through all elements in the YAMLK::Nodes object
      for (YAML::const_iterator it=config.begin();it!=config.end();it++)
 	  {
        if (it->IsSequence()){
	      std::cout << "Scalar:Loop True" << std::endl;

          // We have a object with n items, need to loop through
          // not nice code, loop in a loop in a loopception....
          std::cout << it->size()<< std::endl;
          int name=0;
          int id=1;
          int conntect_to=2;
          int value=3;

          Node* node = new Node(
                 (*it)[name].as<std::string>(),
                 (*it)[id].as<int>(), 
                 (*it)[value].as<int>());

          g.addNode(node);
          if ((*it)[conntect_to].as<int>() == (*it)[id].as<int>() )
          {
            g.addEdge(new Edge(*node, *node));
          }
          network.push_back(node);

          if (it->size() > 1)
          {
            std::cout << (*it)[0].as<char>() << "\n";
            // The last 3 are ints 

            for (std::size_t i=1;i<it->size();i++) 
            {
             std::cout << (*it)[i].as<int>() << "\n";
            }
          } 
          
        }
        if (it->IsMap()){
	      std::cout << "Map:Loop True" << std::endl;
        }
        if (it->IsScalar()){
	      std::cout << "Scalar: True" << std::endl;
        }

       
        // std::cout << it->first.as<std::string>() << std::endl; 
        // std::cout << "Last logged in: " << config[it->first.as<std::string>()] << "\n";
        std::cout << "Test"<<std::endl;

        //  Node* node1  = new Node(it->first.as<std::string>(), 1, 1);
        //  g.addNode(node1);

     }
      for (size_t node_n = 0; node_n < network.size();node_n++)
      {
        cout << network[node_n] <<endl;
      }
        
       std::cout << g.toString() << std::endl;

       //std::cout << "Last logged in: " << config["name"].as<std::string>() << "\n";

       // std::cout << typeid(config["name"].as<std::string>()).name() << std::endl;
       // Node* node1  = new Node(config["name"].as<std::string>(), , );
       // Node* node2 = new Node(config["name2"].as<std::string>());
        //Node* node3 = new Node(config["name3"].as<std::string>());

        //Graph g;
       // g.addNode(node1);

       
        //std::cout << g.toString() << std::endl;
     
    }

    return 0;
}

