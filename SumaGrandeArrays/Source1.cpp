#include <iostream>
#include <conio.h>
using namespace std;

int* multiplicarPorDigito(int* numero, int size, int digito, int& resultSize) {
    int carry = 0;
    int* resultado = new int[size + 1];

    for (int i = size - 1; i >= 0; i--) {
        int producto = numero[i] * digito + carry;
        resultado[i + 1] = producto % 10;
        carry = producto / 10;
    }

    if (carry > 0) {
        resultado[0] = carry;
        resultSize = size + 1;
    }
    else {
        resultSize = size;
        resultSize--;
        for (int i = 0; i < size; i++) {
            resultado[i] = resultado[i + 1];
        }
    }

    return resultado;
}

void main() {
    srand(time(NULL));
    int size = 7;
    int* numero = new int[size];
    for (int i = 0; i < size; i++) {
        numero[i] = rand() % 10;
    }

    int digito = 5; 

    int resultSize;
    int* resultado = multiplicarPorDigito(numero, size, digito, resultSize);

    cout << "Número grande: ";
    for (int i = 0; i < size; i++) {
        cout << numero[i];
    }
    cout << endl;

    cout << "Dígito: " << digito << endl;

    cout << "Resultado: ";
    for (int i = 0; i < resultSize; i++) {
        cout << resultado[i];
    }
    cout << endl;
    _getch();
}
