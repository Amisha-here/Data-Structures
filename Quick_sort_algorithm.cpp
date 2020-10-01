#include <iostream>
using namespace std;

class quicksort {
    int a[50];

public:
    void getdata(int n)
    {
        cout << "Enter array elements :- ";
        for (int i = 0; i < n; i++) {

            cin >> a[i];
        }
    }
    void display(int n)
    {
        cout << "Sorted array : " << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
    }

    void swap(int& a, int& b)
    {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
    int partition(int low, int high)
    {
        int pivot;
        pivot = a[low];
        int i = low + 1;
        int j = high;
        do {
            while (a[i] < pivot) {
                i++;
            }
            while (a[j] > pivot) {
                j--;
            }
            if (i < j) {
                swap(a[i], a[j]);
            }

        } while (i <= j);
        swap(a[low], a[j]);
        return j;
    }
    void quick_sort(int low, int high)
    {
        int j;
        if (low < high) {
            j = partition(low, high);
            quick_sort(low, j - 1);
            quick_sort(j + 1, high);
        }
    }
};
int main()
{
    quicksort q;
    int n;
    cout << "Enter total number of elements : ";
    cin >> n;
    q.getdata(n);
    q.quick_sort(0, n - 1);
    q.display(n);
}
