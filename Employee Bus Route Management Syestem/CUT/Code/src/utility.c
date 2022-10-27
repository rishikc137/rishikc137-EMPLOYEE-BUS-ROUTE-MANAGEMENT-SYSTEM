#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>

void see_bus()
{
	bus * front1 = read_bus_csv();
	printf("Route | Stops    | Total Seats | Seats Fill\n");
	while(front1 != NULL)
	{
		bus * eiter1 = NULL;
		printf("%3d   |%10s|      %d      |      %d\n",front1 -> broute,front1 -> stops,front1 -> total_seats,front1 -> seats_fill);
		eiter1 = front1;
		front1 = front1 -> next;
		free(eiter1);
	}
	
}

void see_user()
{
	employee *front = read_usr_csv();
		printf("Job ID|   NAME   | Route No.\n");
	while(front != NULL)
	{
		employee * eiter;
		eiter=front;
		printf("%3d   |%10s|  %d\n",eiter ->job_id,eiter ->name,eiter ->route);
		front =front -> next1;
		free(eiter);
	}	
}

void see_queue()
{

	employee *front = read_queue_csv();
		printf("Job ID|   NAME   | Route No.\n");
	while(front != NULL)
	{
		employee * eiter;
		eiter=front;
		printf("%3d   |%10s|  %d\n",eiter ->job_id,eiter ->name,eiter ->route);
		front =front -> next1;
		free(eiter);
	}	
	
}
