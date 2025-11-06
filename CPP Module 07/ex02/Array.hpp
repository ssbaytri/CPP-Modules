#pragma once

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	private:
		T* _data;
		unsigned int _size;

	public:
	// Default constructor - creates empty array
		Array() : _data(NULL), _size(0) {}

		// Constructor with size parameter
		Array(unsigned int n) : _data(NULL), _size(n)
		{
			if (n > 0)
				_data = new T[n]();
		}

		// Copy constructor - DEEP COPY
		Array(const Array &other) : _data(NULL), _size(other._size)
		{
			if (_size > 0)
			{
				_data = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_data[i] = other._data[i];
			}
		}

		// Destructor
    	~Array() {
        	if (_data)
            	delete[] _data;
		}

		// Assignment operator - DEEP COPY
		Array& operator=(const Array &other)
		{
			if (this != other)
			{
				if (_data)
				{
					delete[] _data;
					_data = NULL;
				}
				_size = other._size;
				if (_size > 0)
				{
					_data = new T[_size];
					for (unsigned int i = 0; i < _size; i++)
						_data[i] = other._data[i];
				}
			}
			return *this;
		}

		T& operator[](unsigned int index) 
		{
			if (index >= _size) {
				throw std::out_of_range("Index out of bounds");
			}
			return _data[index];
		}

		// Const version
		const T& operator[](unsigned int index) const
		{
			if (index >= _size) {
				throw std::out_of_range("Index out of bounds");
			}
			return _data[index];
		}

		unsigned int size() const
		{
        	return _size;
    	}
};