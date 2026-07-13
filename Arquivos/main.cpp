#include "Gerenciador.h"
#include <iostream>

using namespace std;

int main() {
  int opcao;
  string nomeBusca;
  Gerenciador gerenciador;

  cout << "-----------------------------------------------\n";
  cout << "      Sistema de Produtos da Floricultura      \n";

  do {
    cout << "-----------------------------------------------\n"
         << "1. Inserir    Produto\n"
         << "2. Listar    Produtos\n"
         << "3. Exibir     Produto\n"
         << "4. Alterar    Produto\n"
         << "5. Remover    Produto\n"
         << "6. Exibir   Relatório\n"
         << "7. Sair\n";
    cout << "Escolha uma das opções acima: ";
    cin >> opcao;
    cin.ignore();
    cout << "-----------------------------------------------\n";

    switch (opcao) {
    case 1:
      gerenciador.inserirProduto();
      break;
    case 2:
      gerenciador.listarProdutos();
      break;
    case 3:
      cout << "Digite um nome para a busca: ";
      getline(cin >> ws, nomeBusca);
      gerenciador.exibirProduto(nomeBusca);
      break;
    case 4:
      cout << "Digite o nome do produto que deseja alterar: ";
      getline(cin >> ws, nomeBusca);
      gerenciador.alterarProduto(nomeBusca);
      break;
    case 5:
      cout << "Digite o nome do produto que deseja remover: ";
      getline(cin >> ws, nomeBusca);
      gerenciador.removerProduto(nomeBusca);
      break;
    case 6:
      gerenciador.exibirRelatorio();
      break;
    case 7:
      cout << "\nAté mais! =)\n";
      break;
    default:
      cout << "Ops, opção inválida! Por favor, escolha uma das opcões listadas "
              "abaixo: \n";
      break;
    }
  } while (opcao != 7);

  return 0;
}
