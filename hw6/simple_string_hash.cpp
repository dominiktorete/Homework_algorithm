#include <iostream>
#include <string>

int simple_string_hash(std::string str) {
	int hash = 0;
	for (char element : str) {
		hash += static_cast<int>(element);
	}
	return hash;
}
int main() {
	std::string string_user{};
	do {
		std::cout << "Enter string: ";
		std::getline(std::cin, string_user);
		std::cout << "Naive hash of a string \"" << string_user << "\": " << simple_string_hash(string_user);
		std::cout << '\n';
	} while (string_user != "exit");
}