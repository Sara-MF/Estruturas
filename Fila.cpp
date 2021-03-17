#include <iostream>
using namespace std;

// Classe contendo a estrutura de um nó de uma fila //
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

// Classe contendo os métodos de uma fila //
class Fila {
private:
	No* _inicio;
	No* _fim;

public:
	Fila() :
		_inicio(NULL),
		_fim(NULL)
	{}

	No* Get_inicio();
	No* Get_fim();
	
	void Set_inicio(No* inicio);
	void Set_fim(No* fim);

	bool Nothing();
	void Adiciona(int num);
	void Remove();
	void Acaba();
	
	void Busca_elem(int num);

	void Printa();
	
	~Fila() {
		if (Nothing()) {
			_inicio == NULL;
			_fim == NULL;
		} else {
			do { Remove(); } while (Nothing() == 0);	
		}
	}

};

No* Fila::Get_inicio() {
	return _inicio;
}

No* Fila::Get_fim() {
	return _fim;
}

void Fila::Set_inicio(No* inicio) {
	_inicio = inicio;
}

void Fila::Set_fim(No* fim) {
	_fim = fim;
}

// Verifica se a fila está vazia //
bool Fila::Nothing() {

	if (_inicio == NULL) {
		return true;
	}

	return false;

}

// Adiciona um elemento na fila //
void Fila::Adiciona(int num) {

	No* nova;
	nova = new No(num);
	
	No* aux;

	if (Nothing()) {
		_inicio = nova;
		_fim = nova;
	} else {
		_fim->Set_prox(nova);
		_fim = nova;
	}

}

// Remove um elemento da fila //
void Fila::Remove() {

	if (Nothing()) {
		cout << "A fila esta vazia" << endl << endl;
	} else {
		No* aux;
		aux = _inicio;
		_inicio = aux->Get_prox();
		aux->Set_prox(NULL);
		delete aux;
	}

}

// Destroi uma fila //
void Fila::Acaba() {
	
	if (Nothing()) {
		cout << "A fila ja esta vazia" << endl << endl;
	} else {
		do { Remove(); } while (Nothing() == 0);	
	}

}

// Verifica se um elemento está ou não contido na fila //
void Fila::Busca_elem(int num) {
	
	if (Nothing()) {
		cout << "Nao ha nada para buscar" <<  endl << endl;
	} else {
		bool encontrou = false;
	
		Fila nova;
		
		// Coloca todos os elementos da fila original na fila nova //
		do {
			No* aux;
			aux = _inicio;
			if (aux->Get_valor() == num) {
				encontrou = true;
			}
			nova.Adiciona(aux->Get_valor());
			this->Remove();
		} while (_inicio != NULL);
		
		// Volta todos os elementos da fila nova para a fila original //
		do {
			No* retorna;
			retorna = nova.Get_inicio();
			this->Adiciona(retorna->Get_valor());
			nova.Remove();
		} while (nova.Get_inicio() != NULL);
		
		if (encontrou) {
			cout << "O numero esta na fila" << endl << endl;
		} else {
			cout << "O numero nao esta na fila" << endl << endl;
		}
		
	}
	
}

// Imprime os elementos de uma fila //
void Fila::Printa() {
	
	if (Nothing()) {
		cout << "Nada a exibir";
	} else {
		Fila nova;
		
		while (!Nothing()) {
			cout << this->_inicio->Get_valor() << " ";
			nova.Adiciona(this->_inicio->Get_valor());
			this->Remove();
		}
		
		while (!nova.Nothing()) {
			this->Adiciona(nova.Get_inicio()->Get_valor());
			nova.Remove();
		}
		
	}

	cout << endl << endl;

}

int main () {

	Fila banco;

	banco.Adiciona(1);
	banco.Adiciona(2);
	banco.Adiciona(3);
	banco.Adiciona(4);

	banco.Printa();

	banco.Remove();
	banco.Printa();

	banco.Acaba();
	banco.Printa();
	
	banco.Adiciona(5);
	banco.Printa();
	
	banco.Remove();
	
	banco.Acaba();
	
	banco.Adiciona(7);
	banco.Adiciona(4);
	banco.Adiciona(0);
	banco.Adiciona(1);

	banco.Printa();
	
	banco.Busca_elem(1);
	banco.Busca_elem(9); 
	
}
