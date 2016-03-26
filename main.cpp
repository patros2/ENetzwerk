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
#include "./lib/berechnungen/widerstand.h"
#include "./lib/berechnungen/kondensator.h"



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



static const char VERSION[] = "ENetzwerk 0.3";

int main(int argc, const char** argv){
    std::map<std::string, docopt::value> args = docopt::docopt(USAGE, 
                                                  { argv + 1, argv + argc },
                                                  true,               // show help if requested
                                                  VERSION);  // version string

    if (args["berechnen"].isBool() && args["berechnen"].asBool() == true ){
    Node* a = new Node("Spannungsquelle", 1.9, 4);
    Node* b = new Node("Kondesator", 3.5, 2);
    Node* c = new Node("Spule", 1.5, 3);
    Node* d = new Node("Widerstand", 2.1, 1);

    Node* e = new Node("Spannungsquelle", 1.9, 4);
    Node* f = new Node("Kondesator", 3.5, 2);
    Node* g = new Node("Spule", 1.5, 3);
    Node* h = new Node("Widerstand", 2.3, 1);
    Node* i = new Node("Kondesator", 2.5, 2);
    Node* j = new Node("Spule", 1.5, 3);
    Node* k = new Node("Widerstand", 1.7, 1);

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
    testn.addNode(i);
    testn.addNode(k);

    //std::cout << std::endl << "Das ist ein Wert aus Netz: \n" << netz.getNode() << std::endl;
    /*
    Node* container[11] = { 0 };
    container[11] = netz.getNode();

    std::cout << "Das ist der 3. Wert aus Netz: "<< container[2]->getValue() << std::endl;
    std::cout << "Das ist der 1. Wert aus Netz: "<< container[0]->getValue() << std::endl;
    std::cout << "Das ist der 4. Wert aus Netz: "<< container[3]->getValue() << std::endl;
    */
    std::cout << "Das ist das vollstaendige Netz: \n" << netz.toString2() << std::endl;

    std::cout << "start von w_rs" << std::endl;
    std::cout << "Das Ergebnis der Reihenschaltung der Widerstaende aus testn ist: " << w_rs(testn) << " Ohm" << std::endl;
    std::cout << "Das Ergebnis der Parallelschaltung der Widerstaende aus testn ist: " << w_ps(testn)  << " Ohm" << std::endl;


    std::cout << "das neu mit getwert fuer 1:  " << testn.getwert("3") << std::endl;
    std::cout << "das neu mit getwert fuer Widerstand:  " << testn.getwert("Widerstan1d") << std::endl;

    std::cout << std::endl << "break" << std::endl;
    double t1 = w_rs(testn);
    double t2 = w_ps(testn);
    std::cout << "das ist der W_Wert des netzes gesetzt mit dem Wert aus wrs: " << testn.setwert(1, t1) << " Ohm" << std::endl;
    std::cout << "das ist der W_Wert des netzes gesetzt mit dem Wert aus wps: " << testn.setwert(1, t2) << " Ohm" << std::endl;

    std::cout << std::endl << "break" << std::endl;
    double t3 = k_rs(testn);
    double t4 = k_ps(testn);
    std::cout << "das ist der K_Wert des netzes gesetzt mit dem Wert aus krs: " << testn.setwert(2, t3) << " Farad" << std::endl;
    std::cout << "das ist der K_Wert des netzes gesetzt mit dem Wert aus kps: " << testn.setwert(2, t4) << " Farad" << std::endl;

    //double as = netz.getNode()->getValue();
    //std::string ad = netz.getNode()->getName();

    //std::cout << "das ist : " << as << std::endl;
    //std::cout << "das ist : " << ad << std::endl;

    std::cout << std::endl << "1" << std::endl << std::endl;
    std::cout << a->getID() << " vom Typ " << a->getType() << " hat den Wert " << a->getValue() << " und ist ein/e " << a->getName() << std::endl;
    std::cout << b->getID() << " vom Typ " << b->getType() << " hat den Wert " << b->getValue() << " und ist ein/e " << b->getName() << std::endl;
    std::cout << c->getID() << " vom Typ " << c->getType() << " hat den Wert " << c->getValue() << " und ist ein/e " << c->getName() << std::endl;
    std::cout << d->getID() << " vom Typ " << d->getType() << " hat den Wert " << d->getValue() << " und ist ein/e " << d->getName() << std::endl;




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
      deque<Bauteil*> network;
      // going through all elements in the YAMLK::Nodes object
      for (YAML::const_iterator it=config.begin();it!=config.end();it++)
 	  {
        if (it->IsSequence()){
	      //std::cout << "Scalar:Loop True" << std::endl;

          // We have a object with n items, need to loop through
          // not nice code, loop in a loop in a loopception....
          //std::cout << it->size()<< std::endl;
          int name=0;
          int value=4;
          int type=1;
          int root=2;
          int conntect_to=3;

          //  Node("Widerstand", 1.7, 1);
          Bauteil* node = new Bauteil(
                 (*it)[name].as<std::string>(),
                 (*it)[value].as<int>(), 
                 (*it)[type].as<int>(), 
                 (*it)[root].as<int>(),
                 (*it)[conntect_to].as<int>()
          );

          g.addNode(node);
          network.push_back(node);
     }}
     // we need to verify the network first
     // check for desecend number order that ends in 0
    
     for (size_t node_n = 0; node_n < network.size();node_n++)
     {
       int c;
       c = node_n;
       if ( c != network[node_n]->getRoot())
       {
        // a throw would be nice , but this do the job
         cout << "ID aren't consisten they need to be in a ascending order!" << endl;
         return 2;
      }
     }

     //evaluate connections 
     // get the connection and ensure that the circut is complete
     // verify that the fist and the last element of the network are connected
     if ( network[0]->getRoot() != network[network.size() - 1 ]->getConnection() )
     {
         cout << "Network is not compete! Make sure that the last element and the first are connected!" << endl;
         return 3;
     }

     
     for (size_t node_n = 0; node_n < network.size();node_n++)
     {
       int c;
       c = node_n;
       if ( c != network[node_n]->getRoot())
       {
        // a throw would be nice , but this do the job
         cout << "ID aren't consisten they need to be in a ascending order!" << endl;
         return 2;
      }
     }

     // We have an arry with the objects. will access into the each
     // of them to ensure that they:
     // are equal or bigger than zero or they beginning one
     // Maybe we should auto generate an ID for each object?
      for (size_t node_n = 0; node_n < network.size();node_n++)
        {
        cout << "DEBUG:" << node_n << endl;
        //cout << network[node_n]<< " "<< network[node_n]->getConnection() <<endl;
        // When the loop is over we need to stop accessing node_n -1 else it end's in a segfault
        cout << "DEBUG: network.size()" << network.size() << endl;
        cout << "DEBUG: node_n +1: " << node_n +1 << "network.size():" << network.size()
              << "\nnetwork[node_n]->getConnection():" << network[node_n]->getConnection() << endl ;
        // Check for the current node and the Next destenation
        // build_network that can be added 
        // before this can add we need to check that 
        if ( node_n  +1 < network.size()  && network[node_n]->getConnection() == network[node_n + 1]->getRoot())
        { 
          //verfiy that this is not a parallel network
          // we're look for more conenction that might have same root
          //if (network[node_n]->getConnection() )
          //{//}
          // add nodes to the networkS
          Node*  test= dynamic_cast<Node*>( network[node_n] );
          Node*  test2= dynamic_cast<Node*>( network[node_n +1] );
          // downcasting
          g.addEdge(new Edge(*test, *test2));
          cout << "Test" << endl;
        }
       //end conenction
        if ( network[node_n]->getConnection() == 0 )
        {
         Node*  test= dynamic_cast<Node*>( network[node_n] );
         Node*  test2= dynamic_cast<Node*>( network[0] );
         g.addEdge(new Edge(*test, *test2));
         cout << "DEBUG:  network" << endl;
        }}
      // cout << endl;
      //}
        
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
}

