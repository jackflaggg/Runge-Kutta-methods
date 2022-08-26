#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

// решение задачи Коши методом Рунге-Кутты 4-го порядка
void RungeKutt4Method(ostream &out, double (*f)(double, double), double a, double b, double h, double y0) {
    int n = (b - a) / h + 1; // находим количество точек решения

    // задаём начальные условия
    double x = a;
    double y = y0;

    out << "+-------------------+-------------------+" << endl;
    out << "|         x         |         y         |" << endl;
    out << "+-------------------+-------------------+" << endl;

    // расчитываем значения по методу Рунге-Кутты 4-го порядка
    for (int i = 1; i <= n; i++) {
        out << "| " << setw(17) << x << " | " << setw(17) << y << " |" << endl; // выводим точку

        // расчитываем коэффициенты
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2, y + k1 / 2);
        double k3 = h * f(x + h / 2, y + k2 / 2);
        double k4 = h * f(x + h, y + k3);

        x += h; // обновляем x
        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6; // обновляем y
    }

    out << "+-------------------+-------------------+" << endl;
}

// y' = df(x, y)
double df(double x, double y) {
    return cos(1.5 - y * y) - 1.3;
}

int main() {
    double a; // левая граница
    double b; // правая граница
    double h; // шаг
    double y0; // начальное условие

    cout << "Enter a, b: ";
    cin >> a >> b; // считываем границы
    cout << "Enter h: ";
    cin >> h; // считываем шаг
    cout << "Enter y0: ";
    cin >> y0; // считываем начальное условие

    RungeKutt4Method(cout, df, a, b, h, y0); // решаем задачу Коши с выводом на экран
    ofstream fout("output.txt");
    RungeKutt4Method(fout, df, a, b, h, y0); // решаем задачу Коши с выводом в файл
    fout.close();
}
