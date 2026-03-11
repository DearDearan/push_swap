*This project has been created as part of the 42 Curriculum by lifranco.*

# Description

The objective is to write, in C, a sorting algorithm that finds the fastest way to sort numbers.

This project is often a developer's journey first encounter with algorithmic complexity.

The goal of Push_Swap is to sort numbers in ascending order using a sorting algorithm, like **Butterfly**, **Radix** or **the most inneficient sorting algorithm you found on Reddit**, as long as it sorts numbers and minimizes the number of operations done. 

The programs uses two stacks, A and B, to sort the numbers.

At the end of the execution, the program outputs the list of operations used to sort the numbers.


## Allowed Operations 

It uses the following operations :

* **Push** the top number on A or B.
* **Swap** the first two numbers of A, B or both.
* **Rotate** all elements by 1 on A, B or both. (The first element becomes the last one)
* **Reverse Rotate** all elements by 1 on A, B or both. (The last element becomes the first one)

## Handling Errors

The program prints "Error" followed by a newline ('\n') in the following cases: 

* Arguments not being a valid Integer.
* Arguments exceeding the Integer limit.
* Duplicate numbers being present in the Arguments
* Duplicate signs used (e.g. "++", "--", "+-", "-+")

# Instructions

Nothing's easier than installing the program. Really, just follow the instructions.

First, clone the repository and name it (replace *NAMEOFDIR* by any available directory name within your current directory).

```bash
git clone git@vogsphere.42angouleme.fr:vogsphere/intra-uuid-858c2aca-5e43-4029-b17e-d5c590a16b93-7139692-lifranco NAMEOFDIR
```

then, using the Makefile, run:

```bash 
make all
```

This will create: 
* An **obj** directory, where all .o are (except for ***libft*** files who are inside ***include***)
* An executable file named **push_swap**.

Lastly, use your terminal and write this command to run the program:

```bash
./push_swap ARGS
```

You can provide multiple arguments, a single quoted or double quoted string or both.

## Makefile

Here's the following Makefile rules and what they do:

* all: Compile every files and create an executable.
* clean: Remove every .o files, obj dir but doesn't remove the executable.
* fclean: Same as clean but removes the executable too.
* re: does an fclean and all.

# Ressources

Nothing much, i used my peers help and some AI (ChatGPT) to help me learn the use of linked lists and to help me understand the butterfly algorithm. It also helped me with the parsing.

# The End

This was a brief explanation of how the project works and how to use it.
I don’t have anything else to add. It was fun, I guess?


So here's a lifranco / Dearan's Useless fact !

Did you know ? "Not For Broadcast" is a cool FMV game that won the Guiness World Record of **Most Full Motion Video footage in a videogame**, for a total of 42 Hours, 57 Minutes and 52 Seconds

This game's a blast and Jeremy Donaldson is a great character, his actor is really funny.