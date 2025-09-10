#include <iostream>
#include <cstring>
using namespace std;

struct Comp {
    char br[50];
    char md[50];
    double pr;
};

class Date {
private:
    int d, m, y;
public:
    Date(int dd, int mm, int yy) {
        d = dd;
        m = mm;
        y = yy;
    }
    bool ok() {
        if (y < 1 || m < 1 || m > 12 || d < 1) return false;

        int dm;
        if (m == 2) {
            bool leap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
            dm = leap ? 29 : 28;
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11) {
            dm = 30;
        }
        else {
            dm = 31;
        }

        return d <= dm;
    }
};

int main() {
    int ch;
    cout << "Введите номер (1-4): ";
    cin >> ch;

    if (ch == 1) {
        int n;
        cout << "Размер: ";
        cin >> n;
        int a[100];
        cout << "Элементы: ";
        for (int i = 0; i < n; i++) cin >> a[i];

        int mn = 0, mx = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[mn]) mn = i;
            if (a[i] > a[mx]) mx = i;
        }
        int t = a[mn];
        a[mn] = a[mx];
        a[mx] = t;

        cout << "Результат: ";
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }

    if (ch == 2) {
        int n;
        cout << "Размер: ";
        cin >> n;
        int mtx[20][20];
        cout << "Элементы: ";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mtx[i][j];

        for (int i = 0; i < n; i++) {
            int t = mtx[i][i];
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

    if (ch == 3) {
        int n;
        cout << "Кол-во: ";
        cin >> n;
        Comp c[50];
        for (int i = 0; i < n; i++) {
            cout << "Бренд: ";
            cin >> c[i].br;
            cout << "Модель: ";
            cin >> c[i].md;
            cout << "Цена: ";
            cin >> c[i].pr;
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (c[j].pr > c[j + 1].pr) {
                    Comp t = c[j];
                    c[j] = c[j + 1];
                    c[j + 1] = t;
                }
            }
        }

        cout << "Результат:\n";
        for (int i = 0; i < n; i++) {
            cout << c[i].br << " " << c[i].md << " " << c[i].pr << endl;
        }
    }

    if (ch == 4) {
        int dd, mm, yy;
        cout << "Дата (д м г): ";
        cin >> dd >> mm >> yy;

        Date dt(dd, mm, yy);
        if (dt.ok()) cout << "Корректна\n";
        else cout << "Некорректна\n";
    }

    return 0;
}