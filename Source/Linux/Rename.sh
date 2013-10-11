#!/bin/sh

# Match all instances of ZEDTEMPLATE and ZEDTemplate, replacing with the user's
# own project name

UPPERNAME = `echo $1 | tr '[:lower:]' '[:upper:]'`

sed -i "s/ZEDTEMPLATE/$UPPERNAME/g" ./Headers/*.hpp
sed -i "s/ZEDTemplate/$1/g" ./Headers/*.hpp
sed -i "s/ZEDTEMPLATE/$UPPERNAME/g" ./Source/*.cpp
sed -i "s/ZEDTemplate/$1/g" ./Source/*.cpp
sed -i "s/ZEDTEMPLATE/$UPPERNAME/g" ./Makefile
sed -i "s/ZEDTemplate/$1/g" ./Makefile
sed -i "s/ZEDTEMPLATE/$UPPERNAME/g" ../Common/Headers/*.hpp
sed -i "s/ZEDTemplate/$1/g" ../Common/Headers/*.hpp
sed -i "s/ZEDTEMPLATE/$UPPERNAME/g" ../Common/Source/*.cpp
sed -i "s/ZEDTemplate/$1/g" ../Common/Source/*.cpp
