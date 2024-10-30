#include <iostream>
#include <iomanip>
using namespace std;
/***********************************************
	Criar um array para as 6 notas de um aluno
	1- pedir os valores e preencher o array
	2- listar o conteúdo do array
************************************************/
int main(int argc, char** argv) {
	int nota[6]; // criar o array com 6 posições
	
	cout << "Escreva as 6 notas do aluno\n";
	
	for(int i=0; i<6; i++){ // ler as notas
		cin >> nota[i];
	}
	
	cout << "As 6 notas do aluno foram:\n";
	for(int i=0; i<6; i++){ // Escrever as notas
		cout << setw(4) << nota[i];
	}
	
	return 0;
}
