#include <iostream>
#include <string>
class Dynamic {
private:
	int* arr = nullptr;
	int logic_size;
	int fact_size;
public:
	Dynamic(int _logic_size, int _fact_size) : logic_size(_logic_size), fact_size(_fact_size) {
		if (_logic_size > _fact_size || _fact_size <= 0) {
			throw std::invalid_argument("Error: logic size > fact size or fact_size <= 0");
		}
		else {
			arr = new(int[fact_size]);
		}
	}
	int* get_massive() {
		return arr;
	}
	int* get_index(int index) {
		return arr + index;
	}
	int get_logic_size() {
		return logic_size;
	}
	int get_fact_size() {
		return fact_size;
	}
	~Dynamic() {
		if (arr != nullptr) {
			delete[] arr;
		}
	}
};
void print_dynamic_array(int* arr, int logical_size, int actual_size) {
	if (arr == nullptr || actual_size == 0) {
		std::cout << "Massive empty!\n";
		return;
	}
	std::cout << "Dynamic massive: ";
	for (int i = 0; i < actual_size; i++) {
		if (i < logical_size)
			std::cout << arr[i] << " ";
		else {
			std::cout << "_ ";
		}
	}
	std::cout << "\n";
}

int main() {
	int logic{};
	int fact{};
	std::cout << "Enter fact size: ";
	std::cin >> fact;
	std::cout << "Enter logic size: ";
	std::cin >> logic;
	try {
		Dynamic arr = Dynamic(logic, fact);
		for (int i = 0; i < logic; i++) {
			std::cout << "Enter arr[" << i << "]: ";
			std::cin >> *arr.get_index(i);
		}
		print_dynamic_array(arr.get_massive(), arr.get_logic_size(), arr.get_fact_size());
	}
	catch (std::invalid_argument& ex) {
		std::cout << ex.what();
	}
}