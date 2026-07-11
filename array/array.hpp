#ifndef SFS_ARRAY_HPP
#define SFS_ARRAY_HPP

#include <cstddef>
#include <iterator>
#include <stdexcept>
#include <string>
#include <algorithm>

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

        constexpr reference at( size_type pos ) {
            if ( pos >= this->size() ) {
                throw std::out_of_range( "sfs::array::at: position (which is "
                                        + std::to_string(pos)
                                        + ") >= size (which is "
                                        + std::to_string(N)
                                        + ")" );
            }
            return data_[pos];
        }

        constexpr const_reference at( size_type pos ) const {
            if ( pos >= this->size() ) {
                throw std::out_of_range( "sfs::array::at: position (which is "
                                        + std::to_string(pos)
                                        + ") >= size (which is "
                                        + std::to_string(N)
                                        + ")" );
            }
            return data_[pos];
        }

        constexpr reference operator[]( size_type pos ) {
            return data_[pos];
        }

        constexpr const_reference operator[]( size_type pos ) const {
            return data_[pos];
        }

        constexpr reference front() {
            return data_[0];
        }

        constexpr const_reference front() const {
            return data_[0];
        }

        constexpr reference back() {
            return data_[N - 1];
        }

        constexpr const_reference back() const {
            return data_[N - 1];
        }

        constexpr pointer data() {
            return &data_[0];
        }

        constexpr const_pointer data() const {
            return &data_[0];
        }
        
    //
    // Iterators
    //

        constexpr iterator begin() {
            return &data_[0];
        }

        constexpr const_iterator begin() const {
            return &data_[0];
        }

        constexpr const_iterator cbegin() const {
            return this->begin();
        }

        constexpr iterator end() {
            return &data_[N];
        }

        constexpr const_iterator end() const {
            return &data_[N];
        }

        constexpr const_iterator cend() const {
            return this->end();
        }

        constexpr reverse_iterator rbegin() {
            return this->end();
        }

        constexpr const_reverse_iterator rbegin() const {
            return this->end();
        }

        constexpr const_reverse_iterator crbegin() const {
            return this->rbegin();
        }

        constexpr reverse_iterator rend() {
            return this->begin();
        }

        constexpr const_reverse_iterator rend() const {
            return this->begin();
        }

        constexpr const_reverse_iterator crend() const {
            return this->rend();
        }

    //
    // Capacity
    //

        constexpr bool empty() const {
            return (N == 0);
        }

        constexpr size_type size() const {
            return N;
        }

        constexpr size_type max_size() const {
            return this->size();
        }

    //
    // Operations
    //

        constexpr void fill ( const_reference value ) {
            for ( size_type i{0}; i < N; ++i ) {
                data_[i] = value;
            }
        }

        constexpr void swap( array& other ) {
            for ( size_type i{0}; i < N; ++i ) {
                std::swap( this->data_[i], other.data_[i] );
            }
        }

    };
}

#endif