#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
class node
{
public:
	T info;
	node<T> *next;                 //next is a pointer pointing to object of node class
	node()
	{
       next=NULL;
    }

	/*node(T x,node *n=NULL)
	{
		info = x;
		next = n;
	}*/
};

template <class T>
class stacktype
{
	node<T> *top;
	
public:
	stacktype()
	{
		top = NULL;
	}
	
	void push(node<T> *);
	T pop();
	int isempty();
	void display();
	T topmost();
	void clear();
	node<T>* createnewnode(T);
};

template <class T>
node<T>* stacktype<T>::createnewnode(T p)
{
	node<T> *temp;
    temp = new node<T>;
    temp->info=p;
    temp->next=NULL;
    return temp;
}

template <class T>
T stacktype<T>::pop()
{
node<T>* temp;
temp=top;
top=top->next;
temp->next=NULL;
return temp->info;
}

template <class T>
void stacktype<T>::push(node<T> *c)
{
if(top==NULL)
	top=c;
else
    {
	c->next=top;
	top=c;
	}
}

template <class T>
int stacktype<T>::isempty()
{
if(top==NULL)
	return 1;
else
	return 0;
}

template <class T>
void stacktype<T>::display()
{
node<T>* temp;
cout<<"\nStack elements starting from top are - ";
for(temp=top;temp!=NULL;temp=temp->next)
	cout<<temp->info<<" ";
cout<<endl;
}

template <class T>
T stacktype<T>::topmost(){
return top->info;
}

template <class T>
void stacktype<T>::clear()
{
  T d;
  while(top!=NULL)
    {
	   d=pop();
    }
}

int main()
{
	stacktype<int> st;
	node<int>* temp;
	char c = 'y';
	int choice,p,d,e;
	
	while(c=='y'||c=='Y')
	{
		cout<<"MAIN MENU :"<<endl;
		cout<<"From the following options which operation you want to perform on stack :"<<endl;
		cout<<"1. PUSH onto the stack "<<endl;
		cout<<"2. POP from the stack "<<endl;
		cout<<"3. Check if stack is EMPTY "<<endl;
		cout<<"4. CLEAR the stack "<<endl;
		cout<<"5. TOPMOST element of stack "<<endl;
		cout<<"6. DISPLAY the stack "<<endl;
		cout<<"Enter your Choice: ";
		cin>>choice;
		
		switch(choice)
		{
			  case 1:
				    cout<<"Enter the element you want to push- ";
				    cin>>p;
				    temp=st.createnewnode(p);
	                st.push(temp);
	                cout<<endl;
				    st.display();
				    break;
				    
			  case 2:
			  	e=st.isempty();
	             if(e==1)
		            cout<<"UNDERFLOW: Deletion not possible"<<endl;
	             else{
	            	d=st.pop();
		            cout<<"\n"<<d<<" has been deleted";
		          }
            	st.display();
            	break;
            	
              case 3:
              	e = st.isempty();
				if(e==1)
				{
					cout<<"Stack is empty"<<endl;
				}
				else
				{
					cout<<"Stack is not empty"<<endl;
					st.display();
				}
				break;
				
			  case 4:
			  	st.clear();
				cout<<"\nStack is cleared!!"<<endl;
				break;
				
			  case 5:
			  	e = st.isempty();
				if(e == 1)
				{
					cout<<endl;
				}
				else
				{
					cout<<"The topmost element of the stack is - ";
				    cout<<st.topmost()<<endl;
				}
				break;
				
			 case 6:
			 	st.display();
				break;
				
			default:
		    	cout<<"Invalid Choice!!"<<endl;
		    	break;
		}
		
		cout<<"\nDo you want to continue ??(Y/N): ";
		cin>>c;
	}
	return 0;
}
              	

			  	










