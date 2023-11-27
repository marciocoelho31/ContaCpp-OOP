#include "Caixa.hpp"

Caixa::Caixa(Cpf cpf, std::string nome, float salario, DiaDaSemana diaDoPagto)
	:Funcionario(cpf, nome, salario, diaDoPagto) {

}

float Caixa::bonificacao() const {
	return recuperaSalario() * 0.1;
}