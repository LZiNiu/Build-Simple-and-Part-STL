#include "myVector.h"
#include <assert.h>


template<typename T>
T& vector<T>::operator[](int pos)
{
	/*for user to []*/
	
	//check if vector is accessible(initialized)
	assert( this->first != nullptr && !this->is_reserve );

	//reverse indices
	if (pos < 0) {
		pos = -pos-1;
	}
	//type cast avoid warining

	//check if out of range
	if (size_t(pos) >= this->capacity())
	{
		std::cout << "index out of range!";
		exit(-1);
	}
	return this->first[pos];
}
template<typename T>
T& vector<T>::operator[](size_t pos) const
{
	/*for overload << or other const situation to use []*/
	
	//check if vector is accessible(initialized)
	assert(this->first != nullptr && !this->is_reserve);

	//check if out of range
	if (pos >= this->capacity())
	{
		std::cout << "index out of range!";
		exit(-1);
	}
	return this->first[pos];
}

template<typename T>
void vector<T>::push_back(const T& val)
{
	/*
	add data to the tail of vector
	if the capacity is not enough to add the data,
	expand(double) the capacity
	*/

	size_t n_capacity = this->capacity();
	if (n_capacity == 0) {
		this->first = this->end = new T[2];
		this->EndOfStorage = this->first + 2;
		n_capacity = 2;
	}
	//if reserve has been called, initialized data(make vector can be accessed)
	if (this->is_reserve) {
		this->is_reserve =false;
	}

	//when after push_back size > capacity, reallocate space 
	if (this->size() + 1 > n_capacity) {
		size_t n_size = this->size();
		n_capacity = 2 * n_capacity;
		//assign a new memory storage
		T *data = new T[n_capacity];
		//move original data to the new vector
		for (size_t i = 0; i < n_size; i++) {
			data[i] = this->first[i];
		}
		//delete original taken space
		delete[] this->first;
		//uddate new pointer
		this->first = data;
		this->end = this->first + n_size;
		this->EndOfStorage = this->first + n_capacity;
	}
	
	*(this->end++) = val;
}
template<typename T>
T& vector<T>::pop()
{
	return *(this->end--);
}

template<typename T>
void vector<T>::resize(size_t _len, const T& val)
{
	//when the size of resize target is smaller than the orgin one
	//just make the capacity reduce to the _len which is equal to do logistic delete
	
	size_t n_size = this->size();
	//space too much
	if (n_size >= _len) {
		this->EndOfStorage = this->end = this->first + _len;
	}
	else {
		
		if (this->capacity() < _len) {

			T* data = new T[_len];
			for (size_t i = 0; i < _len; i++) {
				data[i] = (i < n_size) ? this->first[i]: val;
			}
			delete[] this->first;
			this->first = data;
			this->end = this->first + n_size;
		}
		//space enough just move pointer forward 
		this->EndOfStorage = this->first + _len;
	}
	
}

template<typename T>
void vector<T>::reserve(int _len)
{
	this->is_reserve = true;
	this->first = this->end = new int[_len];
	this->EndOfStorage = this->first + _len;
}

template<typename T>
size_t vector<T>::size() const
{
	return this->end - this->first;
}

template<typename T>
size_t vector<T>::capacity() const
{
	return this->EndOfStorage - this->first;
}

template<typename Ty>
inline std::ostream & operator<<(std::ostream & out, const vector<Ty>& v)
{
	for (size_t i = 0; i < v.size(); i++) {
		out << v[i] << " ";
	}
	return out;
}


//int & vector::iterator::operator*()
//{
//	return *ptr;
//}
