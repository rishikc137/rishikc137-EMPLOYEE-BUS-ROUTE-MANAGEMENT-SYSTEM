#pragma once

#define stop_len 100
#define name_len 100
#define LINE_SIZE 100

typedef struct _bus_ //structure for reading/writing info of bus
{
	int broute;
	char stops[stop_len];
	int total_seats;
	int seats_fill;
	struct _bus_ * next;
}bus;

typedef struct _emp_ //structure for reading/writing info of employees
{
	int job_id;
	char name[name_len];
	int route;
	struct _emp_ * next1;
}employee;

