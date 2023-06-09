﻿#include <iostream>
#include <iomanip>
#include <math.h>
#include <Windows.h>

using namespace std;
// Laba-10
int main()
{
    setlocale(LC_CTYPE, "rus");

    int n=0;
    cout << "\n\n   Сколько есть стратегии: "; cin >> n;

    double** arr = new double* [n*3];
    for (int i = 0; i < n*3; i++)
        arr[i] = new double[2];

/*
    for (int i = 0; i < n*3; i++) {
        //for (int j = 0; j < 2; j++) {
            cin >> arr[i][0];
            cin >> arr[i][1];
        //}
    }
*/

    for (int i = 0; i < n; i++) {
        cout << "\n\n      ЗНАЧЕНИИ ДЛЯ "<<i+1<<"-го ФОНДА \n";
        cout << "   Вероятность падение стоймости пакета(Ухудшится): ";
        cin >> arr[3 * i][0];
        cout << "   Прибыль когда стоймость пакета падает: ";
        cin >> arr[3 * i][1];

        cout << "\n   Вероятность сохранения стоймости пакета(Умеренная): ";
        cin >> arr[3 * i + 1][0];
        cout << "   Прибыль когда стоймость пакета сохраняется: ";
        cin >> arr[3 * i + 1][1];

        cout << "\n   Вероятность подорожание пакета(Возрастать): ";
        cin >> arr[3 * i + 2][0];
        cout << "   Прибыль когда стоймость пакета возрастеть: ";
        cin >> arr[3 * i + 2][1];
    }

    /*
    for (int i = 0; i < n * 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    */
    cout << "\n\n\n         Думаем";
    for (int i = 0; i < 24; i++)
    {
        cout << ".";
        Sleep(300);
    }

    std::cout << "\n" << "                                      *=======================================================*";
    std::cout << "\n" << "                                      |  Наши эксперты все подсчитали крч и вот результаты!!  |";
    std::cout << "\n" << "                                      *=======================================================*";
    std::cout << "\n \n";

    cout << "   -----------------------------------------\n   | Фонды           |   Ожидаемый прибыль |\n   -----------------------------------------\n";
    for (int i = 0; i < n; i++){
        cout <<"   | от " << i + 1 << " - го фонда | " << std::setw(20) << arr[3 * i][0] * arr[3 * i][1] + arr[3 * i + 1][0] * arr[3 * i + 1][1] + arr[3 * i + 2][0] * arr[3 * i + 2][1] << " |   \n   -----------------------------------------\n";
    }

    double* result = new double[n];

    for (int i = 0; i < n; i++) {
        result[i] = arr[3 * i][0] * arr[3 * i][1] + arr[3 * i + 1][0] * arr[3 * i + 1][1] + arr[3 * i + 2][0] * arr[3 * i + 2][1];
    }

    int naw = 0;
    for (int i = 1; i < n; i++)
        if (result[i] > result[naw])
            naw = i;
    cout << "\n\n\n   По мнению наших экспертов, чтобы получить максимальную прибыль равную на " << result[naw] << " вы должны вложиться на " << naw+1 << "-го фонда" << endl;


    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"