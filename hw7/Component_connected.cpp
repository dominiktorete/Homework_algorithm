#include <iostream>
#include <fstream>
#include <vector>
void dfs_under(std::vector<std::vector<int>>& vec_2d, std::vector<int>& comp, int vertex, int index_compomemt) {
	comp[vertex] = index_compomemt;
	for (int i = 0; i < vec_2d[vertex].size(); i++) {
		if (vec_2d[vertex][i] == 1 && !comp[i]) {
			dfs_under(vec_2d, comp, i, index_compomemt);
		}
	}
}

void dfs(std::vector<std::vector<int>>& vec_2d) {
	std::vector<int> comp(vec_2d.size(), 0);
	int index_component = 0;
	for (int i = 0; i < vec_2d.size(); i++) {
		if (!comp[i]) {
			index_component++;
			dfs_under(vec_2d, comp, i, index_component);
		}

	}
	std::cout << "The vertices belong to the connected components:\n";
	for (int i = 0; i < comp.size(); i++) {
		std::cout << i + 1 << " - " << comp[i] << '\n';
	}
	std::cout << "Count components to the connected: " << index_component;
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