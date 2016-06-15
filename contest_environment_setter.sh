#!/bin/bash

clear

cd E:\Code
touch in.txt
touch out.txt

touch A.cpp
echo "//Problem A will go here" > A.cpp
cat templt.cpp >> A.cpp  
cb A.cpp

touch B.cpp
echo "//Problem B will go here" > B.cpp
cat templt.cpp >> B.cpp  

touch C.cpp
echo "//Problem C will go here" > C.cpp
cat templt.cpp >> C.cpp

touch D.cpp
echo "//Problem D will go here" > D.cpp  
cat templt.cpp >> D.cpp  

touch E.cpp
echo "//Problem E will go here" > E.cpp
cat templt.cpp >> E.cpp  

cb B.cpp 
cb C.cpp
cb D.cpp
cb E.cpp

clear
echo "Template ready"