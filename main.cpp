#include <stdio.h>
#include <utility>
#include <iostream>
#include <string>
#include <time.h>
#include <typeinfo>
#include <deque>
#include <vector>
#include <list>

#include "./lib/yaml-cpp-master/include/yaml-cpp/yaml.h" 
#include "./lib/docopt.cpp-master/docopt.h" 
#include "./lib/NodesEdges/Node.h" 
#include "./lib/NodesEdges/Graph.h"
#include "./lib/NodesEdges/Bauteil.h"
#include "./lib/berechnungen/widerstand.h"
#include "./lib/berechnungen/kondensator.h"
#include "./lib/berechnungen/spule.h"
#include "./lib/berechnungen/netzanalyse.h"






void sum_p(Node* src, Node* a, Node* b, Graph* g)
{


  std::string name = (*a).getID() + (*b).getID() ;

  int type = (*a).getType();

  Edge* c= new Edge((*a),(*b));
  std::cout << "3"<< name << std::endl;
  double value = pot(c,2);
  
  Node* z = new Node(name, value, type);
  

  g->deleteNode(a);
  g->deleteNode(b);
  g->addNode(z);
  g->addEdge(new Edge(*src, *z));
 
}


void sum_r(Node* src,Node* a, Node* b, Graph* g)
{
  std::string name = (*b).getID() + (*a).getID() ;
  int type = (*a).getType();
  double value = pot((*b->getOutgoingEdges().begin()),1);
  
  Node* z = new Node(name, value, type);
  
  g->deleteNode(a);
  g->deleteNode(b);
  g->addNode(z);
  g->addEdge(new Edge(*src, *z));
 
}



int count_edges(Node* n)
{
  return (*n).getOutgoingEdges().size();
}

Graph* to_tree(Graph* g)                                                                                      
  {                                                                                                             
   std::list<Edge*> edges = (*g).getedges();                                                                    
   for (std::list<Edge*>::iterator t = edges.begin(); t != edges.end(); t++)                                    
   {                                                                                                            
    if ((*t)->getDstNode().getType() == 4 )                                                                     
    g->deleteEdge((*t));                                                                                        
   }                                                                                                            
   return g;                                                                                                    
}                                                                                                             
                                                                                                                
                                                                                                                
  int get_depth(Node* e, int depth){                                                                            
    // get a list of edges                                                                                      
    std::list<Edge*>& edges= (*e).getOutgoingEdges();                                                           
    depth = depth +1 ;                                                                                          
    //std::cout << "depth is: " << depth << std::endl;                                                          
    for (std::list<Edge*>::iterator t = edges.begin(); t != edges.end(); t++)                                   
    {                                                                                                           
      //std::cout << "&(*t)->getDstNode() " <<  &(*t)->getDstNode() << std::endl;                                                          
      //std::cout << " &(*edges.begin())->getSrcNode() " << &(*edges.begin())->getSrcNode() << std::endl;                                              
      //std::cout << " &(*t)->getSrcNode() "<< &(*t)->getSrcNode() << std::endl;                                                          
      //std::cout << " (*e).getID() " << (*e).getID() << std::endl;                                              
      //std::cout << " &(*t)->getDstNode() "<<(*t)->getDstNode().getID() << std::endl;                                                          
      //std::cout << " &(*t)->getDstNode() "<<(*t)->getDstNode().getOutgoingEdges().empty() << std::endl;                                                          
     if ( (*t)->getDstNode().getOutgoingEdges().empty() == 0)
     { 
      //std::cout << "True" << std::endl;
      depth = get_depth(&(*t)->getDstNode(), depth);
      }                                                                                                         
    }                                                                                                           
  return depth;                                                                                                 
  }                                                                                                             

void sum_all_r(Graph* g)
{
     std::list<Node*> nodes_in_g = (*g).getnodes();
     for (std::list<Node*>::iterator it = nodes_in_g.begin(); it != nodes_in_g.end(); it++)
     { 
       if (count_edges((*it)) == 0 && it != nodes_in_g.begin())
       {
       Node *o = (*it);
       Node *p = (*--it);
       it++;
       std::cout << p->getID() << std::endl;
       std::cout << o->getID() << std::endl;
       sum_r(*it,o,p, g);

        /*
         for (std::list<Edge*>::iterator t = (*it)->getOutgoingEdges().begin(); t != (*it)->getOutgoingEdges().end(); t++)
         {
          cout << (*t)->getDstNode().getID() << endl;
          temp_n.push_back(&(*t)->getDstNode());
         }

        cout <<temp_n[0]->getOutgoingEdges().size() << endl;
        cout <<temp_n[1]->getOutgoingEdges().size() << endl;


        cout << "Klappt!" << endl;
        */

      }
     }
}



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
    Node* g1 = new Node("Sp2", 1.5, 3);
    Node* h = new Node("W2", 2.3, 1);
    Node* i = new Node("K3", 2.5, 2);
    Node* j = new Node("SP3", 1.9, 3);
    Node* k = new Node("W3", 1.7, 1);
    Node* l = new Node("W4", 1.7, 1);
    Node* m = new Node("W5", 2.7, 1);

//hinzufuegen der nodes zum graphen
    Graph g;
    g.addNode(a);
    g.addNode(b);
    g.addNode(c);
    g.addNode(d);
    g.addNode(e);
    g.addNode(f);
    g.addNode(g1);
    g.addNode(h);
    g.addNode(i);
    g.addNode(j);
    g.addNode(k);
    //g.addNode(k);
    //g.addNode(l);
    //g.addNode(m);
    //g.addNode(n);

//erstellen der edges
/*
    Edge* swi1 = new Edge (*a , *d);
    Edge* wi1w2 = new Edge (*a , *h);
    Edge* wi2w3 = new Edge (*a , *k);
    Edge* wi1s = new Edge (*d , *a);
    Edge* wi2s = new Edge (*h , *a);
    Edge* wi3s = new Edge (*k , *a);
    Edge* sw1 = new Edge (*a , *d);
    Edge* w1w2 = new Edge (*d , *h);
    Edge* w2w3 = new Edge (*h , *k);
    Edge* w3w4 = new Edge (*k , *l);
    Edge* w4s = new Edge (*l , *a);
    Edge* sr1 = new Edge(*a, *d);
    Edge* r1r2 = new Edge(*d, *h);
    Edge* r1r3 = new Edge(*d, *k);
    Edge* r2r4 = new Edge(*h, *l);
    Edge* r3r4 = new Edge(*k, *l);
    Edge* r4s = new Edge(*l , *a);
*/
    Edge* line1 = new Edge(*h,*k);
    Edge* line2 = new Edge(*f,*i);
    Edge* line3 = new Edge(*j,*k);
    Edge* line4 = new Edge(*e,*k);

    //hinzufuegen der edges zum Graphen
    g.addEdge(line1);
    g.addEdge(line2);
    g.addEdge(line3);
    g.addEdge(line4);
    to_tree(&g);
    cout << g.toString() << endl;
    int ca =0;
    list<Node*>  nodes_in_g = g.getnodes();
    for (std::list<Node*>::iterator it = nodes_in_g.begin(); it != nodes_in_g.end(); it++)
     {
     cout << get_depth((*it), ca) << endl;
     }

//bis hier kann alles weg
//start der Netzwerkberechnung

    //setzen der spannung
    double u = spannung(g);
    g.setwert(4,u);

    //Test edge mit analyse
    std::cout << "widerstand in reihe " << pot(line1,1) << std::endl;
    std::cout << "widerstand parallel " << pot(line1,2) << std::endl;
    std::cout << "kondensator in reihe " << pot(line2,1) << std::endl;
    std::cout << "kondensator parallel " << pot(line2,2) << std::endl;
    std::cout << "spule in reihe " << pot(line3,1) << std::endl;
    std::cout << "spule in parallel " << pot(line3,2) << std::endl;


    //setzen des widerstandes, kondensators oder spule
    double endwert = gesamtwert(g);
    int endtyp = gesamttyp(g);
    g.setwert(endtyp,endwert);

    //setzen der stromstaerke
    double stromstaerke = strom(g);
    g.setwert(5,stromstaerke);
    //setzen der Leistung
    double p = leistung(g);
    g.setwert(6,p);

//test gesamt netzwerk
    std::cout << std::endl << "break" << std::endl;
    std::cout << "Das Netzwerk hat:" << std::endl;
    std::cout << "Den Widerstand: " << g.getwert("1") << " Ohm"  << std::endl;
    std::cout << "Den Kondensator: " << g.getwert("2") << " Farad"  << std::endl;
    std::cout << "Die Spule: " << g.getwert("3") << " Henry"  << std::endl;
    std::cout << "Die Spannungsquelle: " << g.getwert("4") << " Volt"  << std::endl;
    std::cout << "Die Stromstaerke: " << g.getwert("5") << " Amper"  << std::endl;
    std::cout << "Die Leistung: " << g.getwert("6") << " Watt"  << std::endl;




/*
    gut.addEdge(swi1);
    gut.addEdge(wi1w2);
    gut.addEdge(wi2w3);
    gut.addEdge(wi1s);
    gut.addEdge(wi2s);
    gut.addEdge(wi3s);
*/



    //test für widerstaende in reihe
  /*  Graph info;
    info.addNode(a);
    info.addNode(d);
    info.addNode(h);
    info.addNode(k);
    info.addNode(l);
*/



    //baue(test);


    //std::cout << "raus" << std::endl;


/*
    std::list<Edge*> te = d->getOutgoingEdges();
    //baue(info);
    for (std::list<Edge*>::iterator it = te.begin(); it != te.end(); it++)
        {
                Node dst = (*it)->getDstNode();
                std::string temp = dst.getName();
                std::cout << "das ist temp: j" << temp << std::endl;
        }
  */  //std::cout << a->getOutgoingEdges(). << std::endl;

  //  std::cout << "ausgerechnet baue (info): " << w_rs(info) << std::endl;
  //  std::cout << "info zuende......" << std::endl;

    //baue(gut);

    //std::cout << "ausgerechnet baue (gut): " << w_ps(gut) << std::endl;
    //std::cout << "gut zuende......" << std::endl;


    //test edge mit spannung


    //std::cout << std::endl << "Das ist ein Wert aus Netz: \n" << netz.getNode() << std::endl;
    /*
    Node* container[11] = { 0 };
    container[11] = netz.getNode();

    std::cout << "Das ist der 3. Wert aus Netz: "<< container[2]->getValue() << std::endl;
    std::cout << "Das ist der 1. Wert aus Netz: "<< container[0]->getValue() << std::endl;
    std::cout << "Das ist der 4. Wert aus Netz: "<< container[3]->getValue() << std::endl;
    */
    //std::cout << "Das ist das vollstaendige Netz: \n" << netz.toString2() << std::endl;
/*
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
*/



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
                 (*it)[value].as<double>(), 
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
     list<Node*>  nodes_in_g = g.getnodes();

     vector<deque<Node*>> meta_network;
     //meta_network.push_back(network);
     // Split the network into single segments 
     cout << g.toString() << std::endl;
     list<Edge*> t = g.getedges();
     list<Edge*> to_count;
     
     int count = 0; 
     std::vector<std::pair<Node*, int>> node_to_deep;

     to_tree(&g);
     cout << g.toString() << endl;
     int cc=0;

     // build depth
     for (std::list<Node*>::iterator it = nodes_in_g.begin(); it != nodes_in_g.end(); it++)
     {
       int d = get_depth((*it), count);
       cout <<"depth ist: "<< d << " for node: " <<  (*it)->getID() << endl;
       //d = get_depth((*it), count) ;
       node_to_deep.push_back(pair<Node*, int>(*it, d));
       cout << "\n\n\n\n" << node_to_deep[cc].second << node_to_deep[cc].first << endl;
       cc = cc + 1;
     }

     for (std::list<Node*>::iterator it = nodes_in_g.begin(); it != nodes_in_g.end(); it++)
     { 
       vector<Node*> temp_n;
       if (count_edges((*it)) > 1)
       {
         for (std::list<Edge*>::iterator t = (*it)->getOutgoingEdges().begin(); t != (*it)->getOutgoingEdges().end(); t++)
         {
          cout << (*t)->getDstNode().getID() << endl;
          temp_n.push_back(&(*t)->getDstNode());
         }

        //cout <<temp_n[0]->getOutgoingEdges().size() << endl;
        //cout <<temp_n[1]->getOutgoingEdges().size() << endl;

        //sum_p( &(*(*it)->getOutgoingEdges().begin())->getDstNode(), &(*(*it)->getOutgoingEdges().end())->getDstNode(), &g);
        sum_p(*it, temp_n[0], temp_n[1], &g);

        cout << g.toString() << endl;
      }
     }

     // Now there should be no parallel elements be left
     // ToDo we need some way to ensure that all only have a single connetion
     // need to reload the nodes of graph
     nodes_in_g = g.getnodes();
        cout << "Klappt!" << endl;
     sum_all_r(&g);
     cout << g.toString() << endl;
    }

}

