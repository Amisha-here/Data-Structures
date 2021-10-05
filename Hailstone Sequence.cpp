/*Start with any positive integer (an initial seed) and obtain a sequence of numbers by following these rules.

1. If the current number is even, divide it by two; else if it is odd, multiply it by three and add one. 
2. Repeat.

Let’s try a few numbers to see what happens: 
n=3; 10, 5, 16, 8, 4, 2, 1, 4, 2, 1, … 
n=4; 2, 1, 4, 2, 1, … 
n=5; 16, 8, 4, 2, 1, 4, 2, 1, … 
n=6; 3, 10, 5, 16, 8, 4, 2, 1, 4, 2, 1, … 
n=7; 22, 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1, 4, 2, 1, …*/

#include<bits/stdc++.h>
using namespace std;

//*HailSequence using recursion
void HailSequence(int n,int length){
    if (length==0)
    {
        return;
    }else if (n%2==0)
    {
        cout<<n<<" ";
        HailSequence(n/2,length-1);
    }else{
        cout<<n<<" ";
        HailSequence((3*n)+1,length-1);
    }
    return;
}

int main(){

    HailSequence(13,10);
    
    return 0;
}
