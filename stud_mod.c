#include"student.h"
void search_by_roll(void);
void search_by_name(void);
void search_by_percent(void);
int countNode(void);
void sort_by_name(void);
void sort_by_percentage();
void modify(void)
{
	struct student *p=head;
	if(p==0)
	{
		printf("No records found\n");
		return ;
	}
	char op;
	printf("Enter which record to search for modification:\n");
	printf("R/r : Search by roll number\n");
	printf("N/n : Search by name\n");
	printf("P/p : Search by percentage\n");
	scanf(" %c",&op);
	switch(op)
	{	
		case 'R':	
		case 'r':search_by_roll();break;
		case 'N':
		case 'n':search_by_name();break;
		case 'P':
		case 'p':search_by_percent();break;
		default:printf("Invalid Choice\n");
	}
}

void search_by_percent(void)
{
	struct student *p=head;
	int c=0;float percent;
	printf("Enter percentage to search\n:");
	scanf("%f",&percent);
	while(p)
	{
		if(p->percentage==percent)
		{
			c++;
			printf("%d %s %f\n",p->rollno,p->name,p->percentage);
		}
		p=p->next;
	}
	if(c==0)
		printf("No record found with the given name\n");
	if(c>1)
	{
		search_by_roll();
	}
}

void search_by_name(void)
{
	struct student *p=head;
	char name[20];
	int c=0;
	printf("Enter name to search\n:");
	scanf(" %s",name);
	while(p)
	{
		if(strcmp(name,p->name)==0)
		{
			c++;
			printf("%d %s %f\n",p->rollno,p->name,p->percentage);
		}
		p=p->next;
	}
	if(c==0)
		printf("No record found with the given name\n");
	if(c>1)
	{
		search_by_roll();
	}
}

void search_by_roll(void)
{
	struct student *p=head;
	int roll,op,flag=0;
	printf("Enter rollno to search:\n");
	scanf("%d",&roll);
	while(p)
	{
		if(p->rollno==roll)
		{
			flag=1;
			printf("%d %s %f\n",p->rollno,p->name,p->percentage);
			printf("Do you want to change details?\n");
			printf("1.Yes\n 0.No\n");
			scanf("%d",&op);
			if(op)
			{
				printf("Enter updated details\n");
				scanf(" %s%f",p->name,&p->percentage);
			}
		}
		p=p->next;
	}
	if(flag==0)
		printf("No record found with given rollno\n");
}

void sort(void)
{
	if(head==0)
	{
		printf("No records found\n");
		return;
	}
	struct student *p=head;
	char op;
	printf("Enter your choice:\n");
	printf("N/n : Sort with name\n");
	printf("P/p : Sort with percentage\n");
	scanf(" %c",&op);
	switch(op)
	{
		case 'N':
		case 'n':sort_by_name();break;
		case 'P':
		case 'p':sort_by_percentage();break;
		default:printf("Invalid choice\n");
	}
}

void reverse(void)
{
	if(head==0)
	{
		printf("No records found\n");
		return;
	}
	struct student  *p=head,**a,*t=head;
	int i,c=countNode();
	if(c>1)
	{
		a=malloc(sizeof(struct student*)*c);
		for(i=0;i<c;i++)
		{
			a[i]=t;
			t=t->next;
		}
		for(i=c-1;i>0;i--)
			a[i]->next=a[i-1];
		a[0]->next=0;
		head=a[c-1];
	}
}
void sort_by_name(void)
{
	struct student *p=head,*q,t;
	int i,j,c=countNode();
	for(i=0;i<c-1;i++)
	{
		q=p->next;
		for(j=0;j<c-1-i;j++)
		{
			if(p->name[0] < q->name[0])
			{
				t.rollno=p->rollno;
				strcpy(t.name,p->name);
				t.percentage=p->percentage;
				p->rollno=q->rollno;
				strcpy(p->name,q->name);
				p->percentage=q->percentage;
				q->rollno=t.rollno;
				strcpy(q->name,t.name);
				q->percentage=t.percentage;
			}
			q=q->next;
		}
		p=p->next;
	}
}
void sort_by_percentage(void)
{
	struct student *p=head,*q,t;
	int i,j,c=countNode();
	for(i=0;i<c-1;i++)
	{
		q=p->next;
		for(j=0;j<c-1-i;j++)
		{
			if(p->percentage < q->percentage)
			{
				t.rollno=p->rollno;
				strcpy(t.name,p->name);
				t.percentage=p->percentage;
				p->rollno=q->rollno;
				strcpy(p->name,q->name);
				p->percentage=q->percentage;
				q->rollno=t.rollno;
				strcpy(q->name,t.name);
				q->percentage=t.percentage;
			}
			q=q->next;
		}
		p=p->next;
	}
}

int countNode(void)
{
	int c=0;
	struct student *p=head;
	while(p)
	{
		c++;
		p=p->next;
	}
	return c;
}
