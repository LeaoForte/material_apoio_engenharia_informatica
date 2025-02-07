/**********************************************************
* Com base numa estrutura de 3 elementos (pessoas),
* utilizando ciclos de repetição:
*	- Ler os dados das pessoas
*	- Escrever os dados lidos
*
* Ordenar as pessoas por ordem crescente das idades
*
* NOTA: Se usarmos strings, ou pointers onde há alocação dinâmica
* de memória, tem de se ter algum cuidado com as cópias das
* variáveis feitas por atribuição (operador =).
*
* Para que não seja feita uma "shallow copy" (cópia sem duplicação
* do espaço em memória, ou seja: apenas se copia o apontador para
* o espaço inicialmente existente), devemos criar um construtor
* personalizado para a cópia.
*
* Desta forma, fazemos uma "deep copy" e, como tal, é alocado um
* novo espaço de memória e copiado o conteúdo inicial.
*
* O problema da "shallow copy" é que se alterarmos a variável
* inicial, a cópia também é alterada, uma vez que não tem existência
* física distinta.
*
* Esta solução do exercício anterior é feita com strings (objeto)
* e mostra como prevenir a "shallow copy".
***********************************************************/
#include <iostream>
#include <string>
using namespace std;

// Definição da estrutura. Não implica reserva de espaço
// Criar um tipo novo chamado "pes"
struct pes {
	string nome;	//campo nome
	int idade;		//campo idade
 
    // Constructor default
    pes() : nome(""), idade(0) {}

    // Constructor para cópia não ser "shallow copy"
    pes(const pes& outra) {
        nome = outra.nome;  // "Deep copy" da string
        idade = outra.idade;
	}
};

int main(int argc, char** argv) {
	pes turma[3]; // array de estruturas
	pes aux; // para as trocas

	// ler, usando um ciclo de repetição, os nomes e idades para cada pessoa
	cout << endl << "Dados para as 3 pessoas" << endl;
	cout << "-----------------------" << endl;
	// escreva aqui o código :-)
	for(int i=0; i<3; i++){
		cout << " Nome " << i+1 << ": ";
		
		// Na 1ª passagem pelo loop, ainda não se usou nenhum cin
		// antes do getline, pelo que não se pode incluir o cin.ignore()
		if(i) cin.ignore();// para poder misturar cin com cin.getline()
		// Relembrar que no C qualquer coisa diferente de ZERO
		// é interpretada como true

		getline(cin, turma[i].nome);
		cout << "Idade " << i+1 << ": ";
		cin >> turma[i].idade;
	}
	
	//	Escrever, usando um ciclo de repetição, os nomes e idades para cada pessoa
	cout << endl << "Dados lidos das 3 pessoas" << endl;
	cout << "-------------------------" << endl;
	// escreva aqui o código :-)
	for(int i=0; i<3; i++){
		cout << " Nome " << i+1 << ": " << turma[i].nome << endl;
		cout << "Idade " << i+1 << ": " << turma[i].idade << endl;
	}
	
	
	cout << endl << "Listagem por ordem de idade" << endl;
	cout << "---------------------------" << endl;
	// Pai de todos os desafios
	// escrever os dados das 3 pessoas, ordenados por idade
	
	// Ordenar
	if( turma[0].idade > turma[1].idade ){
		aux = turma[0];
		turma[0] = turma[1];
		turma[1] = aux;
	}
	// chegado aqui, n1 tem o menor dos 2
	
	if( turma[1].idade > turma[2].idade ){
		aux = turma[1];
		turma[1] = turma[2];
		turma[2] = aux;
	}
	// chegado aqui, n3 tem o maior dos 3
	
	if( turma[0].idade > turma[1].idade ){
		aux = turma[0];
		turma[0] = turma[1];
		turma[1] = aux;
	}
	// estão ordenados
	
	// Listar
	for(int i=0; i<3; i++){
		cout << " Nome " << i+1 << ": " << turma[i].nome << endl;
		cout << "Idade " << i+1 << ": " << turma[i].idade << endl;
	}

	return 0;
}
