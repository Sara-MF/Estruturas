#include <iostream>
using namespace std;

// Classe contendo a estrutura do nó de uma lista //
class No {
private:
	int _valor;
	No* _prox;

public:
	No(int valor) :
		_prox(NULL),
		_valor(valor)
	{}

	int Get_valor();
	void Set_valor(int valor);

	No* Get_prox();
	void Set_prox(No* prox);
};

int No::Get_valor() {
	return _valor;
}

void No::Set_valor(int valor) {
	_valor = valor;
}

No* No::Get_prox() {
	return _prox;
}

void No::Set_prox(No* prox) {
	_prox = prox;
}

// Classe contendo os métodos de uma lista //
class Lista {
private:
	No* _inicio;
	int _tam;

public:
	Lista() :
		_inicio(NULL),
		_tam(0)
	{}

	No* Get_inicio();
	int Get_tam();
	
	void Set_inicio(No* inicio);
	void Set_tam(int tamanho);

	void Insere_inicio(int num);
	void Insere_fim(int num);
	void Insere_na_pos(int pos, int num);

	bool Nothing();
	bool Busca(int num);
	
	void Remove_inicio();
	void Remove_fim();
	void Remove_na_pos(int pos);
	void Remove_num(int num);

	void Printa();
	
	~Lista() {
		do {
			Remove_inicio();
		} while (Nothing() == 0);	
	}

};

No* Lista::Get_inicio() {
	return _inicio;
}

int Lista::Get_tam() {
    return _tam;
}

void Lista::Set_inicio(No* inicio) {
	_inicio = inicio;
}

void Lista::Set_tam(int tamanho) {
    _tam = tamanho;
}

// Insere um elemento no inicio da lista //
void Lista::Insere_inicio(int num) {

	No* novo;
	novo = new No(num);

	novo->Set_prox(_inicio);
	_inicio = novo;

	_tam++;

}

// Insere um elemento no fim da lista //
void Lista::Insere_fim(int num) {

	No* novo;
	novo = new No(num);
	
	No* aux;

	if (_inicio == NULL) {
		_inicio = novo;	
	} else {
		// Percorre a lista e para no último elemento //
		for(aux = _inicio; aux->Get_prox() != NULL; aux = aux->Get_prox());
		aux->Set_prox(novo);
	}

	_tam++;

}

// Insere um elemento em uma posição indicada //
void Lista::Insere_na_pos(int pos, int num) {

	No* novo;
	novo = new No(num);

	No* aux;
	int i;

	// Se a lista tem 5 elementos, pode inserir na posição 6 //
	if (pos <= 0 or pos >= _tam + 2) {
		cout << "Posicao invalida" << endl << endl;
	} else {
		// Percorre a lista até a posição anterior que a passada no parâmetro //
		for(aux = _inicio, i = 1; aux != NULL and i != pos - 1; aux = aux->Get_prox(), i++);
		novo->Set_prox(aux->Get_prox());
		aux->Set_prox(novo);
		_tam++;
	}

}

// Verifica se a lista está vazia //
bool Lista::Nothing() {

	if (_inicio == NULL) {
		return true;
	}

	return false;

}

// Verifica se um número está na lista //
bool Lista::Busca(int num) {

	No* aux;

	for (aux = _inicio; aux != NULL; aux = aux->Get_prox()) {
		if (aux->Get_valor() == num) {
			return true;
		}
	}

	return false;

}

// Remove o primeiro elemento da lista //
void Lista::Remove_inicio() {

	if (Nothing()) {
		cout << "Nada a remover" << endl; 
	} else {
		No* aux;

		aux = _inicio;
		_inicio = aux->Get_prox();
		aux->Set_prox(NULL);
		delete aux;
		_tam--;
	}

}

// Remove o último elemento da lista //
void Lista::Remove_fim() {

	No* aux;
	No* del;

	if (Nothing()) {
		cout << "Nada a remover" << endl;
	// Condição para caso haja apenas 1 elemento //
	} else if (_inicio->Get_prox() == NULL) {
		aux = _inicio;
		aux->Set_prox(NULL);
		delete aux;
		_tam--;
	} else {
		for(aux = _inicio; aux->Get_prox()->Get_prox() != NULL; aux = aux->Get_prox());
		del = aux->Get_prox();
		aux->Set_prox(NULL);
		delete del;
		_tam--;
	}

}

// Remove o elemento na posição desejada //
void Lista::Remove_na_pos(int pos) {

	No* aux;
	No* del;
	int i;

	if (Nothing()) {
		cout << "Nada a remover" << endl;
	// Se a lista tem 5 elementos, não pode ser retirado um elemento na posição 6 //
	} else if (pos <= 0 or pos >= _tam + 1) {
		cout << "Posicao invalida" << endl;
	} else if (pos == 1) {
		Remove_inicio();	
	} else if (pos == _tam) {
			Remove_fim();
	} else {
		for(aux = _inicio, i = 1; aux->Get_prox() != NULL and i != pos - 1; aux = aux->Get_prox(), i++);
		del = aux->Get_prox();
		aux->Set_prox(del->Get_prox());
		del->Set_prox(NULL);
		delete del;
		_tam--;
	}

}

// Remove um número específico //
void Lista::Remove_num(int num) {
	
	No* aux;
	No* del;
	
	if(!Busca(num)) {
		cout << "Esse elemento nao existe na lista" << endl << endl;
	} else {
		if (_inicio->Get_valor() == num) {
			Remove_inicio();
		} else {
			for(aux = _inicio; aux->Get_prox()->Get_valor() != num; aux = aux->Get_prox());
			del = aux->Get_prox();
			aux->Set_prox(del->Get_prox());
			del->Set_prox(NULL);
			delete del;
			_tam--;
		}
	}
	
}

// Imprime os elementos da lista //
void Lista::Printa() {

	No* aux;
	int i;

	if (_inicio == NULL) {
		cout << "NULL";
	}

	for (aux = _inicio, i = 1; aux != NULL; aux = aux->Get_prox(), i++) {
		if (i != _tam) {
			cout << aux->Get_valor() << " -> ";
		} else {
			cout << aux->Get_valor() << " -> NULL";
		}
	}

	cout << endl << endl;

}

int main () {

	Lista L;

	L.Printa();

	L.Insere_inicio(3);
	L.Insere_fim(17);
	L.Insere_inicio(50);
	L.Insere_fim(51);
	L.Printa();

	L.Insere_na_pos(2, 45);
	L.Printa();

	L.Remove_inicio();
	L.Printa();

	L.Remove_fim();
	L.Printa();
	
	L.Remove_na_pos(3);
	L.Printa();

	L.Insere_na_pos(3, 5);
	L.Printa();
	
	L.Insere_na_pos(19, 6);
	
	L.Insere_fim(2);
	L.Insere_fim(3);
	L.Printa();
	
	L.Remove_num(45);
	L.Printa();
	
	L.Remove_num(2);
	L.Printa();
	
	L.Remove_num(98);
	
	Lista l;
	
	l.Insere_fim(1);
	l.Printa();
	
	l.Remove_inicio();
	
}
