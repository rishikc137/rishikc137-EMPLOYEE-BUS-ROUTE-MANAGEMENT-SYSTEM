#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>

employee * read_usr_csv()
{
	
	FILE * fptr;
	fptr= fopen("../data/usr.txt","r");
	char empline[LINE_SIZE];
	char * token;
	employee* front= NULL;
	employee* rear= NULL;
	while(fgets(empline, LINE_SIZE, fptr) != NULL)
	{	
		employee* eiter= (employee*) malloc(sizeof(employee));
		token = strtok (empline, ",");
    		if ( token != NULL )
    		{
        		eiter ->job_id = atoi(token);
   	 	}
    		token = strtok (NULL, ",");
    		if ( token != NULL )
    		{
        		strncpy (eiter -> name, token, name_len-1);
        	

    		}
    		token = strtok (NULL, ",");
    		if ( token != NULL )
    		{
       
        		eiter -> route = atoi(token);

    		}
		eiter->next1=NULL;
		{
			if(front==NULL)
			{
				front = eiter;
				rear = eiter;
			}	
			else 
			{
				rear -> next1 = eiter;
				rear = eiter;
			}
		}	
			
	}
	fclose(fptr);
	return(front);
}	

employee * read_queue_csv()
{
	
	FILE * fptr;
	fptr= fopen("../data/queue.txt","r");
	char empline[LINE_SIZE];
	char * token;
	employee* front= NULL;
	employee* rear= NULL;
	while(fgets(empline, LINE_SIZE, fptr) != NULL)
	{	
		employee* eiter= (employee*) malloc(sizeof(employee));
		token = strtok (empline, ",");
    		if ( token != NULL )
    		{
        		eiter ->job_id = atoi(token);
   	 	}
    		token = strtok (NULL, ",");
    		if ( token != NULL )
    		{
        		strncpy (eiter -> name, token, name_len-1);
        	

    		}
    		token = strtok (NULL, ",");
    		if ( token != NULL )
    		{
       
        		eiter -> route = atoi(token);

    		}
		eiter->next1=NULL;
		{
			if(front==NULL)
			{
				front = eiter;
				rear = eiter;
			}	
			else 
			{
				rear -> next1 = eiter;
				rear = eiter;
			}
		}	
			
	}
	fclose(fptr);
	return(front);
}

bus * read_bus_csv()
{
	FILE * fptr;
	fptr= fopen("../data/bus.txt","r");
	char empline[LINE_SIZE];
	char * token;
	bus * front= NULL;
	bus* rear= NULL;
	while(fgets(empline, LINE_SIZE, fptr) != NULL)
	{	
		bus* eiter= (bus*) malloc(sizeof(employee));
		token = strtok (empline, ",");
    		if ( token != NULL )
    		{
        		eiter -> broute = atoi(token);
   	 	}
    		token = strtok (NULL, ",");
    		if ( token != NULL )
    		{
        		strncpy (eiter -> stops, token, name_len-1);
        	

    		}
    		token = strtok (NULL, ",");
    		if ( token != NULL )
    		{
       
        		eiter -> total_seats = atoi(token);

    		}
		token=strtok(NULL,",");
    		if ( token != NULL )
    		{
       
        		eiter -> seats_fill = atoi(token);

    		}
		eiter -> next =NULL;
		{
			if(front==NULL)
			{
				front = eiter;
				rear = eiter;
			}	
			else 
			{
				rear -> next = eiter;
				rear = eiter;
			}
		}	
			
	}
	fclose(fptr);
	return(front);
}
