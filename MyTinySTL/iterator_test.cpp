#include <iostream>
//#include "myVector.h"
//#include <vector>
//using namespace std;

//template<typename T>
//T func(int a) {
//	return a;
//}

struct input_iterator_tag {};

template <class T> struct input_iterator
{
	typedef input_iterator_tag	iterator_category;
	typedef T					value_type;
	typedef T*					pointer;
	typedef T&					reference;
};

template<class Category, class T, class Pointer = T * , class Reference = T & >
struct iterator
{
	typedef Category	iterator_category;
	typedef T			value_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
};

template<class Iterator>
struct iterator_traits
{
	typedef typename Iterator::iterator_category	iterator_category;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference 			reference;
};
template<class T>
typename input_iterator<T>::pointer it;


template<class Iterator>
typename iterator_traits<Iterator>::value_type function() {

}
//template<typename _Ty>


int main() {
	/*vector<int> v;
	v.push_back(1);
	v.push_back(2);
	vector<int>::iterator it;*/
	
	int* p1 = nullptr;
	int* p2 = nullptr;
	std::cout << p1 - p1;

	return 0;
}