tutorial:
	@# todo: have this actually run some kind of tutorial wizard?
	@echo "Please read the 'Makefile' file to go through this tutorial"


       

download: docopt.cpp.zip yaml-cpp.zip
	@# todo: have this actually run some kind of tutorial wizard?

docopt.cpp.zip: lib
	@wget -c -O lib/$@ https://github.com/docopt/docopt.cpp/archive/master.zip


yaml-cpp.zip: lib
	@wget -c -O lib/$@ https://github.com/jbeder/yaml-cpp/archive/master.zip

unzip: download
	@unzip lib/yaml-cpp.zip -d lib/
	@unzip lib/docopt.cpp.zip -d lib/

build_dep:
	@mkdir lib/yaml-cpp-master/build
	@cmake lib/yaml-cpp-master lib/yaml-cpp-master/build


lib:
	@mkdir $@


.PRECIOUS: docopt.cpp.zip

.PRECIOUS: yaml-cpp.zip
