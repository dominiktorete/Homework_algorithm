#include <iostream>
int fibonacci(int numb) {
	if (numb == 0) {
		return 0;
	}
	else if (numb == 1) return 1;
	return fibonacci(numb-1) + fibonacci(numb-2) ;

}

int main() {

	std::cout << fibonacci(3);

}

///*
//* —ложность алгоритма ќ(2^n)так как число узлов вдвое больше чем глубина рекурсии. O(n) так как глубина рекурсии равна числу numb
//*/