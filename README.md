Programiranje 1 - FERI
===================
Welcome. This page is used for uploading and storing small homeworks (projects) that are done on regular basis for programming 1 subject on FERI (Maribor).

All assignments will contain descriptions, however the English that is used may seem slightly odd since official language on FERI is Slovenian and this is just google translated text.


###Assignemt 1 - Temperature

Write a program that in each new line, displays the temperature of air for the previous 5 days. The temperature of each day should be displayed on a new line. You should prepare 2 variants:
    a) minimum (e. g. morning) temperatures: if the temperature of air in the morning is less than 12 degrees, display a sign '#' (exception).
    b) maximum (e. g. afternoon) temperatures: if the temperature of air in the afternoon is more than 35 degrees, display a sign '?' (exception).

Find the air temperatures on the internet for 5 previous days for the current month in Maribor.

###Assignment 2 - Drive
Write a program that reads three real values: velocity, time spent and route length.
After entering the three values those nubers have to be output on the screen separated by spaces.

Then output the remaining path to the goal, that the bicycle raider still has to do.

Calculating the remaining path expression: 
remaining path = total path length - time spent * velocity

Also output some information if the raider has already passed his goal or not.
###Assignment 3 - Graphing drive
Complete the task of N2 by plotting the progress of the rider on the road. With the symbol * draw the number of percent by which a rider has finished the track, then write "." character for unfinished part of the track. Write the percentage of distance traveled.

Then draw a rectangle progress in multi-line (line graph) for 5 riders on the same route. The number of rows to the side of each rectangle is given by the user. Enter a value of N, which is the same for all rectangles. Use the local variables, pass them into functions, so that you avoid using global variables.

An example of the plot to the side of the graph N = 2:
Competitor 1 (1%)
*................................................. ..................................................
*................................................. ..................................................
Competitor 2 (60%)
************************************************** **********........................................
************************************************** **********........................................
Competitor 3 (30%)
******************************.................... ..................................................
******************************.................... ..................................................
Competitor 4 (10%)
**********........................................ ..................................................
**********........................................ ..................................................
Competitor 5 (90%)
************************************************** ****************************************..........
************************************************** ****************************************..........
###Assignment 4 - Prime numbers
Write a function that for a given integer returns the logical value, if a number is prime (test its divisors). Make sure that the negative numbers, 0 and 1 are not prime numbers.

Write another (second) function that calculates and returns number of prime numbers in the range from -217 up to and including including 9001

Write yet another (third) function which has two parameters, the first is an array of 20 numbers, the second is an integer. The function stores in this array the first 20 prime numbers, which are equal to or greater than the specified number in the second parameter. Then in this third function, also calculate the average value of these prime numbers in array and return this result using return statement.

Before defining those three functions declare their signature (function prototype). Do not use global variables. These three functions are not required to read and write on the screen, but it's done in the main program.

In the main program, the user then enters a number. Using this number, for the given array to third function, print first prime element of the resulting array, being closest to square root of the read number.
###Assignment 5 - Functions
a) Write a function f1, which accepts two integers and returns the multiple of 2 of their least common multiple.
b) Write the function f2, which calculates and returns how many numbers are divisible by the number 7 within a range not less than 300 (inclusive) and up to and including number 2000.
c) Write the function f3, which receives an array of integers and the array size as two arguments to this function. The function fills the array with the numbers which are divisible by the number 7 in the range from and including 300 up to and including 2000, and returns the median of the array.
d) Write the function f4 to display numbers at even indices (also index 0) from left to right.
e) Write the function f5 to display the numbers at odd indices from right to left.

