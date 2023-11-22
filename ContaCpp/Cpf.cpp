#include "Cpf.hpp"
#include <iostream>

Cpf::Cpf(std::string numero) :numero(numero)
{
	validaNumeroCpf();
}

std::string Cpf::recuperaNumero() const
{
    return numero;
}

void Cpf::validaNumeroCpf()
{
	if (numero.empty()) {
		std::cout << "Cpf vazio" << std::endl;
		exit(1);
	}
}
