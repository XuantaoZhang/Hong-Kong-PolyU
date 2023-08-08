#include <iostream>
#include <cstring>
using namespace std;

void rotate(char *, int *);

int main()
{
    cout << "Please Enter your input (the maximum input should be 100 characters)" << endl;
    const int MAX = 101;
    char series[MAX];
    cin >> series;

    int count = 0;
    for (int a = 0; a < 101; a++)
    {
        if (int(series[a]) != 0)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    int *countPr = &count;
    rotate(series, countPr);

    return 0;
}

void rotate(char *charArray, int *sizeOfArray)
{
    int size = *sizeOfArray;
    for (int i = 0; i < size; i++)
    {
        char last = charArray[i];
        int index = i;
        int inverse_index = 0;
        char temp[size];

        for (int j = 0; j < size - 1; j++)
        {
            if (j < size - 1 - i)
            {
                temp[j] = charArray[index + 1];
                index++;
            }

            else if (j >= size - 1 - i)
            {
                temp[j] = charArray[inverse_index];
                inverse_index++;
            }
        }
        for (int c = 0; c < size - 1; c++)
        {
            cout << temp[c];
        }

        cout << last << endl;
    }
}
