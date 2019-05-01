A C++ Concepts Primer
=====================

by **Erik Sven Vasconcelos Jansson** in late-2018.

Abstract
--------

Right now C++ is experiencing a *renaissance*, fueled by new language features and an extended standard library introduced with C++11, C++14, and C++17. It's a different beast than C++98 (want to feel old?: that's two decades ago!), while still keeping to its core philosophies: the *zero-overhead principle*, having a *simple and direct mapping to hardware*, and to be completely *multi-paradigm*. The language has become more powerful, but also simpler, since a lot of the rough edges in C++98 have been removed, or replaced, with modern variants. Interest in C++ has surged again, and with C++20 coming soon™, doubly so.

In this primer we'll be looking at *concepts*, a way to *constrain templates*, which leads to: *clearer template errors*, a way to *overload functions based on constraints*, and more *explicitly defined function template interfaces* by using requirements. The goals of this primer are to teach you how to *apply constraints* to template parameters by using the *requires clause*, and how to *define* your own set of *requirements* by using the various forms of *requires expressions*. You'll then see that we can compose requirements together to form useful *concepts*, that can be used together with *terse syntax*, for writing less verbose generic code.

Documents
---------

* **[Primer (pdf)](primer/primer.pdf):** the primer itself, which consists of a short overview of *generic programming* in a  pre-concepts world, the problems with using *unconstrained template parameters*, what methods we currently have (e.g. *type traits and SFINAE*) for solving these or similar problems, and why they are *insufficient*. Then, we present *concepts*, a way to *constrain template parameters* by using `requires` *clauses* and  `requires` *expressions*. The primer also covers *standard library concepts*, their use in the *ranges* proposal, and the different *terse syntaxes* proposed for C++20 (which is more of a historical curiosity nowadays, since the syntax has already been chosen now). **Warning!** This is still work in progress!
* **[Slides (pdf)](slides/slides.pdf):** essentially the same information as the above, but condensed, and not as good. Good for a quick read.

Typesetting
-----------

Both the primer and the slides are typeset with *LaTeX*, and are available as PDFs in the section above, but if if you still want to typeset the latest version for some reason, here is how to do it (in *TeXLive*): go into `primer` or `slides`, and then call `make`.

Examples
--------

Almost all examples in the primer should be runnable after doing the hack in `concepts.h`. In fact, I would recommend you to just import `concepts.h` if you want to play around with concepts. The only examples that aren't runnable, are those that use the more novel *terse syntaxes* (i.e. *concepts in-place syntax* and the *adjective syntax*). The *natural syntax* as in the TS should work fine. You can compile all examples in the primer by going to `primer/listings` and calling `make`. Since code in the primer is taken directly from these listings, everything you see in the primer is syntactically correct (not terse syntax).

Acknowledgements
----------------

* **Roger Orr:** for his awesome [*Concepts Lite in Practice*](https://www.youtube.com/watch?v=S1Z-RbygAlw) talk and for the [article](https://accu.org/index.php/journals/2246) from ACCU 2016. Some motivating examples (e.g bad errors, and type traits) in this primer are borrowed (with consent) from there.
* **Andrew Sutton:** for another great [talk](https://www.youtube.com/watch?v=_rBhX-FJCdg): *Generic Programming with Concepts* at C++Now 2015. Many of the early examples in this primer are based from that talk (with some modifications).
* **Peter Sommerlad:** and the rest of the committee, for allowing me to participate in the discussion on Concepts, Modules and Contracts in the *Rapperswil* 2018 EWG meeting. It was great fun, and it was very interesting to get a perspective on how the commitee operates; while the work was tiring, it was very rewarding!
* **Tobias Lasser:** and the rest of the teachers/participants in the course seminar *Discovering and Teaching Modern C++*, for the very interesting talks and for providing a platform where like-minded people can discuss and teach modern C++ to each other. It forced me (being really lazy), to write something that might (?) be useful (I hope?) to others.

References
----------

* Bjarne Stroustrup. Concepts: The Future of Generic Programming. Document P0557 R1, 31/01/2017.
* Casey Carter and Eric Niebler. Standard Library Concepts (SLC). Document P0898 R3, 08/06/2018.
* Eric Niebler, Casey Carter, C. Di Bella. The One Ranges Proposal. Document P0896 R2, 25/06/2018.
* Köppe et al. Yet Another Approach For Constrained Declarations. Document P1141 R0, 23/06/2018.
* Stroustrup B. A Minimal Solution to the Concepts Syntax Problems. Document P1079 R0, 06/05/2018.
* Sutter H. Concepts In-Place Syntax (the post-Jacksonville variant!). Document P0745 R1, 29/04/2018.
* Working Draft, C++ Extension for Concepts (Concepts TS Draft). Technical Spec. D4553, 02/10/2015.
* Wording Paper, C++ Extension for Concepts (C++20WD Syntax). Document P0734 R0, 14/07/2017.
