#include <iostream>
#include <string>
#include "Conta.hpp"
#include "ContaCorrente.hpp"
#include "ContaPoupanca.hpp"
#include "Titular.hpp"
#include "Cpf.hpp"
#include "Funcionario.hpp"
#include "Gerente.hpp"
#include "Caixa.hpp"

using namespace std;

void realizaSaque(Conta& conta) {
	conta.sacar(20);
}

int main()
{
	Titular umTitular(Cpf("01234567899"), "Marcio");
	ContaPoupanca umaConta("00001", umTitular);
	//realizaSaque(umaConta);
	cout << "Saldo conta poupanca " << endl;
	umaConta.exibeDadosConta();

	ContaCorrente umaOutraConta("00002", Titular(Cpf("9876543210"), "Joseph"));
	cout << "Depositando 300 na corrente" << endl;
	umaOutraConta.depositar(300);
	cout << "Saldo conta corrente " << endl;
	umaOutraConta.exibeDadosConta();

	cout << "Transferindo 250 de corrente pra poupanca" << endl;
	umaOutraConta.transferePara(umaConta, 250);

	cout << "Saldo conta corrente " << endl;
	umaOutraConta.exibeDadosConta();

	cout << "Saldo conta poupanca " << endl;
	umaConta.exibeDadosConta();

	// passando uma string pro construtor de Cpf (conversão implícita)
	// para evitar, usar : explicit Cpf(std::string numero);
	ContaCorrente maisUmaConta("00003", Titular(string("030303030303"), "Paulo"));
	//maisUmaConta.exibeDadosConta();

	//cout << "Numero de contas: " << Conta::recuperaNumeroDeContas() << endl;

	Gerente gerente(Cpf("0998877665"), "Funcionario teste", 1000);
	cout << "Nome do gerente: " << gerente.recuperaNome() << endl;

	return 0;
}
