/************************************************************************
* Esta sequência de exemplos mostra as diferenças entre usar strings
* 	- no formato de array de caracteres
* 	ou
*	- no formato string (objecto)
*
* NOTA: Se precisar de usar o getline() após ter usado um cin, deve
*       limpar o '\n' do buffer de entrada escrevendo a instrução
*	    cin.ignore();
*       antes do getline()
************************************************************************/
#include <iostream>
#include <string>  // para o array de caracteres
#include <limits>    // para numeric_limits
#include <windows.h> // para a função Sleep(miliseconds);
using namespace std; // para o objecto string (e para o cin e cout)

int main(int argc, char** argv) {
	/*********************************
	 array de char (termina com '\0')
	**********************************/
	cout << "******************* Array de char *************\n\n";
	char st1[81], st1final[81], res1[161];
	
	cout << "Escreva uma string: ";

	//cin.ignore(); // necessário caso tivesse usado um cin antes

	// para ler deve-se usar a função cin.getline()
	cin.getline(st1,81); // é obrigatório especificar a dimensão do array
	cout << "\nEu li:" << st1 << endl;
	
	cout << "Comprimento da string: " << strlen(st1) << endl;
	
	// percorrer uma string
	for(int i=0; i<strlen(st1); i++){
		cout << st1[i]; // escrever a string, caracter a caracter
		Sleep(100); // para ir escrevendo devagar
	}
	cout << endl;
	
	// outra forma de percorrer a string
	for(int i=0; st1[i]!='\0'; i++){
		cout << st1[i]; // escrever a string, caracter a caracter
		Sleep(100); // para ir escrevendo devagar
	}
	cout << endl;
	
	// copiar strings
	// se tentarmos "st1final = st1;" o compilador dá erro
	// não se podem fazer atribuições tal como se fazem para os tipos simples
	// em vez disso, ou se faz um "for" para percorrer a string,
	// ou se usa a função strcpy(destino, origem)
	strcpy(st1final, st1);
	cout << "Comprimento da string st1final = " << strlen(st1final) << endl;
	cout << "st1final=" << st1final << endl;
	
	// juntar (concatenar) strings
	strcpy(res1, st1);
	strcat(res1, st1final); // acrescentar no fim da string
	cout << "Comprimento da string res1 = " << strlen(res1) << endl;
	cout << "res1=" << res1 << endl;
	
	/***************************************************
	 objecto string ('\0' é um caracter como os outros)
	****************************************************/
	cout << "\n\n\n******************* objecto string *************\n\n";
	string st2, st2final, res2;
	
	cout << "Escreva outra string: ";

	//cin.ignore(); // necessário caso tivesse usado um cin antes

	getline(cin, st2); //função para ler strings
	
	cout << "Comprimento da string usando size(): " << st2.size() << endl;
	// também se pode usar
	cout << "Comprimento da string usando length(): " << st2.length() << endl;
	
	// percorrer uma string
	// Não se deve usar o teste "st2[i]!='\0'" como se faz no array de char
	for(int i=0; i < st2.size(); i++){
		cout << st2[i]; // escrever a string, caracter a caracter
		Sleep(100); // para ir escrevendo devagar
	}
	cout << endl;
	
	// copiar strings
	// com o ojecto string, podem-se fazer atribuições usando o =
	// tal como se faz para os outros tipos
	st2final = st2;
	cout << "Comprimento da string st2final = " << st2final.size() << endl;
	cout << "st2final=" << st2final << endl;
	
	// juntar (concatenar) strings
	res2 = st2 + st2final;
	cout << "Comprimento da string res2 = " << res2.size() << endl;
	cout << "res2=" << res2 << endl;

	return 0;
}
5.Strings.cpp
A apresentar 5.Strings.cpp.
1.5. Strings
Jorge Leiria Pires
•
15/03 (Editado às 15/03)
No formato array de caracteres
No formato objecto string

5.Strings.cpp
Texto

10. Strings.jpg
Imagem
Comentários de turma
