//============================================================================
// Name        : myvector.cpp
// Author      : akash
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "myvector.h"
using namespace std;

int main() {
	my::vector<int> myvec(10);
	std::cout << myvec << std::endl;
	std::cout << myvec.size() << "/" << myvec.capacity() << std::endl;
	for (int i = 0; i < 10; ++i) {
		myvec.push_back(i);
	}
	std::cout << myvec << std::endl;
	std::cout << myvec.size() << "/" << myvec.capacity() << std::endl;
	myvec.push_back(10);
	std::cout << myvec << std::endl;
	std::cout << myvec.size() << "/" << myvec.capacity() << std::endl;
	return 0;
}
