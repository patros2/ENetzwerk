Programm zum berechnen von einfachen Schaltung.
Simple appliance to calucate electical network with linare elements.

## Build
```
   mkdir build && cd build/
   cmake ..
   cmake --build .
```

Note for build on Windows. You'll need cmake and codeblocks.

It's essential to place the mingwin compiler `;C;/MinGW/bin;` in the `PATH` in Windows System envionment to ensure a stable build.

## ToDo
 - Autolinking libraries in Windows to executable


## Dependency 
[docopt mit c++11](https://github.com/docopt/docopt.cpp)

[yaml-cpp c++11](https://github.com/jbeder/yaml-cpp)
