/*   File name - main.c
 *   
 *   Description - This file presents a menu in front of the user who is using the program and call the functions accordigly.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>

int main()
{
	int a,b,c,d,i;
	do
	{	
		printf("\n******MENU******\n1.Admin \n2.User\n3.Exit\nEnter your choice : ");
		scanf("%d",&a);//get the choice of the user wether he is a admin or user
		if(a==1)//check if the person selcted the admin option
		{
			printf("Enter your password: ");
			scanf("%d",&b);
			if(b==123)//validating the password
			{
				printf("Acess Granted....\n");
				printf("\n\n******ADMIN MENU******\n1.Add User\n2.Delete User\n3.Modify User\n4.See Bus Info\n5.See info of  users in route\n6.See info of users in queue\n7.Exit\nEnter your choice: ");
				scanf("%d",&c);
				if(c==1)//check if admin selected the add user option
				{
					int flag=0;
					i=1;
					add_user(flag,NULL);
				}	
				else if(c==2)//check if admin selected the delete user option
				{
					int d=1;
					i=1;
					del_user(d,0,0);
				}
				else if(c==3)//check if admin selected the modify user option
				{
					mod_user();
					i=1;
				}
				else if(c==4)//check if admin selected to see the bus info
				{
					see_bus();
					i=1;
				}	
				else if(c==5)//check if admin selected to see user info
				{
					see_user();
					i=1;
				}	
				else if(c==6)//check if admin selected to see the users who are in queue
				{
					i=1;
					see_queue();
				
				}	
				else//if admin wants to exit 
					return(0);	
			}
			else 
			{
				printf("Acess Denied....\n");//if the person inserted wrong password
				return(0);
			}
		}
		else if(a==2)//check if the person selected the user option
		{
	        	printf("\n\n******USER MENU******\n1.Add Request\n2.Opt out Request\n3.Exit\nEnter your choice : ");
			scanf("%d",&d);//getting the choice of the user
			if(d==1)//check if the user wants to avail the bus facility
			{
				add_req();
				i=1;
			}
			else if(d==2)//check if the user want to opt out from the bus facility
			{
				op_req();
				i=1;
			}
			else//if the user wants to exit
				return(0);	
		}
		else if(a==3)//if the person choose to exit from the main menu
		{        
			return(0);
		}	
		else 
		{       
			i=0;
			printf("Wrong Choice,Enter a valid choice...\n");//if the person enters a wrong choice in the main menu
		}	

	}while(i==0);//loop to validate if the person enters the valid choice or not,loop goes on untill the user give a valid choice
}    	

