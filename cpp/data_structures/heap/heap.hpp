#pragma once

#include <cstddef>
#include <stdexcept>

template <typename T, typename Comp>
class Heap {
public:
    Heap(Comp comp)
        : m_Comp(comp) {
        ReAlloc(3);
    }

    Heap(const Heap<T, Comp> &other) = delete;
    Heap(Heap<T, Comp> &&other) = delete;;

    ~Heap() {
        delete[] m_Data;
    }

    Heap<T, Comp> &operator=(const Heap<T, Comp> &other) = delete;;
    Heap<T, Comp> &operator=(Heap<T, Comp> &&other) = delete;;

    int Size() const { return m_Size; }

    bool Empty() const { return m_Size == 0; }

    const T &Peek() const {
        if (m_Size == 0)
            throw std::runtime_error("size is 0");

        return m_Data[0];
    }

    T Pop() {
        if (m_Size == 0)
            throw std::runtime_error("size is 0");

        T item = m_Data[0];
        m_Data[0] = m_Data[--m_Size];

        HeapifyDown();

        return item;
    }

    void Push(const T &item) {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity / 2);

        m_Data[m_Size++] = item;

        HeapifyUp();
    }

private:
    int GetLeftChildIndex(int parentIndex) const { return 2 * parentIndex + 1; }
    int GetRightChildIndex(int parentIndex) const { return 2 * parentIndex + 2; }
    int GetParentIndex(int childIndex) const { return (childIndex - 1) / 2; }

    bool hasLeftChild(int index) const { return GetLeftChildIndex(index) < m_Size; }
    bool hasRightChild(int index) const { return GetRightChildIndex(index) < m_Size; }
    bool hasParent(int index) const { return GetParentIndex(index) >= 0; }

    T &LeftChild(int index) { return m_Data[GetLeftChildIndex(index)]; }
    T &RightChild(int index) { return m_Data[GetRightChildIndex(index)]; }
    T &Parent(int index) { return m_Data[GetParentIndex(index)]; }

    void Swap(int indexOne, int indexTwo) {
        T temp = m_Data[indexOne];
        m_Data[indexOne] = m_Data[indexTwo];
        m_Data[indexTwo] = temp;
    }

    void ReAlloc(int newCapacity) {
        if (newCapacity < m_Size)
            m_Size = newCapacity;

        T *newBlock = new T[newCapacity];

        for (int i = 0; i < m_Size; ++i)
            newBlock[i] = m_Data[i];

        delete[] m_Data;
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }

    void HeapifyUp() {
        int index = m_Size - 1;
        while (hasParent(index) && m_Comp(Parent(index), m_Data[index])) {
            Swap(GetParentIndex(index), index);
            index = GetParentIndex(index);
        }
    }

    void HeapifyDown() {
        int index = 0;
        while (hasLeftChild(index)) {
            int smallerChildIndex = GetLeftChildIndex(index);
            if (hasRightChild(index) && !m_Comp(RightChild(index), LeftChild(index)))
                smallerChildIndex = GetRightChildIndex(index);

            if (!m_Comp(m_Data[index], m_Data[smallerChildIndex]))
                break;

            Swap(index, smallerChildIndex);
            index = smallerChildIndex;
        }
    }

private:
    T *m_Data = nullptr;

    Comp m_Comp;

    int m_Capacity = 0;
    int m_Size = 0;
};

