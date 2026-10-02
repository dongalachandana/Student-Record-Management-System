#include"student.h"
void show(void)
{
printf("***************************\n");
printf("Rollno Name     Percentage\n");
printf("***************************\n");
if(head==0)
{
printf("No records found\n");
printf("***************************\n");
return;
}
struct student *p=head;
while(p)
{
printf("%d %s %f\n",p->rollno,p->name,p->percentage);
p=p->next;
}
printf("***************************\n");
}
