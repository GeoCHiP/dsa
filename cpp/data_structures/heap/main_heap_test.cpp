#include <iostream>
#include <vector>
#include <unordered_map>

#include "heap.hpp"

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        if (k == nums.size()) {
            return nums;
        }

        std::unordered_map<int, int> count;
        for (const int &n : nums)
            ++count[n];

        auto comp = [&count](int a, int b) { return count[a] > count[b]; };
        Heap<int, decltype(comp)> heap(comp);

        for (const auto &[n, c] : count) {
            heap.Push(n);
            if (heap.Size() > k)
                heap.Pop();
        }

        std::vector<int> result(k);
        for (int i = k - 1; i >= 0; --i) {
            result[i] = heap.Peek();
            heap.Pop();
        }

        return result;
    }
};

int main() {
    Solution s;

    std::vector<int> nums = {2,2,2,2,3,3,1,1,1,1,1,4,4,4,5,5,5,5,5,5,6,6,7,8};

    std::vector<int> result = s.topKFrequent(nums, 4);

    for (const int &n : result) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;
}

