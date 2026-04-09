#include <iostream>
#include <vector>

int pivoting(int* arr, int size, int pi) {
	int left = 0;
	int right = size;
	int pivot = arr[pi];
	while (true) {
		while (arr[left] < pivot) left++;
		while (arr[right] > pivot) right--;
		if (left >= right) return left;
		std::swap(arr[left], arr[right]);
		left++;
		right--;
	}

}
void quick_sort(int* arr, int size) {
	if (size <= 1)return;

	int pi = rand() % size;
	int mid = pivoting(arr, size, pi);
	quick_sort(arr, mid - 1);
	quick_sort(arr + mid, size - mid);
}
int main() {
	int arr[]{ 3, 43, 38 ,29 ,18, 72, 57, 61, 2, 33 };
	std::cout << "Source massive: ";
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << " ";
	}
	quick_sort(arr, 9);
	std::cout << "\nNew massive: ";
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << " ";
	}
	int arr2[]{ 88, 91, 87 ,59 ,53 ,49, 29, 16 ,4 ,27 ,28 ,89 ,2 ,25, 74 };
	std::cout << "\nSource massive: ";
	for (int i = 0; i < 15; i++) {
		std::cout << arr2[i] << " ";
	}
	quick_sort(arr2, 14);
	std::cout << "\nNew massive: ";
	for (int i = 0; i < 15; i++) {
		std::cout << arr2[i] << " ";
	}
	int arr3[]{ 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
	std::cout << "\nSource massive: ";
	for (int i = 0; i < 18; i++) {
		std::cout << arr3[i] << " ";
	}
	quick_sort(arr3, 17);
	std::cout << "\nNew massive: ";
	for (int i = 0; i < 18; i++) {
		std::cout << arr3[i] << " ";
	}

}