#include <stdio.h>
#include <string.h>

struct job
{
    int jobID;    
    char name[50];  
};

int length = 5;    
struct job j[5];    
int rear = -1;
int front = -1;     

int isEmpty()         
{
    if (rear == front)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    if (rear == length - 1)  
    {
        return 1;
    }
    return 0;
}

void add(struct job j[5], char name[50], int id){
    if (isFull())
    {
        printf("Queue is full"); 
    }
    else
    {
        rear++;                               
        strcpy(j[rear].name, name);          
        j[rear].jobID = id;                    
        printf("\nElement added id = %d and name = %s\n", 
               j[rear].jobID, j[rear].name); 
    }
}

void processjob()
{
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        front++;
        printf("\nDeleted item is : ID = %d name = %s\n",
               j[front].jobID,
               j[front].name);
    }
}

void display()
{
    int i;     
    for (i = front + 1; i <= rear; i++) 
    {
        printf("\nID: %d || Name = %s\n", j[i].jobID, j[i].name); 
    }
}

int main()
{
    int n;
    char name1[50];
    int cont = 1; 
    int JobID;

    do
    {
        printf("\nEnter your choice : 1) AddingJob 2) Processing job 3) Display jobs 4) Exit\n");
        scanf("%d", &n);

        switch (n)
        {
            case 1:
            {
                printf("Enter the name: ");
                
                scanf("%s", name1);

                printf("Enter the jobID");
                scanf("%d", &JobID); 
                add(j, name1 , JobID);
            }
            break;

            case 2:
                processjob();
                break;

            case 3:
                display();
                break;

            case 4:
                cont = 0;
                break;

            default:
                printf("Invalid choice\n");
        }
    }
    while (cont == 1);

    return 0;
}