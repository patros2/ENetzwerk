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
#include "./lib/NodesEdges/Bauteil.h"

using namespace std;

int main(void)
{

    Node* a = new Node("Spannungsquelle", 1.9, 4);
    Node* b = new Node("Kondesator", 3.5, 2);
    Node* c = new Node("Spule", 1.5, 3);
    Node* d = new Node("Widerstand", 2.1, 1);

    Node* e = new Node("Spannungsquelle", 1.9, 4);
    Node* f = new Node("Kondesator", 3.5, 2);
    Node* g = new Node("Spule", 1.5, 3);
    Node* h = new Node("Widerstand", 2.3, 1);

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

Graph netz;
    netz.addNode(a);
    netz.addNode(b);
    netz.addNode(c);
    netz.addNode(d);

    Graph testn;
    testn.addNode(e);
    testn.addNode(f);
    testn.addNode(g);
    testn.addNode(h);

    std::cout << std::endl << "Das ist ein Wert aus Netz: \n" << netz.getNode() << std::endl;
/*
    Node* container[11] = { 0 };
    container[11] = netz.getNode();

    std::cout << "Das ist der 3. Wert aus Netz: "<< container[2]->getValue() << std::endl;
    std::cout << "Das ist der 1. Wert aus Netz: "<< container[0]->getValue() << std::endl;
    std::cout << "Das ist der 4. Wert aus Netz: "<< container[3]->getValue() << std::endl;
*/
    std::cout << std::endl << "Das ist das vollstaendige Netz: \n" << netz.toString2() << std::endl;

    //berechnen(a,b,c,d);
    std::cout << "Ende von berechnen, start von rs" << std::endl;
    std::cout << "Das Ergebnis der Reihenschaltung der Widerstaende aus testn ist: " << w_rs(testn) << " Ohm" << std::endl;
    std::cout << "Das Ergebnis der Parallelschaltung der Widerstaende aus testn ist: " << w_ps(testn)  << " Ohm" << std::endl;
    std::cout << "das ist der Widerstand des Netzwerks normal: " << testn.getwid() << std::endl;
    std::cout << "das ist die Kapazitaet des Netzwerks normal: " << testn.getkap() << std::endl;
    std::cout << "das ist die Spannung des Netzwerks normal: " << testn.getspa() << std::endl;
    std::cout << "das ist die Induktivitaet des Netzwerks normal: " << testn.getind() << std::endl;
    std::cout << "das ist die Stromstaerke des Netzwerks normal: " << testn.getstrom() << std::endl;

    //double as = netz.getNode()->getValue();
    //std::string ad = netz.getNode()->getName();

    //std::cout << "das ist : " << as << std::endl;
    //std::cout << "das ist : " << ad << std::endl;

    std::cout << std::endl << "1" << std::endl << std::endl;
using namespace std;
    std::cout << a->getID() << " vom Typ " << a->getType() << " hat den Wert " << a->getValue() << " und ist ein/e " << a->getName() << std::endl;
    std::cout << b->getID() << " vom Typ " << b->getType() << " hat den Wert " << b->getValue() << " und ist ein/e " << b->getName() << std::endl;
    std::cout << c->getID() << " vom Typ " << c->getType() << " hat den Wert " << c->getValue() << " und ist ein/e " << c->getName() << std::endl;
    std::cout << d->getID() << " vom Typ " << d->getType() << " hat den Wert " << d->getValue() << " und ist ein/e " << d->getName() << std::endl;

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

 
        deque<Bauteil*> network;
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

          Bauteil* node = new Bauteil(
                 (*it)[name].as<std::string>(),
                 (*it)[id].as<int>(), 
                 (*it)[value].as<int>(),
                 (*it)[conntect_to].as<int>()
          );

          g.addNode(node);
    
          //if ((*it)[conntect_to].as<int>() == (*it)[id].as<int>() )
          //{
          //  g.addEdge(new Edge(*node, *node));
          //}
          network.push_back(node);

          if (it->size() > 1)
          {
            std::cout << (*it)[0].as<char>() << "\n";
            // The last 3 are ints 

            for (std::size_t i=1;i<it->size();i++) 
            {
             cout << "Here" << endl;
             cout << (*it)[i].as<int>() << "\n";
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
      // We have an arry with the objects. will access into the each
      // of them to ensure that they:
      // are equal or bigger than zero or they beginning one
      // Maybe we should auto generate an ID for each object?
      for (size_t node_n = 0; node_n < network.size();node_n++)
      {
        cout << "DEBUG:" << node_n << endl;
        cout << network[node_n]<< " "<< network[node_n]->getConnection() <<endl;
        // When the loop is over we need to stop accessing node_n -1 else it end's in a segfault
        cout << "DEBUG: network.size()" << network.size() << endl;
        if ( node_n  +1 < network.size()  && network[node_n]->getConnection() == network[node_n + 1]->getType())
        { 
         cout << "DEBUG: node_n -1:"<< (node_n + 1) << endl ;
         cout << "DEBUG: add Node:" << node_n << " and Node" << node_n + 1 << endl;
         Node*  test= dynamic_cast<Node*>( network[node_n] );
         Node*  test2= dynamic_cast<Node*>( network[node_n +1] );
         // downcasting
         g.addEdge(new Edge(*test, *test2));
         
        }
       //end conenction
        if ( network[node_n]->getConnection() == 0 )
        {
         Node*  test= dynamic_cast<Node*>( network[node_n] );
         Node*  test2= dynamic_cast<Node*>( network[0] );
         g.addEdge(new Edge(*test, *test2));
         cout << "here" << endl;
        }

       cout << endl;
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

