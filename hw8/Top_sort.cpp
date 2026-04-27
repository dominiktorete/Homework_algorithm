#include <iostream>
#include <stack>
#include <vector>
#include <fstream>
void dfs(std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int vertex, std::stack<int>& stack) {
    visited[vertex] = true;
    for (int i = 0; i < graph[vertex].size(); i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(graph, visited, i, stack);
        }
    }
    stack.push(vertex + 1);
}

std::stack<int> top_sort(std::vector<std::vector<int>>& graph) {
    std::vector<bool> visited(graph.size(), false);
    std::stack<int> stack;
    for (int i = 0; i < graph.size(); i++) {
        if (!visited[i]) {
            dfs(graph, visited, i, stack);

        }
    }
    return stack;
}


int main()
{
    std::ifstream file("input.txt");
    if (file.is_open()) {
        int size{};
        file >> size;
        std::vector<std::vector<int>> graph(size, std::vector<int>(size, 0));
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph.size(); j++) {
                file >> graph[i][j];
            }
        }
        std::stack<int> stack = top_sort(graph);
        std::cout << "Topological order of vertices: ";
        while (!stack.empty()) {
            std::cout << stack.top() << " ";
            stack.pop();
        }
        file.close();
    }
    else {
        std::cout << "Error: file not open!\n";
    }
    return 0;
}
