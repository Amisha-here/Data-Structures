#include <iostream>
using namespace std;

#define fl(i, a, b) for (int i = a; i < b; i++)

int maxProfit(int* prices, int size)
{
	int maxProfit = 0;
	fl(i, 1, size) if (prices[i] > prices[i - 1]) maxProfit
		+= prices[i] - prices[i - 1];
	return maxProfit;
}

// Driver Function
int main()
{
	int prices[] = { 10, 80, 60, 30, 40, 55, 65 };
	int N = sizeof(prices) / sizeof(prices[0]);
	cout << maxProfit(prices, N) << endl;
	return 0;
}

