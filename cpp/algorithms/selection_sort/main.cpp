#include <iostream>
#include <vector>

void selectionSort(std::vector<int> &v) {
    for (int minPos = 0; minPos < v.size(); ++minPos) {
        int currentMinIndex = minPos;
        for (int i = minPos; i < v.size(); ++i) {
            if (v[i] < v[currentMinIndex]) {
                currentMinIndex = i;
            }
        }
        int temp = v[minPos];
        v[minPos] = v[currentMinIndex];
        v[currentMinIndex] = temp;
    }
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

    selectionSort(v);

    std::cout << "After:\n";
    PrintVec(v);
}

