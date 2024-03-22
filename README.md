# Push_Swap
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.
Because Swap_push isn’t as natural

## This Push_Swap

Does 100 random numbers in 580 avrg

Does 500 random numbers in 5100 avrg

## Push_Swap Rules

The program is only allowed two stacks to work with, stack A and stack B. All the numbers are initially added to stack A, and B is empty.

The possible actions are:

* ```pa``` (push A): Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
* ```pb``` (push B): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
* ```sa``` (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
* ```sb``` (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
* ```ss```: ```sa``` and ```sb``` at the same time.
* ```ra``` (rotate A): Shift all elements of stack A up by 1. The first element becomes the last one.
* ```rb``` (rotate B): Shift all elements of stack B up by 1. The first element becomes the last one.
* ```rr```: ```ra``` and ```rb``` at the same time.
* ```rra``` (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first one.
* ```rrb``` (reverse rotate B): Shift all elements of stack b down by 1. The last element becomes the first one.
* ```rrr``` : ```rra``` and ```rrb``` at the same time.

## Bonus

* The Bonus exercise was to write a Program called 'checker' that can read the Operations from stdin and perform them on a stack of numbers.
* checker will return 'KO' when the given Operations will sort the numbers in ascending order. Otherwise it returns 'KO'.
* In case of an error (f.ex. Operations doesn't exist) it returns 'Error'.

## How to use

Clone the repository:
```bash
https://github.com/Drkpulse/push_swap.git
```
Go to the repository and run make
```bash
make
```
run make bonus to compile checker files
```bash
make bonus
```
Call the executable together with a set of numbers seperated by a space
```bash
./push_swap 10 7 8 2 3 6 1 4 9 5
```
To run the checker on push swap, use the pipe operator
```bash
ARG="10 7 8 2 3 6 1 4 9 5"; ./push_swap $ARG | ./checker $ARG
```
Use clean to delete all object files, fclean to remove all object files and executable and re to recompile the program, debug makes and cleans temps
```bash
make clean / make fclean / make re / make debug
```
