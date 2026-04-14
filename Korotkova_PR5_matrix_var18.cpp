#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Функция проверки корректности ввода целого числа 
bool IntUserInput(string input){
    if(input.empty())return false;

    try{
        size_t pos;
        stoi(input, &pos);
        return input.length() == pos;
    }catch(...){
        return false;
    }
}

// Функция ввода целого числа с повторением запроса до корректного ввода
int IntEnterNumber(string label){
    string raw_input;
    cout << label;
    getline(cin, raw_input);
    while(!IntUserInput(raw_input)){
        cout << label;
        getline(cin, raw_input);
    }
    return stoi(raw_input);
}

// Функция проверки корректности ввода вещественного числа
bool DoubleUserInput(string input){
    if(input.empty())return false;

    try{
        size_t pos;
        stod(input, &pos);
        return pos == input.length();
    }catch(...){
        return false;
    }
    

}

// Функция ввода вещественного числа с повторением запроса до корректного ввода
double DoubleEnterNumber(string label){
    string raw_input;
    cout << label;
    getline(cin, raw_input);
    while(!DoubleUserInput(raw_input)){
        cout << label;
        getline(cin, raw_input);
    }
    return stod(raw_input);
}

// Задание 1. Найти минимальный элемент каждого столбца матрицы и заменить его на
// среднее арифметическое всех элементов этого столбца. Вывести обновлённую матрицу.
void problem1() {
    double A[4][5] = {{2.5, -2.0, 3.8, 9.19, 14.14},
    {12.5, 5.21, 4.2, -10.45, -10.454},
    {0.89, 8.2, 3.1, 8.9, 0.9},
    {0.12, -0.13, 1.11, 1.12, 3.4}
    };


    cout << "Исходный массив:\n";
    for (auto&x : A){
        for (auto& rows : x){
            cout << rows << "\t";
        }
        cout << "\n";
    }

    for (int j = 0; j < 5; j++){
        double min_el = 1000.0;
        double summa = 0;
        for (int i = 0; i < 4; i++){
            summa += A[i][j];
            if (min_el > A[i][j]){
                min_el = A[i][j];
            }
        } 

        for (int i = 0; i < 4; i++){
            if (A[i][j] == min_el){
                A[i][j] = summa/4;
            }
        }
    }

    cout << "Обновленный массив:\n";
    for (auto&x : A){
        for (auto& rows : x){
            cout << rows << "\t";
        }
        cout << "\n";
    }
}

// Задание 2. Для квадратной матрицы вычислить произведение элементов побочной диагонали. 
// Если произведение равно нулю, вывести соответствующее предупреждение.
void problem2() {
    int n = IntEnterNumber("Введите размер квадратной матрицы: ");
    double A[10][10];
    int i = 0;
    cout << "Введите массив:\n";
    while (i < n) {
        int j = 0;
        while (j < n) {
            string label = "A[" + to_string(i) + "][" + to_string(j) + "] = ";
            *(*(A + i) + j) = DoubleEnterNumber(label);
            j++;
        }
        i++;
    }
 
    cout << "\nИсходный массив:\n";
    int i1 = 0;
    while (i1 < n) {
        int j1 = 0;
        while (j1 < n) {
            cout << *(*(A + i1) + j1) << "\t";
            j1++;
        }
        cout << "\n";
        i1++;
    }
 
    double pr = 1;
    int i2 = 0;
    int j2 = n - 1;
    while (i2 < n) {
        pr *= *(*(A + i2) + j2);
        i2++;
        j2--;
    }
 
    if (pr == 0.0) {
        cout << "Произведение равно 0!\n";
    }
    else {
        cout << "Произведение элементов на побочной диагонали: " << pr << "\n";
    }
}
 
// Задание 3. Бухгалтер: каждая строка матрицы – это ежедневные доходы и расходы
// компании за месяц. Напишите программу, которая выявляет дни с отрицательной суммой и подсчитывает общую прибыль за каждую неделю.

void problem3() {
    int days = IntEnterNumber("Введите количество дней: ");
    double** A = new double*[days];
    for (int i = 0; i < days; i++) {
        A[i] = new double[2];
    }

    srand(time(0));
 
    for (int i = 0; i < days; i++) {
        for (int j = 0; j < 2; j++) {
            A[i][j] = rand() %  2000 - 1000;
        }
    }
 
    for (int i = 0; i < days; i++) {
        cout << "\nДень " << i << ":\n";
        cout << "Прибыль (в тыс.руб) | Расходы (в тыс.руб)\n";
    }
 
    for (int i = 0; i < days; i++) {
        delete[] A[i];
    }
    delete[] A;
}
 
int main()
{    
    setlocale(LC_ALL, "Russian");
    problem3();
    return 0;
}