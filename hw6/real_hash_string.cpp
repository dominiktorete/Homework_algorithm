#include <iostream>
#include <string>
#include <exception>
int real_string_hash(std::string str, int p, int n) {
	unsigned long long hash = 0;
	unsigned long long mult = 1;
	for (char element : str) {
		if (hash + static_cast<unsigned int>(element) * mult > ULLONG_MAX || mult * p > ULLONG_MAX) {
			throw std::invalid_argument("Error: An overflow has occurred");
		}
		hash += (static_cast<unsigned int>(element) * mult);
		mult *= p;
	}
	return (hash % n);
}

int main() {
	std::string string_user{};
	int simple_number, mod;
	std::cout << "Enter simple number: ";
	std::cin >> simple_number;
	std::cout << "Enter mod: ";
	std::cin >> mod; // Если это число сделать слишком маленьким, то будет коллизия.
	std::cin.ignore();
	do {
		std::cout << "Enter string: ";
		std::getline(std::cin, string_user);
		try {
			std::cout << "Hash of a string \"" << string_user << "\": " << real_string_hash(string_user, simple_number, mod);
			std::cout << '\n';
		}
		catch (std::invalid_argument& ex) {
			std::cout << ex.what() << '\n';
		}
	} while (string_user != "exit");
}