/*	File name - utility.c
 *
 *	Description - This file output the contents of all csv files in readable manner 
*/	





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>

void see_bus()//to display the bus info,can be used by admin only
{
	bus * front1 = read_bus_csv();
	printf("\n\nThe Bus info is as follows :\n");
	printf("\tRoute | Stops    | Total Seats | Seats Fill\n");
	while(front1 != NULL)
	{
		bus * eiter1 = NULL;
		printf("\t%3d   |%10s|      %d      |      %d\n",front1 -> broute,front1 -> stops,front1 -> total_seats,front1 -> seats_fill);
		eiter1 = front1;
		front1 = front1 -> next;
		free(eiter1);
	}
	
}

void see_user()//fordisplaying the info of users availing the bus facility
{
	employee *front = read_usr_csv();
	printf("\n\nThe user info who are availing the bus facility and  whose salary needs to be cut is as follows :\n");
		printf("\tJob ID|   NAME   | Route No.\n");
	while(front != NULL)
	{
		employee * eiter;
		eiter=front;
		printf("\t%3d   |%10s|  %d\n",eiter ->job_id,eiter ->name,eiter ->route);
		front =front -> next1;
		free(eiter);
	}	
}

void see_queue()//displaying the info of users who are in queue 
{

	employee *front = read_queue_csv();
	printf("\n\nUsers in queue :\n");
		printf("\tJob ID|   NAME   | Route No.\n");
	while(front != NULL)
	{
		employee * eiter;
		eiter=front;
		printf("\t%3d   |%10s|  %d\n",eiter ->job_id,eiter ->name,eiter ->route);
		front =front -> next1;
		free(eiter);
	}	
	
}
