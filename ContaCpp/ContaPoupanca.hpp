#pragma once
#include "Conta.hpp"

class ContaPoupanca final : public Conta
{
public:
	ContaPoupanca(std::string numeroConta, Titular titular);
	float taxaDeSaque() const override;	// override avisa que vai sobrescrever um metodo virtual da classe base
};
