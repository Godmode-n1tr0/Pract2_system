#include <iostream>
#include <cstring>
using namespace std;

struct Comp {
    char br[50];  // Поле для бренда
    char md[50];  // Поле для модели
    double pr;  // Поле для цены
};

class Date {
private:
    int d, m, y;
public:
    Date(int dd, int mm, int yy) {  // Конструктор класса Date
        d = dd;  // Инициализация
        m = mm;
        y = yy; 
    }
    bool ok() {  // Метод проверки корректности даты
        if (y < 1 || m == 1 || m > 12 || d < 1) return false;  // Проверка базовых границ

        int dm;
        if (m == 2) {  // Проверка февраля
            bool leap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);  // Определение високосного года
            dm = leap ? 29 : 28;  // Установка дней для февраля
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11) {  // Проверка месяцев с 30 днями
            dm = 30;  // Установка 30 дней
        }
        else {
            dm = 31;  // Установка 31 дня
        }

        return d <= dm;  // Проверка корректности дня
    }
};

int main() {
    int ch;
    cout << "Введите номер (1-4): ";
    cin >> ch;

    // Обработка задания 1
    if (ch == 1) { 
        int n;
        cout << "Размер: ";
        cin >> n;
        int a[100];  // Объявление
        cout << "Элементы: ";
        for (int i = 0; i < n; i++) cin >> a[i];  // Ввод

        int mn = 0, mx = 0;
        for (int i = 1; i < n; i++) {  // Поиск минимума и максимума
            if (a[i] < a[mn]) mn = i;  // Обновление минимума
            if (a[i] > a[mx]) mx = i;  // Обновление максимума
        }
        int t = a[mn];  // Обмен значений минимума и максимума
        a[mn] = a[mx];
        a[mx] = t;

        cout << "Результат: ";
        for (int i = 0; i < n; i++) cout << a[i] << " ";  // Вывод массива
        cout << endl;
    }
    // Обработка задания 2
    if (ch == 2) { 
        int n;  
        cout << "Размер: ";
        cin >> n;  
        int mtx[20][20];  // Объявление
        cout << "Элементы: "; 
        for (int i = 0; i < n; i++)  // Ввод
            for (int j = 0; j < n; j++)
                cin >> mtx[i][j];

        for (int i = 0; i < n; i++) {  // Обмен элементов диагоналей
            int t = mtx[i][i];  // Обмен через временную переменную
            mtx[i][i] = mtx[i][n - i - 1];
            mtx[i][n - i - 1] = t;
        }

        cout << "Результат:\n";
        for (int i = 0; i < n; i++) {  
            for (int j = 0; j < n; j++)
                cout << mtx[i][j] << " ";
            cout << endl;
        }
    }
    // Обработка задания 3
    if (ch == 3) {
        int n; 
        cout << "Кол-во: ";  
        cin >> n;  
        Comp c[50];  // Объявление массива структур
        for (int i = 0; i < n; i++) {  // Ввод
            cout << "Бренд: ";
            cin >> c[i].br;  // Ввод бренда
            cout << "Модель: ";
            cin >> c[i].md;  // Ввод модели
            cout << "Цена: ";
            cin >> c[i].pr;  // Ввод цены
        }

        for (int i = 0; i < n - 1; i++) {  // Сортировка пузырьком по цене
            for (int j = 0; j < n - i - 1; j++) {
                if (c[j].pr > c[j + 1].pr) {  // Сравнение цен
                    Comp t = c[j];  // Обмен структур
                    c[j] = c[j + 1];
                    c[j + 1] = t;
                }
            }
        }
        cout << "Результат:\n"; 
        for (int i = 0; i < n; i++) {
            cout << c[i].br << " " << c[i].md << " " << c[i].pr << endl;  // Вывод
        }
    }
    // Обработка задания 4
    if (ch == 4) {
        int dd, mm, yy;
        cout << "Дата (д м г): ";  // Вывод приглашения
        cin >> dd >> mm >> yy;

        Date dt(dd, mm, yy);  // Создание объекта Date
        if (dt.ok()) cout << "Корректна\n";  // Проверка и вывод результата
        else cout << "Некорректна\n";
    }

    return 0;
}