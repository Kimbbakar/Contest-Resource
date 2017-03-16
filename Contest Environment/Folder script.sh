#!/bin/bash


echo "Uva Problem ID[ENTER]:"
read ID


cd E:\Uva_1k_project

if [ ! -d "$ID" ]; then
	mkdir "$ID"
	cd "$ID"

	touch in.txt
	printf "No Critical Case \n" > in.txt

	touch "$ID".cpp
	touch "$ID".py

	touch Note.txt

	printf "Tag: \n\nDescription: \n" > Note.txt 
	echo "Template ready"


else
	echo "!!! Directory Exist !!!"

fi 
 

