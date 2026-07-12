#pragma once
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Produto {
protected:
  string nome;
  float preco;
  int indice;
  int quantidade;

public:
  Produto(string n, float p, int i, int q) : nome(n), preco(p), indice(i), quantidade(q) {}
  virtual ~Produto() {}

  virtual string getTipo() = 0;
  virtual void salvar(ofstream &out) {
    out << nome << "-" << preco << "-" << indice << "-" << quantidade << "-";
  }
  virtual void exibir() {
    cout << "\nProduto: " << nome << endl
         << "Preço: " << preco << endl
         << "Código: " << indice << endl
         << "Quantidade em Estoque: " << quantidade << endl;
  }

  string getNome() { return nome; }
  float getPreco() { return preco; }
  int getIndice() { return indice; }
  int getQuantidade() { return quantidade; }
};
