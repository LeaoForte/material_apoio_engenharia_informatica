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
	pes pessoa; // criar a variável "pessoa" que é do tipo "pes"
	pes outraPessoa;
	
	// para fazer um conjunto de pessoas
	pes turma[3]; // array de estruturas
	
	// escrever no campo "idade" da variável "pessoa"
	pessoa.idade = 20; // dizer que a pessoa tem 20 anos;
	
	// escrever no campo "nome" da variável "pessoa"
	strcpy(pessoa.nome, "Jorge"); // dizer que a pessoa se chama "Jorge"
	
	// escrever no ecrã os dados da pessoa
	cout << " Nome: " << pessoa.nome << endl;
	cout << "Idade: " << pessoa.idade << endl;

	cout << "---------------------" << endl;
		
	// indique o nome para a 2ª pessoa
	cout << " Nome da outra pessoa: ";
	cin.getline(outraPessoa.nome,81);
	
	// indique a idade para a 2ª pessoa
	cout << "Idade da outra pessoa: ";
	cin >> outraPessoa.idade;
	
	// escrever no ecrã os dados da outra pessoa
	cout << "---------------------" << endl;
	cout << " Nome lido: " << outraPessoa.nome << endl;
	cout << "Idade lida: " << outraPessoa.idade << endl;

	return 0;
}
