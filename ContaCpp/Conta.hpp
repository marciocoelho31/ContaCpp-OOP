#pragma once
#include <string>
#include "Titular.hpp"

class Conta {
private:
	static int numeroDeContas;
public:
	static int recuperaNumeroDeContas();

private:
	std::string numeroConta;
	Titular titular;
protected:
	float saldo;

public:
	
	Conta(std::string numeroConta, Titular titular);
	~Conta(); //destrutor
	
	void sacar(float valorASacar);
	void depositar(float valorADepositar);
	void exibeDadosConta() const;

	std::string recuperaNumeroConta() const;
	float recuperaSaldo() const;
};