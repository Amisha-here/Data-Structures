#include <iostream.h>
using namespace std;

#define SIZE 10
int stack[SIZE];
int TOP = -1;
int ch,no,i;
char ans;



void menu()
{
	printf("====================MENU==================== \n");
	printf("1. PUSH \n");
	printf("2. PEEP \n");
	printf("3. POP \n");
	printf("4. Check the list is empty or not \n");
	printf("5. See i th element in the stack \n");
  printf("6. Display the stack \n");
	cout<<endl<<"Enter your choice:";
	cin>>ch;
	cout<<endl;
}



void PUSH (int value)
{
  if (TOP==SIZE-1)
  printf("Overflow. Stack is full \n");
  else
   { TOP++;
     stack[TOP]=value;
     printf("Insertion was successful. \n");
   }
}

void POP () 
{
  if(TOP==-1)
  printf("Stack is empty \n");
  else
  { printf("deleted: %d",stack[TOP]);
    TOP--;
  }
}

void PEEP()
{
  if(TOP==-1)
  printf("Stack is empty \n");
  else
  printf("First element in the stack is : %d",stack[TOP]);
}

void get_element(int i)
{
  int item,j;
  for(j=TOP;j>=i;j--)
  item=stack[i];
  printf("i th element from top is : %d",item);
}

void DISPLAY()
{
  if(TOP==-1)
  printf("Stack is empty \n");
  else
  {
    int i;
    printf("Stack elements are : \n");
    for(i=TOP;i>=0;i--)
    printf("%d \n",stack[i]);
  }
}

bool isEmpty()
{
	if(TOP==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{  
  x:
	cout<<endl;
  
  
	menu();
	switch(ch)
	{
		case 1:
			{
				printf("Enter the element: ");
				scanf("%d",&no);
				PUSH(no);
				printf("Do u wanna continue(y/n):");
				scanf("%d",&ans);
				if(ans=='y')
				{
					goto x;
				}
				else
				{
					exit(0);
				}
			}
		case 2:
			{
				PEEP();
				cout<<"Do u wanna continue(y/n):";
				cin>>ans;
				if(ans=='y')
				{
					goto x;
				}
				else
				{
					exit(0);
				}
			}
		case 3:
			{
				POP();
				cout<<"Do u wanna continue(y/n):";
				cin>>ans;
				if(ans=='y')
				{
					goto x;
				}
				else
				{
					exit(0);
				}
			}
		case 4:
			{
				if(isEmpty()==true)
				{
					cout<<"yes"<<endl;
				}
				else
				{
					cout<<"no"<<endl;
				}
				cout<<"Do u wanna continue(y/n):";
				cin>>ans;
				if(ans=='y')
				{
					goto x;
				}
				else
				{
					exit(0);
				}
			}
  case 5:
			{
				printf("Enter the element: ");
				scanf("%d",&i);
				get_element(i);
				printf("Do u wanna continue(y/n):");
				scanf("%d",&ans);
				if(ans=='y')
				{
					goto x;
				}
				else
				{
					exit(0);
				}
			}
      
		case 6:
			{
				DISPLAY();
        cout<<"Do u wanna continue(y/n):";
				cin>>ans;
				if(ans=='y')
				{
					goto x;
				}
				else
				{
					exit(0);
				}
        
			}
		default:
			{
				cout<<"Do u wanna continue(y/n):";
				cin>>ans;
				if(ans=='y')
				{
					goto x;
				}
				else
				{
					exit(0);
				}
			}
		
	}
		
}


  


  
  
