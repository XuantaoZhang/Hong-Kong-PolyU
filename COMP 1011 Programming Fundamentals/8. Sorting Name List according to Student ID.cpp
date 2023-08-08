#include <iostream>
#include <cstring>
using namespace std;

struct Student
{
    char name[51];
    int id;
};

int main()
{
    cout << "Enter student names and ID, and input END to finish the input:" << endl;
    Student student[101]; // END takes one place, so the number inside the bracket should be 101. However, the max of name-input is still 100.
    int count = 0;
    const char end[] = "END";

    for (int a = 0; a < 101; a++)
    {
        cin >> student[a].name;
        if (strcmp(student[a].name, end) != 0)
        {
            cin >> student[a].id;
            count = count + 1;
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1; j++)
        {
            if (student[j].id > student[j + 1].id)
            {
                int temp_id;
                temp_id = student[j].id;
                student[j].id = student[j + 1].id;
                student[j + 1].id = temp_id;

                char temp_name[51];
                strcpy(temp_name, student[j].name);
                strcpy(student[j].name, student[j + 1].name);
                strcpy(student[j + 1].name, temp_name);
            }
        }
    }

    for (int x = 0; x < count; x++)
    {
        cout << student[x].name << " " << student[x].id << endl;
    }

    return 0;
}