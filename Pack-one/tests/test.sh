#!/bin/bash
cmake --build build

number=(14 10 6 25 81 37 15)

echo -e "\033[36m\nTest Factorial func:\033[0m"
for i in {1..20}
do
build/Cli_app -f "$i"
done

echo -e "\033[36m\nTest NaturalDivX func:\033[0m"
for i in "${number[@]}"
do
build/Cli_app -h "$i"
done

echo -e "\033[36m\nTest IsSimple func:\033[0m"
for i in "${number[@]}"
do
build/Cli_app -p "$i"
done

echo -e "\033[36m\nTest HexNumber func:\033[0m"
for i in "${number[@]}"
do
build/Cli_app -s "$i"
done

echo -e "\033[36m\nTest Exponents func:\033[0m"
for i in 5 8 10
do
build/Cli_app -e "$i"
done

echo -e "\033[36m\nTest Natural func:\033[0m"
for i in "${number[@]}"
do
build/Cli_app -a "$i"
done