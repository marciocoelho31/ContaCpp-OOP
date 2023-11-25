#include "ContaCorrente.hpp"
#include <iostream>

ContaCorrente::ContaCorrente(std::string numeroConta, Titular titular):Conta(numeroConta, titular)
{
}

float ContaCorrente::taxaDeSaque() const {
	std::cout << "Chamando metodo de sacar de conta corrente" << std::endl;
	return 0.05;
}

