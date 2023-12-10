#include <cstddef>

template<typename T, size_t S>
class Array {
public:
    constexpr size_t Size() const { return S; }

    T &operator[](size_t i) { return m_Data[i]; }
    const T &operator[](size_t i) const { return m_Data[i]; }

    T *Data() { return m_Data; }
    const T *Data() const { return m_Data; }
private:
    T m_Data[S];
};
