#!/bin/bash


git clone https://github.com/nathanweeks/ipcmd

cd ipcmd
cd src

gcc ipcmd.c -o ipcmd

msqid=`./ipcmd msgget`
read napis
./ipcmd msgsnd -q $msqid -t 1 -n $napis
./ipcmd msgrcv -q $msqid | aspell -a -l pl
cd ..
cd ..
rm -rf ipcmd




