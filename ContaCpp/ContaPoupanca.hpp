#pragma once
#include "Conta.hpp"

class ContaPoupanca : public Conta
{
public:
	ContaPoupanca(std::string numeroConta, Titular titular);
	void sacar(float valorASacar);
};
