#include <iostream> 
#include <cstdlib> 
#include <ctime> 

using namespace std;

int** create_array(int M, int N) {

    int** array = new int* [M];

    for (int i = 0; i < M; ++i) {
        array[i] = new int[N];

        for (int j = 0; j < N; ++j) {
            array[i][j] = rand() % 10 - 7;
        }
    }
    return array;
}


int** create_opposite_array(int** originalArray, int M, int N) {
    int** oppositeArray = new int* [N];

    for (int i = 0; i < N; ++i) {
        oppositeArray[i] = new int[M];
        for (int j = 0; j < M; ++j) {
            oppositeArray[i][j] = originalArray[j][i] * -1;
        }
    }
    return oppositeArray;
}

void print_arr(int** array, int M, int N) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}


void delete_arr(int** array, int M) {
    for (int i = 0; i < M; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

int main() {
    setlocale(LC_ALL, "RU");

    srand(time(nullptr));

    int M = 6;
    int N = 3;

    int** originalArray = create_array(M, N);
    cout << "Массив в изначальном виде: " << endl;
    print_arr(originalArray, M, N);

    int** oppositeArray = create_opposite_array(originalArray, M, N);
    cout << "\nПеревернутый массив:" << endl;
    print_arr(oppositeArray, N, M);

    return 0;
}


/*
Написать функцию, которая создает
ДВУМЕРНЫЙ динамический массив размера M x N
Например
M = 6
N = 3

** ** **

Можно думать о нем как о таблице

0 -6 8 -4 8
5 0 -1  2 3
4 6  7 -3 1

Заполнить его случайными числами

Написать функцию, которая создает массив N x M,
у которого в "противоположной" позиции - число
 с обратным знаком


 0  -5 -4
 6   0 -6
-8   1 -7 
 4  -2  3
-8  -3 -1*/