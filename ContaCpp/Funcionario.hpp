#pragma once
#include "Cpf.hpp"
#include "DiaDaSemana.hpp"
#include "Pessoa.hpp"
#include <string>

class Funcionario : public Pessoa
{
private:
	float salario;
	DiaDaSemana diaDoPagto;	// 0 domingo, 1 segunda, 2 terça, ...
public:
	Funcionario(Cpf cpf, std::string nome, float salario, DiaDaSemana diaDoPagto);
	std::string recuperaNome() const;
	float recuperaSalario() const;
	virtual float bonificacao() const = 0;
};

