#pragma once
#include <string>
#include "Titular.hpp"

// classe abstrata em C++ é aquela que possui um ou mais métodos puramente virtuais (ver no final)
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

	// metodo virtual pode ser definido na classe base ou nas derivadas - perde um pouco da performance
	virtual float taxaDeSaque() const = 0;
	// = 0 ---> método puramente virtual (abstrato) - não tem implementação na classe base
};
