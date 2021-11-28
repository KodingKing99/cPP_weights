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
        const R count() { return m_count; }
        template <typename S>
        weight operator+(S s)
        {
            weight w(s.count() + m_count);
            return w;
        }

      private:
        R m_count;
    };
    using microgram = weight<std::ratio<1, 100000>, double>;
    using gram = weight<>;
    using kilogram = weight<std::ratio<1000, 1>, double>;
    using ounce = weight<std::ratio<2834952, 100000>, double>;
    using ton = weight<std::ratio<9071847, 10>, double>;
    using pound = weight<std::ratio<4535924, 10000>, double>;
} // namespace usu
