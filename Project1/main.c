/*
Author:	Matt Rutherford, Meghan Molumby, Abubakr Hassan
Course: COP2220
Project#: 1
Title	:	Project 1 - Unit Conversion Tool
Due Date:	9/14/2014

Prompts user for 3 integer values for Fahrenheit, pounds, and feet
converts them to their metric values, and then displays them in a formatted output. 
*/
#include<stdio.h>
#include<stdlib.h>
#define HEADER_FORMAT "%15s%15s%15s%15s\n"
#define ROW_FORMAT "%15s%15d%15s%15.3f\n"
#define FEET_CONVERSION_VALUE 0.3048
#define POUND_CONVERSION_VALUE 0.4536

int main()
{
	//Variables to store user input and converted values 
	int temp, weight, distance;
	double celcius, meters, kilos;

	//Displays Name of Authors and Project
	printf("%s", "Matt Rutherford, Megan Molumby, Abubakr Hassan, Emily Largent\n");
	printf("%s", "Project 1- Unit Conversion Tool\n");

	//Gets input from keyboard for calculations
	printf("\nEnter a Fahrenheit temperature (integer): ");
	scanf_s("%d", &temp);
	printf("Enter a distance in feet (integer): ");
	scanf_s("%d", &weight);
	printf("Enter a weight in pounds (integer): ");
	scanf_s("%d", &distance);
	printf("\n");

	//Performs unit conversion from user input values and stores them in variables so we can display them later 
	celcius = (temp - 32) * 5 / 9;
	kilos = (weight * POUND_CONVERSION_VALUE);
	meters = (distance * FEET_CONVERSION_VALUE);

	//Displays header, original values, and converted values. Constants are used to format the columns and values as required by the project specifications
	printf(HEADER_FORMAT,"Original","Value","Converted to","Value");
	printf(HEADER_FORMAT,"--------","-----","------------","-----");	
	printf(ROW_FORMAT, "Pounds", weight,"Kilograms", kilos);	
	printf(ROW_FORMAT, "Feet", distance, "Meters", meters);
	printf(ROW_FORMAT, "Fahrenheit", temp, "Celsius", celcius);
	system("pause");
	return 0; 

}