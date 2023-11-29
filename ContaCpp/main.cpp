#include <iostream>
#include <string>
#include <utility>
#include "Conta.hpp"
#include "ContaCorrente.hpp"
#include "ContaPoupanca.hpp"
#include "Titular.hpp"
#include "Cpf.hpp"
#include "Funcionario.hpp"
#include "Gerente.hpp"
#include "Caixa.hpp"

using namespace std;

void realizaSaque(Conta& conta) {
	std::variant<Conta::ResultadoSaque, float> resultado = conta.sacar(20);
	if ( auto saldo = std::get_if<float>(&resultado) ) {	// se o resultado tiver um float, sinal de que ele retorna um valor float
		cout << "Novo saldo da conta: " << *saldo << endl;
	}
}

void fazLogin(Autenticavel& alguem, string senha) {
	if (alguem.autentica(senha)) {
		cout << "Login realizado com sucesso" << endl;
	}
	else
	{
		cout << "Acesso nao autorizado" << endl;
	}
}

ostream& operator<<(ostream& cout, const Conta& conta) {
	Pessoa titular = conta.titular;
	cout << "O saldo da conta (operador) eh " << conta.recuperaSaldo() << endl;
	cout << "O titular da conta eh " << titular.recuperaNome() << endl << endl;

	return cout;
}

int main()
{
	Titular umTitular(Cpf("01234567899"), "Marcio", "umasenha");
	ContaCorrente umaConta("00001", umTitular);
	umaConta.depositar(1000);
	realizaSaque(umaConta);
	//cout << umaConta;

	ContaCorrente umaOutraConta("00002", Titular(Cpf("9876543210"), "Joseph", "outrasenha"));
	cout << "Depositando 300 na corrente" << endl;
	umaOutraConta.depositar(300);
	cout << "Depositando +300 na corrente" << endl;
	(Conta&)umaOutraConta += 300;	// operator overload + casting

	cout << umaOutraConta;

	cout << "Transferindo 250 de corrente pra poupanca" << endl;
	umaOutraConta.transferePara(umaConta, 250);

	cout << umaOutraConta;

	cout << umaConta;

	// passando uma string pro construtor de Cpf (conversão implícita)
	// para evitar, usar : explicit Cpf(std::string numero);
	ContaCorrente maisUmaConta("00003", Titular(string("030303030303"), "Paulo", "maisumasenha"));
	//maisUmaConta.exibeDadosConta();

	//cout << "Numero de contas: " << Conta::recuperaNumeroDeContas() << endl;

	Gerente gerente(
		Cpf("0998877665"), 
		"Gerente teste", 
		1000, 
		DiaDaSemana::Terca, 
		"senhagerente"
	);
	cout << "Nome do gerente: " << gerente.recuperaNome() << endl << endl << endl;

	ContaCorrente outraContaCorrente("762576", umTitular);
	outraContaCorrente += umaOutraConta;
	cout << umaOutraConta;
	cout << outraContaCorrente;

	return 0;
}
