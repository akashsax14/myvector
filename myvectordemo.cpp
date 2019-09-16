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
	{
		std::cout << "Test Case 1 : Empty constructor" << std::endl;
		my::vector<int> myvec;
		std::cout << myvec << std::endl;
		std::cout << myvec.size() << "/" << myvec.capacity() << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "Test Case 2 : Capacity constructor" << std::endl;
		my::vector<int> myvec(10);
		std::cout << myvec << std::endl;
		std::cout << myvec.size() << "/" << myvec.capacity() << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "Test Case 3 : Size/Value constructor" << std::endl;
		my::vector<int> myvec(10, 999);
		std::cout << myvec << std::endl;
		std::cout << myvec.size() << "/" << myvec.capacity() << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "Test Case 4 : Copy constructor" << std::endl;
		my::vector<int> myvec(15, 999);
		my::vector<int> mynewvec(myvec);
		std::cout << myvec << std::endl;
		std::cout << myvec.size() << "/" << myvec.capacity() << std::endl;
		std::cout << mynewvec << std::endl;
		std::cout << mynewvec.size() << "/" << mynewvec.capacity() << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "Test Case 5 : Initializer list constructor" << std::endl;
		my::vector<int> myvec({5,8,10,6,0,3});
		std::cout << myvec << std::endl;
		std::cout << myvec.size() << "/" << myvec.capacity() << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "Test Case 6 : Assignment operator" << std::endl;
		my::vector<int> myvec({5,8,10,6,0,3});
		my::vector<int> mynewvec;
		mynewvec = myvec;
		std::cout << myvec << std::endl;
		std::cout << myvec.size() << "/" << myvec.capacity() << std::endl;
		std::cout << mynewvec << std::endl;
		std::cout << mynewvec.size() << "/" << mynewvec.capacity() << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "Test Case 7 : Assignment operator initializer list" << std::endl;
		my::vector<int> myvec;
		myvec = {1,2,3,4,5,6};
		std::cout << myvec << std::endl;
		std::cout << myvec.size() << "/" << myvec.capacity() << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "Test Case 8 : Push back within capacity" << std::endl;
		my::vector<int> myvec = {1,2,3,4,5,6};
		std::cout << myvec << std::endl;
		std::cout << myvec.size() << "/" << myvec.capacity() << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "Test Case 9 : Push back out of capacity" << std::endl;
		my::vector<int> myvec = {1,2,3,4,5,6};
		std::cout << myvec << std::endl;
		std::cout << myvec.size() << "/" << myvec.capacity() << std::endl;
		for(int i = 10; i < 80; i+=10) {myvec.push_back(i);}
		std::cout << myvec << std::endl;
		std::cout << myvec.size() << "/" << myvec.capacity() << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "Test Case 10 : Clear" << std::endl;
		my::vector<int> myvec = {1,2,3,4,5,6};
		myvec.clear();
		std::cout << myvec << std::endl;
		std::cout << myvec.size() << "/" << myvec.capacity() << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "Test Case 11 : Element access" << std::endl;
		my::vector<int> myvec = {1,2,3,4,5,6};
		std::cout << myvec[4] << std::endl;
		myvec[4] = 50;
		std::cout << myvec << std::endl;
		std::cout << myvec.size() << "/" << myvec.capacity() << std::endl;
		std::cout << std::endl;
	}
	return 0;
}
