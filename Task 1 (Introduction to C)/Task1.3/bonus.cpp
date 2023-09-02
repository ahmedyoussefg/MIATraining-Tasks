#include <iostream>
#include <stdio.h>
#include <list>
#include <string>
#include <stdlib.h>
#include<unistd.h>
#include<windows.h>

using namespace std;

void showMenu();
void printTasks(list<string>&tasks, list<bool> & completed);
void deleteTaskAt(list<string>& tasks, int indx, list<bool> & completed);
void markComplete(list<bool> & completed, int indx);
void drawLine();

int main()
{
    list<string> tasks;
    showMenu();
    list<bool> completed;
    while(true)
    {
        cout << '\n';
        int option = -1;
        do
        {
            printf("Select an option: ");
            cin >> option;
        } while (option < 1 || option > 5);
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
                completed.push_back(false);
                cout << "Task added successfully!\n";
                break;
            }
            case 2: // View Tasks
            {
                printTasks(tasks, completed);
                break;
            }
            case 3: // mark task as completed
            {
                int sz = tasks.size();
                if(sz == 0)
                {
                    cout << "No tasks exist!";
                    continue;
                }
                int cmp = -1;
                do
                {
                    cout << "Enter completed Task ID: ";
                    cin >> cmp;
                } while (cmp > sz || cmp <= 0);
                markComplete(completed, cmp);
                cout << "Task " << cmp << " is marked as complete successfully!";
                break;
            }
            case 4: // Remove Task
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
                deleteTaskAt(tasks, rem_indx, completed);
                break;
            }
            case 5: // Exit
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
    printf("3. Mark task as completed\n");
    printf("4. Remove Task\n");
    printf("5. Exit\n");
    printf("\n");
}
void printTasks(list<string>&tasks, list<bool> & completed)
{
    if (tasks.empty())
    {
        cout << "No tasks exist!";
        return;
    }
    cout << "Current Tasks:\n";
    drawLine();
    printf("Task ID\t\t|\t\tStatus\t\t|\tTask Description\n");
    drawLine();
    int cnt = 1;
    auto it2= completed.begin();
    for (auto it = tasks.begin(); it != tasks.end(); it++,it2++)
    {
        cout << cnt++ << "\t\t|\t\t";
        *it2 ? cout << "COMPLETED\t|\t" : cout << "NOT COMPLETED\t|\t";
        cout << *it << "\n";
    }
    drawLine();
}
void deleteTaskAt(list<string>& tasks, int indx,list<bool> & completed)
{
    auto it = tasks.begin();
    auto it2 = completed.begin();
    for (int i = 0; i < indx-1; i++, it++, it2++);
    tasks.erase(it);
    completed.erase(it2);
}
void markComplete(list<bool> & completed, int indx)
{
    auto it = completed.begin();
    for (int i = 0; i < indx - 1; i++, it++);
    *it = true;
}
void drawLine()
{
    for (int i = 0; i < 80; i++)
        cout << '_';
        cout << '\n';
}

