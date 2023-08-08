#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    cout << "Enter student names and input END to finish the input:" << endl;

    const int SIZE = 200;
    char input;
    char name_list[SIZE][51];
    int count = 0;
    for (int i = 0; i < 200; i++)
    {
        cin.getline(name_list[i], 51, '\n');
        count++;
        for (int j = 0; j < strlen(name_list[i]); j++)
        {
            if (int(name_list[i][j]) < 65 | int(name_list[i][j]) > 122 | 90 < int(name_list[i][j]) && int(name_list[i][j]) < 97)
            {
                cout << "Wrong input: please input only upper-case and low-case letters with no space between" << endl;
                i--;
                count--;
                break;
            }
        }

        if (int(name_list[i][0]) == 69 && int(name_list[i][1]) == 78 && int(name_list[i][2]) == 68)
        {
            i--;
            count--;
            break;
        }
    }

    for (int a = 0; a < count; a++)
    {
        for (int b = 0; b < strlen(name_list[a]); b++)
        {
            if (97 <= int(name_list[a][b]) && int(name_list[a][b]) <= 122)
            {
                name_list[a][b] -= 32;
            }
        }
    }

    char temp[51] = {'\0'};
    for (int x = 0; x < count - 1; x++)
    {
        for (int y = 0; y < count - 1; y++)
        {
            if (strcmp(name_list[y], name_list[y + 1]) > 0)
            {
                strcpy(temp, name_list[y]);
                strcpy(name_list[y], name_list[y + 1]);
                strcpy(name_list[y + 1], temp);
            }
        }
    }

    for (int c = 0; c < count; c++)
    {
        cout << name_list[c] << endl;
    }

    return 0;
}
