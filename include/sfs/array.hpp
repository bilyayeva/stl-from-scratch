#ifndef SFS_ARRAY_HPP
#define SFS_ARRAY_HPP

#include <cstddef>
#include <iterator>
#include <stdexcept>
#include <algorithm>
#include <type_traits>
#include <compare>
#include <utility>
#include <concepts>
#include <tuple>

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

        [[nodiscard]] constexpr reference at( size_type pos ) {
            if ( pos >= this->size() ) {
                throw std::out_of_range( "sfs::array::at: position >= size" );
            }
            return data_[pos];
        }

        [[nodiscard]] constexpr const_reference at( size_type pos ) const {
            if ( pos >= this->size() ) {
                throw std::out_of_range( "sfs::array::at: position >= size" );
            }
            return data_[pos];
        }

        [[nodiscard]] constexpr reference operator[]( size_type pos ) noexcept {
            return data_[pos];
        }

        [[nodiscard]] constexpr const_reference operator[]( size_type pos ) const noexcept {
            return data_[pos];
        }

        [[nodiscard]] constexpr reference front() noexcept {
            return data_[0];
        }

        [[nodiscard]] constexpr const_reference front() const noexcept {
            return data_[0];
        }

        [[nodiscard]] constexpr reference back() noexcept {
            return data_[N - 1];
        }

        [[nodiscard]] constexpr const_reference back() const noexcept {
            return data_[N - 1];
        }

        [[nodiscard]] constexpr pointer data() noexcept {
            return &data_[0];
        }

        [[nodiscard]] constexpr const_pointer data() const noexcept {
            return &data_[0];
        }
        
    //
    // Iterators
    //

        [[nodiscard]] constexpr iterator begin() noexcept {
            return &data_[0];
        }

        [[nodiscard]] constexpr const_iterator begin() const noexcept {
            return &data_[0];
        }

        [[nodiscard]] constexpr const_iterator cbegin() const noexcept {
            return this->begin();
        }

        [[nodiscard]] constexpr iterator end() noexcept {
            return &data_[N];
        }

        [[nodiscard]] constexpr const_iterator end() const noexcept {
            return &data_[N];
        }

        [[nodiscard]] constexpr const_iterator cend() const noexcept {
            return this->end();
        }

        [[nodiscard]] constexpr reverse_iterator rbegin() noexcept {
            return reverse_iterator( this->end() );
        }

        [[nodiscard]] constexpr const_reverse_iterator rbegin() const noexcept {
            return const_reverse_iterator( this->end() );
        }

        [[nodiscard]] constexpr const_reverse_iterator crbegin() const noexcept {
            return this->rbegin();
        }

        [[nodiscard]] constexpr reverse_iterator rend() noexcept {
            return reverse_iterator( this->begin() );
        }

        [[nodiscard]] constexpr const_reverse_iterator rend() const noexcept {
            return const_reverse_iterator( this->begin() );
        }

        [[nodiscard]] constexpr const_reverse_iterator crend() const noexcept {
            return this->rend();
        }

    //
    // Capacity
    //

        [[nodiscard]] constexpr bool empty() const noexcept {
            return (N == 0);
        }

        [[nodiscard]] constexpr size_type size() const noexcept {
            return N;
        }

        [[nodiscard]] constexpr size_type max_size() const noexcept {
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

    [[nodiscard]] friend constexpr bool operator==( const array& lhs, const array& rhs ) {
        return std::equal( lhs.begin(), lhs.end(), rhs.begin(), rhs.end() );
    }

    [[nodiscard]] friend constexpr auto operator<=>( const array& lhs, const array& rhs ) {
        return std::lexicographical_compare_three_way( lhs.begin(), lhs.end(), rhs.begin(), rhs.end() );
    }

    };

//
//  Explicit specialization for empty array (N = 0)
//

    template<class T>
    struct array<T, 0> {

        struct empty_element {};

        [[no_unique_address]] empty_element data_{};
    
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

    //
    // Element Access (N = 0)
    //

        [[nodiscard]] constexpr reference at( size_type ) {
            throw std::out_of_range( "sfs::array::at: position >= size (N == 0)" );
        }

        [[nodiscard]] constexpr const_reference at( size_type ) const {
            throw std::out_of_range( "sfs::array::at: position >= size (N == 0)" );
        }

        [[nodiscard]] constexpr reference operator[]( size_type pos ) noexcept {
            return *data();
        }

        [[nodiscard]] constexpr const_reference operator[]( size_type pos ) const noexcept {
            return *data();
        }

        [[nodiscard]] constexpr reference front() noexcept {
            return *data();
        }

        [[nodiscard]] constexpr const_reference front() const noexcept {
            return *data();
        }

        [[nodiscard]] constexpr reference back() noexcept {
            return *data();
        }

        [[nodiscard]] constexpr const_reference back() const noexcept {
            return *data();
        }

        [[nodiscard]] constexpr pointer data() noexcept {
            return nullptr;
        }

        [[nodiscard]] constexpr const_pointer data() const noexcept {
            return nullptr;
        }
        
    //
    // Iterators (N = 0)
    //

        [[nodiscard]] constexpr iterator begin() noexcept {
            return nullptr;
        }

        [[nodiscard]] constexpr const_iterator begin() const noexcept {
            return nullptr;
        }

        [[nodiscard]] constexpr const_iterator cbegin() const noexcept {
            return this->begin();
        }

        [[nodiscard]] constexpr iterator end() noexcept {
            return nullptr;
        }

        [[nodiscard]] constexpr const_iterator end() const noexcept {
            return nullptr;
        }

        [[nodiscard]] constexpr const_iterator cend() const noexcept {
            return this->end();
        }

        [[nodiscard]] constexpr reverse_iterator rbegin() noexcept {
            return reverse_iterator( this->end() );
        }

        [[nodiscard]] constexpr const_reverse_iterator rbegin() const noexcept {
            return const_reverse_iterator( this->end() );
        }

        [[nodiscard]] constexpr const_reverse_iterator crbegin() const noexcept {
            return this->rbegin();
        }

        [[nodiscard]] constexpr reverse_iterator rend() noexcept {
            return reverse_iterator( this->begin() );
        }

        [[nodiscard]] constexpr const_reverse_iterator rend() const noexcept {
            return const_reverse_iterator( this->begin() );
        }

        [[nodiscard]] constexpr const_reverse_iterator crend() const noexcept {
            return this->rend();
        }

    //
    // Capacity (N = 0)
    //

        [[nodiscard]] constexpr bool empty() const noexcept {
            return true;
        }

        [[nodiscard]] constexpr size_type size() const noexcept {
            return 0;
        }

        [[nodiscard]] constexpr size_type max_size() const noexcept {
            return this->size();
        }

    //
    // Operations (N = 0)
    //

        constexpr void fill ( const_reference ) noexcept {}

        constexpr void swap( array& ) noexcept( std::is_nothrow_swappable_v<T> ) {}

    //
    // Non-member functions (N = 0)
    //

        [[nodiscard]] friend constexpr bool operator==(const sfs::array<T, 0>& lhs, const sfs::array<T, 0>& rhs) {
            return true;
        }

        [[nodiscard]] friend constexpr auto operator<=>( const sfs::array<T, 0>& lhs, const sfs::array<T, 0>& rhs) {
            return std::strong_ordering::equal;
        }

    };

    template< class T, class... U >
    array( T, U... ) -> array<T, 1 + sizeof...(U)>;

//
// Non-member functions (continued)
//

    template<std::size_t I, class T, std::size_t N>
    [[nodiscard]] constexpr T& get( sfs::array<T, N>& a ) noexcept {
        static_assert(I < N, "sfs::get: index out of bounds");
        return a[I];
    }

    template<std::size_t I, class T, std::size_t N>
    [[nodiscard]] constexpr T&& get( sfs::array<T, N>&& a ) noexcept {
        static_assert(I < N, "sfs::get: index out of bounds");
        return std::move(a[I]);
    }

    template<std::size_t I, class T, std::size_t N>
    [[nodiscard]] constexpr const T& get( const sfs::array<T, N>& a ) noexcept {
        static_assert(I < N, "sfs::get: index out of bounds");
        return a[I];
    }

    template<std::size_t I, class T, std::size_t N>
    [[nodiscard]] constexpr const T&& get( const sfs::array<T, N>&& a ) noexcept {
        static_assert(I < N, "sfs::get: index out of bounds");
        return std::move(a[I]);
    }

    template<class T, std::size_t N>
    constexpr void swap( sfs::array<T, N>& lhs, sfs::array<T, N>& rhs ) noexcept(noexcept(lhs.swap(rhs))) {
        lhs.swap(rhs);
    }

    template<class T, std::size_t N>
    [[nodiscard]] constexpr sfs::array<std::remove_cv_t<T>, N> to_array( T (&a)[N] ) noexcept(std::is_nothrow_constructible_v<T, T&>) {
        return [&a]<std::size_t... I>( std::index_sequence<I...> ) {
            return sfs::array<std::remove_cv_t<T>, N>{{ a[I]... }};
        }( std::make_index_sequence<N>{});
    }

    template<class T, std::size_t N>
    [[nodiscard]] constexpr sfs::array<std::remove_cv_t<T>, N> to_array( T (&&a)[N] ) noexcept(std::is_nothrow_constructible_v<T, T&&>) {
        return [&a]<std::size_t... I>( std::index_sequence<I...> ) {
            return sfs::array<std::remove_cv_t<T>, N>{{ std::move(a[I])... }};
        }( std::make_index_sequence<N>{});
    }

}

namespace std {

    template<class T, std::size_t N>
    struct tuple_size< sfs::array<T, N> > : std::integral_constant<std::size_t, N> {};

    template<std::size_t I, class T, std::size_t N>
    struct tuple_element<I, sfs::array<T,N>> {
        static_assert(I < N, "std::tuple_element: index out of bounds");
        using type = T;
    };

    using sfs::get;
}

#endif