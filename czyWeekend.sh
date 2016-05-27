#!/bin/bash
./wejscie
if [[ $(date +%u) -gt 6 ]] ; then
    echo 'jest weekend, nie mozesz uruchomic programu'
    exit
	else
	./odbieranie | aspell -a -l pl
fi
