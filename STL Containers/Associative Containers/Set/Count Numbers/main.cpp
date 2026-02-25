#include <iostream>
#include <set>

int main() {
    std::set<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8};
    int L, R;

    std::cout << "L: ";
    std::cin >> L;
    
    std::cout << "R: ";
    std::cin >> R;

    auto start = numbers.lower_bound(L);
    auto end = numbers.upper_bound(R);
    
    int count = 0;
    for (auto it = start; it != end; it++) {
        std::cout << *it << " ";
        count++;
    }
    
    std::cout << "\nCount: " << count;
}