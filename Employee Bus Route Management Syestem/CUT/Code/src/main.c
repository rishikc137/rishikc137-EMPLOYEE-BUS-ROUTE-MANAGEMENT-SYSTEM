#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>

int main()
{
	int a,b,c,d;
	printf("1.Admin \n2.User\n3.Exit\nEnter your choice : ");
	scanf("%d",&a);
	if(a==1)
	{
		printf("Enter your password: ");
		scanf("%d",&b);
		if(b==123)
		{
			printf("Acess Granted....\n");
			printf("1.Add User\n2.Delete User\n3.Modify User\n4.See Bus Info\n5.See info of  users in route\n6.See info of users in queue\n7.Exit\nEnter your choice: ");
			scanf("%d",&c);
			if(c==1)
			{
				int flag=0;
				add_user(flag,NULL);
			}	
			else if(c==2)
			{
				int d=1;
				del_user(d,0,0);
			}
			else if(c==3)
			{
				mod_user();
			}
			else if(c==4)
			{
				see_bus();
			}	
			else if(c==5)
			{
				see_user();
			}	
			else if(c==6)
			{
				see_queue();
			}	
			else
				return(0);	
		}
		else 
		{
			printf("Acess Denied....\n");
			return(0);
		}
	}
	else if(a==2)
	{
	        printf("1.Add Request\n2.Opt out Request\n3.Exit\nEnter your choice : ");
		scanf("%d",&d);
		if(d==1)
		{
			add_req();
		}
		else if(d==2)
		{
			op_req();
		}
		else
			return(0);	
	}
	else
	{        
		return(0);
	}	
	        return(0);	
}    	

