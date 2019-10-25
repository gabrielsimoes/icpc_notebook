.DEFAULT_GOAL := notebook.pdf

CODES = $(shell find ../code/ -type f -name '*.cpp')

content.tex: builder.sh hashify.sh ../code/config $(CODES)
	./builder.sh > content.tex

notebook.tex: head.tex content.tex notes.tex tail.tex
	cat head.tex content.tex notes.tex tail.tex > notebook.tex

notebook.pdf: notebook.tex
	pdflatex --interaction=batchmode notebook.tex
	pdflatex --interaction=batchmode notebook.tex

clean:
	rm -rf content.tex notebook.* src
