// Median of 2 sorted arrays of Different size

#include <bits/stdc++.h>
using namespace std;

// TC: O(n1+n2) 	SC: O(n1+n2)
int get_median(int a[], int n1, int b[], int n2) {
	int add[n1 + n2];

	int i = 0, j = 0, k = 0;
	while (i < n1 && j < n2)
	{
		if (a[i] <= b[j])
			add[k++] = a[i++];
		else if (b[j] < a[i])
			add[k++] = b[j++];
	}

	while (i < n1)
		add[k++] = a[i++];

	while (j < n2)
		add[k++] = b[j++];

	int med = -1;
	if (k % 2 == 0)
		med = (add[k / 2 - 1] + add[k / 2]) / 2;
	else
		med = add[k / 2];

	return med;
}

// int get_median(int a[], int n1, int b[], int n2) {
// }

int main() 
{
	int n1; cin >> n1;

	int a[n1];
	for (int i = 0; i < n1; ++i)
		cin >> a[i];

	int n2; cin >> n2;

	int b[n2];
	for (int i = 0; i < n2; ++i)
		cin >> b[i];

	int m = get_median(a, n1 , b, n2);

	cout << m;

	return 0;
}
