#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

void bfs(std::vector<std::vector<int>>& vec_2d) {
	std::vector<bool> visited(vec_2d.size(), false);

	std::cout << "There are " << vec_2d.size() << " vertices in the graph. Enter vertex: ";
	int begin_vertex;
	std::cin >> begin_vertex;

	while (begin_vertex <= 0 || begin_vertex > vec_2d.size()) {
		std::cout << "Try enter vertex: ";
		std::cin >> begin_vertex;
	}
	std::cout << "Graph traversal procedure: ";
	std::queue<int> q;
	q.push(begin_vertex - 1);
	while (!q.empty()) {
		int vertex = q.front();
		q.pop();
		visited[vertex] = true;
		std::cout << vertex + 1 << " ";
		for (int i = 0; i < vec_2d[vertex].size(); i++) {
			if (vec_2d[vertex][i] == 1 && !visited[i]) {
				visited[i] = true;
				q.push(i);
			}
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
		bfs(vec_2d);
	}
	else {
		std::cout << "Error read file!!!\n";
		return -1;
	}
}