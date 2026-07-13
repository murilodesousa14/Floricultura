#pragma once

class Data
{
protected:
    int dia, mes, ano;

public:
    Data(int d, int m, int a) : dia(d), mes(m), ano(a) {}
    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAno() { return ano; }
    void exibir() {
        cout << "Data de Cadastro: " << dia << "/" << mes << "/" << ano << endl;
    }
};