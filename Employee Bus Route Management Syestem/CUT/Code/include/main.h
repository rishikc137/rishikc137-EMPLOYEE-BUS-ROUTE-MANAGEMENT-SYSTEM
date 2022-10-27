#ifndef __MAIN_H__
#define __MAIN_H__
#include <struct.h>

// Forward declarations of the functions
extern employee * read_usr_csv();
extern employee * read_queue_csv();
extern bus *  read_bus_csv();
extern void add_user( int flag ,employee* ab);
extern void add_req();
extern void del_user(int d,int id,int rou);
extern void op_req();
extern void mod_user();
extern void see_bus();
extern void see_user();
extern void see_queue();

#endif
