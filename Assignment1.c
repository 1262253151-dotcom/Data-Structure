#include <stdio.h>
void accept(int a[10][10],int r,int c)
{
    int i,j;

    printf("Enter element of the matrix:\n");

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

void display(int a[10][10],int r,int c)
{
    int i,j;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

/*int main()
{
    int m[10][10],r,c;

    printf("Enter number of rows:\n");
    scanf("%d",&r);

    
    printf("Enter number of columns:\n");
    scanf("%d",&c);
    
    accept( m, r, c);
    display(m,r,c);

    return 0;

}*/

void add(int a[10][10], int b[10][10],int r,int c)
{
    int i,j;
    int sum [10][10];
    printf("Addition of matrices:\n");

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            sum[i][j]=a[i][j]+b[i][j];
            printf("%d ", sum[i][j]);
        }
          printf("\n");
    }
  
}

void sub(int a[10][10],int b[10][10],int r, int c)
{
    int i,j;
    int diff[10][10];
    printf("subtraction of matrix:\n");

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            diff[i][j]=a[i][j]-b[i][j];
            printf("%d ",diff[i][j]);
        }
        printf("\n");
    }
}


void mult(int a[10][10],int b[10][10],int r1,int c1,int c2)
{
    int i,j;
    int k;
    int mul[10][10];

    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            mul[i][j]=0;
            for (k=0;k<c1;k++)
            {
                mul[i][j]+=a[i][k]*b[k][j];
            }
            printf("%d ",mul[i][j]);
        }
        printf("\n");
    }
}

void transpose(int a[10][10],int r,int c)
{
    int i,j;
    int trans[10][10];
    printf("Transpose of matrix:\n");

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            trans[j][i] = a[i][j];
        }
    }

    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("%d ",trans[i][j]);
        }
        printf("\n");
    }

}


int main()
{
    int a[10][10],b[10][10];
    int r1,r2,c1,c2;
    int choice;

    printf("Enter number of rows and columns fo M1:\n");
    scanf("%d%d",&r1,&c1);
    accept(a,r1,c1);
    display(a,r1,c1);
    
    printf("Enter number of rows and columns for M2:\n");
    scanf("%d%d",&r2,&c2);
    
    accept(b,r2,c2);
    display(b,r2,c2);

    printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Transpose\n");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
            if(r1==r2 && c1==c2)
            {
                add(a,b,r1,c1);
            }
            else
            {
                printf("Addition is not possible");
            }
    
            break;

    case 2:
           if(r1==r2 && c1==c2)
            {
                sub(a,b,r1,c1);
            }
            else
            {
                printf("Subtraction is not possible");
            }
    
            break;
    case 3: 
            if(c1==r2)
            {
            mult(a,b,r1,c1,c2);
            }
            else{
                printf("Multiplication not possible");
            }
            break;

    case 4:
{
    int matrixChoice;

    printf("Which matrix do you want to transpose?\n");
    printf("1. Matrix 1\n");
    printf("2. Matrix 2\n");
    scanf("%d", &matrixChoice);

    switch(matrixChoice)
    {
        case 1:
            transpose(a, r1, c1);
            break;

        case 2:
            transpose(b, r2, c2);
            break;

        default:
            printf("Invalid choice\n");
    }

    break;
}
            break;
 
    default:
            printf("Invalid choice");
    }
    return 0;

}
