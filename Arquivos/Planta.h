#pragma once
#include "Produto.h"
#include <fstream>

class Planta : public Produto {
private:
  float comprimento;
  string especie;

public:
  Planta(int d, int m, int a, string n, float p, int i, int q, float c, string e) : Produto(d, m, a, n, p, i, q), comprimento(c), especie(e) {}

  void exibir() {
    cout << "Tipo de Produto: Planta";
    Produto::exibir();
    cout << "Comprimento(m): " << comprimento << endl
         << "Espécie: " << especie << endl;
  }

  string getTipo() { return "P"; }

  void salvar(ofstream &out) {
    out << "P-";
    Produto::salvar(out);
    out << comprimento << "-" << especie << endl;
  }
};
