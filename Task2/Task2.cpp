#include <iostream>
#include <vector>

template <class T>
class Table {
private:
    int rows_;
    int cols_;
    std::vector<std::vector<T>> data_;

public:
    Table(int rows, int cols) : rows_(rows), cols_(cols) {
        data_.resize(rows, std::vector<T>(cols));
    }

    // Константная версия оператора [], возвращающая строку
    const std::vector<T>& operator[](int row) const {
        return data_[row];
    }

    // Неконстантная версия оператора [], возвращающая строку
    std::vector<T>& operator[](int row) {
        return data_[row];
    }

    // Константная функция Size, возвращающая размер таблицы
    const std::pair<int, int> Size() {
        return std::make_pair(rows_, cols_);
    }

    // Заполняет таблицу случайными числами в заданном диапазоне и выводит в консоль
    void fillRandom(T min_value, T max_value) {
        std::srand((std::time(nullptr)));  
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                data_[i][j] = static_cast<T>(std::rand() % (max_value - min_value + 1) + min_value);
                std::cout << data_[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    system("chcp 1251");
    Table<int> table(3, 4);

    table.fillRandom(1, 9);

    std::pair<int, int> size = table.Size();
    std::cout << "Число строк: " << size.first << std::endl;
    std::cout << "Число столбцов: " << size.second << std::endl;

    std::cout << "Элемент [0][0]: " << table[0][0]; 

    return 0;
}
