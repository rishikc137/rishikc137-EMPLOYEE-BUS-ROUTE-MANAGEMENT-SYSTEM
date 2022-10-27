#ifndef __MAIN_H__
#define __MAIN_H__
#include <struct.h>

// Forward declarations of the functions

// Functions in listMgmt.c
extern employee * read_usr_csv();//reading the info of users from csv file
extern employee * read_queue_csv();//reading the info of users who are in queue from csv file
extern bus *  read_bus_csv();//reading the info of bus from csv file 

// Functions in crud.c
extern void add_user( int flag ,employee* ab);//for Admin for adding the user
extern void add_req();//for requesting the bus facility for user
extern void del_user(int d,int id,int rou);//for Admin  for removing user from queue or from the route
extern void op_req();//for User to opt out from the bus facility
extern void mod_user();//Option for  Admin  to update/change the name of the user

//functions in utility.c
extern void see_bus();//Option for  Admin  to see the status of the different buses
extern void see_user();//Option for Admin  to see the info of user availing the bus facilty
extern void see_queue();//Option for  Admin   to see the info of user in the queue

#endif
