tutorial:
	@# todo: have this actually run some kind of tutorial wizard?
	@echo "Please read the 'Makefile' file to go through this tutorial"


file.zip:
      wget -c -O $@ http://foo/bar


.PRECIOUS file.zip
