/******************************************************************
NOTA sobre a formatação de números
----------------------------------

	cout << setprecision(n); // define "n" como o nº máximo de
							 // dígitos a mostrar (excluindo o ".")
							 
	cout << fixed;	// fixa o número de casas decimais
					// se necessário acrescenta zeros à direita
					
	cout << scientific; // mostrar o valor em notação científica
					
	Após o fixed ou o scientific, o set precision passa a definir
	o n de casas decimais (em vez de ser o nº de dígitos) a mostrar
*******************************************************************/	

#include <iostream>
#include <iomanip>
using namespace std;

/*****************************************************************
	Faça um programa para ler várias notas (valores inteiros)
	para vários alunos.
	1- Pedir os valores e preencher o array
	2- Listar o conteúdo do array
	3- Listar a média de cada aluno à frente das suas notas
	4- Escrever a média (do teste) no final de cada coluna
	5- Escrever a média da turma
	
	As notas são valores entre 0 e 20 (não precisa testar)
	As médias são valores com duas casas decimais

	O programa deve ter as seguintes constantes:
	"MaxAluno" para o nº de alunos (máximo 9)
	"MaxNota" para o nº de notas por aluno (máximo 9)
*************************************************************/

/**********************************************************************
	Este código apresenta 3 soluções possíveis para o cálculo
	da média da turma
		Solução (pior): somando todas as notas de todos os alunos
		Solução não muito boa (fraca): somando as médias de cada aluno
		Solução (boa): somando as médias de cada teste
***********************************************************************/

const int MaxAluno = 3;
const int MaxNota = 4;

int main(int argc, char** argv) {
	int nota[MaxAluno][MaxNota]; // criar o array bidimensional
								 // para as notas de todos os alunos
	float mediaTeste[MaxNota],   // array para as médias dos testes
	      mediaAluno,			 // média por aluno
		  mediaTurma;			 // média da turma
	
	//setlocale(LC_ALL,"");
	// ler as notas de cada aluno
	cout << "Escreva as " << MaxNota << " notas para cada aluno\n";
	for(int i=0; i<MaxAluno; i++){ // percorre os alunos
		// para cada aluno
		cout << "Aluno " << i+1 << endl;
		for(int j=0; j<MaxNota; j++){ // percorre as notas de 1 aluno
			cin >> nota[i][j];
		}
	}
	
	// Colocar as médias dos testes a zero
	for(int i=0; i<MaxNota; i++) mediaTeste[i]=0;
	
	cout << "As " << MaxNota << " notas de cada aluno foram:\n";
	// Escrever a linha com o nº dos testes
	cout << "        ";
	for(int i=0; i<MaxNota; i++) cout << setw(5) << "T" << i+1;
	cout << endl;

	// Escrever as notas de cada aluno
	for(int i=0; i<MaxAluno; i++){ // percorre os alunos
		// para cada aluno
		mediaAluno = 0;
		cout << "Aluno " << i+1 << ":";
		for(int j=0; j<MaxNota; j++){ // percorre as notas de 1 aluno
			cout << setw(6) << nota[i][j];
			mediaAluno += nota[i][j];
			mediaTeste[j] += nota[i][j]; // somatório das notas de cada teste
//			mediaTurma += nota[i][j]; // somando todas as notas (pior)
		}
		mediaAluno /= MaxNota;
		cout << "      Media: " << mediaAluno << endl;
//		mediaTurma += mediaAluno; // somando as médias dos alunos (fraca)
	}
//	mediaTurma /= MaxAluno; // somando as médias dos alunos (fraca)
//	mediaTurma /= MaxAluno * MaxNota; // somando todas as notas (pior)
	
	// para alinhar a 1ª média com a coluna das notas
	cout << "  Média:   ";
	cout << fixed << setprecision(2);
	
	// Calcular a média para cada teste
	for(int i=0; i<MaxNota; i++){
		mediaTeste[i] /= MaxAluno;
		cout << setw(6) << mediaTeste[i];
		mediaTurma += mediaTeste[i]; // somando média dos testes (boa)
	}
	mediaTurma /= MaxNota; // somando média dos testes (boa)
	cout << "   Média da turma: " << mediaTurma;
	
	return 0;
}
