#include "Conta.hpp"
#include <iostream>

int Conta::numeroDeContas = 0;

int Conta::recuperaNumeroDeContas()
{
	return Conta::numeroDeContas;
}

Conta::Conta(std::string numeroConta, Titular titular) :
	numeroConta(numeroConta),
	titular(titular),
	saldo(0)
{
	numeroDeContas++;
}

std::variant<Conta::ResultadoSaque, float> Conta::sacar(float valorASacar) {

	if (valorASacar < 0) {
		std::cout << "Nao pode sacar valor negativo" << std::endl;
		return ValorNegativo;
	}

	float tarifaDeSaque = valorASacar * taxaDeSaque();
	float valorDoSaque = valorASacar + tarifaDeSaque;

	if (valorDoSaque > saldo) {
		std::cout << "Saldo insuficiente" << std::endl;
		return SaldoInsuficiente;
	}

	saldo -= valorDoSaque;
	return saldo;
}

void Conta::depositar(float valorADepositar) {
	if (valorADepositar < 0) {
		std::cout << "Nao pode depositar valor negativo" << std::endl;
		return;
	}

	saldo += valorADepositar;
}

void Conta::operator+=(float valorADepositar)
{
	depositar(valorADepositar);
}

float Conta::recuperaSaldo() const {
	return saldo;
}

std::string Conta::recuperaNumeroConta() const
{
	return numeroConta;
}

Conta::~Conta()
{
	numeroDeContas--;
}

void Conta::exibeDadosConta() const
{
	//Conta umaContaDesnecessaria("999", "999", "999");
	//std::cout << "Numero " << recuperaNumeroConta() << " Titular: " << Titular::recuperaNome() << " CPF: " << recuperaCpfTitular() << std::endl;
	std::cout << "Saldo: " << recuperaSaldo() << std::endl;
}
