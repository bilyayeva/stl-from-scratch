#ifndef SFS_ARRAY_HPP
#define SFS_ARRAY_HPP

#include <cstddef>
#include <iterator>

namespace sfs {
    
    template<class T, std::size_t N>
    struct array {

    // Underlying storage for the elements;
    // Size is fixed at compile time (N)
        T data_[N];

    //
    // Element Access
    //

        T& at( std::size_t pos );

        const T& at( std::size_t pos );

        T& operator[]( std::size_t pos );

        const T& operator[]( std::size_t pos) const;

        T& front();

        const T& front() const;

        T& back();

        const T& back() const;

        T* data();

        const T* data() const;
        
    //
    // Iterators
    //

        T* begin();

        const T* begin() const;

        const T* cbegin() const;

        T* end();

        const T* end() const;

        const T* cend() const;

        std::reverse_iterator<T*> rbegin();

        const std::reverse_iterator<const T*> rbegin() const;

        const std::reverse_iterator<const T*> crbegin() const;

        std::reverse_iterator<T*> rend();

        const std::reverse_iterator<const T*> rend() const;

        const std::reverse_iterator<const T*> crend() const;

    //
    // Capacity
    //

        bool empty() const;

        std::size_t size() const;

        std::size_t max_size() const;

    //
    // Operations
    //

        void fill (const T& value );

        void swap( array& other );

    };
}

#endif