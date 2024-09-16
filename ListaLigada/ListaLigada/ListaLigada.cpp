#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------

int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria para os elementos
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == novo->valor) {
			free(novo);
			cout << "Valor ja inserido. Digite outro.\n";
			return; 
		}
		aux = aux->prox;
	}

	if (primeiro == NULL || primeiro->valor >= novo->valor)
	{
		primeiro = novo;
		ultimo = novo;
	}
	else
	{
		NO* anterior = primeiro;
		while (anterior->prox != NULL && anterior->prox->valor < novo->valor)
		{
			anterior = anterior->prox;
		}
		novo->prox = anterior->prox;
		anterior->prox = novo;
		if (novo->prox == NULL) {
			ultimo = novo; 
		}
	}
}

void excluirElemento()
{

}

void buscarElemento()
{
	int achar;
    cout << "Digite o valor a ser buscado: ";
    cin >> achar;
	NO* aux = primeiro;
	while (aux != NULL) 
	{
		if (aux->valor == achar)
		{
			cout << "Valor "<<achar<<" encontrado!\n"; 
			break;
		}
		aux = aux->prox;
	}
	cout << "Valor "<<achar<<" não encontrado!\n";  
	
}
