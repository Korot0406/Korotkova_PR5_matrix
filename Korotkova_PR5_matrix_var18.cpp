// Короткова
#include <iostream>
#include <string>
#include <ctime>
#include <map>
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
    int month = IntEnterNumber("Введите номер месяца: ");
    while (month < 1 || month > 12){
        month = IntEnterNumber("Введите номер месяца: ");
    }

    int year = IntEnterNumber("Введите год: ");
    while (year < 1){
        year = IntEnterNumber("Введите год: ");
    }
    
    bool is_leap = false;
    if (year % 4 == 0 || (year % 100 == 0 && year % 400 !=0)){
        is_leap = true;
    }

    int days = 0;

    if (!is_leap && month == 2){
        days = 28;
    }
    else if (is_leap && month == 2){
        days = 29;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        days = 31;
    }else{
        days = 30;
    }

    int** A = new int*[days];
    for (int i = 0; i < days; i++) {
        A[i] = new int[2];
    }

    srand(time(0));

    for (int i = 0; i < days; i++) {
        for (int j = 0; j < 2; j++) {
            A[i][j] = rand() %  2000 - 1000;
        }
    }

    for (int i = 0; i < days; i++) {
        cout << "\nДень " << i+1 << ":\n";
        cout<< "Прибыль (в тыс.руб) | Расходы (в тыс.руб)\n";
        printf("%12d        | %12d",A[i][0], A[i][1]);
    }

    cout << "\n\n";

    int k_negative_sum = 0;
    int weeks[5] = {0};
    int copy_days = days;

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 7; j++){
            if (copy_days < 1){
                break;
            }
             weeks[i] += A[j+i*7][0] + A[j+i*7][1];
             if (A[j+i*7][0] + A[j+i*7][1] < 0){
                k_negative_sum++;
             }
            --copy_days;
        }
    }

    cout << "\n";
    for (int i = 0; i < 5; i++){
        cout << "Неделя " << to_string(i+1) << ":\nОбщая прибыль: " << weeks[i] << " тыс.руб\n\n";
    }

    cout << "Количество дней с отрицательной суммой: " << k_negative_sum << "\n";

    for (int i = 0; i < days; i++) {
        delete[] A[i];
    }
    delete[] A;
}
 
struct MenuItem{
    string title;
    void (*action)();
};

int main()
{    
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    map<int, MenuItem> menu = {
        {1, {"Problem 1. Найти минимальный элемент каждого столбца матрицы и заменить его на среднее арифметическое всех элементов этого столбца. Вывести обновлённую матрицу.", problem1}},
        {2, {"Problem 2. Для квадратной матрицы вычислить произведение элементов побочной диагонали.\nЕсли произведение равно нулю, вывести соответствующее предупреждение.", problem2}},
        {3, {"Problem 3. Бухгалтер: каждая строка матрицы – это ежедневные доходы и расходы компании за месяц.\nНапишите программу, которая выявляет дни с отрицательной суммой и подсчитывает общую прибыль за каждую неделю.", problem3}}
    };

    int choice = 0;
    
    while(true){
        cout << "Меню:\n";

        for (const auto& item: menu){
            cout << "Task " << item.first << ". " << item.second.title << "\n";
        }

        cout << "0. Выход\n";

        choice = IntEnterNumber("Введите номер пункта: ");

        if (choice == 0){
            cout << "© 2026 Korotkova I.S.\n";
            break;
        }

        cout << "\n";

        if (menu.find(choice) != menu.end()){
            menu[choice].action();
        }else{
            cout << "Некорректный ввод.\n";
        }
    }

    return 0;
}