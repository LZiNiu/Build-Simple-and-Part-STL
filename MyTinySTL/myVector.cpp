#include "myVector.h"
#include <assert.h>


template<typename T>
T& vector<T>::operator[](int pos)
{
	/*for user to []*/
	
	//check if vector is accessible(initialized)
	assert( this->data != nullptr );

	//reverse indices
	if (pos < 0) {
		pos = -pos-1;
	}
	//type cast avoid warining

	//check if out of range
	if (size_t(pos) >= this->m_capacity)
	{
		std::cout << "index out of range!";
		exit(-1);
	}
	return this->data[pos];
}
template<typename T>
T& vector<T>::operator[](size_t pos) const
{
	/*for overload << or other const situation to use []*/
	
	//check if vector is accessible(initialized)
	assert(this->data != nullptr);

	//check if out of range
	if (pos >= this->m_capacity)
	{
		std::cout << "index out of range!";
		exit(-1);
	}
	return this->data[pos];
}

template<typename T>
void vector<T>::push_back(const T& val)
{
	/*
	add data to the tail of vector
	if the capacity is not enough to add the data,
	expand(double) the capacity
	*/
	
	if (this->m_capacity == 0) {
		this->m_capacity=2;
		this->data = new T[this->m_capacity];
	}
	//if reserve has been called, initialized data
	if (this->is_reserve) {
		this->data = new T[this->m_capacity];
		this->is_reserve =false;
	}

	//when after push_back size > capacity, reallocate space 
	if (this->m_size + 1 > this->m_capacity) {
		this->m_capacity = 2 * this->m_capacity;
		//assign a new memory storage
		T *data = new T[this->m_capacity];
		//move original data to the new vector
		for (size_t i = 0; i < this->m_size; i++) {
			data[i] = this->data[i];
		}
		//delete original taken space
		delete[] this->data;
		this->data = data;
	}
	this->data[this->m_size++] = val;
}
template<typename T>
T& vector<T>::pop()
{
	return this->data[--this->m_size];
}

template<typename T>
void vector<T>::resize(size_t _len, const T& val)
{
	//when the size of resize target is smaller than the orgin one
	//just make the capacity reduce to the _len which is equal to do logistic delete
	if (this->m_capacity > _len) {
		this->m_capacity = _len;
		if (this->m_size >= _len) this->m_size = _len;
		return;
	}
	T* data = new T[_len];
	
	for (size_t i = 0; i < _len; i++) {
		data[i] = (i < this->m_size) ? this->data[i]: val;
	}
	delete[] this->data;
	this->data = data;
	this->m_capacity = _len;
}

template<typename T>
void vector<T>::reserve(int _len)
{
	this->m_capacity = _len;
	this->is_reserve = true;
}

template<typename T>
size_t vector<T>::size() const
{
	return this->m_size;
}

template<typename T>
size_t vector<T>::capacity() const
{
	return this->m_capacity;
}

template<typename Ty>
inline std::ostream & operator<<(std::ostream & out, const vector<Ty>& v)
{
	// TODO: 在此处插入 return 语句
	for (size_t i = 0; i < v.size(); i++) {
		out << v[i] << " ";
	}
	return out;
}


//int & vector::iterator::operator*()
//{
//	return *ptr;
//}
