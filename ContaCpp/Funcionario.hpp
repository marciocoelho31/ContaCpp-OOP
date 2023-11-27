#pragma once
#include "Cpf.hpp"
#include "Pessoa.hpp"
#include <string>

class Funcionario : public Pessoa
{
private:
	float salario;
public:
	Funcionario(Cpf cpf, std::string nome, float salario);
	std::string recuperaNome() const;
	float recuperaSalario() const;
	virtual float bonificacao() const = 0;
};

