// Algorithm:         Knuth-Morris-Pratt (KMP) String Matching Algorithm
// Problem Statement: We are given two strings: a text string and a pattern string. We need to print the index position of all occurrence of the pattern in the text.
// Sample Input:      text- ababdcbabdbdac   pattern- abd
// Sample Output:     2 7
// Explanation:       The pattern 'abd' occurred in the text at index position 2 and 7.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void CalcLPSArray(string pattern, int n, vector<int> &lpsArray) {
    int len = 0;
    lpsArray[0] = 0;
    int i = 1;
    while(i<n) {
        if(pattern[i] == pattern[len]) {
            len++;
            lpsArray[i] = len;
            i++;
        } else {
            if(len!=0) {
                len = lpsArray[len-1];
            } else {
                lpsArray[i] = 0;
                i++;
            }
        }
    }
}

void KMP(string text, string pattern) {
    int m = text.length(); // length of text
    int n = pattern.length(); // length of pattern
    vector<int> lpsArray(n);

    CalcLPSArray(pattern, n, lpsArray); // fills the LPS Array

    for(int i=0,j=0;i<m;) {
        if(text[i] == pattern[j]) { // continue if match found
            i++;
            j++;
        }
        if(j==n) { // condition for match
            cout << i-j << " "; // we found the pattern match and print the index
            j = lpsArray[j-1]; // j = last matched character
        } else if(i<m && text[i]!=pattern[j]) { // condition for mismatch
            if(j==0) {
                i++; // if j is 0, increment i
            } else {
                j = lpsArray[j-1]; // j = last matched character
            }
        }
    }
}

int main() {
    string text, pattern;
    cin >> text; // enter the text string
    cin >> pattern; // enter the pattern string
    KMP(text, pattern);
    return 0;
}
