#include<stdio.h>
#include<stdlib.h>
#define max 10
int q[max],front=-1, rear=-1;

void enqueue()
{
	int item;
	printf("\nenter element: ");
	scanf("%d", &item);
	if(front==0 && rear==max-1)
		printf("\n overflow");
	else if(front==-1 && rear==-1)
	{
		rear=0;
		front=rear;
		q[rear]=item;
	}
	else if((rear==max-1) && (front!=0))
	{
		rear=0;
		q[rear]=item;
	}

	else
	{
		rear++;
		q[rear]=item;
	}
}

int dequeue()
{
	int item;
	if((front==-1)&& (rear==-1))
	{
		printf("\n Underflow");
		return -1;
	}
	item= q[front];
	if(front==rear)
		front=rear=-1;
	else
	{
		if(front==max-1)
			front=0;
		else
			front++;
	}
	return item;
}

void display()
{
	int i;
	printf("\n");
	if ((front==-1) && (rear==-1))
	printf ("Queue is empty");
	else
	{
		if(front<rear)
		{
			for(i=front;i<=rear;i++)
			printf(" %d", q[i]);
		}
		else if(front==rear)
		printf(" %d", q[front]);
		else
		{
			for(i=front;i<max;i++)
			printf(" %d", q[i]);

			for(i=0;i<=rear;i++)
			printf(" %d", q[i]);
		}
	}
}

int main()
{
	int c;char ch='y';
    while(ch=='y')
    {
	   printf("\n1.enqueue\n2.dequeue\n3.exit\n");
		scanf("%d",&c);
		switch(c)
		{
		case 1:
		enqueue();
		printf("queue:");
		display(front);
		break;
		case 2:
		dequeue();
		printf("queue:");
		display(front);

		break;
		case 3:
		exit(0);
		break;
	    printf("back to menu?");
	    scanf("%c",&ch);
		}
	}
	return 0;
}
