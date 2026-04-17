#include <iostream>

void print_pyramid(int* arr, int index, int size) {
	if ((index * 2) + 1 < size) {
		int level{};
		if (index == 0) {
			std::cout << level << " root " << arr[index] << '\n';
		}
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

int main() {

	int arr[10] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	print_pyramid(arr, 0, size);
}