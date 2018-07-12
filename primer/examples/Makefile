CXXFLAGS := -std=c++17 -fconcepts -Wall -Wextra -Wpedantic
LDLIBS   := -lstdc++

all: scratch mean centroid average
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

clean: .FORCE
	@rm -f *.o
distclean: clean
	@rm -f checker scratch mean point2 centroid average

# These are not the dependencies you are looking for
# - Obi-Wan Kenobi, Star Wars IV.
.PHONY: all check clean distclean
# Use the force, Luke!
.FORCE:
