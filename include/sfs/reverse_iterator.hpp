#ifndef SFS_REVERSE_ITERATOR_HPP
#define SFS_REVERSE_ITERATOR_HPP

#include <iterator>
#include <type_traits>
#include <concepts>
#include <compare>

namespace sfs {

    template<class Iter>
    class reverse_iterator {
    public:

        using iterator_type         = Iter;
        using iterator_concept      = std::conditional_t
                                        <
                                            std::random_access_iterator<Iter>,
                                            std::random_access_iterator_tag,
                                            std::bidirectional_iterator_tag
                                        >;
        using iterator_category     = std::conditional_t
                                        <
                                            std::derived_from
                                            <
                                                typename std::iterator_traits<Iter>::iterator_category,
                                                std::random_access_iterator_tag
                                            >,
                                            std::random_access_iterator_tag,
                                            typename std::iterator_traits<Iter>::iterator_category
                                        >;
        using value_type            = std::iter_value_t<Iter>;
        using difference_type       = std::iter_difference_t<Iter>;
        using pointer               = typename std::iterator_traits<Iter>::pointer;
        using reference             = std::iter_reference_t<Iter>;
        
    protected:
        
        Iter current;
    
    public:

    //
    // Member functions
    //

        constexpr reverse_iterator();

        constexpr explicit reverse_iterator(iterator_type x);

        template<class U>
        requires (std::convertible_to<const U&, Iter>)
        constexpr reverse_iterator(const reverse_iterator<U>& other);

        template<class U>
        requires (std::convertible_to<const U&, Iter> && std::assignable_from<Iter&, const U&>)
        constexpr reverse_iterator& operator=(const reverse_iterator<U>& other);
     
        constexpr iterator_type base() const;

        constexpr reference operator*() const;

        constexpr pointer operator->() const
        requires (std::is_pointer_v<Iter> || requires (const Iter i) {i.operator->();});

        constexpr reference operator[](difference_type n) const;

        constexpr reverse_iterator& operator++();

        constexpr reverse_iterator& operator--();

        constexpr reverse_iterator operator++(int);

        constexpr reverse_iterator operator--(int);

        constexpr reverse_iterator operator+(difference_type n) const;

        constexpr reverse_iterator operator-(difference_type n) const;

        constexpr reverse_iterator& operator+=(difference_type n);

        constexpr reverse_iterator& operator-=(difference_type n);

    //
    // Non-member functions
    //

        template<class Iter1, class Iter2>
        constexpr bool operator==(const std::reverse_iterator<Iter1>& lhs,
                                  const std::reverse_iterator<Iter1>& rhs);

        template<class Iter1, class Iter2>
        constexpr bool operator!=(const std::reverse_iterator<Iter1>& lhs,
                                  const std::reverse_iterator<Iter1>& rhs);

        template<class Iter1, class Iter2>
        constexpr bool operator<(const std::reverse_iterator<Iter1>& lhs,
                                 const std::reverse_iterator<Iter1>& rhs);

        template<class Iter1, class Iter2>
        constexpr bool operator<=(const std::reverse_iterator<Iter1>& lhs,
                                  const std::reverse_iterator<Iter1>& rhs);

        template<class Iter1, class Iter2>
        constexpr bool operator>(const std::reverse_iterator<Iter1>& lhs,
                                 const std::reverse_iterator<Iter1>& rhs);

        template<class Iter1, class Iter2>
        constexpr bool operator>=(const std::reverse_iterator<Iter1>& lhs,
                                  const std::reverse_iterator<Iter1>& rhs);

        template<class Iter1, std::three_way_comparable_with<Iter1> Iter2>
        constexpr std::compare_three_way_result_t<Iter1, Iter2>
                    operator<=>(const std::reverse_iterator<Iter1>& lhs,
                                const std::reverse_iterator<Iter2>& rhs);

        template<class Iter>
        constexpr reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n,
                                         const reverse_iterator<Iter>& it);

        template<class Iter1, class Iter2>
        auto operator-(const reverse_iterator<Iter1>& lhs,
                       const reverse_iterator<Iter2>& rhs) -> decltype(rhs.base() - lhs.base());

        friend constexpr std::iter_rvalue_reference_t<Iter>
        iter_move(const reverse_iterator& i)
            noexcept(
                std::is_nothrow_copy_constructible_v<Iter> &&
                noexcept(std::ranges::iter_move(--std::declval<Iter&>()))
            );

    };

} // namespace sfs

#endif