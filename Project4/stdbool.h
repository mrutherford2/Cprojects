/*
	Title:		stdbool.h
	Authour:	Jim Littleton
	Course:		COP2220
	Due Date:	October 1, 2013

	This header file provides the Boolean data type "bool"
	and the Boolean values "true" and "false".

	When using Visual Studio's Visual C++ programming environment,
	this header file can be placed in the following path:

	C:\Users\<username>\Documents\Visual Studio 2012\Projects\

	To access this header file within a C program using the 
	Visual C++ programming environment, add the following
	preprocessor statement:

	#include "..\..\stdbool.h"
*/

#define bool int
#define false 0
#define true !(false)