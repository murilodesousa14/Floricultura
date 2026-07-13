#pragma once
#include <iostream>

using namespace std;

class Data
{
protected:
    int dia, mes, ano;

public:
    Data(int d, int m, int a) : dia(d), mes(m), ano(a) {}
    void exibir() {
        cout << "Data de Cadastro: " << dia << "/" << mes << "/" << ano << endl;
    }
};