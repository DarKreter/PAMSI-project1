#ifndef PAIR_PAMSI_PROJECT_DEFINE
#define PAIR_PAMSI_PROJECT_DEFINE

namespace pamsi {

/**
 * @brief Data type which can store two values of different types
 * The first value is perceived as a key and comparison operators are basing on
 * comparing keys
 *
 * @tparam T data type of key
 * @tparam W data type of value
 */
template <typename T, typename W>
class Pair_t {
    T _first;
    W _second;

public:
    /**
     * @brief Construct a new Pair_t object.
     * Creates object with default values.
     *
     */
    Pair_t() = default;
    /**
     * @brief Construct a new Pair_t object.
     *
     * @param t value to store in key
     * @param w value to store in second variable
     */
    Pair_t(T t, W w);
    /**
     * @brief Copy constructor
     *
     */
    Pair_t(const Pair_t&);
    /**
     * @brief Getter for first value
     *
     * @return T type of key
     */
    [[nodiscard]] T first() const;
    /**
     * @brief Getter for second value
     *
     * @return W type of second variable value
     */
    [[nodiscard]] W second() const;

    /**
     * @brief Setter of first variable
     *
     * @param t value to set
     */
    void first(T t) { _first = t; }
    /**
     * @brief Setter of second variable
     *
     * @param w value to set
     */
    void second(W w) { _second = w; }

    /**
     * @brief Comparison operator. Is comparing object, just like it would
     * compare keys.
     *
     */
    bool operator<(const Pair_t&);
    bool operator>(const Pair_t&);
    /**
     * @brief Comparison operator. Is comparing object, just like it would
     * compare keys.
     *
     */
    Pair_t operator=(const Pair_t&);
    /**
     * @brief assignment operator. Write values from second object to the first
     * one.
     *
     */
    Pair_t operator=(Pair_t&&);
};

} // namespace pamsi

#include "Pair.tpp"

#endif // LIST_PAMSI_PROJECT_DEFINE