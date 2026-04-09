#include <iostream>
#include <vector>

void count_sort(int* arr, int size) {
	std::vector<int> vec(15);
	for (int i = 0; i < size; i++) {
		vec[(arr[i] - 10) % 15]++;
	}
	int c = 0;
	int i = 0;
	while (c < vec.size()) {
		while (vec[c] != 0) {
			arr[i] = c + 10;
			i++;
			vec[c]--;
		}
		c++;
	}
}
int main() {
	int arr[]{ 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16 ,17 ,20, 22, 11, 20 ,16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
	std::cout << "Source massive: ";
	int size1 = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < size1; i++) {
		std::cout << arr[i] << " ";
	}
	count_sort(arr, size1);
	std::cout << "\nNew massive: ";
	for (int i = 0; i < size1; i++) {
		std::cout << arr[i] << " ";
	}
	int arr2[]{ 16,17,14,20,22,20,17,22,16,19,23,24,20,22,21,18,14,16,17,21,10,11,19,23,11,11,17,17,11,21,17,11,17,16,12,11,16, 22, 23, 16 };
	std::cout << "\nSource massive: ";
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	for (int i = 0; i < size2; i++) {
		std::cout << arr2[i] << " ";
	}
	count_sort(arr2, size2);
	std::cout << "\nNew massive: ";
	for (int i = 0; i < size2; i++) {
		std::cout << arr2[i] << " ";
	}
	int arr3[]{ 21,15,19,18,23,12,18,18,19,23,12,20,15,22,21,18,19,20,12,16,20,14,17,13,10,23,19,14,10,22,19,12,24,23,22,15,13,22,18,18,11,23,24,17,10 };
	std::cout << "\nSource massive: ";
	int size3 = sizeof(arr3) / sizeof(arr3[0]);
	for (int i = 0; i < size3; i++) {
		std::cout << arr3[i] << " ";
	}
	count_sort(arr3, size3);
	std::cout << "\nNew massive: ";
	for (int i = 0; i < size3; i++) {
		std::cout << arr3[i] << " ";
	}

}