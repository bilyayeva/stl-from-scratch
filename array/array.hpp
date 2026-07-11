#ifndef SFS_ARRAY_HPP
#define SFS_ARRAY_HPP

#include <cstddef>
#include <iterator>
#include <stdexcept>
#include <algorithm>
#include <type_traits>
#include <compare>
#include <utility>

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
                throw std::out_of_range( "sfs::array::at: position >= size" );
            }
            return data_[pos];
        }

        constexpr const_reference at( size_type pos ) const {
            if ( pos >= this->size() ) {
                throw std::out_of_range( "sfs::array::at: position >= size" );
            }
            return data_[pos];
        }

        constexpr reference operator[]( size_type pos ) noexcept {
            return data_[pos];
        }

        constexpr const_reference operator[]( size_type pos ) const noexcept {
            return data_[pos];
        }

        constexpr reference front() noexcept {
            return data_[0];
        }

        constexpr const_reference front() const noexcept {
            return data_[0];
        }

        constexpr reference back() noexcept {
            return data_[N - 1];
        }

        constexpr const_reference back() const noexcept {
            return data_[N - 1];
        }

        constexpr pointer data() noexcept {
            return &data_[0];
        }

        constexpr const_pointer data() const noexcept {
            return &data_[0];
        }
        
    //
    // Iterators
    //

        constexpr iterator begin() noexcept {
            return &data_[0];
        }

        constexpr const_iterator begin() const noexcept {
            return &data_[0];
        }

        constexpr const_iterator cbegin() const noexcept {
            return this->begin();
        }

        constexpr iterator end() noexcept {
            return &data_[N];
        }

        constexpr const_iterator end() const noexcept {
            return &data_[N];
        }

        constexpr const_iterator cend() const noexcept {
            return this->end();
        }

        constexpr reverse_iterator rbegin() noexcept {
            return reverse_iterator( this->end() );
        }

        constexpr const_reverse_iterator rbegin() const noexcept {
            return const_reverse_iterator( this->end() );
        }

        constexpr const_reverse_iterator crbegin() const noexcept {
            return this->rbegin();
        }

        constexpr reverse_iterator rend() noexcept {
            return reverse_iterator( this->begin() );
        }

        constexpr const_reverse_iterator rend() const noexcept {
            return const_reverse_iterator( this->begin() );
        }

        constexpr const_reverse_iterator crend() const noexcept {
            return this->rend();
        }

    //
    // Capacity
    //

        constexpr bool empty() const noexcept {
            return (N == 0);
        }

        constexpr size_type size() const noexcept {
            return N;
        }

        constexpr size_type max_size() const noexcept {
            return this->size();
        }

    //
    // Operations
    //

        constexpr void fill ( const_reference value ) noexcept {
            for ( size_type i{0}; i < N; ++i ) {
                data_[i] = value;
            }
        }

        constexpr void swap( array& other ) noexcept( std::is_nothrow_swappable_v<T> ) {
            for ( size_type i{0}; i < N; ++i ) {
                std::swap( this->data_[i], other.data_[i] );
            }
        }

    //
    // Non-member functions
    //

        friend constexpr bool operator==(const sfs::array& lhs, const sfs::array& rhs) {
            for ( size_type i{0}; i < N; ++i ) {
                if ( lhs.data_[i] != rhs.data_[i] ) {
                    return false;
                }
            }
            return true;
        }

        friend constexpr auto operator<=>( const sfs::array& lhs, const sfs::array& rhs) {
            for ( size_type i{0}; i < N; ++i ) {
                if ( auto cmp = lhs.data_[i] <=> rhs.data_[i]; cmp != 0 ) {
                    return cmp;
                }
            }
            return std::strong_ordering::equal;
        }

    };

    template<std::size_t I, class T, std::size_t N>
    constexpr T& get( sfs::array<T, N>& a ) noexcept {
        static_assert(I < N, "sfs::get: index out of bounds");
        return a[I];
    }

    template<std::size_t I, class T, std::size_t N>
    constexpr T&& get( sfs::array<T, N>&& a ) noexcept {
        static_assert(I < N, "sfs::get: index out of bounds");
        return std::move(a[I]);
    }

    template<std::size_t I, class T, std::size_t N>
    constexpr const T& get( const sfs::array<T, N>& a ) noexcept {
        static_assert(I < N, "sfs::get: index out of bounds");
        return a[I];
    }

    template<std::size_t I, class T, std::size_t N>
    constexpr const T&& get( const sfs::array<T, N>&& a ) noexcept {
        static_assert(I < N, "sfs::get: index out of bounds");
        return std::move(a[I]);
    }

    template<class T, std::size_t N>
    constexpr void swap( sfs::array<T, N>& lhs, sfs::array<T, N>& rhs ) noexcept(noexcept(lhs.swap(rhs))) {
        lhs.swap(rhs);
    }

}

#endif