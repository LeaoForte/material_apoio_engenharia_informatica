#include <iostream>
using namespace std;

/* Passar um array tradicional como parâmetro */

// Note que não se especifica a dimensão do array
// mas a função tem de a conhecer (2º parâmetro)
// Embora dim possa ser um int (neste caso), é preferível
// usar o tipo apropriado size_t (exemplos seguintes)
// ATENÇÃO que, ao receber um array tradicional como parâmetro,
// não se pode usar o ":" no for, pois a função não conhece
// a dimensão do array (não está associada ao parâmetro)
void listar( int arr[], int dim ){
	cout << "Listar\n";
	for(int i=0; i<dim; i++){
		cout << "Idade " << i+1 << ": " << arr[i] << endl;
	}
	// for( auto el : arr ) teria dado erro
}

// Outra hipótese é declarar a função como um template, e deixa
// de ser preciso especificar a dimensão do array
// Desta forma, pode-se usar o ":" no for, pois a função conhece
// a dimensão do array
template <typename T, size_t N>
void listar2( T (&arr)[N] ){
	size_t i=1; // só para poder escrever o nº do elemento

	cout << "Listar usando \"auto\" dentro da função\n";
	for( auto el : arr){
		cout << "Idade " << i++ << ": " << el << endl;
	}
}

// O array é sempre passado por referência de endereço
// A prova é que a alteração feita dentro desta função
// é reconhecida no exterior (parâmetro de ENTRADA/SAÍDA)
void incrementar(int ida[], size_t dim){
	cout << "\nIncrementar idade\n";
	for(size_t i=0; i<dim; i++){
		ida[i]++;
	}
}

// outra forma de passar o array
void outroIncrementar(int *ida, size_t dim){
    cout << "\nNovo incremento\n";
    for(size_t i=0; i<dim; i++){
        ida[i]++;
    }
}

int main(int argc, char** argv) {
	int idade[3] = {20, 30, 40}; // array com 3 elementos
	// como foi iniciado na declaração, era desnecessário o 3
	
	// passagem do array como parâmetro
	cout << "Valores iniciais\n";
	listar(idade, 3); // resultado: 20 30 40

	// somar 1 a cada idade
	incrementar(idade, 3);
	
	// como se vê (ao executar), as idades foram incrementadas
	listar(idade, 3); // resultado: 21, 31, 41
	
    // somar novamente 1 a cada idade (outra forma)
    outroIncrementar(idade, 3);

	// como se vê (ao executar), as idades foram novamente incrementadas
	// Exemplo usando a função com template, que
	// dispensa a indicação da dimensão
	listar2(idade); // resultado: 22, 32, 42

	return 0;
}