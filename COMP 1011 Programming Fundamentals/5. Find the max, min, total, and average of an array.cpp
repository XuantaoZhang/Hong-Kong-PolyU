#include <iostream>
#include <iomanip>
using namespace std;

int myMax(int array_1[], int a)
{
    int largest;
    largest = array_1[0];
    return largest;
}

int myMin(int array_2[], int b)
{
    int smallest;
    smallest = array_2[b - 1];
    return smallest;
}

int myTotal(int array_3[], int c)
{
    int total = 0;
    for (int x = 0; x < c; x++)
    {
        total = array_3[x] + total;
    }
    return total;
}

double myAverage(int array_4[], int d)
{
    double sum = 0;
    for (int y = 0; y < d; y++)
    {
        sum = sum + array_4[y];
    }

    double average = sum / d;
    return average;
}

int main()
{
    cout << "Enter a sequence of integer (-999 to finish)" << endl;

    const int SIZE = 1000;
    int sequence[SIZE] = {0};
    int input = 0;
    int count = 0;

    do
    {
        cin >> input;
        sequence[count] = input;
        count++;
    } while (input != -999);
    count = count - 1;

    int sort_array[count];
    for (int position = 0; position < count; position++)
    {
        sort_array[position] = sequence[position];
    }

    int exchange;

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1; j++)
        {
            if (sort_array[j + 1] > sort_array[j])
            {
                exchange = sort_array[j + 1];
                sort_array[j + 1] = sort_array[j];
                sort_array[j] = exchange;
            }
        }
    }
    cout << "Largest Number is " << myMax(sort_array, count) << endl;
    cout << "Smallest Number is " << myMin(sort_array, count) << endl;
    cout << "Total is " << myTotal(sort_array, count) << endl;
    cout << "Average is " << fixed << setprecision(3) << myAverage(sort_array, count) << endl;
    return 0;
}
