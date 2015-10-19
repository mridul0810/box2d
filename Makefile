.SUFFIXES: .cpp .hpp

# Programs
SHELL 	= bash
CC     	= g++
LD	= ld
RM 	= rm
ECHO	= /bin/echo
CMAKE = cmake
MAKE = make
DOT = dot
CP = cp
CD = cd
POPD = popd
PUSHD = pushd
GPROF = gprof
CAT	= cat
PRINTF	= printf
SED	= sed
DOXYGEN = doxygen
######################################
# Project Name (generate executable with this name)
TARGET = cs251_base

.PHONY: all codeDoc report clean distclean profile release


all: codeDoc report release

release:
	@$(ECHO) "Setting up release..."
	@$(MAKE) -C liquidfun/Box2D/ >>/dev/null
	@mkdir -p bin
	@$(CP) liquidfun/Box2D/Testbed/Release/Testbed bin/cs251_base

report: 
	@$(ECHO) "Setting up report..."
	@$(MAKE) -C report/ >> /dev/null



codeDoc:
	@$(ECHO) "Generating Doxygen Documentation ...  "
	@mv documentation/Doxyfile Doxyfile
	@$(DOXYGEN) Doxyfile
	@mv html/ documentation/html
	@mv latex/ documentation/latex
	@mv Doxyfile documentation/Doxyfile

profile:
	@chmod a+x gprof2dot.py
	@$(ECHO) "Make sure you have run the simulation for me to profile it ..."
	@$(ECHO) -n "Trying to profile the code ..."
	@$(GPROF) bin/cs251_base bin/gmon.out >> analysis.txt
	@python3 gprof2dot.py analysis.txt >> out.dot
	@$(DOT) -Tpng out.dot -o profile.png
	@mkdir profile
	@mv analysis.txt profile/analysis.txt
	@mv profile.png profile/profile.png
	@mv out.dot profile/out.dot
	@$(ECHO) "Done"

clean:
	@$(ECHO) -n "Cleaning up..."
	@$(RM) -rf bin/ profile/ report/Beamer.aux report/Beamer.log report/Beamer.nav report/Beamer.out report/Beamer.snm report/Beamer.toc 
	@mv documentation/Doxyfile Doxyfile
	@rm -rf documentation/
	@mkdir documentation/
	@mv Doxyfile documentation/Doxyfile
	@$(MAKE) clean -C liquidfun/Box2D -f Makefile >> /dev/null
	@$(ECHO) "Done"

distclean: clean
