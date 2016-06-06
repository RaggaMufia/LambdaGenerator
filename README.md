# LambdaGenerator
An prolog implementation using DCG to generate lambda terms from an given alphabet. The result can be evaluated by C program that return an list of accepted words.

# Compiling (C)
gcc -o teste pushdown.c

# Running
> C: ./teste

> Prolog: Open the 'll1.pl' file and run the clause "run".

# Comments 
The prolog's generated output file for words with size of 7 or more has huge size (Above 16 GB). Therefore, our example result has only the first 10000 rows.

