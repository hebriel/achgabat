#ifndef AG_VECTOR2_HPP
#define AG_VECTOR2_HPP

#include <SFML/System/Vector2.hpp>

namespace ag {

template<class T>
class Vector2 : public sf::Vector2<T>
{
    public:
        Vector2();
        Vector2(T x, T y) : sf::Vector2<T>(x, y) {}

        Vector2 operator*(const T& number)
        {
            return Vector2<T>(this->x * number, this->y * number);
        }

    protected:

    private:
};

typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;
typedef Vector2<unsigned int> Vector2u;

} // namespace ag

#endif // AG_VECTOR2_HPP
