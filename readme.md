A C++ Concepts Primer
=====================

by **Erik Sven Vasconcelos Jansson** in mid-2018.

Abstract
--------

Documents
---------

* **[Primer (pdf)](primer/primer.pdf):** the primer itself, which consists of a short overview of *generic programming* in a  pre-concepts world, the problems with *unconstrained template parameters*, what methods we already have (e.g. *type traits and SFINAE*) for solving these problems, and why they are *insufficient*. Then, we present *concepts*, a way to *constrain template parameters* with the `requires` *clause*, and the `requires` *expression*, a way to easily specify *requirements* for a `concept`. The primer also covers *standard library concepts*, and the different *terse syntaxes* proposed for C++20, and their current status.
* **[Slides (pdf)](slides/slides.pdf):** essentially the same information as the above, but condensed, and not as good. Only for an introduction.

Typesetting
-----------

Both the primer and the slides are typeset with *LaTeX*, and are available as PDFs in the section above, but if if you still want to typeset the latest version for some reason, here is how to do it (in *TeXLive*): go into `primer` or `slides`, and call `make` :)

Examples
--------

Almost all examples in the primer should be runnable after doing the hack in `concepts.h`. In fact, I would recommend you to just import `concepts.h` if you want to play around with concepts. The only examples that aren't runnable, are those that use the more novel *terse syntaxes* (i.e. *concepts in-place syntax* and the *adjective syntax*). The *natural syntax* as in the TS should work fine. You can compile all examples in the primer by going to `primer/listings` and calling `make`. Since code in the primer is taken directly from these listings, everything you see in the primer is syntactically correct (not terse syntax).

Acknowledgements
----------------

References
----------
