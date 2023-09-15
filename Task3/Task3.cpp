#include <iostream>
#include <vector>
#include <algorithm>

class DivisibleByThreeCounter {
private:
    int sum;
    int count;

public:
    DivisibleByThreeCounter() : sum(0), count(0) {}

    void operator()(int num) {
        if (num % 3 == 0) {
            sum += num;
            count++;
        }
    }

    int get_sum() {
        return sum;
    }

    int get_count() {
        return count;
    }
};

int main() {
    std::vector<int> numbers;

    std::srand((std::time(nullptr)));
    for (int i = 0; i < 10; ++i) {
        numbers.push_back(std::rand() % 11);
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    DivisibleByThreeCounter counter = std::for_each(numbers.begin(), numbers.end(), DivisibleByThreeCounter());

    std::cout << "get_sum() = " << counter.get_sum() << std::endl;
    std::cout << "get_count() = " << counter.get_count() << std::endl;

    return 0;
}
