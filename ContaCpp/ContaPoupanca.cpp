#include "ContaPoupanca.hpp"
#include <iostream>

ContaPoupanca::ContaPoupanca(std::string numeroConta, Titular titular): Conta(numeroConta, titular)
{
}

float ContaPoupanca::taxaDeSaque() const {
	std::cout << "Chamando metodo de sacar de conta poupanca" << std::endl;
	return 0.03;
}