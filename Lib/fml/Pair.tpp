#include "Pair.hpp"

namespace pamsi {
template <typename T, typename W>
Pair_t<T, W>::Pair_t(T t, W w)
{
    _first = t;
    _second = w;
}

template <typename T, typename W>
Pair_t<T, W>::Pair_t(const Pair_t& p)
{
    this->_first = p._first;
    this->_second = p._second;
}

template <typename T, typename W>
[[nodiscard]] T Pair_t<T, W>::first() const
{
    return _first;
}

template <typename T, typename W>
[[nodiscard]] W Pair_t<T, W>::second() const
{
    return _second;
}

template <typename T, typename W>
bool Pair_t<T, W>::operator<(const Pair_t& p)
{
    return _first < p._first;
}
template <typename T, typename W>
bool Pair_t<T, W>::operator>(const Pair_t& p)
{
    return _first > p._first;
}
template <typename T, typename W>
Pair_t<T, W> Pair_t<T, W>::operator=(const Pair_t& p)
{
    this->_first = p._first;
    this->_second = p._second;

    return (*this);
}

template <typename T, typename W>
Pair_t<T, W> Pair_t<T, W>::operator=(Pair_t&& p)
{
    this->_first = p._first;
    this->_second = p._second;

    return (*this);
}

} // namespace pamsi