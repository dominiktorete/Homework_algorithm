#include <iostream>
#include <vector>

std::vector<int> merge(int* arr, int size, int* arr2, int size2) {
	std::vector<int> mass(size + size2);
	int i{}, j{}, k{};
	while (i < size || j < size2) {
		if (i < size && j < size2) {
			if (arr[i] <= arr2[j]) {
				mass[k] = arr[i];
				k++;
				i++;
			}
			else {
				mass[k] = arr2[j];
				k++;
				j++;
			}
		}
		else {
			while (i < size) {
				mass[k] = arr[i];
				k++;
				i++;
			}
			while (j < size2) {
				mass[k] = arr2[j];
				k++;
				j++;
			}
		}
	}
	return mass;
}
void merge_sort(int* arr, int size) {
	if (size == 1) {
		return;
	}
	int mid = size / 2;
	merge_sort(arr, mid);
	merge_sort(arr + mid, size - mid);
	std::vector<int> vec = merge(arr, mid, arr + mid, size - mid);
	for (int i = 0; i < vec.size(); i++) {
		arr[i] = vec[i];
	}
}
int main() {
	int arr[]{ 3, 43, 38 ,29 ,18, 72, 57, 61, 2, 33 };
	std::cout << "Source massive: ";
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << " ";
	}
	merge_sort(arr, 10);
	std::cout << "\nNew massive: ";
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << " ";
	}
	int arr2[]{ 88, 91, 87 ,59 ,53 ,49, 29, 16 ,4 ,27 ,28 ,89 ,2 ,25, 74 };
	std::cout << "\nSource massive: ";
	for (int i = 0; i < 15; i++) {
		std::cout << arr2[i] << " ";
	}
	merge_sort(arr2, 15);
	std::cout << "\nNew massive: ";
	for (int i = 0; i < 15; i++) {
		std::cout << arr2[i] << " ";
	}
	int arr3[]{ 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
	std::cout << "\nSource massive: ";
	for (int i = 0; i < 18; i++) {
		std::cout << arr3[i] << " ";
	}
	merge_sort(arr3, 18);
	std::cout << "\nNew massive: ";
	for (int i = 0; i < 18; i++) {
		std::cout << arr3[i] << " ";
	}
}