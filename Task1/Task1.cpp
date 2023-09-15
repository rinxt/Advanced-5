#include <iostream>
#include <vector>

// Реализация для чисел
template <class T>
T square(T value) {
    return value * value;
}

// Реализация для векторов
template <class T>
std::vector<T> square(const std::vector<T>& values) {
    std::vector<T> result;
    for (const T& value : values) {
        result.push_back(value * value);
    }
    return result;
}

template <class T>
void print_vec(const std::vector<T>& values) {
    for (const auto& value : values) {
        std::cout << value;
        if (&value != &values.back()) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

int main() {
    system("chcp 1251");
    std::srand(std::time(nullptr));

    int num = rand() % 199 - 99; // Генерируем случайное число от -99 до 99
    std::cout << "Случайное число для возведения в квадрат: " << num << std::endl;
    auto singleResult = square(num);
    std::cout << "Результат: " << singleResult << std::endl;

    int vectorSize = rand() % 10 + 1; // Генерируем случайный размер вектора от 1 до 10
    std::cout << "Случайный вектор чисел для возведения в квадрат (размер " << vectorSize << "): ";
    std::vector<int> input;
    for (int i = 0; i < vectorSize; ++i) {
        input.push_back(rand() % 100); // Генерируем случайное число от 0 до 99 и добавляем в вектор
    }

    print_vec(input);
    auto vectorResult = square(input);
    std::cout << "Результат: ";
    print_vec(vectorResult);
    
    return 0;
}
