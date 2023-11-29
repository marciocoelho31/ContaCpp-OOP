#pragma once
#include <string>
#include "Conta.hpp"
#include "Titular.hpp"

class ContaCorrente final : public Conta
{
public:
	ContaCorrente(std::string numeroConta, Titular titular);
	float taxaDeSaque() const override;
	void transferePara(Conta& destino, float valor);
	void operator+=(ContaCorrente& contaOrigem);
};

