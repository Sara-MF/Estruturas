#include <iostream>
using namespace std;

// Classe contendo um nó de uma estrutura de lista //
class No {
private:
    int _valor;
    No* _ante;
    No* _prox;

public:
    No(int valor) :
        _valor(valor),
        _ante(NULL),
        _prox(NULL)
    {}

    int Get_valor();
    No* Get_ante();
    No* Get_prox();

    void Set_valor(int valor);
    void Set_ante(No* ante);
    void Set_prox(No* prox);

};

int No::Get_valor() {
    return _valor;
}

No* No::Get_ante() {
    return _ante;
}

No* No::Get_prox() {
    return _prox;
}

void No::Set_valor(int valor) {
    _valor = valor;
}

void No::Set_ante(No* ante) {
    _ante = ante;
}

void No::Set_prox(No* prox) {
    _prox = prox;
}

// Classe contendo os métodos de uma lista //
class Lista {
private:
    No* _inicio;
    No* _fim;
    int _tam;

public:
    Lista() :
        _inicio(NULL),
        _fim(NULL),
        _tam(0)
    {}

    No* Get_inicio();
    No* Get_fim();
    int Get_tam();

    void Set_inicio(No* inicio);
    void Set_fim(No* fim);
    void Set_tam(int tamanho);

    void Insere_inicio(int num);
    void Insere_fim(int num);
    void Insere_na_pos(int pos, int num);
    
    bool Nothing();
    bool Busca(int num);

	void Remove_inicio();
	void Remove_fim();
	void Remove_na_pos(int pos);
    void Remove(int num);

    void Printa();
    
    ~Lista() {
    	do {
    		Remove_inicio();
		} while (_inicio != NULL);
	}

};

No* Lista::Get_inicio() {
    return _inicio;
}

No* Lista::Get_fim() {
    return _fim;
}

int Lista::Get_tam() {
    return _tam;
}

void Lista::Set_inicio(No* inicio) {
    _inicio = inicio;
}

void Lista::Set_fim(No* fim) {
    _fim = fim;
}

void Lista::Set_tam(int tamanho) {
    _tam = tamanho;
}

// Insere um elemento no começo da lista //
void Lista::Insere_inicio(int num) {

    No* novo;
    novo = new No(num);

    if (Nothing()) {
        _inicio = novo;
        _fim = novo;
    } else {
        _inicio->Set_ante(novo);
        novo->Set_prox(_inicio);
        _inicio = novo;
    }

    _tam++;

}

// Insere um elemento no fim da lista //
void Lista::Insere_fim(int num) {

    No* novo;
    novo = new No(num);

    if (_fim == NULL) {
        _inicio = novo;
        _fim = novo;
    } else {
        _fim->Set_prox(novo);
        novo->Set_ante(_fim);
        _fim = novo;
    }

    _tam++;

}

// Insere um elemento na posição indicada //
void Lista::Insere_na_pos(int pos, int num) {

    No* novo;
    novo = new No(num);

    int i;
    No* aux;

    if (pos == 1) {
        Insere_inicio(num);
    // Se a lista tem 5 elementos, pode ser inserido um elemento na posição 6 //
    } else if (pos == _tam + 1) {
        Insere_fim(num);
    } else if (pos <= 0 or pos >= _tam + 2) {
        cout << "Posicao invalida" << endl << endl;
    } else {
        for(i = 1, aux = _inicio; i < pos - 1; i++, aux = aux->Get_prox());
        novo->Set_ante(aux);
        novo->Set_prox(aux->Get_prox());
        aux->Get_prox()->Set_ante(novo); 
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

// Verifica se um elemento está contido na lista //
bool Lista::Busca(int num) {
	
	No* aux;

	for (aux = _inicio; aux != NULL; aux = aux->Get_prox()) {
		if (aux->Get_valor() == num) {
			return true;
		}
	}

	return false;
	
}

// Remove o primeiro elemento //
void Lista::Remove_inicio() {
	
	No* aux;
	
	if (Nothing()) {
		cout << "Nada a remover" << endl;
	// Caso haja apenas um elemento na lista //
	} else if (_inicio->Get_ante() == _fim->Get_ante()) {
		_inicio = NULL;
		delete _inicio;
		_tam--;
	} else {
		aux = _inicio;
		_inicio = aux->Get_prox();
		aux->Get_prox()->Set_ante(NULL);
		aux->Set_prox(NULL);
		delete aux;
		_tam--;
	}
	
}

// Remove o último elemeto da lista // 
void Lista::Remove_fim() {
	
	No* aux;
	
	if (Nothing()) {
		cout << "Nada a remover" << endl << endl;
	// Caso haja apenas um elemento na lista //
	} else if (_inicio->Get_ante() == _fim->Get_ante()) {
		_fim = NULL;
		delete _fim;
		_tam--;
	} else {
		aux = _fim;
		_fim = aux->Get_ante();
		aux->Get_ante()->Set_prox(NULL);
		aux->Set_ante(NULL);
		delete aux;
		_tam--;
	}
	
}

// Remove o elemento na posição desejada //
void Lista::Remove_na_pos(int pos) {
	
	No* aux;
	int i;
	
	if (pos == 1) {
		Remove_inicio();
	} else if (pos == _tam) {
		Remove_fim();
	} else if (pos <= 0 or pos > _tam) {
		cout << "Posicao invalida" << endl << endl;
	} else {
		for(aux = _inicio, i = 1; aux != NULL and i < pos; aux = aux->Get_prox(), i++);
		aux->Get_ante()->Set_prox(aux->Get_prox());
		aux->Get_prox()->Set_ante(aux->Get_ante());
		aux->Set_ante(NULL);
		aux->Set_prox(NULL);
		delete aux;
		_tam--;
	}
	
}

// Remove a primeira ocorrência de um número na lista //
void Lista::Remove(int num) {
	
	int i;
	No* aux;
	
	if (!Busca(num)) {
		cout << "O numero nao esta na lista" << endl << endl;
	} else if (_inicio->Get_valor() == num) {
		Remove_inicio();
	} else if (_fim->Get_valor() == num) {
		Remove_fim();
	} else {
		for(aux = _inicio; aux->Get_valor() != num; aux = aux->Get_prox());
		aux->Get_ante()->Set_prox(aux->Get_prox());
		aux->Get_prox()->Set_ante(aux->Get_ante());
		aux->Set_ante(NULL);
		aux->Set_prox(NULL);
		delete aux;
		_tam--;
	}
	
}

// Imprime a lista //
void Lista::Printa() {

	No* aux;
	int i;
	
	if (_tam == 0) {
		cout << "NULL";
	}
	
	for (aux = _inicio, i = 1; aux != NULL; aux = aux->Get_prox(), i++) {

		if (i == 1) {
			cout << "NULL <- " << aux->Get_valor();
			if (_tam == 1) {
				cout << " -> NULL";
			}
		} else if (i > 1 and i == _tam) {
			cout << " <-> " << aux->Get_valor() << " -> NULL";
		} else {
			cout << " <-> " << aux->Get_valor();
		}

	}
	
	cout << endl << endl;

}

int main () {


    Lista L;
	L.Insere_inicio(2);
	L.Insere_fim(37);
	L.Insere_inicio(4);
	L.Insere_fim(0);
	L.Printa();
	
	L.Insere_na_pos(3, 7);
	L.Printa();
	
	L.Insere_na_pos(1, 9);
	L.Printa();
	
	L.Insere_na_pos(7, 6);
	L.Printa();
	
	L.Insere_na_pos(9, 15);
	
	L.Remove_inicio();
	L.Printa();
	
	L.Remove_fim();
	L.Printa();
	
	L.Remove(0);
	L.Printa();
	
	L.Remove(32);
	
	L.Remove_na_pos(2);
	L.Printa();
	
	L.Remove_na_pos(4);
	
	L.Remove_na_pos(3);
	L.Printa();
	
	L.Remove_na_pos(1);
	L.Printa(); 
	
	
	Lista l;
	
	l.Insere_inicio(6);
	l.Printa();
	
	l.Remove_inicio();
	
	l.Printa();
	
	l.Insere_inicio(7);
	l.Insere_inicio(8);
	l.Insere_inicio(9);
	l.Printa();

}
