/*
Authors: Matt Rutherford, Megan Molumby, Abubakr Hassan
Course: COP2220
Project #: 4
Title: Random Number Statistics
Due Date: 11/30/2014

Reads seed and count values from an input file, checks to see if a file was actually read from the command line,
checks the range of the input values that were read from the input file,
generates random numbers based on the values from the input file,
populates an array of count values based on how many times a random number was generated,
displays statistics that are derived from the array such as minimum count, maximum count, median count, average count,
and then displays the contents of the array including the position in the array, the amount of times a random number was generated,
and the percentage of how many times a random number was generated from the total size of the array. 
*/
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include "..\..\..\stdbool.h"
#define ARRAY_SIZE 100

//Function Prototypes
void calculateStatistics(int array[], int *pMin, int *pMax, double *pMedian, double *pAverage);
void copyArray(int array[], int copy[]);
void generateNumbers(int array[], int seed, int count);
double getAverage(int array[]);
int getMax(int array[]);
double getMedian(int array[]);
int getMin(int array[]);
void initializeArray(int array[]);
void printReport(int array[], int count, int min, int max, double median, double average);
bool readFile(char *filename, int *pSeed, int *pCount);
void sortArray(int array[]);
void swap(int array[], int pos1, int pos2);
bool validateInput(int seed, int count);
bool withinRange(int value, int minRange, int maxRange); 


int main(int argc, char *argv[])
{
	//Variables to store our count, minimum, max, seed, average, and median values
	int count=0, min=0, max=0, seed=0;
	double average=0.00, median=0.00;
	//Declaration of our array to store our statistical information 
	int array[ARRAY_SIZE];

	printf("Matt Rutherford, Megan Molumby, Abubakr Hassan, Ramiz Hadad\n");
	printf("Project 4 - Random Number Statistics\n"); 

	//Checks to see if we received the correct amount of command line arguments
	if (argc == 2)
	{
		//Calls our readFile function to read the seed and count values from the input file
		if (readFile(argv[1], &seed, &count) == true)
		{
			//Calls our validateInput function to check to see if we received valid input from the input file
			if (validateInput(seed, count) == true)
			{
				//Calls our function to generate Random Numbers
				generateNumbers(array, seed, count);
				//Calls our function to calculate our statistics
				calculateStatistics(array, &min, &max, &median, &average);
				//Calls our function to display the results from our statiscal operations
				printReport(array, count, min, max, median, average); 
			}
		}
		else
		{
			printf("Atleast one of the supplied values is invalid.\n");
		}
	}
	else
	{
		printf("The required filename parameter is missing."); 
	}
	
	
	
	system("pause");
	return 0; 
}

/*
Checks to see if we received valid data from the input file 
and calls our functions to check the range of the seed and count values from the input file
and returns the status of our flag variable to determine if we received valid data from the input file
seed - The seed value that we received from the input file
count - The count value that we received from the input file
Returns the status of our flag variable
*/
bool validateInput(int seed, int count)
{
	bool isValid = false;
	
		if (withinRange(seed, 0, 10000)==true)
		{
				if (withinRange(count, 100, 1000)==true)
				{
					isValid = true; 
				}
		}
	
	return isValid; 
}

/*
Checks to see if the input values that we received from the input file are within our allowable range
and returns the status of our flag variable to determine if our input values are within the allowable range
value - The input value that we received from the input file
minRange - The minimum range for our input value
maxRange - The maximum range value for our input value
Returns the status of our flag variable
*/
bool withinRange(int value, int minRange, int maxRange)
{
	bool isWithinRange = true; 
	if (value < minRange || value > maxRange)
	{
		isWithinRange = false;
		printf("%s%d%s%d%s", "The supplied value is out of range [", minRange, " - ", maxRange, "]"); 
	}
	return isWithinRange; 
}

/*
Opens our input file based on the filename received from the command line in read mode, 
checks to see if we actually have an input file,
reads a line from the file and determines if we received two integer values from the input file,
stores the two values read from the input file in our seed and count variables,
and then closes the filereader. The function then returns a true value if we were able to read from the file and received the correct values from the file,
otherwise it returns a false value to indicate that we did not have a file to read from or did not receive the correct
input values from the file.
*filename - The pointer for our filename
*pSeed - The pointer for our seed value
*pCount - The pointer for our count value
Returns the status of our flag variable
*/
bool readFile(char *filename, int *pSeed, int *pCount)
{
	bool isValid = false; 
	FILE *fp;
	fp = fopen(filename, "r");
	if (fp != NULL)
	{
		if (fscanf(fp, "%d %d", pSeed, pCount)== 2)
		{
			isValid = true; 
		}
		fclose(fp);
	}
	return isValid; 
}

/*
Gets the minimum value of how many times a random number was generated from our array and then returns our minimum value
array[] - The array that we are passing into the function to determine the minimum value
Returns the minimum value that was calculated from the contents of our array
*/
int getMin(int array[])
{
	int x, min = array[0];

	for (x = 0; x < ARRAY_SIZE; x++)
	{
		if (array[x] < min)
		{
			min = array[x]; 
		}
	}
	return min; 
}

/*
Gets the maximum value of how many times a random number was generated from our array and then returns our maximum value
array[] - The array that we are passing into the function to determine the maximum value
Returns the maximum value that was calculated from the contents of our array
*/
int getMax(int array[])
{
	int x, max = array[0];

	for (x = 0; x < ARRAY_SIZE; x++)
	{
		if (array[x] > max)
		{
			max = array[x]; 
		}
	}
	return max; 
}

/*
Gets the average value of how many times a random number was generated from our array and then returns our average value
array[] - The array that we are passing into the function to determine the average value
Returns the average value that was calculated from the contents of our array
*/
double getAverage(int array[])
{
	int x=0;
	double sum = 0.0; 

	for (x = 0; x < ARRAY_SIZE; x++)
	{
		sum += array[x]; 
	}
	return sum/ARRAY_SIZE; 
}

/*
Initializes our copy array and assumes the middle value of our array is at the middle index of the array
Calls the function to copy the contents of our original array and stores them in our copy array so we can then call the function to sort our copy array
Gets the median value of how many times a random number was generated from our array and then returns our median value
array[] - The array that we are passing into the function to determine the median value
Returns the median value that was calculated from the contents of our copy array
*/
double getMedian(int array[])
{
	int copy[ARRAY_SIZE] = {0};
	int mid = ARRAY_SIZE / 2;
	double median;
	copyArray(array, copy); 
	sortArray(copy); 
	median = copy[mid];
	

	//For even 
	if (ARRAY_SIZE % 2 == 0)
	{
		median = (copy[mid] + copy[mid - 1])/2; 
	}

	return median; 
}

/*
Copies the contents of our original array and stores them in our copy array so we maintain the integrity of our data of the original array
array[] - The array that we are passing into the function to copy the contents from into our copy array
copy[] - The array that we are passing into the function to hold the contents of our original array so we can later perform selection sort on it
*/
void copyArray(int array[], int copy[])
{
	int i; 
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		copy[i] = array[i];
	}
}

/*
Sorts the contents of our array using selection sort by first finding the minimum value in the array then
swaps the minimum value with the value in the first index, then repeats this process for the remainder of the array 
starting at the second position and so on while advancing each time and swapping if it encounters a smaller value until the array is completely sorted
this is done in O(n^2) in a best case scenario.  
array[] - The array that we are passing into the function to perform the selection sort algorithm on
*/
void sortArray(int array[])
{
	int x, y, min;
	for (x = 0; x < ARRAY_SIZE - 1; x++)
	{
		min = x; 
		for (y = x + 1; y < ARRAY_SIZE; y++)
		{
			if (array[y] < array[min])
			{
				min = y; 
			}
		}
		if (min != x)
		{
			swap(array, x, min); 
		}
	}
}

/*
Function that performs the swapping for our selection sort if it encounters a value that is smaller than the current index it is being compared to
array[] - The array that we are passing into the function so we can swap the values at each index that is being compared
pos1 - the first position in the array that is being swapped
pos2 - The second position in the array that is being swapped
*/
void swap(int array[], int pos1, int pos2)
{
	int temp = array[pos2];
	array[pos2] = array[pos1];
	array[pos1] = temp; 
}

/*
Function that performs all of our statistical calculations for min, max, median, and average calculations from our array
array[] - The array that we are passing into the function to perform the statistical calculations on
*pMin - Pointer to our minimum value
*pMax - Pointer to our maximum value
*pMedian - Pointer to our median value
*pAverage - Pointer to our average value 
*/
void calculateStatistics(int array[], int *pMin, int *pMax, double *pMedian, double *pAverage)
{
	*pMin = getMin(array);
	*pMax = getMax(array);
	*pMedian = getMedian(array);
	*pAverage = getAverage(array); 
}

/*
Function that generates our random number based on our seed and count values that are passed into the function 
and updates the count of how many times a random number was generated in our array from 0 to 99.
array[] - The array that is being passed into the function to store our random number counts in the corresponding index
seed - The seed value that is retrieved from the input file that is used as a starting point for our random number function call
count - The count value that is retrieved from the input file that is used as the amount of times a random number can be generated 
*/
void generateNumbers(int array[], int seed, int count)
{
	initializeArray(array); 
	//Initialization of index
	int x;
	srand(seed); 
	
	for (x = 0; x < count; x++)
	{
		array[rand()%100]++; 
	}
}

/*
Function that initializes our array to have a value of zero in every index from 0 all the way to the size of our array which in this case is 100
array[] - The array that is being passed into the function for initialization by our intailizeArray function
*/
void initializeArray(int array[])
{
	int x = 0;
	for (x = 0; x<ARRAY_SIZE; x++)
	{
		array[x] = 0;
	}
}

/*
Function that displays the statistical calculations based of our array including values for min, max, median, average, and the position of the index in the array
as well as the count of how many times a random number was generated as well as the percentage derived from the total amount of numbers generated
array[] - The array that is passed into the function to display the statiscal data that was calculated by our previous functions
count - The value of how many random numbers were generated
min - The minimum value of how many times a random number was generated
max - The maximum value of how many times a random number was generated
median - The median value derived from the random numbers that were generated
average - The average value derived from the random numbers that were generated 
*/
void printReport(int array[], int count, int min, int max, double median, double average)
{	
	//Index for our loop 
	int x;

	printf("%s %d\n", "Minimum Count:", min);
	printf("%s %d\n", "Maximum Count:", max);
	printf("%s %2.2f\n", "Median Count:", median);
	printf("%s %2.2f\n\n", "Average Count:", average);
	printf("Array analysis (Position: Count [Percentage])\n\n");

	for (x = 0; x < ARRAY_SIZE; x++)
	{
		if (x % 8==0)
		{
			printf("\n"); 
		}
		printf("%2d : %2d [%2.1f%%] ", x, array[x], (double)array[x] / count * 100);
	}
};