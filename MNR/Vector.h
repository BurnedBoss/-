#pragma once
#include<stdexcept>

using std::out_of_range;

template<typename T>
class Vector
{
	T* memory;
	int capacity;
	int count;

	void resize();

public:
	Vector();
	Vector(const Vector& other);
	Vector& operator= (const Vector& other);
	~Vector();
	int size() const;
	void push_back(const T& element);
	const T& operator [] (int index) const;
	T& operator [] (int index);
};

template<typename T>
inline void Vector<T> ::   resize()
{
	this->capacity = 2 * this->capacity;
	T* biggerMemory = new T[capacity];
	for (int i = 0; i < capacity; i++)
	{
		biggerMemory[i] = memory[i];
	}

	delete[] memory;
	memory = biggerMemory;
}

template<typename T>
inline Vector<T>::Vector() : count(0), capacity(2)
{
	memory = new T[capacity];
}

template<typename T>
inline Vector<T>::Vector(const Vector& other)
{
	this->capacity = other.capacity;
	this->count = other.count;
	this->memory = new T[capacity];
	for (int i = 0; i < this->count; i++)
	{
		this->memory[i] = other.memory[i];
	}
}

template<typename T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		delete[] memory;
		this->capacity = other.capacity;
		this->count = other.count;
		this->memory = new T[capacity];
		for (int i = 0; i < this->count; i++)
		{
			this->memory[i] = other.memory[i];
		}
	}
	return *this;
}

template<typename T>
inline Vector<T>::~Vector()
{
	delete[] memory;
}

template<typename T>
inline int Vector<T>::size() const
{
	return count;
}

template<typename T>
inline void Vector<T>::push_back( const T& element)
{
	if (count == capacity)
	{
		resize();
	}
	memory[count] = element;
	count++;
}

template<typename T>
 inline const T&  Vector<T>::operator[](int index) const
{
	if (index >= count)
	{
		throw out_of_range("Invalid index");

	}
	return memory[index];
}
 template<typename T>
inline T& Vector<T>::operator[](int index)
{
	if (index >= count)
	{
		out_of_range("Invalid index");
	}
	return memory[index];
}
