#ifndef PAIR_PAMSI_PROJECT_DEFINE
#define PAIR_PAMSI_PROJECT_DEFINE

#include <stdint.h>
#include <string>
#include <utility>

namespace pamsi {

template <typename T, typename W>
class Pair_t {
    T _first;
    W _second;

public:
    Pair_t() = delete;
    Pair_t(T t, W w);
    Pair_t(const Pair_t&);
    [[nodiscard]] T first() const;
    [[nodiscard]] W second() const;

    bool operator<(const Pair_t&);
    bool operator>(const Pair_t&);
    Pair_t operator=(const Pair_t&);
    Pair_t operator=(Pair_t&&);
};

} // namespace pamsi

#include "Pair.tpp"

#endif // LIST_PAMSI_PROJECT_DEFINE