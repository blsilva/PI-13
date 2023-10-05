#include <iostream>
#include <string>

using namespace std;

struct Empregado {
    string nome;
    string sobrenome;
    int anoNascimento;
    string RG;
    int anoAdmissao;
    float salario;
};

void Reajusta_dez_porcento(Empregado empregados[], int qtde) {
    for (int i = 0; i < qtde; i++) {
        empregados[i].salario *= 1.10; 
    }
}

int main() {
    Empregado empregados[50];
    int n;

    cout << "Quantos empregados deseja cadastrar? (Máximo de 50): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Empregado " << i + 1 << ":" << endl;
        cout << "Nome: ";
        cin >> empregados[i].nome;
        cout << "Sobrenome: ";
        cin >> empregados[i].sobrenome;
        cout << "Ano de Nascimento: ";
        cin >> empregados[i].anoNascimento;
        cout << "RG: ";
        cin >> empregados[i].RG;
        cout << "Ano de Admissao: ";
        cin >> empregados[i].anoAdmissao;
        cout << "Salário: ";
        cin >> empregados[i].salario;
    }

    Reajusta_dez_porcento(empregados, n);

    cout << endl << "Salários reajustados:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Empregado " << empregados[i].nome << " " << empregados[i].sobrenome << " agora tem salário de R$ " << empregados[i].salario << endl;
    }

    return 0;
}
