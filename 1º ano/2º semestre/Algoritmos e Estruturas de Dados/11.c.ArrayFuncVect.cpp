#include <iostream>
#include <vector>
using namespace std;

/* Passar um CONTENTOR VECTOR como parâmetro */

// Não é preciso especificar a dimensão do array
void listar( vector<int> arr ){
	size_t i=1; // só para poder escrever o nº do elemento

	cout << "Listar\n";
	for(auto el : arr){
		cout << "Idade " << i++ << ": " << el << endl;
	}
}

// Tal como no CONTENTOR array,
// o CONTENTOR vector é sempre passado por VALOR
// A prova é que a alteração feita dentro desta função
// não é reconhecida no exterior (parâmetro só de ENTRADA)
void naoIncrementa(vector <int> arr){
	cout << "\nIncrementar idade (vai falhar)\n";
	arr[0]++; //fica incrementado 2 vezes
	for(auto el : arr){
		el++;
	}
}

// Para passar o CONTENTOR vector por REFERÊNCIA DE ENDEREÇO
void esteIncrementa(vector <int> &arr){

	cout << "\nIncrementar idade (funciona)\n";
	arr[0]++; //fica incrementado 2 vezes
	for(auto &el : arr){
		el++;
	}
}

// Para passar o CONTENTOR vector por REFERÊNCIA DE ENDEREÇO
// mas não permitir a modificação do original
void esteNaoPodeIncrementar(const vector <int> &arr){

	cout << "\nIncrementar idade (é impossível)\n";
	// arr[0]++; // daria erro
	for(auto &el : arr){
		// el++; // daria erro
	}
}

int main(int argc, char** argv) {
	vector <int> idade = {20, 30, 40}; // vector com 3 elementos
	
	// passagem do vector como parâmetro
	cout << "Valores iniciais\n";
	listar(idade); // resultado: 20 30 40

	// somar 1 a cada idade (vai falhar)
	naoIncrementa(idade);
	
	// como se vê (ao executar), as idades NÃO foram incrementadas
	listar(idade); // resultado: 20, 30, 40
	
    // somar 1 a cada idade (outra forma)
    esteIncrementa(idade);

	// as idades foram incrementadas
	listar(idade); // resultado: 22, 31, 41

   // tentativa de somar 1 a cada idade (impossível)
    esteNaoPodeIncrementar(idade);

	// obviamente, as idades NÃO foram incrementadas
	listar(idade); // resultado: 22, 31, 41
	
	return 0;
}