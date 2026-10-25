#include <stdio.h>
#include <string.h>
#define MAX 5

struct PrintJob
{
int id;
char title[50];
};
struct PrintJob queue[MAX];
int front = -1;
int rear = -1;

void enqueue()
{
struct PrintJob job;

if ((rear + 1) % MAX == front)
{
printf("Queue Overflow! Print queue is full.\n");
return;
}
printf("Enter Print Job ID: ");
scanf("%d", &job.id);
printf("Enter Document Title: ");
scanf("%s", job.title);

if (front == -1)
{
front = 0;
rear = 0;
}
else
{
rear = (rear + 1) % MAX;
}
queue[rear] = job;
printf("Print job is added successfully to the queue.\n");
}

void dequeue()
{
if (front == -1)
{
printf("Queue Underflow! No print jobs available.\n");
return;
}
printf("Print job ID %d (%s) is removed and processed.\n",
queue[front].id, queue[front].title);

if (front == rear)
{
front = -1;
rear = -1;
}
else
{
front = (front + 1) % MAX;
}
}
void display()
{
int i;
if (front == -1)
{
printf("No pending print jobs available.\n");
return;
}
printf("\nPending Print Jobs in FIFO order:\n");
i = front;
while (1)
{
printf("Job ID: %d\tDocument: %s\n",
queue[i].id, queue[i].title);
if (i == rear)
{
break;
}

i = (i + 1) % MAX;
}
}

int main()
{
int choice;
printf("===== PRINTER QUEUE MANAGER =====\n");
while (1)
{
printf("\n1. Enqueue Print Job");
printf("\n2. Dequeue Print Job");
printf("\n3. Display Queue");
printf("\n4. Exit");
printf("\n\nEnter your choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
enqueue();
break;
case 2:
dequeue();
break;
case 3:
display();
break;
case 4:
printf("Program terminates successfully.\n");
return 0;
default:
printf("Invalid choice! Please try again.\n");
}
}
return 0;
}