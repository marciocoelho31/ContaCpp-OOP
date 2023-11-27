#include "Gerente.hpp"

Gerente::Gerente(Cpf cpf, std::string nome, float salario, DiaDaSemana diaDoPagto, std::string senha)
	:Funcionario(cpf, nome, salario, diaDoPagto), Autenticavel(senha) {

}

float Gerente::bonificacao() const {
	return recuperaSalario() * 0.5;
}