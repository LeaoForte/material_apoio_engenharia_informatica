#include <iostream>
#include <string.h>
using namespace std;

// Definição da estrutura. Não implica reserva de espaço
// Criar um tipo novo chamado "pes"
struct pes {
	char nome[81];	//campo nome
	int idade;		//campo idade
};

int main(int argc, char** argv) {
	// para fazer um conjunto de pessoas
	pes turma[3]; // array de estruturas
	
	// ler, usando um ciclo de repetição, os nomes e idades para cada pessoa
	cout << "\n-----------------------" << endl;
	cout << "Dados para as 3 pessoas" << endl;
	cout << "-----------------------" << endl;
	// escreva aqui o código :-)
	
	//	Escrever, usando um ciclo de repetição, os nomes e idades para cada pessoa
	cout << "\n-------------------------" << endl;
	cout << "Dados lidos das 3 pessoas" << endl;
	cout << "-------------------------" << endl;
	// escreva aqui o código :-)
	
	cout << "\n---------------------------" << endl;
	cout << "Listagem por ordem de idade" << endl;
	cout << "---------------------------" << endl;
	// Pai de todos os desafios:
	// escrever os dados das 3 pessoas, ordenados por idade

	return 0;
}
