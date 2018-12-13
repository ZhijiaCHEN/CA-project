#!/bin/sh
reset
mymake.sh
if ["$#" -ne 1] 
then
    echo "using cofiguration myconfig.cfg"
    sim-cache -config myconfig.cfg testprog1 hello world : testprog2 foo bar hello fox
else
    echo "using cofiguration $1"
    sim-cache -config $1 testprog1 hello world : testprog2 foo bar hello fox 
fi
