#include <iostream>
#include <iomanip>
using namespace std;
/***********************************************
	Faça um programa para ler 4 notas
	para 3 alunos diferentes
	1- Pedir os valores e preencher o array
	2- listar o conteúdo do array
************************************************/
int main(int argc, char** argv) {
	int nota[3][4]; // criar o array bidimensional
	
	// ler as notas de cada aluno
	cout << "Escreva as 4 notas para cada aluno\n";
	for(int i=0; i<3; i++){ // percorre os alunos
		// para cada aluno
		cout << "Aluno " << i+1 << endl;
		for(int j=0; j<4; j++){ // percorre as notas de 1 aluno
			cin >> nota[i][j];
		}
	}
	
	// Escrever as notas de cada aluno
	cout << "As 4 notas de cada aluno foram:\n";
	for(int i=0; i<3; i++){ // percorre os alunos
		// para cada aluno
		cout << "Aluno " << i+1 << ":";
		for(int j=0; j<4; j++){ // percorre as notas de 1 aluno
			cout << setw(3) << nota[i][j];
		}
		cout << endl;
	}
	
	return 0;
}
