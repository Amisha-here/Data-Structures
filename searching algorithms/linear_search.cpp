#include <iostream> 
using namespace std; 
  
int linear_search(int arr[], int n, int k) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        if (k == arr[i]) 
            return i; 
    return -1; 
} 

int n,key;
  cout << "Enter size of the array:"<<endl;
  cin >> n;
  cout << "Enter the array elements:"<<endl;
  int *arr = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Enter the key to be searched:"<<endl;
  cin >> key;
  int res = linear_search(arr,n,key);
  if (res != -1)
    cout << key << " found at index " << res << endl;
  else
    cout << key << " not found in the array" << endl;
  return 0;
}


/*
Sample Input/Output:
1. Enter size of the array:
5
Enter the array elements:
12 23 31 40 57 61
Enter the key to be searched:
23
Output: 23 found at index 1

2. Enter size of the array:
5
Enter the array elements:
12 23 31 40 57 61
Enter the key to be searched:
31
Output: 31 not found in the array
*/
