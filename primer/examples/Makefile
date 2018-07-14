CXXFLAGS := -std=c++17 -fconcepts -Wall -Wextra -Wpedantic
LDLIBS   := -lstdc++

all: scratch mean centroid average sfinae factory advance matrix iterator ranges natural zero misc
gcc-test: check
	@./checker
check: checker
	@./checker

checker: checker.o
checker.o: checker.cc
scratch: scratch.o
scratch.o: scratch.cc

point2.o: point2.cc point2.hh

mean: mean.o
mean.o: mean.cc
centroid: centroid.o point2.o
centroid.o: centroid.cc
average: average.o point2.o
average.o: average.cc
sfinae.o: sfinae.cc sfinae.hh
sfinae: sfinae.o
factory: factory.o
factory.o: factory.cc factory.hh
matrix.o: matrix.cc matrix.hh
matrix: matrix.o
advance: advance.o
advance.o: advance.cc
iterator: iterator.o
iterator.o: iterator.cc
natural.o: natural.cc
natural: natural.o
ranges.o: ranges.cc
ranges: ranges.o
zero.o: zero.cc
zero: zero.o
misc.o: misc.cc
misc: misc.o

clean: .FORCE
	@rm -f *.o
distclean: clean
	@rm -f checker scratch mean point2 centroid average sfinae factory advance matrix iterator ranges natural zero misc

# These are not the dependencies you are looking for
# - Obi-Wan Kenobi, Star Wars IV.
.PHONY: all check clean distclean
# Use the force, Luke!
.FORCE:
