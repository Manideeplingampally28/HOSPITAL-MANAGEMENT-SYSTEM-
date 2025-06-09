#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "hospital.h"
//global variables
int g;
//main starts here
main()
{
	printf("\n welcome to the HOSPITAL MANAGEMENT DATA\n\n\t 1.LOGIN\n\t 2.REGISTER\n\t 3.EXIT OR QUIT");
	scanf("%d",&g);
	switch(g)
	{
		case 1:login();
		break;
		case 2:signin();
		break;
		case 3:return(0);
		break;
		default:printf("\n option not found...........please enter the valid option........");
	}
return(0);	
}
