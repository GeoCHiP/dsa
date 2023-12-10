#include <iostream>
#include <vector>
#include "vector.hpp"

struct Vector3 {
    float x = 0.0f, y = 0.0f, z = 0.0f;

    Vector3() {}
    Vector3(int scalar)
            : x(scalar), y(scalar), z(scalar) {}

    Vector3(int x, int y, int z)
            : x(x), y(y), z(z) {}

    ~Vector3() {
        std::cout << "Destroy\n";
    }

    Vector3(const Vector3 &other)
            : x(other.x), y(other.y), z(other.z) {
        std::cout << "Copy\n";
    }
    
    Vector3(Vector3 &&other)
            : x(other.x), y(other.y), z(other.z) {
        std::cout << "Move\n";
    }

    Vector3 &operator=(const Vector3 &other) {
        x = other.x;
        y = other.y;
        z = other.z;

        std::cout << "Copy\n";
        return *this;
    }

    Vector3 &operator=(Vector3 &&other) {
        x = other.x;
        y = other.y;
        z = other.z;

        std::cout << "Move\n";
        return *this;
    }
};

template <typename T>
void PrintVector(const T &vector) {
    for (size_t i = 0; i < vector.Size(); ++i)
        std::cout << vector[i] << std::endl;
}

template<>
void PrintVector(const Vector<Vector3> &vector) {
    for (size_t i = 0; i < vector.Size(); ++i)
        std::cout << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << std::endl;
}

int main() {
    Vector<Vector3> vec;

    vec.EmplaceBack(1, 2, 3);
    vec.EmplaceBack(4);
    vec.EmplaceBack();
    vec.EmplaceBack(2);
    vec.EmplaceBack(1, 6, 9);
    vec.EmplaceBack(6, 2, 7);
    vec.EmplaceBack();
    PrintVector(vec);

    vec.Clear();
}
