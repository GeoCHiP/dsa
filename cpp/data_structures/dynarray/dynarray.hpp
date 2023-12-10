#include <cstddef>

template<typename T>
class DynArray {
public:
    DynArray() : m_Allocated(0), m_Size(0), m_Data(nullptr) {}
    ~DynArray() {
        delete[] m_Data;
    }

    void PushBack(T value) {
        if (m_Size < m_Allocated) {
            m_Data[m_Size++] = value;
        } else {
            T *newData = new T[++m_Allocated];
            for (size_t i = 0; i < m_Size; ++i) {
                newData[i] = m_Data[i];
            }

            delete[] m_Data;
            m_Data = newData;
            m_Data[m_Size++] = value;
        }
    }

    size_t Size() const { return m_Size; }

    T &operator[](size_t idx) { return m_Data[idx]; }
    const T &operator[](size_t idx) const { return m_Data[idx]; }

private:
    size_t m_Allocated;
    size_t m_Size;
    T *m_Data;
};
