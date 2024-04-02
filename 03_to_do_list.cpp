#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

struct Task 
{
    string description;
    bool completion_status;
};

void add_task(vector<Task>& tasks, const string& description); 
void view_tasks(const vector<Task>& tasks);
void mark_task_completed(vector<Task>& tasks, int taskIndex); 
void remove_task(vector<Task>& tasks, int taskIndex); 

int main() 
{
    vector<Task> tasks;
    string description; 
  
    while (true) 
    {
        cout << "------------ To-Do List Manager ------------" << endl;
        cout << "1) Add Task" << endl;
        cout << "2) View Tasks" << endl;
        cout << "3) Mark Task as Completed" << endl;
        cout << "4) Remove Task" << endl;
        cout << "5) Quit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 5) 
        {
            cout << "Adios Amigos!" << endl;
            break;
        }

        switch (choice) 
        {
            case 1:
                cout << "Enter task description: ";
                cin.ignore(); 
                getline(cin, description);
                add_task(tasks, description);
                break;
          
            case 2:
                view_tasks(tasks);
                break;
          
            case 3:
                view_tasks(tasks);
                cout << "Enter the task index to mark as completed: ";
                int markIndex;
                cin >> markIndex;
                mark_task_completed(tasks, markIndex);
                break;
          
            case 4:
                view_tasks(tasks);
                cout << "Enter the task index to remove: ";
                int removeIndex;
                cin >> removeIndex;
                remove_task(tasks, removeIndex);
                break;
          
            default:
                cout << "Invalid choice! Please enter an index from given choices!" << endl;
        }
    }

    return 0;
}

void add_task(vector<Task>& tasks, const string& description) 
{
    Task newTask;
    newTask.description = description;
    newTask.completion_status = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

void view_tasks(const vector<Task>& tasks)
{
    if (tasks.empty()) 
    {
        cout << "No tasks in the list" << endl;
    } 
    
    else 
    {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); i++) 
        {
            cout << i + 1 << ". ";
            if (tasks[i].completion_status) 
            {
                cout << "[X] ";
            } 
            
            else 
            {
                cout << "[ ] ";
            }
            cout << tasks[i].description << endl;
        }
    }
}

void mark_task_completed(vector<Task>& tasks, int task_index) 
{
    if (task_index >= 1 && task_index <= static_cast<int>(tasks.size())) 
    {
        tasks[task_index - 1].completion_status = true;
        cout << "Task marked as completed!" << endl;
    } 
    
    else 
    {
        cout << "Invalid task index" << endl;
    }
}

void remove_task(vector<Task>& tasks, int task_index) 
{
    if (task_index >= 1 && task_index <= static_cast<int>(tasks.size())) 
    {
        tasks.erase(tasks.begin() + task_index - 1);
        cout << "Task removed successfully!" << endl;
    } 
    
    else 
    {
        cout << "Invalid task index" << endl;
    }
}
