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

void Conta::sacar(float valorASacar) {
	std::cout << "Chamando metodo de sacar de conta corrente" << std::endl;

	if (valorASacar < 0) {
		std::cout << "Nao pode sacar valor negativo" << std::endl;
		return;
	}

	float tarifaDeSaque = valorASacar * 0.05;
	float valorDoSaque = valorASacar + tarifaDeSaque;

	if (valorDoSaque > saldo) {
		std::cout << "Saldo insuficiente" << std::endl;
		return;
	}

	saldo -= valorDoSaque;
}

void Conta::depositar(float valorADepositar) {
	if (valorADepositar < 0) {
		std::cout << "Nao pode depositar valor negativo" << std::endl;
		return;
	}

	saldo += valorADepositar;
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
