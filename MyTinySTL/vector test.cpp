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
	for (int i = 0; i < 200; i++) {
		v.push_back(2);
	}
	cout << v[0];
	cout << endl;
	//test size and capacity func
	cout << "Size: " << v.size() << "Capacity: " << v.capacity() << endl;
	cout << "---------------------------------------------------------" << endl;
	//test resize func
	//smaller than orginal
	v.resize(100, 0);
	cout << v;
	cout << endl;
	cout << "Size: " << v.size()<<" " << "Capacity: " << v.capacity() << endl;
	
	cout << "---------------------------------------------------------" << endl;
	//bigger than orginal
	v.resize(150,0);
	for (int i = 0; i < 150; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	cout << "Size: " << v.size() << " " << "Capacity: " << v.capacity() << endl;
	//test pop
	cout << "---------------------------------------------------------"<<endl;
	for (int i = 0; i < 10; i++) {
		cout << v.pop() << " ";
	}
	cout << endl;
	cout << "Size: " << v.size() << "Capacity: " << v.capacity() << endl;
	//
	cout << "---------------------------------------------------------" << endl;
	//test reserve
	vector<int> v1;
	v1.reserve(100);
	//v1[0];
	v1.push_back(0);
	v1.push_back(2);
	cout << v1;

	return 0;

}
