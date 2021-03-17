/* OBS: Todos as variáveis iniciadas com _ são referentes a própria pilha.
   Quando há interação entre mais de uma pilha, é explicitado em
   qual pilha está sendo feita determinada operação.                        */

#include <iostream>
using namespace std;

// Classe contendo a estrutura de um nó de uma pilha //
class No {
private:
	int _valor;
	No* _prox;

public:
	No(int valor):
		_valor(valor),
		_prox(NULL)
	{}

	int Get_valor();
	No* Get_prox();

	void Set_valor(int valor);
	void Set_prox(No* prox);

};

int No::Get_valor() {
	return _valor;
}

No* No::Get_prox() {
	return _prox;
}

void No::Set_valor(int valor) {
	_valor = valor;
}

void No::Set_prox(No* prox) {
	_prox = prox;
}

// Classe contendo os métodos de uma pilha //
class Pilha {
private:
	No* _inicio;

public:
	Pilha() :
		_inicio(NULL)
	{}

	No* Get_inicio();
	void Set_inicio(No* inicio);

	bool Nothing();
	void Empilha(int num);
	int Remove();
	void Esvazia();
	
	void Busca_elem(int num);

	void Printa();
	
	~Pilha() {
		if (Nothing()) {
			_inicio == NULL;
		} else {
			do { Remove(); } while (Nothing() == 0);	
		}
	}

};

No* Pilha::Get_inicio() {
	return _inicio;
}

void Pilha::Set_inicio(No* inicio) {
	_inicio = inicio;
}

// Verifica se a pilha está vazia //
bool Pilha::Nothing() {

	if (_inicio == NULL) {
		return true;
	}

	return false;

}

// Adiciona um elemento na pilha //
void Pilha::Empilha(int num) {

	No* novo;
	novo = new No(num);

	if (Nothing()) {
		_inicio = novo;
	} else {
		novo->Set_prox(_inicio);
		_inicio = novo;
	}

}

// Remove um elemento da pilha //
int Pilha::Remove() {
	
	if (Nothing()) {
		cout << "A pilha esta vazia" << endl << endl;
	} else {
		No* aux;
		aux = _inicio;
		_inicio = aux->Get_prox();
		aux->Set_prox(NULL);
		delete aux;
	}

}

// Destroi uma pilha //
void Pilha::Esvazia() {
	
	if (Nothing()) {
		cout << "A pilha ja esta vazia" << endl << endl;
	} else {
		do { Remove(); } while (Nothing() == 0);	
	}

}

// Verifica se um elemento está ou não contido na pilha //
void Pilha::Busca_elem(int num) {
	
	if (Nothing()) {
		cout << "Nao ha nada para buscar" <<  endl << endl;
	} else {
		bool contido = false;
	
		Pilha nova;
		
		// Coloca todos os elementos da pilha original na pilha nova //
		do {
			No* aux;
			aux = _inicio;
			if (aux->Get_valor() == num) {
				contido = true;
			}
			nova.Empilha(aux->Get_valor());
			this->Remove();
		} while (_inicio != NULL);
		
		// Volta todos os elementos da pilha nova para a pilha original //
		do {
			No* retorna;
			retorna = nova.Get_inicio();
			this->Empilha(retorna->Get_valor());
			nova.Remove();
		} while (nova.Get_inicio() != NULL);
		
		if (contido) {
			cout << "O numero esta na pilha" << endl << endl;
		} else {
			cout << "O numero nao esta na pilha" << endl << endl;
		}	
	}
	
}

// Imprime os elementos de uma pilha //
void Pilha::Printa() {
	
	if (Nothing()) {
		cout << "Nada a exibir" << endl << endl;
	} else {
		Pilha nova;
	
		while (!Nothing()) {
			cout << this->_inicio->Get_valor() << endl;
			nova.Empilha(this->_inicio->Get_valor());
			this->Remove();
		}
		
		while (!nova.Nothing()) {
			this->Empilha(nova.Get_inicio()->Get_valor());
			nova.Remove();
		}
		
		cout << endl;
	}

}

int main () {

	Pilha pratos;

	pratos.Empilha(1);
	pratos.Empilha(0);
	pratos.Empilha(4);
	pratos.Empilha(7);
	pratos.Empilha(14);

	pratos.Printa();

	pratos.Remove();
	pratos.Printa();

	pratos.Esvazia();
	pratos.Printa();
	
	pratos.Empilha(5);
	pratos.Printa();
	
	pratos.Remove();
	
	pratos.Esvazia();
	
	pratos.Empilha(1);
	pratos.Empilha(0);
	pratos.Empilha(4);
	pratos.Empilha(7);
	pratos.Empilha(14);

	pratos.Printa();
	
	pratos.Busca_elem(5);
	pratos.Busca_elem(4);
	
}
