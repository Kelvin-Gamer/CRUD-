#include <string>
#include <iostream>
#include <vector>
using namespace std;

// Função para exibir o menu
void exibir_menu() {
    cout << "\nMenu:\n";
    cout << "1. Listar itens\n";
    cout << "2. Adicionar item\n";
    cout << "3. Atualizar item\n";
    cout << "4. Remover item\n";
    cout << "5. Sair\n";
}

// Função para listar os itens
void listar_itens(const vector<string>& itens) {
    cout << "\nItens:\n";
    for (size_t idx = 0; idx < itens.size(); ++idx) {
        cout << idx + 1 << ". " << itens[idx] << endl;
    }
}

// Função para adicionar um item
void adicionar_item(vector<string>& itens) {
    string novo_item;
    cout << "Digite o novo item: ";
    getline(cin, novo_item);
    itens.push_back(novo_item);
    cout << "Item adicionado com sucesso!\n";
}

// Função para atualizar um item
void atualizar_item(vector<string>& itens) {
    listar_itens(itens);
    size_t idx;
    cout << "Digite o número do item que deseja atualizar: ";
    cin >> idx;
    cin.ignore(); // Limpar o caractere de nova linha deixado pelo cin

    if (idx >= 1 && idx <= itens.size()) {
        string novo_valor;
        cout << "Digite o novo valor para o item: ";
        getline(cin, novo_valor);
        itens[idx - 1] = novo_valor;
        cout << "Item atualizado com sucesso!\n";
    }
    else {
        cout << "Índice inválido!\n";
    }
}

// Função para remover um item
void remover_item(vector<string>& itens) {
    listar_itens(itens);
    size_t idx;
    cout << "Digite o número do item que deseja remover: ";
    cin >> idx;
    cin.ignore(); // Limpar o caractere de nova linha deixado pelo cin

    if (idx >= 1 && idx <= itens.size()) {
        cout << "Item '" << itens[idx - 1] << "' removido com sucesso!\n";
        itens.erase(itens.begin() + idx - 1);
    }
    else {
        cout << "Índice inválido!\n";
    }
}

int main() {
    vector<string> itens;
    while (true) {
        exibir_menu();
        int opcao;
        cout << "Digite a opcao desejada: ";
        cin >> opcao;
        cin.ignore(); // Limpar o caractere de nova linha deixado pelo cin

        switch (opcao) {
        case 1:
            listar_itens(itens);
            break;
        case 2:
            adicionar_item(itens);
            break;
        case 3:
            atualizar_item(itens);
            break;
        case 4:
            remover_item(itens);
            break;
        case 5:
            cout << "Saindo do programa. Até mais!\n";
            return 0;
        default:
            cout << "Opção inválida. Tente novamente.\n";
        }
    }

    return 0;
}
