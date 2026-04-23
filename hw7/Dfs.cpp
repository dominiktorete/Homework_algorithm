#include <iostream>
#include <fstream>
#include <vector>

void dfs_lets(std::vector<std::vector<int>>& vec_2d, std::vector<bool>& visited, int vertex) {
	visited[vertex] = true;
	std::cout << vertex + 1 << " ";
	for (int i = 0; i < vec_2d[vertex].size(); i++) {
		if (!visited[i] && vec_2d[vertex][i] == 1) {
			dfs_lets(vec_2d, visited, i);
		}
	}
}
void dfs(std::vector<std::vector<int>>& vec_2d) {
	std::vector<bool> visited(vec_2d.size(), false);
	std::cout << "Graph traversal procedure: ";
	for (int i = 0; i < vec_2d.size(); i++) {
		if (!visited[i]) {
			dfs_lets(vec_2d, visited, i);
		}
	}
}

int main() {
	std::ifstream file("input.txt");
	if (file.is_open()) {
		int size;
		file >> size;
		std::vector<std::vector<int>> vec_2d(size, std::vector<int>(size));
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				file >> vec_2d[i][j];
			}
		}
		std::cout << "Matrix:\n";
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				std::cout << vec_2d[i][j] << " ";
			}
			std::cout << '\n';
		}
		file.close();
		dfs(vec_2d);
	}
	else {
		std::cout << "Error read file!!!\n";
		return -1;
	}
}