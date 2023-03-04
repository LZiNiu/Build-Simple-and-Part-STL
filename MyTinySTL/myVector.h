#pragma once
#include <iostream>

template<typename T>
class vector {
private:

	T* first;
	T* end;
	T* EndOfStorage;

	bool is_reserve;

public:
	typedef T* pointer;
	typedef T& reference;
	
	struct iterator {
		
		pointer ptr;

		iterator() :ptr(nullptr) {}
			
		reference operator*() { return *ptr; }
		pointer operator->() { return ptr; }
		
		//++i
		reference operator++() { ptr++; return *this; }
		//i++
		reference operator++(int) { 
			iterator temp = *this;
			++(*this);
			return temp;
		}
	};
public:
	vector() :
		first(nullptr),
		end(nullptr),
		EndOfStorage(nullptr),
		is_reserve(false)
	{};

	

	T& operator[](int pos);
	
	T& operator[](size_t pos) const;
	
	//overload cout<< to print to console conveniently
	template<typename Ty>
	friend std::ostream& operator<<(std::ostream& out, const vector<Ty>& v);
	
	void push_back(const T &val);
	T& pop();
	//redistribute a different size space for orginal vector
	void resize(size_t _len, const T& val);
	
	//reserve space for vector but still be inaccessible
	void reserve(int _len);

	//get real size
	size_t size()const;
	//get total size
	size_t capacity()const;

};

//don't forget exclude myVector.cpp from complie
//so can it be linked
#include "myVector.cpp"

