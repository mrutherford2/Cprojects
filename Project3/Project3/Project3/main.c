#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


//Function Prototypes
bool withinRange(int input, int minRange, int maxRange, char *name);
bool isPrime(int prime);
bool validateInput(int *pPrime, int *pFactorial, int *pLeapYear);
bool isLeapYear(int year);
int countPrimes(int number);
int getFactorial(int factorial); 
void performOperations(int *prime, int *factorial, int *leapYear, bool *isLeapYearResult, int *factorialValue, int *primeCount);
void displayReport(int prime, int factorial, int leapYear, bool isLeapYearResult, int factorialValue, int primeCount);

int main(int argc, char *argv[])
{
	int prime = 0, factorial = 0, leapYear = 0, primeCount = 0, factorialValue = 0;
	bool isLeapYearResult = false;

	printf("Matt Rutherford, Megan Molumby, Abubakr Hassan\n"); 
	printf("Project 3 - Simple Operations\n"); 

	if (argc == 4)
	{
		prime = atoi(argv[1]); 
		factorial = atoi(argv[2]); 
		leapYear = atoi(argv[3]);

		if (validateInput(&prime, &factorial, &leapYear)==true)
		{
			performOperations(&prime, &factorial, &leapYear, &isLeapYearResult, &factorialValue, &primeCount);
			displayReport(prime, factorial, leapYear, isLeapYearResult, factorialValue, primeCount);
		}
	}
	else
	{
		printf("Did not get the correct amount of arguments"); 
	}
	
	system("pause"); 
	return 0; 
}

bool validateInput(int *pPrime, int *pFactorial, int *pLeapYear)
{
	bool isValid = false;
	if (*pPrime > 0)
	{
		if (withinRange(*pPrime, 1, 10000, "Prime")==true)
		{
			if (*pFactorial > 0)
			{
				if (withinRange(*pFactorial, 1, 12, "Factorial")==true)
				{
					if (*pLeapYear > 0)
					{
						if (withinRange(*pLeapYear,1,4000, "Leap Year")==true)
						{
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

	return isValid; 
}

bool withinRange(int input, int minRange, int maxRange, char* name)
{
	bool isValid = true;

	if (input < minRange || input > maxRange)
	{
		isValid = false;
		printf("%s%s%s%d%s%d%s", "\nThe ", name, " value is out of range [", minRange, " - ", maxRange, "].\n");
	}

	return isValid; 
}

int countPrimes(int number)
{
	int primeCount = 0; 
	for (int i = 0; i <= number; i++)
	{
		if (isPrime(i))
		{
			primeCount++; 
		}
	}
	return primeCount; 
}

bool isPrime(int prime)
{
	bool isPrime = true;

	if (prime < 2)
	{
		isPrime = false;
	}
	if (prime % 2 == 0 && prime != 2)
	{
		isPrime = false; 
	}
	else
	{
		
		for (int p = 3; p <= sqrt(prime); p += 2)
		{
			if (prime % p == 0)
			{
				isPrime = false;
			}
		}
	}
	return isPrime; 
}

int getFactorial(int factorial)
{
	int calculatedFactorial;

	if (factorial == 0)
	{
		calculatedFactorial = 1;
	}
	else
	{
		calculatedFactorial = factorial * getFactorial(factorial - 1);
	}

	return calculatedFactorial; 
}

bool isLeapYear(int year)
{
	bool isLeap = false;

	if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
	{
		isLeap = true; 
	}
	return isLeap; 
}

void performOperations(int *prime, int *factorial, int *leapYear, bool *isLeapYearResult, int *factorialValue, int *primeCount)
{
	*isLeapYearResult = isLeapYear(*leapYear);
	*factorialValue = getFactorial(*factorial);
	*primeCount = countPrimes(*prime);
}

void displayReport(int prime, int factorial, int leapYear, bool isLeapYearResult, int factorialValue, int primeCount)
{
	printf("\n%s\n", "Operation Results:");
	printf("%s\n", "------------------"); 
	printf("%s%d%s%d\n", "Exactly ", primeCount, " prime numbers exist between 0 and ", prime);
	printf("%s%d%s%d\n", "The value of ", factorial, "! is ", factorialValue);

	if (isLeapYearResult == false)
	{
		printf("%s%d%s", "The year ", leapYear, " is not a leap year.\n");
	}
	else
	{
		printf("%s%d%s", "The year ", leapYear, " is a leap year.\n"); 
	}
}


