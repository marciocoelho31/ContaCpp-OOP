#include <iostream>
#include <string>
#include "Conta.hpp"
#include "ContaCorrente.hpp"
#include "ContaPoupanca.hpp"
#include "Titular.hpp"
#include "Cpf.hpp"
#include "Funcionario.hpp"

using namespace std;

void realizaSaque(Conta& conta) {
	conta.sacar(20);
}

int main()
{
	Titular umTitular(Cpf("01234567899"), "Marcio");
	ContaPoupanca umaConta("00001", umTitular);
	umaConta.depositar(500);
	realizaSaque(umaConta);
	umaConta.exibeDadosConta();

	ContaCorrente umaOutraConta("00002", Titular(Cpf("9876543210"), "Joseph"));
	umaOutraConta.depositar(200);
	realizaSaque(umaOutraConta);
	umaOutraConta.exibeDadosConta();

	// passando uma string pro construtor de Cpf (conversão implícita)
	// para evitar, usar : explicit Cpf(std::string numero);
	ContaCorrente maisUmaConta("00003", Titular(string("030303030303"), "Paulo"));
	maisUmaConta.exibeDadosConta();

	cout << "Numero de contas: " << Conta::recuperaNumeroDeContas() << endl;

	Funcionario funcionario(Cpf("0998877665"), "Funcionario teste", 1000);
	cout << "Nome do funcionario: " << funcionario.recuperaNome() << endl;

	return 0;
}
