#include <cstddef>
#include <stdexcept>
#include <iterator>

template <typename T>
struct ListNode {
    T value;
    ListNode *next;

    ListNode() : value(T()), next(nullptr) {}
    ListNode(const T &value) : value(value), next(nullptr) {}
    ListNode(const T &value, ListNode *next) : value(value), next(next) {}
};

template <typename List>
class ListIterator : public std::iterator<std::forward_iterator_tag, typename List::ValueType> {
public:
    using ReferenceType = typename List::ValueType&;
    using ListNodeType = typename List::ListNodeType;
    using ListNodePointerType = ListNodeType*;

public:
    ListIterator(ListNodePointerType nodePtr)
        : m_NodePtr(nodePtr) {}

    ListIterator &operator++() {
        m_NodePtr = m_NodePtr->next;
        return *this;
    }

    ListIterator operator++(int) {
        ListIterator iterator(*this);
        ++(*this);
        return iterator;
    }

    ReferenceType operator*() {
        return m_NodePtr->value;
    }

    bool operator==(const ListIterator &other) {
        return m_NodePtr == other.m_NodePtr;
    }

    bool operator!=(const ListIterator &other) {
        return !(*this == other);
    }

private:
    ListNodePointerType m_NodePtr;
};

template <typename T>
class List {
public:
    using ValueType = T;
    using ListNodeType = ListNode<T>;
    using Iterator = ListIterator<List<T>>;

public:
    List() : m_Head(nullptr), m_Size(0) {}

    ~List() {
        if (!m_Head)
            return;

        ListNode<T> *currentNode = m_Head;
        while (currentNode) {
            ListNode<T> *nextNode = currentNode->next;
            delete currentNode;
            currentNode = nextNode;
        }

    }

    void PushBack(const T &value) {
        if (!m_Head) {
            m_Head = new ListNode<T>(value);
            m_Size += 1;
            return;
        }

        ListNode<T> *currentNode = m_Head;
        while (currentNode->next) {
            currentNode = currentNode->next;
        }

        currentNode->next = new ListNode<T>(value);
        m_Size += 1;
    }

    void PushFront(const T &value) {
        ListNode<T> *newHead = new ListNode<T>(value, m_Head);
        m_Head = newHead;
        m_Size += 1;
    }

    T PopBack() {
        if (!m_Head)
            throw std::runtime_error("Can't PopBack from an empty list!");

        if (!m_Head->next) {
            T value = m_Head->value;

            m_Size -= 1;

            delete m_Head;
            m_Head = nullptr;

            return value;
        }

        ListNode<T> *previousNode = m_Head;
        ListNode<T> *currentNode = m_Head;
        while (currentNode->next) {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }

        ListNode<T> *nodeToDelete = currentNode;
        T value = nodeToDelete->value;

        previousNode->next = currentNode->next;
        m_Size -= 1;

        delete nodeToDelete;
        return value;
    }

    T PopFront() {
        if (!m_Head)
            throw std::runtime_error("Can't PopFront from an empty list!");

        ListNode<T> *oldHead = m_Head;
        T value = oldHead->value;

        m_Head = m_Head->next;
        m_Size -= 1;

        delete oldHead;
        return value;
    }

    size_t Size() const {
        return m_Size;
    }

    bool Empty() const {
        return m_Head == nullptr;
    }

    Iterator begin() {
        return Iterator(m_Head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

private:
    ListNode<T> *m_Head;
    size_t m_Size;
};

