#pragma once
#define GROWTH_SIZE 1.5
#define CAPACITY_MULTIPLIER 2

#include <iterator>

namespace my {
    typedef unsigned int sz_type;
    
	template <typename T>
	class vector {
	public:
		// typedefs
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
		vector<T>& operator=(const vector<T>&);
		vector<T>& operator=(vector<T>&&);

		// insertions
		void push_back(const T&);
        void push_back(T&&);

		// deletions
		void clear();

		// accessors
		sz_type size() const;
		sz_type capacity() const;
		T& operator [](const sz_type&) const;
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
	vector<T>::vector(const sz_type& size) {
		m_size = size;
		m_capacity = size * CAPACITY_MULTIPLIER;
		for (sz_type i; i < size; ++i) {
			m_arr[i] = T();
		}
	}

	template <typename T>
	vector<T>::vector(const sz_type& size, const T& value) {
		m_size = size;
		m_capacity = size * CAPACITY_MULTIPLIER;
		for (sz_type i; i < m_size; ++i) {
			m_arr[i] = value;
		}
	}

	template <typename T>
	vector<T>::vector(const vector<T>& copy) {
		m_size = copy.m_size;
		m_capacity = copy.m_capacity;
		m_arr = new T[m_capacity];
		for (sz_type i; i < m_size; ++i) {
			m_arr[i] = copy[i];
		}
	}

	template <typename T>
	vector<T>::vector(vector<T>&& copy) {
		m_size = copy.m_size;
		m_capacity = copy.m_capacity;
		m_arr = new T[m_capacity];
		for (sz_type i; i < m_size; ++i) {
			m_arr[i] = std::move(copy[i]);
		}
	}

	template <typename T>
	vector<T>::~vector() {
		delete[] m_arr;
	}

	template <typename T>
	vector<T>& vector<T>::operator=(const vector<T>& assign) {
		if (this == &assign) return *this;

		if (m_size == assign.m_size) {
			memcpy(m_arr, assign.m_arr, assign.m_size * sizeof(T) );
        } else {
			m_size = assign.m_size;
			m_capacity = assign.m_capacity;
			realloc();
			memcpy(m_arr, assign.m_arr, m_size * sizeof(T));
        }
        return *this;
	}

	template <typename T>
	vector<T>& vector<T>::operator=(vector<T>&& assign) {
		if (this == &assign) return *this;
        
        m_size = assign.m_size;
        m_capacity = assign.m_capacity;
        realloc();
        for (sz_type i; i < m_size; ++i) {
            m_arr[i] = std::move(assign.m_arr[i]);
        }
	}
    
    // insertions
    template <typename T>
    void vector<T>::push_back(const T& value) {
        if (m_size >= m_capacity) {
            realloc(m_size * 2);
        }
        m_arr[m_size] = value;
        ++m_size;
    }
    
    template <typename T>
    void vector<T>::push_back(T&& value) {
        if (m_size >= m_capacity) {
            realloc(m_size * 2);
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
		m_arr = new_arr;
	}
}
