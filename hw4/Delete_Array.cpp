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
	void remove_dynamic_array_head() {
		if (arr == nullptr) {
			std::cout << "Massive is empty!\n";
			return;
		}
		if (logic_size - 1 > fact_size / 3) {
			for (int i = 0; i + 1 < logic_size; i++) {
				arr[i] = arr[i + 1];
			}
			logic_size--;
		}
		else if (logic_size - 1 <= fact_size / 3) {
			fact_size /= 3;
			int* new_arr = new(int[fact_size]);

			for (int i = 0; i < logic_size - 1; i++) {
				new_arr[i] = arr[i + 1];
			}
			logic_size--;
			delete[] arr;
			arr = new_arr;
			new_arr = nullptr;
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
			std::cin.ignore();
		}
		print_dynamic_array(arr.get_massive(), arr.get_logic_size(), arr.get_fact_size());
		while (true) {
			std::cout << "Do you want to delete a element of massive?(Yes, No) ";
			std::string command;
			std::getline(std::cin, command);
			if (command == "No") {
				std::cout << "Goodbye!!! ";
				print_dynamic_array(arr.get_massive(), arr.get_logic_size(), arr.get_fact_size());
				break;
			}
			else if (command == "Yes") {
				if (arr.get_logic_size() == 0) {
					std::cout << "Massive is empty, goodbye!!!";
					return 0;
				}
				arr.remove_dynamic_array_head();
			}
			else {
				std::cout << "I don't understand this command, try again, please!\n";
				continue;
			}
			print_dynamic_array(arr.get_massive(), arr.get_logic_size(), arr.get_fact_size());
		}
	}
	catch (std::invalid_argument& ex) {
		std::cout << ex.what();
	}
}