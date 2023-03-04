#pragma once
#include <iostream>

template<typename T>
class vector {
private:
	T* data;
	size_t m_size;
	size_t m_capacity;
	//unsigned int Iter;
	bool is_reserve;
	
	
	class iterator {
		private:
			T *ptr;

		public:
			iterator() :ptr(nullptr) {};
			
			T& operator*();
			T& operator->();
		};
public:
	vector() :data(nullptr),
		m_size(0),
		m_capacity(0),
		/*Iter(0)*/
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

