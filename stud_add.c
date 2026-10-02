#include"student.h"
void add(void)
{
	struct student *new,*p;
	int roll=1;
	new=malloc(sizeof(struct student));
	if(new==NULL)
	{
		printf("Malloc failed..\n");
		return;
	}
	printf("Enter the name,percentage:\n");
	scanf(" %s",new->name);
	while(1)
	{
		scanf("%f",&new->percentage);
		if(new->percentage>=0 && new->percentage<=100)
			break;
		else
			printf("Percentage should be in between 1 and 100\n");

	}
	if(head==0)
	{
		new->next=head;
		head=new;
		new->rollno=1;
	}
	else
	{
		while(1)
		{
			p=head;
			while(p)
			{
				if(p->rollno==roll)
					break;
				p=p->next;
			}
			if(p==0)
				break;
			roll++;
		}
		new->rollno=roll;
		new->next=0;
		p=head;
		while(p->next)
			p=p->next;
		p->next=new;
	}
}
