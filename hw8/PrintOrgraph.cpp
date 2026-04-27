#include <iostream>
#include <vector>
#include <fstream>
void bfs(std::vector<std::vector<int>>& graph, int vertex) {
    bool found_vertex = false;
    for (int i = 0; i < graph[vertex].size(); i++) {
        if (graph[vertex][i] == 1) {
            std::cout << i + 1 << " ";
            found_vertex = true;
        }
    }
    if (!found_vertex)std::cout << "No";
    std::cout << '\n';
}
void bfs_begin(std::vector<std::vector<int>>& graph) {
    for (int i = 0; i < graph.size(); i++) {
        std::cout << i + 1 << ": ";
        bfs(graph, i);
    }
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
        bfs_begin(graph);
        file.close();
    }
    else {
        std::cout << "Error: file not open!\n";
    }
    return 0;
}