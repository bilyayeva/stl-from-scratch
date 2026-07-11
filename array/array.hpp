#ifndef SFS_ARRAY_HPP
#define SFS_ARRAY_HPP

#include <cstddef>
#include <iterator>
#include <stdexcept>
#include <string>

namespace sfs {
    
    template<class T, std::size_t N>
    struct array {
    
    //
    // Aliases
    //
        
        using value_type                = T;
        using size_type                 = std::size_t;
        using difference_type           = std::ptrdiff_t;
        using reference                 = value_type&;
        using const_reference           = const value_type&;
        using pointer                   = value_type*;
        using const_pointer             = const value_type*;
        using iterator                  = value_type*;
        using const_iterator            = const value_type*;
        using reverse_iterator          = std::reverse_iterator<iterator>;
        using const_reverse_iterator    = std::reverse_iterator<const_iterator>;

    // Underlying storage for the elements;
    // Size is fixed at compile time (N)
        value_type data_[N];

    //
    // Element Access
    //

        reference at( size_type pos ) {
            if ( pos >= this->size() ) {
                throw std::out_of_range( "sfs::array::at: position (which is "
                                        + std::to_string(pos)
                                        + ") >= size (which is "
                                        + std::to_string(N)
                                        + ")" );
            }
            return data_[pos];
        }

        const_reference at( size_type pos ) const {
            if ( pos >= this->size() ) {
                throw std::out_of_range( "sfs::array::at: position (which is "
                                        + std::to_string(pos)
                                        + ") >= size (which is "
                                        + std::to_string(N)
                                        + ")" );
            }
            return data_[pos];
        }

        reference operator[]( size_type pos ) {
            return data_[pos];
        }

        const_reference operator[]( size_type pos ) const {
            return data_[pos];
        }

        reference front();

        const_reference front() const;

        reference back();

        const_reference back() const;

        pointer data();

        const_pointer data() const;
        
    //
    // Iterators
    //

        iterator begin();

        const_iterator begin() const;

        const_iterator cbegin() const;

        iterator end();

        const_iterator end() const;

        const_iterator cend() const;

        reverse_iterator rbegin();

        const_reverse_iterator rbegin() const;

        const_reverse_iterator crbegin() const;

        reverse_iterator rend();

        const_reverse_iterator rend() const;

        const_reverse_iterator crend() const;

    //
    // Capacity
    //

        bool empty() const;

        size_type size() const;

        size_type max_size() const;

    //
    // Operations
    //

        void fill ( const_reference value );

        void swap( array& other );

    };
}

#endif