#pragma once
#define GROWTH_SIZE 1.5
#define CAPACITY_MULTIPLIER 2

#include <iterator>

namespace my {
	template <typename T>
	class vector {
	public:
		// typedefs
		typedef unsigned int sz_type;
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef std::reverse_iterator<iterator> reverse_iterator;
		typedef const std::reverse_iterator<iterator> const_reverse_iterator;

		// constructors/destructors and assignment operators
		vector();
		vector(const sz_type&);
		vector(const sz_type&, const T&);
		vector(const vector<T>&);
		vector(vector<T>&&);
		~vector();
		void operator=(const vector<T>&);
		void operator=(vector<T>&&);

		// insertions
		void push_back(const T&);

		// deletions
		void clear();

		// accessors
		sz_type size() const;
		sz_type capacity() const;
		T& operator [](sz_type) const;
		T& front() const;
		T& back() const;

		// iterators
		iterator begin();
		iterator end();
		const_iterator cbegin() const;
		const_iterator cend() const;

		iterator rbegin();
		iterator rend();
		const_iterator crbegin() const;
		const_iterator crend() const;

	private:
		T* arr;
		sz_type size = 0;
		sz_type capacity = 2;
		void realloc();
		void realloc(const sz_type&);
	};

	template <typename T>
	vector<T>::vector() {
		arr = new T[capacity];
	}

	template <typename T>
	vector<T>::vector(const sz_type& nsize) {
		size = nsize;
		capacity = nsize * CAPACITY_MULTIPLIER;
		for (sz_type i; i < n; ++i) {
			arr[i] = T();
		}
	}

	template <typename T>
	vector::vector(const sz_type& nsize, const T& nvalue) {
		size = nsize;
		capacity = nsize * CAPACITY_MULTIPLIER;
		for (sz_type i; i < size; ++i) {
			arr[i] = nvalue;
		}
	}

	template <typename T>
	vector::vector(const vector<T>& copy) {
		size = copy.size;
		capacity = copy.capacity;
		arr = new T[capacity];
		for (sz_type i; i < size; ++i) {
			arr[i] = copy[i];
		}
	}

	template <typename T>
	vector::vector(vector<T>&& copy) {
		size = copy.size;
		capacity = copy.capacity;
		arr = new T[capacity];
		for (sz_type i; i < size; ++i) {
			arr[i] = std::move(copy[i]);
		}
	}

	template <typename T>
	vector::~vector() {
		delete[] arr;
	}

	template <typename T>
	vector<T>& vector::operator=(const vector<T>& assign) {
		if (this == &assign) return *this;

		if (size = assign.size) {
			memcpy(arr, assign.arr, assign.size*sizeof(T));
			return *this;
		} else if (size > assign.size) {
			size = assign.size;
			capacity = assign.capacity;
			realloc();
			memcpy(arr, assign.arr, size*sizeof(T));
		} else {

		}

	}

	template <typename T>
	vector<T>& vector::operator=(vector<T>&& assign) {
		if (this == &assign) return *this;

	}

	template <typename T>
	void vector::realloc() {
		T* new_arr = new T[capacity];
		memcpy(new_arr, arr, size*sizeof(T));
		delete[] arr;
		arr = new_arr;
	}

	template <typename T>
	void vector::realloc(const sz_type& new_capacity) {
		T* new_arr = new T[new_capacity];
		memcpy(new_arr, arr, size*sizeof(T));
		delete[] arr;
		arr = new_arr;
	}
}
