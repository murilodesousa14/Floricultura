#pragma once
#include "Produto.h"

class Vaso : public Produto {
private:
  string material;
  float peso;

public:
  Vaso(string n, float p, int i, int q, string m, float pe) : Produto(n, p, i, q), material(m), peso(pe) {}

  void exibir() {
    Produto::exibir();
    cout << "Material: " << material << endl << "Peso(Kg): " << peso << endl;
  }

  string getTipo() { return "V"; }

  void salvar(ofstream &out) {
    out << "V-";
    Produto::salvar(out);
    out << material << "-" << peso << endl;
  }
};
