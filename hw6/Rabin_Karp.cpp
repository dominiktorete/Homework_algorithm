#include <iostream>
#include <string>

unsigned long long hash_func(std::string str, int begin, int end) {
	unsigned long long hash = 0;
	for (int i = begin; i <= end; i++) {
		hash += static_cast<int>(str[i]);
	}
	return hash;
}
int find_substring_light_rabin_karp(std::string str, std::string sub_str) {
	if (sub_str.size() > str.size() || (sub_str.size() == str.size() && sub_str != str)) return -1;
	if (sub_str == str)return 0;
	int k = sub_str.size();
	unsigned long long hash{};
	unsigned long long hash_sub_str = hash_func(sub_str, 0, k - 1);
	for (int i = 0; i + k - 1< str.size(); i++) {
		if (i == 0) {
			hash = hash_func(str, i, i + k - 1);
		}
		else {
			hash -= static_cast<int>(str[i - 1]);
			hash += static_cast<int>(str[i + k - 1]);
		}
		if (hash == hash_sub_str) {
			bool found = true;
			for (int j = i, m = 0; j < i + k; j++, m++) {
				if (sub_str[m] != str[j])found = false;
			}
			if (found) return i;
		}
	}
	return -1;
}

int main() {
	std::string string_user{};
	std::cout << "Enter string: ";
	std::getline(std::cin, string_user);
	std::string sub_string{};
	do {
		std::cout << "Enter sub string: ";
		std::getline(std::cin, sub_string);
		if (find_substring_light_rabin_karp(string_user, sub_string) == -1) {
			std::cout << "Substring \"" << sub_string << "\" didn't find!" << '\n';
		}
		else {
			std::cout << "Substring \"" << sub_string << "\" found by index: " << find_substring_light_rabin_karp(string_user, sub_string) << '\n';
		}

	} while (sub_string != "exit");
}