/*

Given an array of positive integers arr[] and a sum x, find all unique combinations in arr[] where the sum is equal to x. 
The same repeated number may be chosen from arr[] unlimited number of times. 
Elements in a combination (a1, a2, …, ak) must be printed in non-descending order. (ie, a1 <= a2 <= … <= ak). 

The combinations themselves must be sorted in ascending order, i.e., the combination with smallest first element should be printed first. 
If there is no combination possible the print “Empty” (without quotes).

Input : arr[] = 2, 4, 6, 8 
            x = 8
Output : [2, 2, 2, 2]
         [2, 2, 4]
         [2, 6]
         [4, 4]
         [8]

*/

#include <iostream>
#include <vector>
using namespace std;

 // Print all members of ar[] that have given
 void findNumbers(vector<int>& ar, int sum, vector<vector<int> >& res, vector<int>& r, int i)
 {
 	// if we get exact answer
 	if (sum == 0) {
 		res.push_back(r);
 		return;
 	}

 	// Recur for all remaining elements that have value smaller than sum
 	while (i < ar.size() && sum - ar[i] >= 0) {

 		r.push_back(ar[i]); // add them to list

 		// recur for next numbers
 		findNumbers(ar, sum - ar[i], res, r, i);
 		i++;

 		// Remove number from list (backtracking)
 		r.pop_back();
 	}
 }

 // Returns all combinations of ar[] that have given sum
 vector<vector<int> > combinationSum(vector<int>& ar, int sum)

 {
 	// sort input array
 	sort(ar.begin(), ar.end());

 	// remove duplicates
 	ar.erase(unique(ar.begin(), ar.end()), ar.end());

 	vector<int> r;
 	vector<vector<int> > res;
 	findNumbers(ar, sum, res, r, 0);

 	return res;
 }

 int main()
 {
 	vector<int> ar;
 	ar.push_back(2);
 	ar.push_back(4);
 	ar.push_back(6);
 	ar.push_back(8);
 	int n = ar.size();

 	int sum = 8; 
 	vector<vector<int> > res = combinationSum(ar, sum);

 	if (res.size() == 0) {
 		cout << "Emptyn";
 		return 0;
 	}

 	// Print all combinations stored in res
 	for (int i = 0; i < res.size(); i++) {
 		if (res[i].size() > 0) {
 			cout << "[";
 			for (int j = 0; j < res[i].size(); j++){
 				cout << res[i][j];
 				if (j<(res[i].size()-1))
 				    cout << ", ";
 			}
 			cout << "]\n";
 		}
 	}
 }