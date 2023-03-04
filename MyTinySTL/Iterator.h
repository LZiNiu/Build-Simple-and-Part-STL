#pragma once


template<typename _Tp, typename _Pointer=_Tp*, typename _Reference=_Tp&>
struct iterator
{
	/// One of the iterator_tags tag types.
	//typedef _Category  iterator_category;
	/// The type "pointed to" by the iterator.
	typedef _Tp  value_type;
	/// Distance between iterators is represented as this type.
	//typedef _Distance  difference_type;
	/// This type represents a pointer-to-value_type.
	typedef _Pointer   pointer;
	/// This type represents a reference-to-value_type.
	typedef _Reference reference;
	
};

template<typename iterator>
struct iterator_traits
{
	typedef typename iterator::value_type value_type;
	typedef typename iterator::pointer pointer;
	typedef typename iterator::reference reference;
};
//support origin pointer
template<typename _Tp>
struct iterator_traits<_Tp*>
{
	typedef typename _Tp::value_type value_type;
	typedef typename _Tp::pointer pointer;
	typedef typename _Tp::reference reference;
};
