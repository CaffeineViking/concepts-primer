CXXFLAGS := -std=c++17 -fconcepts -Wall -Wextra -Wpedantic
LDLIBS   := -lstdc++

all: scratch
check: checker
	@./checker
checker: checker.o
checker.o: checker.cc

scratch: scratch.o
scratch.o: scratch.cc

clean: .FORCE
	@rm -f *.o
distclean: clean
	@rm -f checker scratch

# These are not the dependencies you are looking for
# - Obi-Wan Kenobi, Star Wars IV.
.PHONY: all check clean distclean
# Use the force, Luke!
.FORCE:
