#include <cmath>
#include <iostream>
#include <ratio>
namespace usu
{
    template <typename T = std::ratio<1, 1>, typename R = std::uint64_t>
    class weight
    {
        using conversion = T;

      public:
        weight() :
            m_count(0) {}
        weight(R newCount) :
            m_count(newCount) {}
        R count() const { return m_count; }
        template <typename S>
        weight operator+(S s)
        {
            weight w(s.count() + m_count);
            return w;
        }
        template <typename P>
        weight operator-(P p)
        {
            weight w(m_count - p.count());
            return w;
        }
        T getRatio() const
        {
            return m_ratio;
        }

      private:
        R m_count;
        T m_ratio;
    };
    template <typename T>
    T operator*(double i, const T& s)
    {
        // auto num = s->count();
        T w(s.count() * i);
        return w;
    }
    template <typename T>
    T operator*(const T& lhs, double scaler)
    {
        T w(lhs.count() * scaler);
        return w;
    }
    template <typename T, typename S>
    T weight_cast(S oldweight)
    {
        T t;
        T newWeight(static_cast<double>(oldweight.count()) * oldweight.getRatio().num * t.getRatio().den / (oldweight.getRatio().den * t.getRatio().num));
        return newWeight;
    }
    using microgram = weight<std::ratio<1, 100000>, double>;
    using gram = weight<>;
    using kilogram = weight<std::ratio<1000, 1>, double>;
    using ounce = weight<std::ratio<2834952, 100000>, double>;
    using ton = weight<std::ratio<9071847, 10>, double>;
    using pound = weight<std::ratio<4535924, 10000>, double>;
    template <typename T, typename R>
    bool operator==(const T& lhs, const R& rhs)
    {

        std::cout << "w1 count before: " << lhs.count() << " w2 count before: " << rhs.count() << std::endl;
        auto w1 = weight_cast<weight<std::ratio<1, 1>, double>>(lhs);
        auto w2 = weight_cast<weight<std::ratio<1, 1>, double>>(rhs);
        std::cout << "w1 count: " << w1.count() << "w2 count: " << w2.count() << std::endl;
        // std::cout << ""
        // auto result = std::sqrt(std::pow(static_cast<double>(w2.count() - w1.count()), 2.0));
        // std::cout << "result: " << result << std::endl;
        return (w1.count() == w2.count());
    }
} // namespace usu
