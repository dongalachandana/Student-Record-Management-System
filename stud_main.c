#include"student.h"
void load(void);
struct student *head=NULL;
int main()
{
	load();
	int c;
	char op;
	while(1)
	{
		printf("**************Student Record Menu***************\n");
		printf("a/A : Add new record \n");
		printf("d/D : Delete a record \n");
		printf("s/S : Show the list \n");
		printf("m/M : Modify a record \n");
		printf("v/V : Save records \n");
		printf("t/T : Sort the list \n");
		printf("l/L : Delete all the records \n");
		printf("r/R : Reverse the list \n");
		printf("e/E : Exit\n");
		printf("Enter your choice:\n");
		scanf(" %c",&op);
		switch(op)
		{
			case 'A':
			case 'a':add();break;
			case 'D':
			case 'd':del();break;
			case 'S':
			case 's':show();break;
			case 'M':
			case 'm':modify();break;
			case 'V':
			case 'v':save();break;
			case 'T':
			case 't':sort();break;
			case 'L':
			case 'l':del_all();break;
			case 'R':
			case 'r':reverse();break;
			case 'E':
			case 'e':exit_main();break;
			default:printf("Invalid Choice\n");
		}
	}
	return 0;
}
