#pragma once
#include "Produto.h"

class Vaso : public Produto {
private:
  string material;
  float peso;

public:
  Vaso(int d, int m, int a, string n, float p, int i, int q, string ma, float pe) : Produto(d, m, a, n, p, i, q), material(ma), peso(pe) {}

  void exibir() {
    cout << "Tipo de Produto: Vaso";
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
