#include <iostream>
#include <fstream>
#include <vector>
bool dfs_under(std::vector<std::vector<int>>& vec_2d, std::vector<bool>& visited, int vertex, int prev) {
	visited[vertex] = true;
	for (int i = 0; i < vec_2d[vertex].size(); i++) {

		if (vec_2d[vertex][i] == 1 && !visited[i]) {
			return dfs_under(vec_2d, visited, i, vertex);
		}
		else if (vec_2d[vertex][i] == 1 && i != prev) {
			return true;
		}
	}
	return false;
}

bool dfs(std::vector<std::vector<int>>& vec_2d) {
	std::vector<bool> visited(vec_2d.size(), false);
	for (int i = 0; i < vec_2d.size(); i++) {
		if (!visited[i]) {
			if (dfs_under(vec_2d, visited, i, -1))return true;
		}
	}
	return false;

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
		if (dfs(vec_2d))std::cout << "Graph has cycle!!!\n";
		else {
			std::cout << "Graph don't have cycle!!!\n";
		}
	}
	else {
		std::cout << "Error read file!!!\n";
		return -1;
	}
}