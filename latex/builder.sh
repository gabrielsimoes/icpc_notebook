#!/bin/bash

mkdir -p src

while read -r line; do
    if [ "${line:0:1}" == "!" ]; then
	echo ""
        echo "\\section{${line:1}}"
    else
        regex="(<.+>) (<.+>)"
	[[ $line =~ $regex ]]
	
	title=${BASH_REMATCH[1]:1:-1}
	filename=${BASH_REMATCH[2]:1:-1}

	echo "\\subsection{$title}"

	src_filename="src/${filename/\//_}"
	
	./hashify.sh < "../code/$filename" > $src_filename
	
        echo "\\lstinputlisting{$src_filename}"
    fi
done < "../code/config"

