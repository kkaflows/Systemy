#!/bin/bash

if [[ $(date +%u) -gt 5 ]] ; then
    echo 'jest weekend, nie mozesz uruchomic programu'
    exit
fi
