#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display tasks
void displayTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available!\n";
        return;
    }

    cout << "\nYour Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

// Function to add a task
void addTask(vector<string>& tasks) {
    cout << "Enter a new task: ";
    string task;
    cin.ignore(); // Clear input buffer
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added successfully!\n";
}

// Function to delete a task
void deleteTask(vector<string>& tasks) {
    displayTasks(tasks);
    
    if (tasks.empty()) return;

    cout << "Enter the task number to delete: ";
    int index;
    cin >> index;

    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted successfully!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

// Main function
int main() {
    vector<string> tasks;
    int choice;

    do {
        cout << "\nTo-Do List Menu:\n";
        cout << "1. View Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Delete Task\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayTasks(tasks);
                break;
            case 2:
                addTask(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
