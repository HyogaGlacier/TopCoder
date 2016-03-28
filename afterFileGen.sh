#!/bin/sh
firefox $1.html &
geany $1.cpp &
rm $1.script &
wait
exit
