#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm> // Для std::next_permutation, хотя в данном решении не используется

using namespace std;

// Функция для проверки наличия всех цифр от 0 до 9 в трёх числах
bool allDigitsPresent(const vector<int>& nums) {
    unordered_set<char> digits; // Используем множество для хранения уникальных цифр
    
    // Перебираем все три числа в комбинации
    for (int num : nums) {
        string numStr = to_string(num); // Преобразуем число в строку
        // Добавляем все цифры числа в множество
        for (char c : numStr) {
            digits.insert(c);
        }
    }
    
    // Если собрали все 10 цифр - возвращаем true
    return digits.size() == 10;
}

int main() {
    // Ускоряем ввод/вывод (отключаем синхронизацию с C-потоками)
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; // Количество тестовых случаев
    cin >> t;
    
    // Обрабатываем каждый тестовый случай
    for (int testCase = 0; testCase < t; ++testCase) {
        int n; // Количество чисел в тесте
        cin >> n;
        
        vector<int> numbers(n); // Вектор для хранения чисел
        // Читаем n чисел
        for (int i = 0; i < n; ++i) {
            cin >> numbers[i];
        }
        
        bool found = false; // Флаг нахождения решения
        
        // В C++ нет прямого аналога combinations из itertools,
        // поэтому используем три вложенных цикла для перебора всех комбинаций из 3 чисел
        for (int i = 0; i < n && !found; ++i) {
            for (int j = i + 1; j < n && !found; ++j) {
                for (int k = j + 1; k < n && !found; ++k) {
                    // Создаём вектор из трёх текущих чисел
                    vector<int> triple = {numbers[i], numbers[j], numbers[k]};
                    
                    // Проверяем, содержат ли они все цифры от 0 до 9
                    if (allDigitsPresent(triple)) {
                        // Выводим найденную комбинацию
                        cout << numbers[i] << " " << numbers[j] << " " << numbers[k] << "\n";
                        found = true; // Помечаем, что решение найдено
                    }
                }
            }
        }
    }
    
    return 0;
}