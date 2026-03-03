#!/bin/bash
if [[ $1 == '-h' ]]; then echo "gerar documentação. generate documentation."; exit 0; fi
/usr/bin/doxygen ./Doxyfile
