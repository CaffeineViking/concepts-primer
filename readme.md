A C++ Concepts Primer
=====================

Compiling
---------

Since no compiler has (as of this writing) full support for the most recent Concepts
syntax, most of the examples given in the presentation and the attached primer, will
**not** compile. However, an earlier version of GCC *did* introduce the `-fconcepts`
flag, which allows one to at least have a taste of how Concepts works in practice.
The general idea of Concepts will always stay the same though, so all rules of thumb
and knowledge you gain from the old syntax transfers over to the new syntax. I've
therefore compiled a set of examples on how to use Concepts in the old syntax, which
should all compile if you are using GCC 6.1 or higher with the `-fconcepts` flag.
If you are running a Unix-like system, you can build all of the examples with `make all`.
To test that your compiler has proper support for Concepts, run `make check`, and
hope you get a friendly message saying you are **ready to roll**! If not, install
GCC 6.1.0 with `-fconcepts` support.


Resources
---------

* **[Constraints and Concepts:](http://en.cppreference.com/w/cpp/language/constraints)** the description in `cppreference` is quite intuitive, but hasn't been fully updated to match the current proposed syntax. But it's quite nice, to get an overview.
* **[C++ Standards Commitee Papers:](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/)** the only **true** source for accurate and up-to-date information on the current concepts syntax (but a bit daunting to read). Matches with primer syntax.
