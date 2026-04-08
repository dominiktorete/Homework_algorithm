#include <iostream>
int binary_search(int arr[], int number, int size) {
	int left = 0;
	int right = size - 1;
	if (arr[right] == number) return 0;
	while (left < right - 1) {
		int middle = (left + right) / 2;
		if (arr[middle] <= number) {
			left = middle;
		}
		else {
			right = middle;
		}
	}
	return size - 1 - left;
}

int main() {

	int arr[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int point_ref{};
	std::cout << "Enter point of reference: ";
	std::cin >> point_ref;
	std::cout << "Count element massive which is bigger than " << point_ref << ": " << binary_search(arr, point_ref, size);
}
