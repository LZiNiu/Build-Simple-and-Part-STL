#include <iostream>
//#include <vector>
#include "myVector.h"
#include <stdio.h>
#include <string>
using namespace std;

int main() {
	vector<int> v;
	//v0.0.1 test push_back, size, capacity succeed
	string s1 = "hello";
	//test push_back func
	cout << "test push_back" << endl;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	cout << v;
	cout << endl;
	//test size and capacity func
	cout << "Size: " << v.size() << "   " << "Capacity: " << v.capacity() << endl;
	cout << "---------------------------------------------------------" << endl;
	//test resize func
	//smaller than orginal
	cout << "test resize (new length is smaller than orignal)" << endl;
	v.resize(8, 0);
	cout << v;
	cout << endl;
	cout << "Size: " << v.size()<<"   " << "Capacity: " << v.capacity() << endl;
	cout << "---------------------------------------------------------" << endl;

	//bigger than orginal
	cout << endl;
	cout << "test resize (new length is bigger than orignal)" << endl;
	v.resize(15,0);
	for (int i = 0; i < 15; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	cout << "Size: " << v.size() << "   " << "Capacity: " << v.capacity() << endl;
	cout << "---------------------------------------------------------"<<endl;
	//test pop
	cout << endl;
	cout << "test pop (pop 5 elements)" << endl;
	for (int i = 0; i < 5; i++) {
		cout << v.pop() << " ";
	}
	cout << endl;
	cout << "Size: " << v.size() << "   " << "Capacity: " << v.capacity() << endl;
	cout << "---------------------------------------------------------" << endl;

	//test reserve
	cout << "test reserve" << endl;
	vector<int> v1;
	v1.reserve(20);
	//v1[0];
	v1.push_back(0);
	v1.push_back(2);
	cout << v1;
	cout << endl;
	cout << "Size: " << v1.size() << "   " << "Capacity: " << v1.capacity() << endl;
	cout << "---------------------------------------------------------" << endl;

	return 0;

}
