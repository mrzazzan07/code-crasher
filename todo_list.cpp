#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Task {
    string description;
    string priority;
    bool completed;
};

vector<Task> tasks;

// Function to load tasks from a file
void loadTasks() {
    ifstream file("tasks.txt");
    if (!file) return;
    tasks.clear();
    Task task;
    while (getline(file, task.description)) {
        file >> task.priority >> task.completed;
        file.ignore(); // Ignore newline character
        tasks.push_back(task);
    }
    file.close();
}

// Function to save tasks to a file
void saveTasks() {
    ofstream file("tasks.txt");
    for (const auto& task : tasks) {
        file << task.description << endl;
        file << task.priority << " " << task.completed << endl;
    }
    file.close();
}

// Function to display tasks
void displayTasks() {
    if (tasks.empty()) {
        cout << "No tasks available!\n";
        return;
    }

    cout << "\nYour Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << (tasks[i].completed ? "[✔] " : "[ ]