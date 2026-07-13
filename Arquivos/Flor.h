#pragma once
#include "Produto.h"

class Flor : public Produto {
private:
  string cor, formato;

public:
  Flor(int d, int m, int a, string n, float p, int i, int q, string co, string f) : Produto(d, m, a, n, p, i, q), cor(co), formato(f) {}

  void exibir() {
    cout << "Tipo de Produto: Flor";
    Produto::exibir();
    cout << "Cor: " << cor << endl << "Formato: " << formato << endl;
  }

  string getTipo() { return "F"; }

  void salvar(ofstream &out) {
    out << "F-";
    Produto::salvar(out);
    out << cor << "-" << formato << endl;
  }
};
