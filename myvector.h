#pragma once
#define CAPACITY_MULTIPLIER 2
#define DEBUG_FLAG false
#define GROWTH_SIZE 2

#include <cstring>
#include <iostream>
#include <iterator>
#include <initializer_list>

namespace my {
    typedef unsigned int sz_type;
    
	template <typename T>
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef std::reverse_iterator<T*> reverse_iterator;
		typedef const std::reverse_iterator<T*> const_Reverse_iterator;

		// constructors/destructors and assignment operators
		vector();
		vector(const sz_type& capacity);
		vector(const sz_type& size, const T& value);
		vector(const vector<T>& copy);
		vector(vector<T>&& copy);
		vector(std::initializer_list<T> ilist);

		~vector();
		vector<T>& operator=(const vector<T>& assign);
		vector<T>& operator=(vector<T>&& assign);
		vector<T>& operator=(std::initializer_list<T> ilist);

		// insertions
		void push_back(const T& value);
        void push_back(T&& value);

		// deletions
		void clear();

		// accessors
		sz_type size() const;
		sz_type capacity() const;
		T& operator [](const sz_type& index) const;
		T& front() const;
		T& back() const;

		// iterators
		T* begin();
		T* end();
		const T* cbegin() const;
		const T* cend() const;

		std::reverse_iterator<T*> rbegin();
		std::reverse_iterator<T*> rend();
		const std::reverse_iterator<T*> crbegin() const;
		const std::reverse_iterator<T*> crend() const;

		// utility
		template <typename U>
		friend std::ostream& operator<<(std::ostream &os, vector<U> const &vec);
	private:
		T* m_arr;
		sz_type m_size = 0;
		sz_type m_capacity = 2;
		void realloc();
		void realloc(const sz_type&);
	};

    // constructors/destructors and assignment operators
	template <typename T>
	vector<T>::vector() {
		m_arr = new T[m_capacity];
	}

	template <typename T>
	vector<T>::vector(const sz_type& capacity) {
		m_size = 0;
		m_capacity = capacity;
		m_arr = new T[m_capacity];
		for (sz_type i; i < capacity; ++i) {
			m_arr[i] = T();
		}
	}

	template <typename T>
	vector<T>::vector(const sz_type& size, const T& value) {
		m_size = size;
		m_capacity = size * CAPACITY_MULTIPLIER;
		m_arr = new T[m_capacity];
		for (sz_type i = 0; i < m_size; ++i) {
			m_arr[i] = value;
		}
	}

	template <typename T>
	vector<T>::vector(const vector<T>& copy) {
		m_size = copy.m_size;
		m_capacity = copy.m_capacity;
		m_arr = new T[m_capacity];
		for (sz_type i = 0 ; i < m_size; ++i) {
			m_arr[i] = copy[i];
		}
	}

	template <typename T>
	vector<T>::vector(vector<T>&& copy) {
		m_size = copy.m_size;
		m_capacity = copy.m_capacity;
		m_arr = new T[m_capacity];
		for (sz_type i = 0 ; i < m_size; ++i) {
			m_arr[i] = std::move(copy[i]);
		}
	}

	template <typename T>
	vector<T>::vector(std::initializer_list<T> ilist) {
		m_size = ilist.size();
		m_capacity = m_size * CAPACITY_MULTIPLIER;
		m_arr = new T[m_capacity];

		sz_type i = 0;
		for (const T& item : ilist) {
			m_arr[i++] = item;
		}
	}

	template <typename T>
	vector<T>::~vector() {
		if (DEBUG_FLAG) std::cout << "***deleting***" << std::endl;
		delete[] m_arr;
	}

	template <typename T>
	vector<T>& vector<T>::operator=(const vector<T>& assign) {
		if (this == &assign) return *this;

		if (m_size == assign.m_size) {
			std::memcpy(m_arr, assign.m_arr, assign.m_size * sizeof(T) );
        } else {
			m_size = assign.m_size;
			m_capacity = assign.m_capacity;
			realloc();
			std::memcpy(m_arr, assign.m_arr, m_size * sizeof(T));
        }
        return *this;
	}

	template <typename T>
	vector<T>& vector<T>::operator=(vector<T>&& assign) {
		if (this == &assign) return *this;
        
        m_size = assign.m_size;
        m_capacity = assign.m_capacity;
        realloc();
        for (sz_type i = 0; i < m_size; ++i) {
            m_arr[i] = std::move(assign.m_arr[i]);
        }
        return *this;
	}

	template <typename T>
	vector<T>& vector<T>::operator=(std::initializer_list<T> ilist) {
		m_size = ilist.size();
		m_capacity = m_size * CAPACITY_MULTIPLIER;
		realloc();
		sz_type i = 0;
		for (const T& item : ilist) {
			m_arr[i++] = item;
		}
		return *this;
	}
    
    // insertions
    template <typename T>
    void vector<T>::push_back(const T& value) {
        if (m_size >= m_capacity) {
            realloc(m_size * GROWTH_SIZE);
        }
        m_arr[m_size] = value;
        ++m_size;
    }
    
    template <typename T>
    void vector<T>::push_back(T&& value) {
        if (m_size >= m_capacity) {
            realloc(m_size * GROWTH_SIZE);
        }
        m_arr[m_size] = std::move(value);
        ++m_size;
    }

    // deletions
    template <typename T>
    void vector<T>::clear() {
        for (sz_type i; i < m_size; ++i) {
            m_arr[i].~T();
        }
        m_size = 0;
    }
    
    // accessors
    template <typename T>
    sz_type vector<T>::size() const {
        return m_size;
    }
    
    template <typename T>
    sz_type vector<T>::capacity() const {
        return m_capacity;
    }
    
    template <typename T>
    T& vector<T>::operator [](const sz_type& index) const {
        return m_arr[index];
    }
    
    template <typename T>
    T& vector<T>::front() const {
        return m_arr[0];
    }
    
    template <typename T>
    T& vector<T>::back() const {
        return m_arr[m_size - 1];
    }
    
    // iterators
    template <typename T>
    T* vector<T>::begin() {
        return m_arr;
    }
    
    template <typename T>
    T* vector<T>::end() {
        return m_arr + m_size;
    }
    
    template <typename T>
    const T* vector<T>::cbegin() const {
        return m_arr;
    }
    
    template <typename T>
    const T* vector<T>::cend() const {
        return m_arr + m_size;
    }
    
    template <typename T>
    std::reverse_iterator<T*> vector<T>::rbegin() {
        return std::reverse_iterator<T*>(m_arr + m_size);
    }
    
    template <typename T>
    std::reverse_iterator<T*> vector<T>::rend() {
        return std::reverse_iterator<T*>(m_arr);
    }
    
    template <typename T>
    const std::reverse_iterator<T*> vector<T>::crbegin() const {
        return std::reverse_iterator<T*>(m_arr + m_size);
    }
    
    template <typename T>
    const std::reverse_iterator<T*> vector<T>::crend() const {
        return std::reverse_iterator<T*>(m_arr);
    }
    
    template <typename T>
	void vector<T>::realloc() {
		T* new_arr = new T[m_capacity];
		memcpy(new_arr, m_arr, m_size*sizeof(T));
		delete[] m_arr;
		m_arr = new_arr;
	}

	template <typename T>
	void vector<T>::realloc(const sz_type& new_capacity) {
		T* new_arr = new T[new_capacity];
		memcpy(new_arr, m_arr, m_size*sizeof(T));
		delete[] m_arr;
		m_capacity = new_capacity;
		m_arr = new_arr;
	}

	template <typename T>
	std::ostream& operator<<(std::ostream& os, vector<T> const& vec) {
		os << "[ ";
	    for (sz_type i = 0; i < vec.size(); ++i ) {
	    	os << vec[i] << " ";
	    }
	    os << "]";
		return os;
	}
}
