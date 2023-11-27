#include "Funcionario.hpp"

Funcionario::Funcionario(Cpf cpf, std::string nome, float salario, DiaDaSemana diaDoPagto)
	:Pessoa(cpf, nome), salario(salario), diaDoPagto(diaDoPagto) {

}

std::string Funcionario::recuperaNome() const
{
	return nome;
}

float Funcionario::recuperaSalario() const
{
	return salario;
}
