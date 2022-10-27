#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>

void add_user(int flag,employee * ab)
{
	employee *eiter= (employee*) malloc(sizeof(employee));
	bus *front1=read_bus_csv();
	if(flag==0)
	{	
		printf("Enter job ID of the employee : ");
		scanf("%d",&(eiter ->job_id));
		printf("Enter Name of the employee : ");
		scanf("%s",eiter ->name);
		printf("Enter route number : ");
		scanf("%d",&(eiter ->route));
	}
	else
	{
		eiter = ab;
	}
		
			FILE *fptr;
			fptr=fopen("../data/bus.txt","w");
	while(front1 != NULL)
	{
		bus *eiter1 = NULL;
		if(front1 -> broute == eiter -> route)
		{       
			if(front1 -> seats_fill < front1 -> total_seats)
			{
				front1 -> seats_fill=front1 -> seats_fill+1;
				FILE *fptr1;
				fptr1=fopen("../data/usr.txt","a");
				fprintf(fptr1,"%d,%s,%d\n",eiter ->job_id,eiter ->name,eiter ->route);
				fclose(fptr1);
			}
			else
			{
				FILE *fptr2;
				fptr2=fopen("../data/queue.txt","a");
				fprintf(fptr2,"%d,%s,%d\n",eiter ->job_id,eiter ->name,eiter ->route);
				fclose(fptr2);	
			}	
		}
			fprintf(fptr,"%d,%s,%d,%d\n",front1->broute,front1->stops,front1->total_seats,front1->seats_fill);
			eiter1=front1;
			front1 = front1->next;
			free(eiter1);
	}
	fclose(fptr);	
	free(eiter);
	
}

void add_req()
{
	int flag=1;
	employee *eiter = (employee*) malloc(sizeof(employee));
	printf("Enter your job ID : ");
	scanf("%d",&(eiter ->job_id));
	printf("Enter your Name : ");
	scanf("%s",eiter ->name);
	printf("Enter route number : ");
	scanf("%d",&(eiter ->route));
	add_user(flag,eiter);
}	

void del_user(int d,int id,int rou)
{
	int c=1;
	bus * front1 = read_bus_csv();
	employee *front=NULL;
	if(d==1)
	{
		printf("1.Delete the user from list\n2.Delete user from queue\nEnter your choice: ");
		scanf("%d",&c);
		if(c==1)
		{
	       		front= read_usr_csv();
			printf("enter the job ID for deletion : ");
			scanf("%d",&id);
			printf("Enter the route :");
			scanf("%d",&rou);
		}	
		else
		{	
			front=read_queue_csv();
			printf("enter the job ID for deletion : ");
			scanf("%d",&id);
			printf("Enter the route :");
			scanf("%d",&rou);
		}	
	}
	else
		 front = read_usr_csv();
	
	FILE *fptr1;
	fptr1=fopen("../data/bus.txt","w");

	if((d==1 || d==0) && c == 1) 
	while(front1 != NULL)
	{
			bus *eiter1 = NULL;
			if(front1 -> broute==rou)
			{
				front1 -> seats_fill=front1 -> seats_fill-1;
			}	

			fprintf(fptr1,"%d,%s,%d,%d\n",front1 -> broute,front1 -> stops,front1 -> total_seats,front1 -> seats_fill);
			eiter1 = front1;
			front1 = front1 -> next;
			free(eiter1);
			
	}
	fclose(fptr1);
	
	if((d==1 || d==0) && c == 1)
	{	
		FILE * fptr2;
		fptr2=fopen("../data/usr.txt","w");	

		while(front != NULL)
		{
			if(front ->job_id != id)
			{	
				employee* eiter;	
				eiter=front;
				fprintf(fptr2,"%d,%s,%d\n",eiter ->job_id,eiter ->name,eiter ->route);
				front=front ->next1;
				free(eiter);
			}		
		
			else
			{
				employee * eiter;
				eiter= front;
				front = front -> next1;
				free(eiter);
			}	

	
		}
		fclose(fptr2);
	}
	else
	{
		FILE * fptr2;
		fptr2 = fopen("../data/queue.txt","w");	

		while(front != NULL)
		{
			if(front ->job_id != id)
			{	
				employee* eiter;	
				eiter=front;
				fprintf(fptr2,"%d,%s,%d\n",eiter ->job_id,eiter ->name,eiter ->route);
				front=front ->next1;
				free(eiter);
			}		
		
			else
			{
				employee * eiter;
				eiter= front;
				front = front -> next1;
				free(eiter);
			}	

	
		}
		fclose(fptr2);
		
	}	
}

void op_req()
{
	int id,rou;
	printf("enter the job ID for deletion: ");
	scanf("%d",&id);
	printf("Enter the route number: ");
	scanf("%d",&rou);
	del_user(0,id,rou);

}
void mod_user()
{
	int d,id;
	char name[name_len];
	printf("1.User is in the route\n2.User in queue\n.Enter your choice: ");
        scanf("%d",&d);
	printf("Enter the job ID you want to modify information about: ");
	scanf("%d",&id);
	printf("Enter the new name :");
	scanf("%s",name);
	if(d==1)
	{
		employee *front = read_usr_csv();
		FILE * fptr2;
		fptr2=fopen("../data/usr.txt","w");	

		while(front != NULL)
		{
			if(front ->job_id != id)
			{	
				employee* eiter;	
				eiter=front;
				fprintf(fptr2,"%d,%s,%d\n",eiter ->job_id,eiter ->name,eiter ->route);
				front=front ->next1;
				free(eiter);
			}		
		
			else
			{
				employee * eiter;
				eiter= front;
				fprintf(fptr2,"%d,%s,%d\n",eiter ->job_id,name,eiter ->route);
				front = front -> next1;
				free(eiter);
			}	

	
		}
		fclose(fptr2);
	}
	else
	{
		employee *front = read_queue_csv();
		FILE * fptr2;
		fptr2=fopen("../data/queue.txt","w");	

		while(front != NULL)
		{
			if(front ->job_id != id)
			{	
				employee* eiter;	
				eiter=front;
				fprintf(fptr2,"%d,%s,%d\n",eiter ->job_id,eiter ->name,eiter ->route);
				front=front ->next1;
				free(eiter);
			}		
		
			else
			{
				employee * eiter;
				eiter= front;
				fprintf(fptr2,"%d,%s,%d\n",eiter ->job_id,name,eiter ->route);
				front = front -> next1;
				free(eiter);
			}	

	
		}
		fclose(fptr2);
		
	}	
}
