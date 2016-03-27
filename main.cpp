#include <stdio.h>
#include <iostream>
#include <string>
#include <time.h>
#include <typeinfo>
#include <deque>
#include <vector>

#include "./lib/yaml-cpp-master/include/yaml-cpp/yaml.h" 
#include "./lib/docopt.cpp-master/docopt.h" 
#include "./lib/NodesEdges/Node.h" 
#include "./lib/NodesEdges/Graph.h"
#include "./lib/NodesEdges/Bauteil.h"
#include "./lib/berechnungen/widerstand.h"
#include "./lib/berechnungen/kondensator.h"
#include "./lib/berechnungen/spule.h"
#include "./lib/berechnungen/netzanalyse.h"



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

    Node* a = new Node("SQ1", 1.9, 4);
    Node* b = new Node("K1", 3.5, 2);
    Node* c = new Node("SP1", 1.5, 3);
    Node* d = new Node("W1", 2.1, 1);

    Node* e = new Node("SQ2", 1.2, 4);
    Node* f = new Node("K2", 3.5, 2);
    Node* g = new Node("Sp2", 1.5, 3);
    Node* h = new Node("W2", 2.3, 1);
    Node* i = new Node("K3", 2.5, 2);
    Node* j = new Node("SP3", 1.9, 3);
    Node* k = new Node("W3", 1.7, 1);


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
    testn.addNode(j);
    testn.addNode(k);

    Edge* line1 = new Edge(*h,*k);
    Edge* line2 = new Edge(*f,*i);
    Edge* line3 = new Edge(*j,*k);
    testn.addEdge(line1);
    testn.addEdge(line2);
    testn.addEdge(line3);

    //test edge mit baue
    double t7 = spannung(testn);
    testn.setwert(4,t7);




    //Test edge mit analyse
    std::cout << "mal gucken " << pot(line1) << std::endl;
    std::cout << "mal gucken " << pot(line2) << std::endl;
    std::cout << "mal gucken " << pot(line3) << std::endl;
    std::cout << std::endl << "break break" << std::endl;
    //std::cout << std::endl << "Das ist ein Wert aus Netz: \n" << netz.getNode() << std::endl;
    /*
    Node* container[11] = { 0 };
    container[11] = netz.getNode();

    std::cout << "Das ist der 3. Wert aus Netz: "<< container[2]->getValue() << std::endl;
    std::cout << "Das ist der 1. Wert aus Netz: "<< container[0]->getValue() << std::endl;
    std::cout << "Das ist der 4. Wert aus Netz: "<< container[3]->getValue() << std::endl;
    */
    //std::cout << "Das ist das vollstaendige Netz: \n" << netz.toString2() << std::endl;

    std::cout << "start von w_rs" << std::endl;
    std::cout << "Das Ergebnis der Reihenschaltung der Widerstaende aus testn ist: " << w_rs(testn) << " Ohm" << std::endl;
    std::cout << "Das Ergebnis der Parallelschaltung der Widerstaende aus testn ist: " << w_ps(testn)  << " Ohm" << std::endl;


    std::cout << "das neu mit getwert fuer 1:  " << testn.getwert("3") << std::endl;
    std::cout << "das neu mit getwert fuer Widerstand:  " << testn.getwert("Widerstan1d") << std::endl;

//test widerstand
    std::cout << std::endl << "break" << std::endl;
    double t1 = w_rs(testn);
    double t2 = w_ps(testn);
    std::cout << "das ist der W_Wert des netzes gesetzt mit dem Wert aus wrs: " << testn.setwert(1, t1) << " Ohm" << std::endl;
    std::cout << "das ist der W_Wert des netzes gesetzt mit dem Wert aus wps: " << testn.setwert(1, t2) << " Ohm" << std::endl;

//test ob Strom berechnet wird
    double t8 = strom(testn);
    testn.setwert(5,t8);
    std::cout << "strom: " << strom(testn) << std::endl;
    std::cout << std::endl <<"TEST Der Strom: " << testn.getwert("5") << " Amper"  << std::endl;

//test kondensator
    std::cout << std::endl << "break" << std::endl;
    double t3 = k_rs(testn);
    double t4 = k_ps(testn);
    std::cout << "das ist der K_Wert des netzes gesetzt mit dem Wert aus krs: " << testn.setwert(2, t3) << " Farad" << std::endl;
    std::cout << "das ist der K_Wert des netzes gesetzt mit dem Wert aus kps: " << testn.setwert(2, t4) << " Farad" << std::endl;

//test ob Strom berechnet wird
    testn.setwert(1,0);
    testn.setwert(3,0);
    double t9 = strom(testn);
    testn.setwert(5,t9);

//test spule
    std::cout << std::endl << "break" << std::endl;
    double t5 = s_rs(testn);
    double t6 = s_ps(testn);
    std::cout << "das ist der S_Wert des netzes gesetzt mit dem Wert aus srs: " << testn.setwert(3, t5) << " Henry" << std::endl;
    std::cout << "das ist der S_Wert des netzes gesetzt mit dem Wert aus sps: " << testn.setwert(3, t6) << " Henry" << std::endl;



//test gesamt netzwerk
    std::cout << std::endl << "break" << std::endl;
    std::cout << "Das Netzwerk hat:" << std::endl;
    std::cout << "Den Widerstand: " << testn.getwert("1") << " Ohm"  << std::endl;
    std::cout << "Den Kondensator: " << testn.getwert("2") << " Farad"  << std::endl;
    std::cout << "Die Spule: " << testn.getwert("3") << " Henry"  << std::endl;
    std::cout << "Die Spannungsquelle: " << testn.getwert("4") << " Volt"  << std::endl;
    std::cout << "Die Stromstaerke: " << testn.getwert("5") << " Amper"  << std::endl;

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


    cout << args["yaml"] << std::endl;
    if (args["yaml"].isBool() && args["yaml"].asBool() == true ){
      YAML::Node config = YAML::LoadFile("config.yaml");

      Graph g;
      deque<Node*> network;
      // meta_list tracks the network segments


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
 
          //cout << (*it)[name].as<std::string> ()<< endl;

          //  Node("Widerstand", 1.7, 1);
          Node* node = new Node(
                 (*it)[name].as<std::string>(),
                 (*it)[value].as<int>(), 
                 (*it)[type].as<int>()
          );          
                list<Node*> nodes = g.getnodes();
                // (*it)[root].as<int>(),
                // (*it)[conntect_to].as<int>()
          //g.addNode(node);

          bool added = false;
          //cout << "node-ID" << node->getID() <<  endl;
          for (list<Node*>::iterator it = nodes.begin();it != nodes.end();it++){
           //cout << "node-ID: " << node->getID() <<  " it->getID "<< (*it)->getID() << endl;
           if (node->getID() == (*it)->getID()){
            added = true;
            }
           }
          if (added != true)
          {
            g.addNode(node);
          }
          //g.addEdge(new Edge(*test, *test2));
          cout << "Nodes size: "<< nodes.size() << endl;
          network.push_back(node);

          if ( network.size() >= 2 ){
           // cout << "network[(*it)[ root].as<int>()]"<< network[(*it)[ root].as<int>()]->getID() << " " << network[(*it)[conntect_to].as<int>()]->getID()  << endl;
            g.addEdge(new Edge(*network[(*it)[ root].as<int>()], *network[(*it)[conntect_to].as<int>()]));
          }
        }
     }
     cout << g.toString() << endl;

     double testing = spannung(g);
     g.setwert(4, testing);
     cout << "Spannungswert: " << g.getwert("4") << endl;
     cout << "Widerstand: " << g.getwert("1") << endl;
     
     double e = w_ps(g);
     cout << e << endl;


     vector<deque<Node*>> meta_network;
     meta_network.push_back(network);



     // we need to verify the network first
     // check for desecend number order that ends in 0
    
    /* for (size_t node_n = 0; node_n < network.size();node_n++)
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
         //Todo: need to check the entry network for a connection
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
    */

     // We have an arry with the objects. will access into the each
     // of them to ensure that they:
     // are equal or bigger than zero or they beginning one
     // need for parallel circut to loop reveres 
     /*
      for (size_t node_n = 0; node_n < network.size();node_n++)
        {
        bool is_parallel;
        cout << node_n << endl;

        // When the loop is over we need to stop accessing node_n -1 else it end's in a segfault
        // Check for the current node and the Next destenation
        // build_network that can be added 
        // before this can add we need to check that 
        if ( node_n  +1 < network.size()  && network[node_n]->getConnection() == network[node_n + 1]->getRoot())

        { 
          //verfiy that this is not a parallel network
          // we're look for more conenction that might have same root
          //if (network[node_n]->getConnection() )
          //{//}
          deque<Bauteil*> local_network = network;
          Node*  test= dynamic_cast<Node*>( network[node_n] );
          for (size_t rnode_n = local_network.size() - 1 ; rnode_n != 0;rnode_n-- )
          {
            cout << "   DEBUG: reverse loop" << endl ;
            cout <<  local_network[node_n]->getRoot() << "compare"<< local_network[rnode_n]->getConnection()<< endl;
             
            if (local_network[rnode_n]->getConnection() == local_network[node_n]->getRoot() ){
               is_parallel = true;
               cout << "   is_parallel: " << is_parallel << endl;
                Node*  test2= dynamic_cast<Node*>( network[rnode_n] );
                g.addEdge(new Edge(*test, *test2));
            }
            local_network.pop_back();
          }
          // add nodes to the networkS
          Node*  test2= dynamic_cast<Node*>( network[node_n +1] );
          // downcasting
          g.addEdge(new Edge(*test, *test2));
          cout << "Test" << endl;
        }

      //Start to segment the network 
      // for (size_t node_n = 0; node_n < network.size();node_n++) 
      // {
      // }
       double testing = spannung(g);
       g.setwert(4, testing);
       cout << "Spannungswert: " << g.getwert("4") << endl;
 
       vector<deque<Bauteil*>> meta_network;
       meta_network.push_back(network);

       }
       // Split the network into single segments 
       std::cout << g.toString() << std::endl;
       list<Edge*> t = g.getedges();
        for (std::list<Edge*>::iterator it = t.begin(); it != t.end(); it++)                          
      { 
       Edge* pCurrentEdge = *it; 
       cout << &pCurrentEdge->getSrcNode() << endl;
       cout << &pCurrentEdge->getDstNode() << endl;
      }
      */
     
    }
}

