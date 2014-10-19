Using the stdbool.h header file.

The stdbool.h header file add the Boolean data type "bool" and the Boolean values "true" and "false" to a C program.  To add the stdbool.h header file to Visual Studio's Visual C++ programming environment, copy the stdbool.h file to the following path (replace <username> with your username):  

	C:\Users\<username>\Documents\Visual Studio 201x\Projects\

Note:  The above file path is for Windows 7; therefore, other versions of Windows may require a slightly different path to work correctly.  Contact your instructor for assistance, if necessary.

To use the stdbool.h header file in a C program, simply add the following preprocessor statement to the code:

	#include "..\..\stdbool.h"

To test the stdbool.h header file, copy the following code into a C program:

	/*
		Test of the stdbool.h header file.
	*/
	
	#include <stdio.h>
	#include <stdlib.h>
	#include "..\..\stdbool.h"
	
	int main()
	{
		bool itWorks = true;
		
		if(itWorks)
		{
			printf("It works!\n");
		}
		system("pause");
		return 0;
	}