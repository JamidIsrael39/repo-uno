#!/bin/bash

name="Devdojo"

echo "Hola mundo"
echo "Hola ${name}"
echo "Hi there" $1

#echo "What is your name?"
#read name
#La siguiente linea es una reduccion de los dos anteriores
read -p "What is your name? " name

echo "Hi there ${name}"
echo "Welcome to Devdojo!"
