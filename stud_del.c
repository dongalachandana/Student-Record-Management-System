#include"student.h"
void del_by_roll(void);
void del_by_name(void);
void del(void)
{
	struct student *p=head;
	if(p==0)
	{
		printf("No records found\n");
		return ;
	}
	char op;
	printf("Enter your choice:\n");
	printf("R/r : Enter roll number to delete\n");
	printf("N/n : Enter name to delete\n");
	scanf(" %c",&op);
	switch(op)
	{
		case 'R':
		case 'r':del_by_roll();break;
		case 'N':
		case 'n':del_by_name();break;
		default:printf("Invalid choice\n");
	}
}

void del_by_roll(void)
{
	struct student *p=head,*del=head,*prev;
	int roll;
	printf("Enter rollno to delete:");
	scanf("%d",&roll);
	while(del)
	{
		if(del->rollno==roll)
		{
			if(del==head)
				head=del->next;
			else
				prev->next=del->next;
			free(del);
			return;
		}
		prev=del;
		del=del->next;
	}
	printf("Rollno not found\n");
}

void del_by_name(void)
{
	struct student *p=head,*del=head,*prev;
	char name[20];
	printf("Enter name to delete:");
	scanf("%s",name);
	while(del)
	{
		if(strcmp(name,del->name)==0)
		{
			if(del==p)
				p=del->next;
			else
				prev->next=del->next;
			free(del);
			return;
		}
		prev=del;
		del=del->next;
	}
	printf("Name not found\n");
}

void del_all(void)
{
	if(head==0)
	{
		printf("No records found\n");
		return;
	}
	struct student *del=head;
	while(del)
	{
		head=del->next;
		free(del);
		del=head;
	}
	printf("************************************\n");
	printf("All nodes are deleted\n");
	printf("************************************\n");
}
