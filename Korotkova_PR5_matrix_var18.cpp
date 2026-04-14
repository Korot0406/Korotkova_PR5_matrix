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

//
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

//
double DoubleEnterNumber(string label){
    string raw_input;
    cout << label;
    getline(cin, raw_input);
    while(!DoubleUserInput(raw_input)){
        cout << label;
        getline(cin, raw_input);
    }
    return stoi(raw_input);
}

void problem2() {
    int n;
    cout << "Введите размер квадратной матрицы: ";
    cin >> n;
    double A[10][10];
    int i = 0;
    cout << "Введите массив:\n";
    while (i < n) {
        int j = 0;
        while (j < n) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> *(*(A + i) + j);
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
 
void problem3() {
    int weeks = 0;
    cout << "Введите количество недель: ";
    cin >> weeks;
    double** A = new double*[weeks];
 
    srand(time(0));
 
    for (int i = 0; i < weeks; i++) {
        for (int j = 0; j < 7; j++) {
            A[i][j] = rand() % 10 + (rand() % 100) / 100;
        }
    }
 
    for (int i = 0; i < weeks; i++) {
        cout << "Неделя " << i << ":\n";
        for (int j = 0; j < 7; j++) {
            cout << A[i][j] << "\t";
        }
    }
 
    for (int i1 = 0; i1 < weeks; i1++) {
        delete[] A[i1];
    }
    delete[] A;
}
 
int main()
{    
    setlocale(LC_ALL, "Russian");
    problem2();
    return 0;
}