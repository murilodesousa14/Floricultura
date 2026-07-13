#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "Data.h"

using namespace std;

class Produto : public Data {
protected:
  string nome;
  float preco;
  int indice;
  int quantidade;

public:
  Produto(int d, int m, int a, string n, float p, int i, int q) : Data(d, m, a), nome(n), preco(p), indice(i), quantidade(q) {}
  virtual ~Produto() {}

  virtual string getTipo() = 0;
  virtual void salvar(ofstream &out) {
    out << dia << "-" << mes << "-" << ano << "-" << nome << "-" << preco << "-" << indice << "-" << quantidade << "-";
  }
  virtual void exibir() {
    cout << "\nNome: " << nome << endl
         << "Preço: R$ " << preco << endl
         << "Código: " << indice << endl
         << "Quantidade em Estoque: " << quantidade << endl;
         Data::exibir();
  }

  string getNome() { return nome; }
  float getPreco() { return preco; }
  int getIndice() { return indice; }
  int getQuantidade() { return quantidade; }
};
