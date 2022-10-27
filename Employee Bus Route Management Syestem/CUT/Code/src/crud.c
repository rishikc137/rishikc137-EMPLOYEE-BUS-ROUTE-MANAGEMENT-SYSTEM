/*   File name - crud.c
 *   Description - It contains functions which perform various actions such as
 *   			
 *   			1. Add User
 *   			2. Delete User
 *   			3. Modify User Info
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>

void add_user(int flag,employee * ab)//this function adds the user in the list or queue according to seat availability
{
	employee *eiter= (employee*) malloc(sizeof(employee));
	bus *front1=read_bus_csv();
	int a=0;
	if(flag==0)//for admin
	{	
		printf("\n\n******ADD USER MENU******\nEnter job ID of the employee : ");
		scanf("%d",&(eiter ->job_id));
		printf("Enter Name of the employee : ");
		scanf("%s",eiter ->name);
		printf("Enter route number : ");
		scanf("%d",&(eiter ->route));
	}
	else//for user
	{
		eiter = ab;
	}
		
			FILE *fptr;
			fptr=fopen("../data/bus.txt","w");
	while(front1 != NULL)
	{
		bus *eiter1 = NULL;
		if(front1 -> broute == eiter -> route)//checking if the route number is valid or not
		{       
			if(front1 -> seats_fill < front1 -> total_seats)//checks the seat availability
			{
				front1 -> seats_fill=front1 -> seats_fill+1;//increasing the seat fill by 1 on that route
				FILE *fptr1;
				fptr1=fopen("../data/usr.txt","a");
				fprintf(fptr1,"%d,%s,%d\n",eiter ->job_id,eiter ->name,eiter ->route);//putting the user in route if seats are available
				fclose(fptr1);
				a=1;
				printf("User is added to the route...\n\n");
			}
			else
			{
				FILE *fptr2;
				fptr2=fopen("../data/queue.txt","a");
				fprintf(fptr2,"%d,%s,%d\n",eiter ->job_id,eiter ->name,eiter ->route);//putting the user in queue if seats not available
				fclose(fptr2);
				a=1;
				printf("No Seats left,user is added to the queue...\n\n");
			}	
		}
			fprintf(fptr,"%d,%s,%d,%d\n",front1->broute,front1->stops,front1->total_seats,front1->seats_fill);
			eiter1=front1;
			front1 = front1->next;
			free(eiter1);
	}
	if(a==0)
	{
		printf("Wrong route number given,the user is not addded....\n\n");//if the user enters  wrong route number
	}	
	fclose(fptr);	
	free(eiter);
	
}

void add_req()//User menu
{
	int flag=1;
	employee *eiter = (employee*) malloc(sizeof(employee));
	printf("\n\n******ADD USER MENU******\nEnter your job ID : ");
	scanf("%d",&(eiter ->job_id));
	printf("Enter your Name : ");
	scanf("%s",eiter ->name);
	printf("Enter route number : ");
	scanf("%d",&(eiter ->route));
	add_user(flag,eiter);
}	

void del_user(int d,int id,int rou)//Admin Menu
{
	int c=1;
	bus * front1 = read_bus_csv();
	employee *front=NULL;
	int a=0;
	if(d==1)//for admin
	{
		printf("\n\n******DELETE USER MENU******\n1.Delete the user from list\n2.Delete user from queue\nEnter your choice: ");
		scanf("%d",&c);
		if(c==1)//validating the choice enetered by admin
		{
	       		front= read_usr_csv();//reading the contents of user in the route
			printf("\n\nEnter the job ID for deletion : ");
			scanf("%d",&id);
			printf("Enter the route :");
			scanf("%d",&rou);
		}	
		else
		{	
			front=read_queue_csv();//reading the contents of user in queue
			printf("\n\nEnter the job ID for deletion : ");
			scanf("%d",&id);
			printf("Enter the route :");
			scanf("%d",&rou);

		}	
	}
	else//for user
		 front = read_usr_csv();
	

	if((d==1 || d==0) && c == 1) 
	{
		FILE *fptr1;
		fptr1=fopen("../data/bus.txt","w");
		while(front1 != NULL)
		{
			bus *eiter1 = NULL;
			if(front1 -> broute==rou)
			{
				front1 -> seats_fill=front1 -> seats_fill-1;//decreasing the seat number on particular route
			}	

			fprintf(fptr1,"%d,%s,%d,%d\n",front1 -> broute,front1 -> stops,front1 -> total_seats,front1 -> seats_fill);
			eiter1 = front1;
			front1 = front1 -> next;
			free(eiter1);
		}
		fclose(fptr1);
	}
	
	if((d==1 || d==0) && c == 1)//check for from where to delete the user from,from the route or from queue
	{	
		FILE * fptr2;
		fptr2=fopen("../data/usr.txt","w");//if the user is in the route	

		while(front != NULL)
		{
			if(front ->job_id != id)//check if the job ID matches with the choice 
			{	
				employee* eiter;	
				eiter=front;
				fprintf(fptr2,"%d,%s,%d\n",eiter ->job_id,eiter ->name,eiter ->route);
				front=front ->next1;
				free(eiter);
			}		
		
			else//deleting user from the route
			{
				employee * eiter;
				eiter= front;
				front = front -> next1;
				free(eiter);
				printf("User deleted from the route\n\n");
				a=1;
			}	

	
		}
		fclose(fptr2);
	}
	else//if the user is in the queue,this option is for admin only
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
		
			else//deleting the user from the queue
			{
				employee * eiter;
				eiter= front;
				front = front -> next1;
				free(eiter);
				printf("User is deleted from the queue\n\n");
			}	a=1;
		}
		fclose(fptr2);
		
	}
	if(a==0)//check if the route number or job id given for deletion is wrong
	{
		printf("Wrong route number or Job ID given,delete request failed....\n\n");
	}	
}

void op_req()//User menu
{
	int id,rou;
	printf("\n\n******DELETE USER MENU******\nEnter the job ID for deletion: ");
	scanf("%d",&id);
	printf("Enter the route number: ");
	scanf("%d",&rou);
	del_user(0,id,rou);

}
void mod_user()//modifying info of the users in queue or in route,can be done by ADMIN only
{
	int d,id;
	char name[name_len];
	printf("\n\n******MODIFY USER MENU******\n1.User is in the route\n2.User in queue\nEnter your choice: ");
        scanf("%d",&d);
	printf("Enter the job ID you want to modify information about: ");
	scanf("%d",&id);
	printf("Enter the new name :");
	scanf("%s",name);
	printf("User name modified....\n\n");
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
		
			else//modifying the name of the user in route
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
		
			else//modifying nameof the user in queue
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

