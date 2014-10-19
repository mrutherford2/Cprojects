/*
	Authors: Matt Rutherford, Megan Molumby, Abubakr Hassan
	Course: COP2220
	Project #: 2 
	Title: Modularized Conversion Tool
	Due Date: 10/5/2014

	Prompts user to input values for fahrenheit, feet, and pounds. Checks user input to make sure it is an integer
	and within a specified range and then displays the original and converted values in a table format. 
*/
#include<stdio.h>
#include<stdlib.h>

#define HEADER_FORMAT "%15s%15s%15s%15s%15s%15s\n"
#define ROW_FORMAT "%15s%15d%15s%15.3f%15s%15.3f\n"
#define FEET_CONVERSION_VALUE 0.3048
#define POUND_CONVERSION_VALUE 0.4536
#define INCHES_CONVERSION_VALUE 12
#define FAHRENHEIT_CONVERSION_VALUE 32.000
#define KELVIN_CONVERSION_VALUE 459.67
#define STONES_CONVERSION_VALUE 0.0714285714

//Function Prototypes 
void convertDistance(int feet, double *pMeters, double *pInches);
void convertTemperature(int fahrenheit, double *pCelsius, double *pKelvin);
void convertWeight(int pounds, double *pKilograms, double *pStones);
void displayReport(int fahrenheit, int feet, int pounds, double celsius, double meters, double kilograms, double kelvin, double inches, double stones);
int getInput(int *pFahrenheit, int *pFeet, int *pPounds);
void performConversions(int fahrenheit, int feet, int pounds, double *pCelsius, double *pMeters, double *pKilograms, double *pKelvin, double *pInches, double *pStones);
int withinRange(int input, int minRange, int maxRange);

int main()
{
	//Variables to store our original and converted values
	int temp, weight, distance;
	double celcius, meters, kilograms, kelvin, inches, stones;

	//Displays Name of Authors and Project
	printf("%s", "Matt Rutherford, Meghan Molumby, Abubakr Hassan\n");
	printf("%s", "Project 2 - Modularized Unit Conversion Tool\n");

	//Calls getInput function and if we have bad input the conversions and display functions are not executed. 
	if (getInput(&temp, &distance, &weight) == 1)
	{
		//Performs unit conversions
		performConversions(temp, distance, weight, &celcius, &meters, &kilograms, &kelvin, &inches, &stones);

		//Displays original and converted values 
		displayReport(temp, distance, weight, celcius, meters, kilograms, kelvin, inches, stones);
	}

	system("pause");
	return 0;
}

/*
Prompts user to enter integer values for Farenheit, Feet, and Pounds. Checks to see if user
entered an actual integer and if the value is within the specified range for each input. If it is not an integer value it will 
display the appropriate error message.
*pFahrenheit - Pointer for the Fahrenheit value
*pFeet - Pointer for the Feet value
*pPounds - Pointer for the Pounds value
Returns the status of our flag variable
*/
int getInput(int *pFahrenheit, int *pFeet, int *pPounds)
{
	//Flag variable for valid input, default value is set to false until we do our checking 
	int isValid = 0;

	//Gets user input for fahrenheit 
	printf("%s", "\nEnter a Fahrenheit temperature (integer) [0 - 212]: ");
	if (scanf_s("%d", pFahrenheit) == 1)
	{
		//Checks range for fahrenheit  
		if (withinRange(*pFahrenheit, 0, 212) == 1)
		{
			//Gets user input for feet 
			printf("%s", "Enter a distance in feet (integer) [0 - 100]: ");
			if (scanf_s("%d", pFeet) == 1)
			{
				//Checks range for feet 
				if (withinRange(*pFeet, 0, 100) == 1)
				{
					//Gets user input for pounds 
					printf("%s", "Enter a weight in pounds (integer) [0 - 100]: "); 
					if (scanf_s("%d", pPounds) == 1)
					{
						//Checks range for pounds 
						if (withinRange(*pPounds, 0, 100) == 1)
						{	
							//All input is good, set flag variable to a true value 
							isValid = 1; 
						}
					}
					else 
					{
						printf("%s", "\nThe entered weight is invalid.\n");
					}
				}
			}
			else
			{
				printf("%s", "\nThe entered distance is invalid.\n"); 
			}
		}
	}
	else
	{
		printf("%s", "\nThe entered temperature is invalid.\n"); 
	}
	 
	return isValid;
}

/*
Checks the range of the integer values entered by the user. 
If the value is not within range the user is prompted with an error message displaying the min and max range for that value.
input - The input for checking if it is within range
minRange - The minimum range for our input
maxRange - The maximum range for our input
Returns the status of our flag variable 
*/
int withinRange(int input, int minRange, int maxRange)
{
	//Flag variable for within range, default value is set to true until we check the range
	int isWithinRange = 1; 

	if (input < minRange || input > maxRange)
	{
		isWithinRange = 0;
		printf("%s%d%s%d%s", "\nThe entered value is out of range [", minRange, " - ", maxRange, "].\n");
	}
	
	
	return isWithinRange; 
}

/*
Calls functions to perform conversions for Temperature, Distance, and Weight
fahrenheit - The fahrenheit value for temeperature conversion
feet - The feet value for distance conversion
pounds - The pounds value for weight conversion
*pCelsius - Pointer for celsius value for temperature conversion
*pMeters - Pointer for meters value for distance conversion
*pKilograms - Pointer for kilograms value for weight conversion
*pKelvin - Pointer for kelvin value for temperature conversion
*pInches - Pointer for inches value for distance conversion
*pStones - Pointer for stones value for weight conversion 
*/
void performConversions(int fahrenheit, int feet, int pounds, double *pCelsius, double *pMeters, double *pKilograms, double *pKelvin, double *pInches, double *pStones)
{
	convertDistance(feet, pMeters, pInches);
	convertTemperature(fahrenheit, pCelsius, pKelvin);
	convertWeight(pounds, pKilograms, pStones); 
}

/*
Converts feet value entered by user to Meters and Inches and then derefrences the pointers to store our new converted values.
feet - Value for feet used in the conversion
*pMeters - Pointer for meters used in the conversion
*pInches - Pointer for inches used in the conversion 
*/
void convertDistance(int feet, double *pMeters, double *pInches)
{
	*pMeters = (feet * FEET_CONVERSION_VALUE); 
	*pInches = (feet * INCHES_CONVERSION_VALUE);
}

/*
Converts Fahrenheit value entered by user to Celsius and Kelvin  and then derefrences the pointers to store our new converted values.
fahrenheit - Value for fahrenheit used in the conversion
*pCelsius - Pointer for celsius used in the conversion
*pKelvin - Pointer for kelvin used in the conversion 
*/
void convertTemperature(int fahrenheit, double *pCelsius, double *pKelvin)
{
	*pCelsius = (fahrenheit - FAHRENHEIT_CONVERSION_VALUE) * 5 / 9;
	*pKelvin = (fahrenheit + KELVIN_CONVERSION_VALUE) * 5/9; 
}

/*
Converts Pounds value enetered by user to Kilograms and Stones and then derefrences the pointers to store our new converted values.
pounds - Value for pounds used in the conversion
*pKilograms - Pointer for kilograms used in the conversion
*pStones - Pointer for stones used in the conversion
*/
void convertWeight(int pounds, double *pKilograms, double *pStones)
{
	*pKilograms = pounds * POUND_CONVERSION_VALUE; 
	*pStones = pounds * STONES_CONVERSION_VALUE;
}

/*
Displays formatted column headers and rows as well as displaying our original values along with our converted values to the user
fahrenheit - Fahrenheit value used for displaying result
feet - Feet value used for displaying result
pounds - Pounds value used for displaying result
celsius - Celsius value used for displaying result
meters - Meters value used for displaying result
kilograms - Kilograms value used for displaying result
kelvin - Kelvin value used for dispalying result
inches - Inches value used for dispalying result 
stones - Stones value used for displaying result 
*/
void displayReport(int fahrenheit, int feet, int pounds, double celsius, double meters, double kilograms, double kelvin, double inches, double stones)
{
	printf("%s", "\n");
	printf(HEADER_FORMAT, "Original", "Value", "Converted to", "Value", "Converted to", "Value"); 
	printf(HEADER_FORMAT, "--------", "-----", "------------", "-----", "------------", "-----");
	printf(ROW_FORMAT, "Fahrenheit", fahrenheit, "Celsius", celsius, "Kelvin", kelvin);
	printf(ROW_FORMAT, "Feet", feet, "Meters", meters, "Inches", inches); 
	printf(ROW_FORMAT, "Pounds", pounds, "Kilograms", kilograms, "Stones", stones); 
}




