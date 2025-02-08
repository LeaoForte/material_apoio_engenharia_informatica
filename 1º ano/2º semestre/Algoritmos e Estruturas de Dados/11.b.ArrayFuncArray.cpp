#include <iostream>
#include <array>
using namespace std;

/* Passar um CONTENTOR ARRAY como parâmetro */

// É necessário indicar a dimensão do array
// mas pode-se usar o ":" no for
void listar( array<int, 4> arr ){
	size_t i=1; // só para poder escrever o nº do elemento

	cout << "Listar\n";
	for(auto el : arr){
		cout << "Idade " << i++ << ": " << el << endl;
	}
}

// Não é preciso especificar a dimensão do array
// se declararmos uma função template
template <typename T, size_t N>
void listar2( array<T, N> arr ){
	size_t i=1; // só para poder escrever o nº do elemento

	cout << "Listar (template)\n";
	for( auto el : arr){
		cout << "Idade " << i++ << ": " << el << endl;
	}
}

// Ao contrário do array tradicional,
// o CONTENTOR array é sempre passado por VALOR
// A prova é que a alteração feita dentro desta função
// não é reconhecida no exterior (parâmetro só de ENTRADA)
void naoIncrementa(array <int, 4> arr){
	cout << "\nIncrementar idade (vai falhar)\n";
	arr[0]++; //fica incrementado 2 vezes
	for(auto el : arr){
		el++;
	}
}

// Para passar o CONTENTOR array por REFERÊNCIA DE ENDEREÇO
void esteIncrementa(array <int, 4> &arr){

	cout << "\nIncrementar idade (funciona)\n";
	arr[0]++; //fica incrementado 2 vezes
	for(auto &el : arr){
		el++;
	}
}

// Para passar o CONTENTOR array por REFERÊNCIA DE ENDEREÇO
// mas não permitir a modificação do original
void esteNaoPodeIncrementar(const array <int, 4> &arr){

	cout << "\nIncrementar idade (é impossível)\n";
	// arr[0]++; // daria erro
	for(auto &el : arr){
		// el++; // daria erro
	}
}

int main(int argc, char** argv) {
	array <int, 4> idade = {20, 30, 40}; // array com 4 elementos (apenas 3 != 0)
	
	// passagem do array como parâmetro
	cout << "Valores iniciais\n";
	listar(idade); // resultado: 20 30 40

	// somar 1 a cada idade (vai falhar)
	naoIncrementa(idade);
	
	// como se vê (ao executar), as idades NÃO foram incrementadas
	listar(idade); // resultado: 20, 30, 40
	
    // somar 1 a cada idade (outra forma)
    esteIncrementa(idade);

	// as idades foram incrementadas
	listar2(idade); // resultado: 22, 31, 41

   // tentativa de somar 1 a cada idade (impossível)
    esteNaoPodeIncrementar(idade);

	// obviamente, as idades NÃO foram incrementadas
	listar(idade); // resultado: 22, 31, 41
	
	return 0;
}