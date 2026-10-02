#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

struct student
{
int rollno;
char name[50];
float percentage;
struct student *next;
};
extern struct student *head;

void add(void);
void show(void);
void del(void);
void modify(void);
void del_all(void);
void sort(void);
void save(void);
void reverse(void);
void exit_main(void);
