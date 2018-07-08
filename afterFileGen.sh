#!/bin/sh
firefox $1.html &
code $1.cpp &
rm $1.script &
wait
exit
