#include<bits/stdc++.h> 
using namespace std; 
  
struct CQueue 
{ 
    int rear, front;  
    int size; 
    int *arr; 
  
    CQueue(int s) 
    { 
       front = rear = -1; 
       size = s; 
       arr = new int[s];  /*storing dynamic memory value in arr*/
    } 
  
    void enQueue(int val); 
    int deQueue(); 
    void displayQueue(); 
}; 
/*inserting value in circular queue*/

void CQueue::enQueue(int val) 
{ 
    if ((front == 0 && rear == size-1) || 
            (rear == (front-1)%(size-1))) 
    { 
        printf("\nQueue cannot be added its Full!!"); 
        return; 
    } 
  
    else if (front == -1) 
    { 
        front = rear = 0; 
        arr[rear] = val; 
    } 
  
    else if (rear == size-1 && front != 0) 
    { 
        rear = 0; 
        arr[rear] = val; 
    } 
  
    else
    { 
        rear++; 
        arr[rear] = val; 
    } 
} 
  
/*deleting the queue*/
int CQueue::deQueue() 
{ 
    if (front == -1) 
    { 
        printf("\nQueue is already Empty!!"); 
        return INT_MIN; 
    } 
  
    int result = arr[front]; 
    arr[front] = -1; 
    if (front == rear) 
    { 
        front = -1; 
        rear = -1; 
    } 
    else if (front == size-1) 
        front = 0; 
    else
        front++; 
  
    return result; 
} 

void CQueue::displayQueue() 
{ 
    if (front == -1) 
    { 
        printf("\nQueue is Empty!!"); 
        return; 
    } 
    printf("\nElements in Circular Queue are: "); 
    if (rear >= front) 
    { 
        for (int i = front; i <= rear; i++) 
            printf("%d ",arr[i]); 
    } 
    else
    { 
        for (int i = front; i < size; i++) 
            printf("%d ", arr[i]); 
  
        for (int i = 0; i <= rear; i++) 
            printf("%d ", arr[i]); 
    } 
} 
 
int main() 
{ 
    CQueue q(5); 
  
    /* Inserting elements in Circular Queue */ 
    q.enQueue(11); 
    q.enQueue(0); 
    q.enQueue(-3); 
    q.enQueue(6); 
  
    /*To display output*/
    q.displayQueue(); 
  
    /* Deleting values */
    printf("\nDeleted value = %d", q.deQueue()); 
    printf("\nDeleted value = %d", q.deQueue()); 
  
    q.displayQueue(); 
  
    q.enQueue(2); 
    q.enQueue(3); 
    q.enQueue(5); 
  
    q.displayQueue(); 
  
    q.enQueue(8); 
    return 0; 
} 
