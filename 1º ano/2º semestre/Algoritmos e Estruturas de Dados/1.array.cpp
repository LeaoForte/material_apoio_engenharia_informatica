#include <iostream>
using namespace std;

/******************************************************
 Utilização de arrays
  - Um array é um conjunto de espaços todos do mesmo tipo
  - O array só tem UM nome que indica TODOS os espaços
  Exemplo:
   - em vez de criar 10 variáveis, cria-se apenas uma
     com espaço para conter os 10 elementos
     
  - para aceder a um elemento do array, usamos o seu índice
  - os índices começam em ZERO
 
*/

int main(int argc, char** argv) {
	// criar um array para guardar 5 idades
	// int i1, i2, i3,..... -> não faz sentido
	int idade[5];
	
	//setlocale(LC_ALL,""); // para usar caracteres portugueses

	// ler um valor para o 3º elemento do array
	cout << "Escreva o valor para o 3º elemento ";
	cin >> idade[2];
	
	// Somar 10 ao 3º elemento
	idade[2] = idade[2]+10;
	
	// escrever o resultado
	cout << "Após somar 10, o valor fica = ";
	cout << idade[2];

	return 0;
}
