#include <stdio.h>
#include <stdlib.h>
#include "..\..\..\stdbool.h"
#include <math.h>

/*
Authors: Matt Rutherford, Megan Molumby, Abubakr Hassan
Course: COP2220
Project #: 3
Title: Simple Operations
Due Date: 11/2/2014


Takes in command line arguments for prime, factorial, and a leapyear. 
Converts the command line arguments from character form to integer.
Checks the user input to make sure it is an integer and within a specified range.
Displays the amount of prime numbers, the calculated factorial, and if the year is a leapyear or not to the user.  
*/

//Function Prototypes
bool withinRange(int input, int minRange, int maxRange, char *name);
bool isPrime(int prime);
bool validateInput(int argc, char *argv[], int *pPrime, int *pFactorial, int *pLeapYear);
bool isLeapYear(int year);
int countPrimes(int number);
int getFactorial(int factorial); 
void performOperations(int *prime, int *factorial, int *leapYear, bool *isLeapYearResult, int *factorialValue, int *primeCount);
void displayReport(int prime, int factorial, int leapYear, bool isLeapYearResult, int factorialValue, int primeCount);

int main(int argc, char *argv[])
{
	//Variables to store our original values and calculated result values
	int prime = 0, factorial = 0, leapYear = 0, primeCount = 0, factorialValue = 0;
	bool isLeapYearResult = false;

	//Displays Name of Authors and the Project
	printf("Matt Rutherford, Megan Molumby, Abubakr Hassan\n"); 
	printf("Project 3 - Simple Operations\n"); 

		//Calls validateInput function to see if we have valid input from user
		if (validateInput(argc, argv, &prime, &factorial, &leapYear)==true)
		{	
			//Performs operations on values input from command line
			performOperations(&prime, &factorial, &leapYear, &isLeapYearResult, &factorialValue, &primeCount);
			
			//Displays the results of our operations 
			displayReport(prime, factorial, leapYear, isLeapYearResult, factorialValue, primeCount);
		}

	system("pause"); 
	return 0; 
}

/*
Validates our input values for prime, factorial, and leapyear. Checks to see if we have an integer value for 
each of the inputs and if the value is within the specified range for each input.
If it is not an integer value it will display the appropriate error message for each input value.
argc - The amount of arguments that we receive from the command line
argv[] - The array of command line arguments that we received from the command line
*pPrime - Pointer for the prime value
*pFactorial - Pointer for the factorial value
*pLeapYear - Pointer for the leapyear value
Returns the status of our flag variable for valid input 
*/
bool validateInput(int argc, char *argv[],int *pPrime, int *pFactorial, int *pLeapYear)
{
	//Flag variable for valid input, default value is set to false until we do our checking
	bool isValid = false;

	//Checks to see if we have the correct amount of command line arguments from the command line
	if (argc == 4)
	{
		*pPrime = atoi(argv[1]);
		*pFactorial = atoi(argv[2]);
		*pLeapYear = atoi(argv[3]); 
	
	//Checks to see if prime value is an integer and greater than 0
	if (*pPrime > 0)
	{
		//Checks to see if the prime value is within range
		if (withinRange(*pPrime, 1, 10000, "Prime")==true)
		{
			//Checks to see if the favortial value is an integer and greater than 0
			if (*pFactorial > 0)
			{
				//Checks to see if the factorial is within range
				if (withinRange(*pFactorial, 1, 12, "Factorial")==true)
				{
					//Checks to see if the leapyear value is an integer and greater than 0
					if (*pLeapYear > 0)
					{
						//Checks to see if the leapyear value is within range
						if (withinRange(*pLeapYear,1,4000, "Leap Year")==true)
						{
							//All input is good, set flag variable to a true value
							isValid = true; 
						}
					}
					else
					{
						printf("The Leap Year value is invalid.\n");
					}
				}
			}
			else
			{
				printf("The Factorial value is invlaid.\n"); 
			}
		}
	}
	else
	{
		printf("The Prime value is invalid.\n"); 
	}

	}
//Displays error message if we did not receive the correct amount of command line arguments 
else
{
	printf("Did not receive the correct amount of command line arguments"); 
}

	return isValid;
}

/*
Checks the range of the integer values received from the command line.
If the value is not within range the user is prompted with an error message
displaying the min and max range of the value as well as the name of the value.
input - The input for checking if it is within range
minRange - The minimum range for our input
maxRange - The maximum range for our input
*name - Pointer for the name of our input value 
Returns the status of our flag variable 
*/
bool withinRange(int input, int minRange, int maxRange, char* name)
{
	//Flag variable for valid range, set to true by default until we check the range 
	bool isValid = true;

	if (input < minRange || input > maxRange)
	{
		isValid = false;
		printf("%s%s%s%d%s%d%s", "\nThe ", name, " value is out of range [", minRange, " - ", maxRange, "].\n");
	}

	return isValid; 
}

/*
Counts the amount of prime numbers between 0 and up to the number we pass into the function.
If a number is prime between 0 and the number we pass into the function the prime count is 
incremented by 1.
number - The value of the integer we pass into the function to check how many prime numbers are between 0 and this number
Returns the amount of prime numbers between 0 and up to the number we pass into the function
*/
int countPrimes(int number)
{
	//Set our primecount to zero until we check how many prime numbers are between 0 and the value we pass into the function
	int primeCount = 0; 

	//Initialization of our index for the for loop so other compilers don't complain :)  
	int i;

	//Starts at 0 and counts up to and including the number we pass into the function and increments our index
	for (int i = 0; i <= number; i++)
	{
		//If the index value is prime increment our prime count 
		if (isPrime(i))
		{
			primeCount++; 
		}
	}
	return primeCount; 
}

/*
Checks to see if the number we passed into the function is in fact prime.
prime - The value that we are checking to see if it is a prime number
Return the status of our flag variable 
*/
bool isPrime(int prime)
{
	//Flag variable for our prime number, set to true until we check if the number is prime
	bool isPrime = true;

	//Initialization of our index for the for loop so other compilers don't complain :) 
	int i;

	//If the prime value is less than 2 our flag is set to false
	if (prime < 2)
	{
		isPrime = false;
	}
	
	//If the prime value is evenly divisible by 2 and not equal to 2 our flag is set to false
	else if (prime % 2 == 0 && prime != 2)
	{
		isPrime = false;
	}

	//Otherwise we start counting from 3, check all odd index values that are less than or equal to the square root of our prime value
	//when our flag variable is true, and increments our index by 2 
	else
	{
		for (i = 3; i <= sqrt(prime) && isPrime; i += 2)
		{
			//If our prime value is evenly divisible by 0 set flag to false
			if (prime % i == 0)
			{
				isPrime = false;
			}
		}
	}
	return isPrime;
}

/*
Recursively calculates the factorial value of the input value we pass into the function and returns the calculated factorial value 
factorial - The input value that we are performing the factorial calculation on
Returns the calculated factorial value of the original value that we passed into the function 
*/
int getFactorial(int factorial)
{
	//Variable to store our calculated factorial value 
	int calculatedFactorial;

	//If the factorial value that we passed into the function is equal to 0, the calculated value is 1, this is our base case
	if (factorial == 0)
	{
		calculatedFactorial = 1;
	}
	//Otherwise we recursively calculate the value of the factorial value passed into the function
	//by multiplying our original value by having the function call itself and passing in our original value minus 1 until we meet our base case condition. 
	else
	{
		calculatedFactorial = factorial * getFactorial(factorial - 1);
	}

	return calculatedFactorial; 
}

/*
Checks to see if the leapyear value that we passed into the function is in fact a leapyear. If it is we return a true value, otherwise we return false
year - The value of the year that we are passing into the function to see if it is a leapyear. 
Returns the boolean value of our leapyear check, returns false unless our condition is met 
*/
bool isLeapYear(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0; 
}

/*
Calls the functions to perform our operations for prime, factorial, and leapyear
*prime - The pointer to the value of our prime number value from the command line
*factorial - The pointer to the value of our factorial value input from the command line
*leapYear - The pointer to the value of our leapyear value input from the command line
*isLeapYearResult - The pointer to the boolean value of our result value for leapyear
*factorialValue - The pointer to the calculated factorial result value 
*primeCount - The pointer to the prime count result value 
*/
void performOperations(int *prime, int *factorial, int *leapYear, bool *isLeapYearResult, int *factorialValue, int *primeCount)
{
	*isLeapYearResult = isLeapYear(*leapYear);
	*factorialValue = getFactorial(*factorial);
	*primeCount = countPrimes(*prime);
}

/*
Displays the header as well as the results from our operations that we perform on our input values for prime, factorial, and leapyear. 
prime - The prime value that was originally input from the command line
factorial - The factorial value that was originally input from the command line
leapYear- The leapyear value that was originally input from the command line
isLeapYearResult - The result value for whether or not the original leapyear value is or is not a leapyear 
factorialValue - The result value for our original value that we calculated the factorial for
primeCount - The amount of prime numbers that were between 0 and the original prime value that was input from the command line 
*/
void displayReport(int prime, int factorial, int leapYear, bool isLeapYearResult, int factorialValue, int primeCount)
{
	printf("\n%s\n", "Operation Results:");
	printf("%s\n", "------------------"); 
	printf("%s%d%s%d\n", "Exactly ", primeCount, " prime numbers exist between 0 and ", prime);
	printf("%s%d%s%d\n", "The value of ", factorial, "! is ", factorialValue);

	//If the leapYearResult is false display the appropriate result message 
	if (isLeapYearResult == false)
	{
		printf("%s%d%s", "The year ", leapYear, " is not a leap year.\n");
	}
	//Otherwise if the leapYearResult is not false display the appropriate result message 
	else
	{
		printf("%s%d%s", "The year ", leapYear, " is a leap year.\n"); 
	}
}


