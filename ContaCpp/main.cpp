#include <iostream>
#include <string>
#include "Conta.hpp"
#include "Titular.hpp"
#include "Cpf.hpp"

using namespace std;

int main()
{
	Titular umTitular(Cpf("01234567899"), "Marcio");
	Conta umaConta("00001", umTitular);
	umaConta.depositar(500);
	umaConta.sacar(200);
	umaConta.exibeDadosConta();

	Conta umaOutraConta("00002", Titular(Cpf("9876543210"), "Joseph"));
	umaOutraConta.depositar(200);
	umaOutraConta.sacar(50);
	umaOutraConta.exibeDadosConta();

	// passando uma string pro construtor de Cpf (conversão implícita)
	// para evitar, usar : explicit Cpf(std::string numero);
	Conta maisUmaConta("00003", Titular(string("030303030303"), "Paulo"));
	maisUmaConta.exibeDadosConta();

	cout << "Numero de contas: " << Conta::recuperaNumeroDeContas() << endl;

	return 0;
}
