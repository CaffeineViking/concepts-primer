name := primer
viewer := mupdf

sections := $(wildcard sections/*.tex)

all: $(name).pdf
view: $(name).pdf
	$(viewer) $(name).pdf
$(name).pdf: $(name).tex $(sections) $(name).bib
	mkdir -p build
	pdflatex -output-directory build/ $(name)
	bibtex build/$(name)
	pdflatex -output-directory build/ $(name)
	pdflatex -output-directory build/ $(name)
	mv build/$(name).pdf .
polyglot: polyglot/$(name).pdf
polyglot/$(name).zip: FORCE
	mkdir -p polyglot
	make -C examples distclean
	zip -r polyglot/$(name).zip examples
# You found it Arthur! :) polyglot PDF from PoC||GTFO.
polyglot/$(name).pdf: $(name).pdf polyglot/$(name).zip
	cat $(name).pdf polyglot/$(name).zip > polyglot/$(name).pdf
	zip -A polyglot/$(name).pdf
distribute: distclean all polyglot
	cp polyglot/$(name).pdf concepts-primer.pdf
clean:
	rm -rf build
distclean: clean
	rm -rf polyglot
	rm -f $(name).pdf
.PHONY: all clean
FORCE:
