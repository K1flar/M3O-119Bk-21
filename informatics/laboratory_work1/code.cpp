#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    float x;
    float eps;
    cout << "Введите x (от -1 до 1), Eps: ";
    cin >> x >> eps;

    // входной контроль
    if (eps <= 0) {
        cout << "\n Eps должно быть больше 0! \n";
        return 0;
    }
    if (abs(x) >= 1) {
        cout << "\n |x| должен быть меньше единицы! \n";
        return 0;
    }

    // инициализация переменных
    int n = 0,
        znak = 1,
        znam = 1;
    float tsum = atan(x),
        argx = x,
        slag = x,
        sum = x,
        diff = abs(tsum - sum);

    // рассчёт суммы ряда
    while (diff > eps) {
        n++;
        znak = -znak;
        argx = argx * x * x;
        znam = znam + 2;
        slag = znak * argx / znam;
        sum = sum + slag;
        diff = abs(tsum - sum);
    }

    cout << "n = " << n << " \narctg(x)= " << tsum << " \nСумма ряда: " << sum << " \nРазница: " << diff << " \nПогрешность (Eps): " << eps << "\n";
    return 0;
}
