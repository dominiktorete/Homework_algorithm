#include <iostream>
#include <algorithm>
#include <string>

void print_pyramid(int* arr, int index, int size) {
	int level{};
	if (index == 0) {
		std::cout << level << " root " << arr[index] << '\n';
	}
	if ((index * 2) + 1 < size) {

		for (int i = index * 2 + 1; i > 0; i = (i - 1) / 2) {
			level++;
		}
		if ((index * 2) + 1 < size) {
			std::cout << level << " left(" << arr[index] << ") " << arr[(index * 2) + 1] << '\n';
		}
		if ((index * 2) + 2 < size) {
			std::cout << level << " right(" << arr[index] << ") " << arr[(index * 2) + 2] << '\n';
		}

		print_pyramid(arr, index + 1, size);
	}
}
void print_element(int* arr, int index, int begin, int size) {
	if (begin < size) {
		if (index == begin) {
			int level{};
			for (int i = index; i > 0; i = (i - 1) / 2) {
				level++;
			}
			if (level == 0)
				std::cout << "You are here: " << level << " root " << arr[index] << '\n';
			else {
				if (index % 2 != 0)
					std::cout << "You are here: " << level << " left(" << arr[(index - 1) / 2] << ") " << arr[index] << '\n';
				else if (index % 2 == 0)
					std::cout << "You are here: " << level << " right(" << arr[(index - 1) / 2] << ") " << arr[index] << '\n';
			}
		}
		else {
			print_element(arr, index, begin * 2 + 1, size);
			print_element(arr, index, begin * 2 + 2, size);
		}
	}
}

int main() {

	int arr[10] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	print_pyramid(arr, 0, size);
	int index_user = 0;
	std::string command{};
	do {
		print_element(arr, index_user, 0, size);
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		std::transform(command.begin(), command.end(), command.begin(), ::tolower);
		if (command == "up") {
			if (index_user == 0) {
				std::cout << "Error: a parent is missing!\n";
				continue;
			}
			else {
				index_user = (index_user - 1) / 2;
			}
		}
		else if (command == "left") {
			if ((index_user * 2) + 1 >= size) {
				std::cout << "Error: a left child is missing!\n";
				continue;
			}
			else {
				index_user = (index_user * 2) + 1;
			}
		}
		else if (command == "right") {
			if ((index_user * 2) + 2 >= size) {
				std::cout << "Error: a right child is missing!\n";
				continue;
			}
			else {
				index_user = (index_user * 2) + 2;
			}
		}
		else if (command != "exit") {
			std::cout << "Error: there is no such command\n";
			continue;
		}
	} while (command != "exit");
}
