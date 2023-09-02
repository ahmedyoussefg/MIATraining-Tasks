#include <iostream>
#include <stdio.h>
#include <list>
#include <string>
#include <stdlib.h>
#include<unistd.h>
#include<windows.h>

using namespace std;

void showMenu();
void printTasks(list<string>&tasks);
void deleteTaskAt(list<string>& tasks, int indx);

int main()
{
    list<string> tasks;
    showMenu();

    while(true)
    {
        cout << '\n';
        int option = -1;
        do
        {
            printf("Select an option: ");
            cin >> option;
        } while (option < 1 || option > 4);
        cout << '\n';
        switch(option)
        {
            case 1: // Add Task
            {
                string new_task;
                cout << "Enter task description: ";
                cin.get(); // to scan the whitespace
                getline(cin, new_task);

                tasks.push_back(new_task);
                cout << "Task added successfully!\n";
                break;
            }
            case 2: // View Tasks
            {
                printTasks(tasks);
                break;
            }
            case 3: // Remove Task
            {
                int rem_indx;
                int sz = tasks.size();
                if(sz == 0)
                {
                    cout << "No tasks exist!";
                    continue;
                }
                do
                {
                    cout << "Enter task ID to remove: ";
                    cin >> rem_indx;
                } while(rem_indx <= 0 || rem_indx > sz);
                deleteTaskAt(tasks, rem_indx);
                break;
            }
            case 4: // Exit
             {
                cout << "Exiting Minions Task Manager. Have a great day!";
                return 0;
             }
            default:
            {
                printf("Error!");
                return 1;
            }
        }
    }
    return 0;
}
void showMenu()
{
    printf("Minions Task Manager\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Remove Task\n");
    printf("4. Exit\n");
    printf("\n");
}
void printTasks(list<string>&tasks)
{
    if (tasks.empty())
    {
        cout << "No tasks exist!";
        return;
    }
    cout << "Current Tasks:\n";
    int cnt = 1;
    for (auto it = tasks.begin(); it != tasks.end(); it++)
    {
        cout << "Task ID: " << cnt++ << '\n';
        cout << "Description: " << *it << "\n\n";
    }
}
void deleteTaskAt(list<string>& tasks, int indx)
{
    auto it = tasks.begin();
    for (int i = 0; i < indx-1; i++, it++);
    tasks.erase(it);
}

