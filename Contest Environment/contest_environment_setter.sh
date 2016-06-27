#!/bin/bash

clear

touch in.txt
touch out.txt

touch A.cpp
echo "//Problem A will go here" > A.cpp
cat Template.cpp >> A.cpp  
cb A.cpp

touch B.cpp
echo "//Problem B will go here" > B.cpp
cat Template.cpp >> B.cpp  

touch C.cpp
echo "//Problem C will go here" > C.cpp
cat Template.cpp >> C.cpp

touch D.cpp
echo "//Problem D will go here" > D.cpp  
cat Template.cpp >> D.cpp  

touch E.cpp
echo "//Problem E will go here" > E.cpp
cat Template.cpp >> E.cpp  

cb B.cpp 
cb C.cpp
cb D.cpp
cb E.cpp

clear
echo "Template ready"