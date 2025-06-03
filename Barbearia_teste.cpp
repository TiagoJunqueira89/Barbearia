#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Cliente {
    string nome;
    string data;
    string hora;
};

class Barbearia {
private:
    vector<Cliente> agendamentos;

public:
    void agendarCliente(const string& nome, const string& data, const string& hora) {
        Cliente novoCliente = { nome, data, hora };
        agendamentos.push_back(novoCliente);
        cout << "Cliente " << nome << " agendado para " << data << " às " << hora << ".\n";
    }

    void listarAgendamentos() const {
        if (agendamentos.empty()) {
            cout << "Nenhum agendamento encontrado.\n";
            return;
        }

        cout << "Lista de Agendamentos:\n";
        for (const auto& cliente : agendamentos) {
            cout << "Nome: " << cliente.nome << ", Data: " << cliente.data << ", Hora: " << cliente.hora << endl;
        }
    }
};

int main() {
    Barbearia barbearia;
    int opcao;

    do {
        cout << "\nMenu:\n";
        cout << "1. Agendar Cliente\n";
        cout << "2. Listar Agendamentos\n";
        cout << "3. Sair\n";
        cout << "Escolha uma opcao: \n";
        cin >> opcao;

        if (opcao == 1) {
            string nome, data, hora;
            cout << "Digite o nome do cliente: ";
            cin.ignore(); // Limpa o buffer
            getline(cin, nome);
            cout << "Digite a data do agendamento (DD/MM/AAAA): ";
            getline(cin, data);
            cout << "Digite a hora do agendamento (HH:MM): ";
            getline(cin, hora);

            barbearia.agendarCliente(nome, data, hora);
        }
        else if (opcao == 2) {
            barbearia.listarAgendamentos();
        }
        else if (opcao != 3) {
            cout << "Opção inválida. Tente novamente.\n";
        }

    } while (opcao != 3);

    cout << "Saindo do programa.\n";
    return 0;
}