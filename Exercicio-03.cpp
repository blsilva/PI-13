#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Produto {
    string codigo;
    string nome;
    float preco;
};

Produto produtos[300];
int contadorProdutos = 0;

bool produtoExistePorCodigo(string codigo) {
    for (int i = 0; i < contadorProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            return true;
        }
    }
    return false;
}

bool produtoExistePorNome(string nome) {
    for (int i = 0; i < contadorProdutos; i++) {
        if (produtos[i].nome == nome) {
            return true;
        }
    }
    return false;
}

void inserirProduto() {
    if (contadorProdutos >= 300) {
        cout << "Limite de produtos atingido." << endl;
        return;
    }

    Produto p;
    cout << "Informe o código do produto (13 caracteres): ";
    cin >> p.codigo;
    if (produtoExistePorCodigo(p.codigo)) {
        cout << "Produto com esse código já existe." << endl;
        return;
    }

    cout << "Informe o nome do produto (máximo 20 caracteres): ";
    cin.ignore();
    getline(cin, p.nome);
    if (produtoExistePorNome(p.nome)) {
        cout << "Produto com esse nome já existe." << endl;
        return;
    }

    cout << "Informe o preço do produto: ";
    cin >> p.preco;

    produtos[contadorProdutos] = p;
    contadorProdutos++;
}

void excluirProduto() {
    string codigo;
    cout << "Informe o código do produto que deseja excluir: ";
    cin >> codigo;

    int posicao = -1;
    for (int i = 0; i < contadorProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        cout << "Produto não encontrado." << endl;
        return;
    }

    for (int i = posicao; i < contadorProdutos - 1; i++) {
        produtos[i] = produtos[i + 1];
    }
    contadorProdutos--;
    cout << "Produto excluído com sucesso!" << endl;
}

void listarProdutos() {
    cout << left << setw(15) << "Código" << setw(22) << "Nome" << "Preço" << endl;
    cout << "------------------------------------------------" << endl;
    for (int i = 0; i < contadorProdutos; i++) {
        cout << left << setw(15) << produtos[i].codigo << setw(22) << produtos[i].nome << fixed << setprecision(2) << produtos[i].preco << endl;
    }
}

void consultarPreco() {
    string codigo;
    cout << "Informe o código do produto: ";
    cin >> codigo;

    for (int i = 0; i < contadorProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            cout << "Nome: " << produtos[i].nome << " - Preço: R$ " << fixed << setprecision(2) << produtos[i].preco << endl;
            return;
        }
    }
    cout << "Produto não encontrado." << endl;
}

int main() {
    int opcao;
    do {
        cout << endl << "MENU:" << endl;
        cout << "1. Inserir um novo produto" << endl;
        cout << "2. Excluir um produto cadastrado" << endl;
        cout << "3. Listar todos os produtos" << endl;
        cout << "4. Consultar o preço de um produto" << endl;
        cout << "5. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1:
                inserirProduto();
                break;
            case 2:
                excluirProduto();
                break;
            case 3:
                listarProdutos();
                break;
            case 4:
                consultarPreco();
                break;
            case 5:
                cout << "Encerrando..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    } while (opcao != 5);

    return 0;
}
