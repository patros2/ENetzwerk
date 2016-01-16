#include <iostream>
#include <string>
#include <time.h>
#include "/usr/local/include/yaml-cpp/yaml.h"

#include "docopt.cpp-master/docopt.h"

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


    YAML::Emitter out;
    out << "Hello, World!";
   std::cout << "Here's the output YAML:\n" << out.c_str() << std::endl; // prints "Hello, World!"
    }


    return 0;
}
