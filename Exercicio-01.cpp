#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

struct Passageiro {
    string cpf;
    string nome;
    int idade;
    int assento;
};

struct Viagem {
    string data;
    string hora;
    vector<Passageiro> passageiros;
};

vector<Viagem> viagens;

void adicionarPassageiro(Viagem& v, Passageiro p) {
    v.passageiros.push_back(p);
}

float arrecadacaoDaViagem(const Viagem& v) {
    return 80.0 * v.passageiros.size();
}

string nomeDoPassageiroNoAssento(const Viagem& v, int assento) {
    for (const Passageiro& p : v.passageiros) {
        if (p.assento == assento) return p.nome;
    }
    return "Assento vazio!";
}

float mediaDeIdade(const Viagem& v) {
    int totalIdade = 0;
    for (const Passageiro& p : v.passageiros) {
        totalIdade += p.idade;
    }
    return static_cast<float>(totalIdade) / v.passageiros.size();
}

float arrecadacaoTotalNoMes(const string& mes) {
    float total = 0.0;
    for (const Viagem& v : viagens) {
        if (v.data.find(mes) != string::npos) {
            total += arrecadacaoDaViagem(v);
        }
    }
    return total;
}

string horarioMaisRentavel() {
    string horario = "";
    float maxArrecadacao = 0.0;
    for (const Viagem& v : viagens) {
        float arrecadacaoAtual = arrecadacaoDaViagem(v);
        if (arrecadacaoAtual > maxArrecadacao) {
            maxArrecadacao = arrecadacaoAtual;
            horario = v.hora;
        }
    }
    return horario;
}

float mediaDeIdadeGeral() {
    int totalIdade = 0;
    int totalPassageiros = 0;
    for (const Viagem& v : viagens) {
        totalIdade += accumulate(v.passageiros.begin(), v.passageiros.end(), 0,
                                  [](int sum, const Passageiro& p) { return sum + p.idade; });
        totalPassageiros += v.passageiros.size();
    }
    return static_cast<float>(totalIdade) / totalPassageiros;
}


int main() {
    int opcao;
    do {
        cout << endl << "MENU:" << endl;
        cout << "1. Adicionar Viagem" << endl;
        cout << "2. Adicionar Passageiro a uma Viagem" << endl;
        cout << "3. Total arrecadado de uma viagem" << endl;
        cout << "4. Total arrecadado em um mês" << endl;
        cout << "5. Nome do passageiro de determinado assento em uma viagem" << endl;
        cout << "6. Horário de viagem mais rentável" << endl;
        cout << "7. Média de idade dos passageiros" << endl;
        cout << "8. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1: {
                string data, hora;
                cout << "Data da viagem (dd/mm/yyyy): ";
                getline(cin, data);
                cout << "Hora da viagem (hh:mm): ";
                getline(cin, hora);
                Viagem v = {data, hora, {}};
                viagens.push_back(v);
                break;
            }

            case 2: {
                int numViagem;
                Passageiro p;
                cout << "Número da viagem (índice começando de 1): ";
                cin >> numViagem;
                cin.ignore();
                cout << "CPF do passageiro: ";
                getline(cin, p.cpf);
                cout << "Nome do passageiro: ";
                getline(cin, p.nome);
                cout << "Idade do passageiro: ";
                cin >> p.idade;
                cout << "Número do assento: ";
                cin >> p.assento;
                cin.ignore();
                if (numViagem > 0 && numViagem <= viagens.size()) {
                    adicionarPassageiro(viagens[numViagem - 1], p);
                } else {
                    cout << "Número de viagem inválido!" << endl;
                }
                break;
            }

            case 3: {
                int numViagem;
                cout << "Número da viagem (índice começando de 1): ";
                cin >> numViagem;
                if (numViagem > 0 && numViagem <= viagens.size()) {
                    cout << "Total arrecadado: R$ " << arrecadacaoDaViagem(viagens[numViagem - 1]) << endl;
                } else {
                    cout << "Número de viagem inválido!" << endl;
                }
                break;
            }

            case 4: {
                string mes;
                cout << "Mês desejado (mm/yyyy): ";
                cin >> mes;
                cout << "Total arrecadado no mês: R$ " << arrecadacaoTotalNoMes(mes) << endl;
                break;
            }

            case 5: {
                int numViagem, assento;
                cout << "Número da viagem (índice começando de 1): ";
                cin >> numViagem;
                cout << "Número do assento: ";
                cin >> assento;
                if (numViagem > 0 && numViagem <= viagens.size()) {
                    cout << "Nome do passageiro: " << nomeDoPassageiroNoAssento(viagens[numViagem - 1], assento) << endl;
                } else {
                    cout << "Número de viagem inválido!" << endl;
                }
                break;
            }

            case 6: {
                cout << "Horário de viagem mais rentável: " << horarioMaisRentavel() << endl;
                break;
            }

            case 7: {
                cout << "Média de idade dos passageiros: " << mediaDeIdadeGeral() << endl;
                break;
            }

            case 8: {
                cout << "Saindo..." << endl;
                break;
            }

            default: {
                cout << "Opção inválida!" << endl;
                break;
            }
        }

    } while (opcao != 8);

    return 0;
}

