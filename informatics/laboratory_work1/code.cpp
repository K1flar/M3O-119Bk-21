/*-----------------------------------------------------------------------*
|                                                                        |
| Project type   : Win32 Console Application                             |
| Project name   : laboratory_work1                                      |
| File name      : code.cpp                                              |
| Language       : C++, MS VS 2019                                       |
| Programmer(1)  : Давыдов Денис Вадимови                                |
| Programmer(2)  : Таласов Данил Сергеевич                               |
| Programmer(3)  : Коцур Савелий Витальевич                              |
| Created        : 15.07.21                                              |
| Last revision  : 22.09.21                                              |
| Comment        : ЛР сделана с помощью удаленного репозитория на GitHub |
| Link to Github : https://github.com/K1flar/M3O-119Bk-21                |
|                                                                        |
*------------------------------------------------------------------------*
| Кафедра 304                                                            |
| Курс      : информатика                                                |
| Задание 1 : Вычисление суммы бесконечного числового ряда               |
*------------------------------------------------------------------------*
|                            ВАРИАНТ №12                                 |
*-----------------------------------------------------------------------*/

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    // декларация переменных
    float x;    // значение аргумента x
    float eps;  // погрешность для вычисления arctg(x)
    float argx; // числитель слагаемого элемента
    float slag; // значение текущего элемента суммы ряда
    float tsum; // точное значение arctg(x)
    float sum;  // текущая сумма ряда
    float diff; // разница между точной суммой и текущей суммой ряда
    int n;      // текушее количество элементов суммы ряда
    int znak;   // знак текущего слагаемого 
    int znam;   // знаменатель слагаемого 

    cout << "Введите x (от -1 до 1), затем Eps: ";
    cin >> x >> eps;

    // входной контроль
    if (eps <= 0) {
        cout << "\nEps должно быть больше 0! \n";
        return 0;
    }
    if (abs(x) >= 1) {
        cout << "\n|x| должен быть меньше единицы! \n";
        return 0;
    }

    // инициализация переменных
    n = 0;
    znak = 1;
    znam = 1;
    tsum = atan(x);
    argx = x;
    slag = x;
    sum = x;
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

    // печать результата
    cout << "n = " << n << "\n";
    cout << "arctg(x) = " << tsum << "\n";
    cout << "Сумма ряда: " << sum << "\n";
    cout << "Разница: " << diff << "\n"; 
    cout << "Погрешность(Eps): " << eps << "\n";
    return 0;
}
