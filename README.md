Programm zum berechnen von einfachen Schaltung.
Simple appliance to calucate electical network with linare elements.

## Build
```
   mkdir build && cd build/
   cmake ..
   cmake --build .
```



### Bulding Windows

You'll need [cmake](https://cmake.org/download/) [mingw] (http://www.mingw.org/) and [codeblocks](http://www.codeblocks.org/)

It's essential to place the mingwin compiler `;C;/MinGW/bin;` in the `PATH` in Windows System envionment to ensure a stable build.
Please first install mingw than codeblocks and last cmake. It appeared to break the build process if done otherwise.

In addtion to this you need to place a patch for mingw manul to support the necessary feature:
 (Enabling string conversion functions in MinGW)[http://tehsausage.com/mingw-to-string]



## ToDo
 - Autolinking libraries in Windows to executable


## Dependency 
[docopt mit c++11](https://github.com/docopt/docopt.cpp)

[yaml-cpp c++11](https://github.com/jbeder/yaml-cpp)
