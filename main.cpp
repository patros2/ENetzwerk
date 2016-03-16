#include <iostream>
#include <string>
#include <time.h>

#include <typeinfo>

#include <yaml-cpp/yaml.h>
#include <docopt/docopt.h>

#include "./lib/NodesEdges/Node.h"
#include "./lib/NodesEdges/Graph.h"


//using namespace std;


static const char USAGE[] =
R"(ENetzwerk

    Usage:
      ENetzwerk yaml 
      ENetzwerk (-h | --help)
      ENetzwerk --version

    Options:
      -h --help     Show this screen.
      --version     Show version.
)";


static const char VERSION[] = "ENetzwerk 0.1";


int main(int argc, const char** argv)
{


    std::map<std::string, docopt::value> args = docopt::docopt(USAGE, 
                                                  { argv + 1, argv + argc },
                                                  true,               // show help if requested
                                                  VERSION);  // version string

// print
//    for(auto const& arg : args) {
//        std::cout << arg.first << ": " << arg.second << std::endl;
//    } 



    std::cout << args["yaml"] << std::endl;
    if (args["yaml"].isBool() && args["yaml"].asBool() == true ){
      YAML::Node config = YAML::LoadFile("config.yaml");


      if (config["name"]) {
        

        //std::cout << "Last logged in: " << paramter << "\n";

        std::cout << typeid(config["name"].as<std::string>()).name() << std::endl;
        Node* node1  = new Node(config["name"].as<std::string>());
        Node* node2 = new Node(config["name2"].as<std::string>());
        Node* node3 = new Node(config["name3"].as<std::string>());

        Graph g;
        g.addNode(node1);
        g.addNode(node2);
        g.addNode(node3);
       
        g.addEdge(new Edge(*node1, *node2));
        g.addEdge(new Edge(*node1, *node3)); 
        g.addEdge(new Edge(*node3, *node2)); 
       
        std::cout << g.toString() << std::endl;
     

      }

    
    }





    return 0;
}
