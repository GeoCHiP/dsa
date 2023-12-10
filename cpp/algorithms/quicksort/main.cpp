#include <iostream>
#include <vector>
#include <random>

int partition(std::vector<int> &v, int l, int r) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(l, r);

    int pivotIndex = dist(gen);
    int pivot = v[pivotIndex];
    std::swap(v[pivotIndex], v[r]);

    int i = l;

    for (int j = l; j < r; ++j) {
        if (v[j] <= pivot) {
            std::swap(v[i], v[j]);
            i += 1;
        }
    }

    std::swap(v[i], v[r]);

    return i;
}

void quickSort(std::vector<int> &v, int l, int r) {
    if (l >= r)
        return;

    int p = partition(v, l, r);

    quickSort(v, l, p - 1);
    quickSort(v, p + 1, r);
}

void PrintVec(const std::vector<int> &v) {
    for (int num : v) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> v = {4, 1, 0, -3, 8, -7, 4, 2, 9};

    std::cout << "Before:\n";
    PrintVec(v);

    quickSort(v, 0, v.size() - 1);

    std::cout << "After:\n";
    PrintVec(v);
}

