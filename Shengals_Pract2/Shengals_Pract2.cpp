#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

void task1() {
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) minIndex = i;
        if (arr[i] > arr[maxIndex]) maxIndex = i;
    }
    swap(arr[minIndex], arr[maxIndex]);

    cout << "Массив после замены:\n";
    for (int x : arr) cout << x << " ";
    cout << endl;
}

void task2() {
    int n;
    cout << "Введите размер квадратной матрицы: ";
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    for (int i = 0; i < n; i++)
        swap(matrix[i][i], matrix[i][n - 1 - i]);

    cout << "Матрица после замены диагоналей:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

struct Computer {
    char brand[50];
    char model[50];
    double price;
};

void task3() {
    int n;
    cout << "Введите количество компьютеров: ";
    cin >> n;
    vector<Computer> comps(n);

    for (int i = 0; i < n; i++) {
        cout << "Бренд: ";
        cin >> comps[i].brand;
        cout << "Модель: ";
        cin >> comps[i].model;
        cout << "Цена: ";
        cin >> comps[i].price;
    }

    sort(comps.begin(), comps.end(), [](Computer& a, Computer& b) {
        return a.price < b.price;
        });

    cout << "\nКомпьютеры после сортировки по цене:\n";
    for (auto& c : comps) {
        cout << c.brand << " " << c.model << " - " << c.price << endl;
    }
}

class Date {
private:
    int day, month, year;
public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    bool isValid() {
        if (year < 1 || month < 1 || month > 12 || day < 1) return false;
        int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        if (month == 2) {
            bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            if (leap) daysInMonth[1] = 29;
        }
        return day <= daysInMonth[month - 1];
    }
};

void task4() {
    int d, m, y;
    cout << "Введите дату (день месяц год): ";
    cin >> d >> m >> y;
    Date date(d, m, y);
    if (date.isValid()) cout << "Дата корректна\n";
    else cout << "Дата некорректна\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;
    cout << "Выберите задание (1-4): ";
    cin >> choice;

    switch (choice) {
    case 1: task1(); break;
    case 2: task2(); break;
    case 3: task3(); break;
    case 4: task4(); break;
    default: cout << "Неверный выбор\n";
    }
    return 0;
}
