#include <iostream>
int func(int arr[], int number, int size) {
	int n = size / 2;
	int top = size - 1;
	while (true) {
		if (number >= arr[size - 1])
			return 0;
		if (arr[n] <= number) {
			n = (size + n) / 2;
		}
		else if (arr[n] > number) {
			if (arr[n-1] <= number)return size - n;
			top = n;
			n = top / 2;
		}
	}

}

int main() {

	int arr[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
	int size = sizeof(arr) / sizeof(arr[0]);

	std::cout << "count element massive " << func(arr, 69, size);
	

}

