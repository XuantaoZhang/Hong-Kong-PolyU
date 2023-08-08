#include <iostream>
using namespace std;

void sorting(int[], int);

int main()
{
    cout << "Enter a sequence of integer (-999 to finish) :" << endl;

    const int LENGTH = 1000;
    int input[LENGTH] = {0};
    int count = 0, number = 0;

    do
    {
        cin >> number;
        input[count] = number;
        count = count + 1;
    } while (number != -999);

    count = count - 1;

    int array[count];
    for (int b = 0; b < count; b++)
    {
        array[b] = input[b];
    }

    sorting(input, count);

    return 0;
}

void sorting(int array[], int total)
{
    int odd = 0, even = 0;
    for (int a = 0; a < total; a++)
    {
        if (array[a] % 2 == 0)
        {
            even = even + 1;
        }
        else
        {
            odd = odd + 1;
        }
    }

    int odd_array[odd] = {0}, even_array[even] = {0};

    int array_index = 0, odd_index = 0, even_index = 0;
    while (array_index < total)
    {
        if (array[array_index] % 2 != 0)
        {
            odd_array[odd_index] = array[array_index];
            odd_index = odd_index + 1;
            array_index = array_index + 1;
        }
        else
        {
            even_array[even_index] = array[array_index];
            array_index = array_index + 1;
            even_index = even_index + 1;
        }
    }

    int odd_exchange, even_exchange;

    for (int i = 0; i < odd - 1; i++)
    {
        for (int j = 0; j < odd - 1; j++)
        {
            if (odd_array[j] > odd_array[j + 1])
            {
                odd_exchange = odd_array[j];
                odd_array[j] = odd_array[j + 1];
                odd_array[j + 1] = odd_exchange;
            }
        }
    }

    for (int c = 0; c < even - 1; c++)
    {
        for (int d = 0; d < even - 1; d++)
        {
            if (even_array[d + 1] > even_array[d])
            {
                even_exchange = even_array[d + 1];
                even_array[d + 1] = even_array[d];
                even_array[d] = even_exchange;
            }
        }
    }

    for (int x = 0; x < odd; x++)
    {
        cout << odd_array[x] << " ";
    }

    for (int y = 0; y < even; y++)
    {
        cout << even_array[y] << " ";
    }
}
