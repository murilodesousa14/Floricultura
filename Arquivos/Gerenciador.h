#pragma once
#include "Flor.h"
#include "Planta.h"
#include "Produto.h"
#include "Vaso.h"
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Gerenciador {
private:
  vector<Produto *> produtos;
  string arquivo = "arquivo.txt";

public:
  Gerenciador() { lerArquivo(); }
  ~Gerenciador() { salvarArquivo(); }

  void inserirProduto() {
    int tipo;
    cout << "1. Vaso\n"
         << "2. Planta\n"
         << "3. Flor\n"
         << "Escolha um dos tipos de produtos acima para cadastrar: ";
    cin >> tipo;
    cin.ignore();

    string nome;
    float preco;
    int indice, quantidade;
    cout << "Nome: ";
    getline(cin, nome);
    cout << "Preço: ";
    cin >> preco;
    cout << "Código: ";
    cin >> indice;
    cout << "Quantidade: ";
    cin >> quantidade;
    cin.ignore();

    if (tipo == 1) {
      string material;
      float peso;
      cout << "Material: ";
      getline(cin, material);
      cout << "Peso(Kg): ";
      cin >> peso;
      cin.ignore();
      produtos.push_back(new Vaso(nome, preco, indice, quantidade, material, peso));
    } else if (tipo == 2) {
      float comprimento;
      string especie;
      cout << "Comprimento(m): ";
      cin >> comprimento;
      cin.ignore();
      cout << "Espécie: ";
      getline(cin, especie);
      produtos.push_back(new Planta(nome, preco, indice, quantidade, comprimento, especie));
    } else if (tipo == 3) {
      string cor, formato;
      cout << "Cor: ";
      getline(cin, cor);
      cout << "Formato: ";
      getline(cin, formato);
      produtos.push_back(new Flor(nome, preco, indice, quantidade, cor, formato));
    }

    cout << "Produto cadastrado com sucesso!\n";
  }

  void listarProdutos() {
    if (produtos.empty()) {
      cout << "Estoque de produtos vazio!\n";
    }
    for (auto p : produtos) {
      cout << "\n";
      p->exibir();
    }
    cout << "\n";
  }

  int pesquisarProduto(string nome) {
    vector<int> encontrado;
    for (size_t i = 0; i < produtos.size(); i++) {
      if (produtos[i]->getNome().find(nome) == 0) {
        encontrado.push_back(i);
      }
    }

    if (encontrado.empty()) {
      return -1;
    }
    if (encontrado.size() == 1) {
      return encontrado[0];
    }

    cout << "\nMais de um produto cadastrado com mesmo nome:\n";
    for (int index : encontrado) {
      cout << "\nCódigo: " << produtos[index]->getIndice() << endl
           << "Produto: " << produtos[index]->getNome() << endl
           << "Índice: " << index << endl << endl;
    }

    int escolha;
    cout << "Por favor, digite o índice do produto desejado: ";
    cin >> escolha;
    cin.ignore();
    return escolha;
  }

  void exibirProduto(string nome) {
    int index = pesquisarProduto(nome);
    if (index != -1) {
      produtos[index]->exibir();
    } else {
      cout << "Produto não encontrado!\n";
    }
  }

  void alterarProduto(string nome) {
    int index = pesquisarProduto(nome);
    if (index != -1) {
      delete produtos[index];
      produtos.erase(produtos.begin() + index);
      cout << "Produto removido com sucesso!\n"
           << "Cadastre um novo produto:\n";
      inserirProduto();
    } else {
      cout << "Produto não encontrado!\n";
    }
  }

  void removerProduto(string nome) {
    int index = pesquisarProduto(nome);
    if (index != -1) {
      delete produtos[index];
      produtos.erase(produtos.begin() + index);
      cout << "Produto removido com sucesso!\n";
    } else {
      cout << "Produto não encontrado!\n";
    }
  }

  void exibirRelatorio() {
    float valorTotal = 0;
    int totalProdutos = 0;
    for (auto p : produtos) {
      totalProdutos += p->getQuantidade();
      valorTotal += (p->getPreco() * p->getQuantidade());
    }
    cout << "\nRelatório de Estoque:\n";
    cout << "Tipos de produtos cadastrados: " << produtos.size() << endl;
    cout << "Total de produtos: " << totalProdutos << endl;
    cout << "Total em estoque: R$ " << valorTotal << endl << "\n";
  }

  void salvarArquivo() {
    ofstream out(arquivo);
    for (auto p : produtos) {
      p->salvar(out);
    }
    out.close();
    for (auto p : produtos) {
      delete p;
    }
  }

  void lerArquivo() {
    ifstream in(arquivo);
    if (!in.is_open()) {
      return;
    }

    string linha;
    while (getline(in, linha)) {
      stringstream ss(linha);
      string tipo, nome, precoS, indiceS, quantidadeS, info1, info2;
      getline(ss, tipo, '-');
      getline(ss, nome, '-');
      getline(ss, precoS, '-');
      getline(ss, indiceS, '-');
      getline(ss, quantidadeS, '-');
      getline(ss, info1, '-');
      getline(ss, info2);

      if (tipo.empty()) {
        continue;
      }

      float preco = stof(precoS);
      int indice = stoi(indiceS);
      int quantidade = stoi(quantidadeS);

      if (tipo == "V") {
        produtos.push_back(
            new Vaso(nome, preco, indice, quantidade, info1, stof(info2)));
      } else if (tipo == "P") {
        produtos.push_back(
            new Planta(nome, preco, indice, quantidade, stof(info1), info2));
      } else if (tipo == "F") {
        produtos.push_back(
            new Flor(nome, preco, indice, quantidade, info1, info2));
      }
    }

    in.close();
  }
};
