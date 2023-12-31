#pragma once
#include <string>
#include <utility>
#include <variant>
#include "Titular.hpp"

// classe abstrata em C++ � aquela que possui um ou mais m�todos puramente virtuais (ver no final)
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
	enum ResultadoSaque {
		Sucesso, ValorNegativo, SaldoInsuficiente
	};

	Conta(std::string numeroConta, Titular titular);
	~Conta(); //destrutor

	//std::pair<ResultadoSaque, float> sacar(float valorASacar);
	std::variant<ResultadoSaque, float> sacar(float valorASacar);
	void depositar(float valorADepositar);

	void operator+=(float valorADepositar);	// operator overload

	void exibeDadosConta() const;

	std::string recuperaNumeroConta() const;
	float recuperaSaldo() const;

	// metodo virtual pode ser definido na classe base ou nas derivadas - perde um pouco da performance
	virtual float taxaDeSaque() const = 0;
	// = 0 ---> m�todo puramente virtual (abstrato) - n�o tem implementa��o na classe base

	friend std::ostream& operator<<(std::ostream& cout, const Conta& conta);
};
