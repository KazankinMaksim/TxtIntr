#include <iostream>
#include <cmath>
#include <getopt.h>
#define PI 3.14159265
using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        cout << "Тригонаметрический Калькулятор" << endl
             << "Чтобы выбрать действие, нужно ввести один из параметров:" << endl
             << "-s или --sin — вычисление синуса" << endl
             << "-c или --cos — вычисление косинуса" << endl
             << "-d или --degrees — режим градусов(стоит по умолчанию)" << endl
             << "-r или --radians — режим радиан" << endl
             << "Для того чтобы продолжить запустите программу еще раз с нужным параметром и введите значения угла/радиан" << endl;
    }

    struct option longopts[] = {
        {"sin", required_argument, NULL, 's'},
        {"cos", required_argument, NULL, 'c'},
        {"degrees", no_argument, NULL, 'd'},
        {"radians", no_argument, NULL, 'r'},
        {0, 0, 0, 0},
    };

    int opt;
    double result = 0, x, n;
    bool degrees = true; // по умолчанию используется режим градусов

    while ((opt = getopt_long(argc, argv, "s:c:dr", longopts, NULL)) != -1)
    {
        switch (opt)
        {
        case 's':
            x = strtod(optarg, NULL);
            if (degrees)
			{
				double Degrees = x;
				n = x * PI / 180; // преобразование градусов в радианы
            	result = sin(n);
              	cout << "Синус " << x << " градусов: " << result << endl;
			} 
			else 
			{
				result = sin(x);
				cout << "Синус " << x << " радиан: " << result << endl;
			}
            break;

        case 'c':
            x = strtod(optarg, NULL);
            if (degrees)
			{
				double Degrees = x;
		 		n = x * PI / 180; // преобразование градусов в радианы
            	result = cos(n);
            	cout << "Косинус " << x << " градусов: " << result << endl;
			} 
			else 
			{
				result = cos(x);
				cout << "Косинус " << x << " радиан: " << result << endl;
			}
            break;

        case 'd':
            degrees = true;
            break;

        case 'r':
            degrees = false;
            break;
        }
    }

    return 0;
}
