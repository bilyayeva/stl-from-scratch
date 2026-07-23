#ifndef SFS_REVERSE_ITERATOR_HPP
#define SFS_REVERSE_ITERATOR_HPP

#include <iterator>
#include <type_traits>
#include <concepts>

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

        constexpr reverse_iterator();

        constexpr explicit reverse_iterator(iterator_type x);

        template<class U>
        requires std::convertible_to<const U&, Iter>
        constexpr reverse_iterator(const reverse_iterator<U>& other);

    };

} // namespace sfs

#endif