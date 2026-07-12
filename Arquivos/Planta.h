#pragma once
#include "Produto.h"
#include <fstream>

class Planta : public Produto {
private:
  float comprimento;
  string especie;

public:
  Planta(string n, float p, int i, int q, float c, string e) : Produto(n, p, i, q), comprimento(c), especie(e) {}

  void exibir() {
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
