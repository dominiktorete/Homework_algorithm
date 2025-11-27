#include <iostream>
#include <vector>
int fibonacci(int numb) {
	std::vector<int>vec;
	vec.push_back(0);
	for (int i = 1; i <= numb; i++) {
		if (vec.size() == 1) {
			vec.push_back(1);
		}
		else 
			vec.push_back((vec[i - 1] + vec[i - 2]));
	}
	return vec[numb];

}

int main() {

	std::cout << fibonacci(0);

}
