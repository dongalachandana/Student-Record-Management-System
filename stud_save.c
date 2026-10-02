#include"student.h"
void save(void)
{
	printf("****************\n");
	if(head==0)
	{
		printf("No records found\n");
		return;
	}
	struct student *p=head;

	FILE *fp=fopen("student.data","w");
	while(p)
	{
		fprintf(fp,"%d %s %f\n",p->rollno,p->name,p->percentage);
		p=p->next;
	}
	printf("Data saved in file\n");
	printf("****************\n");
	fclose(fp);
}

void load(void)
{
	FILE *fp=fopen("student.data","r");
	if(fp==0)
		return;
	struct student *new,*last;
	int roll;char name[20];float percent;
	while(fscanf(fp,"%d%s%f",&roll,name,&percent)==3)
	{
		new=malloc(sizeof(struct student));
		new->rollno=roll;
		strcpy(new->name,name);
		new->percentage=percent;
		new->next=0;
		if(head==0)
			head=new;
		else
		{
			last=head;
			while(last->next)
				last=last->next;
			last->next = new;
		}
	}
	fclose(fp);
}

void exit_main(void)
{
	char op;
	printf("Enter your choice:\n");
	printf("S/s : Save and exit\n");
	printf("E/e : Exit without saving\n");
	scanf(" %c",&op);
	switch(op)
	{
		case 'S':
		case 's':save();del_all();exit(0);
		case 'E':
		case 'e':del_all();exit(0);
		default:printf("Invalid Choice\n");
	}
}
