#include <iostream>
#include <conio.h>
using namespace std;

int* sumarNumerosGrandes(int* num1, int size1, int* num2, int size2, int& resultSize) {
    int maxSize = (size1 > size2) ? size1 : size2;
    int* resultado = new int[maxSize + 1];

    int carry = 0;
    int i = size1 - 1;
    int j = size2 - 1;
    int k = maxSize;

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;

        if (i >= 0) {
            sum += num1[i];
            i--;
        }

        if (j >= 0) {
            sum += num2[j];
            j--;
        }

        resultado[k] = sum % 10;
        carry = sum / 10;
        k--;
    }

    resultSize = maxSize - k;
    return &resultado[k + 1];
}

void main6() {
    int n = 20;
    int *numero1 = new int[n]; // Número grande 1
    for (int i = 0; i < n; i++) {
        numero1[i] = rand() % 10;
    }

    int m = 20;
    int *numero2 =new int[m]; // Número grande 2
    for (int i = 0; i < m; i++) {
        numero2[i] = rand() % 10;
    }

    int resultSize;
    int* resultado = sumarNumerosGrandes(numero1, n, numero2, m, resultSize);

    cout << "Número 1: ";
    for (int i = 0; i < n; i++) {
        cout << numero1[i];
    }
    cout << endl;

    cout << "Número 2: ";
    for (int i = 0; i < m; i++) {
        cout << numero2[i];
    }
    cout << endl;

    cout << "Resultado: ";
    for (int i = 0; i < resultSize; i++) {
        cout << resultado[i];
    }
    cout << endl;
    _getch();
    // delete[] resultado;
  
}
