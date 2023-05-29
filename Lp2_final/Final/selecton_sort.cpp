#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
}

void selection_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

int main()
{
    int n;
    std::cout << "enter total no of elements:" << endl;
    std::cin >> n;
    int arr[n];
    std::cout << "enter array elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    std::cout << endl;

    std::cout << "array before sorting:" << endl;
    display(arr, n);
    std::cout << "array  after sorting:" << endl;
    selection_sort(arr, n);
    display(arr, n);
    return 0;
}