#include <iostream>

// Estrutura de nó da árvore
struct No {
    int valor;
    No* esquerda;
    No* direita;
};

// Função para criar um novo nó
No* criarNo(int valor) {
    No* novoNo = new No();
    novoNo->valor = valor;
    novoNo->esquerda = nullptr;
    novoNo->direita = nullptr;
    return novoNo;
}

// Função para inserir um valor na árvore
No* inserir(No* raiz, int valor) {
    if (raiz == nullptr) {
        return criarNo(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

// Função para buscar um valor na árvore
No* buscar(No* raiz, int valor) {
    if (raiz == nullptr || raiz->valor == valor) {
        return raiz;
    }

    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    } else {
        return buscar(raiz->direita, valor);
    }
}

// Função para imprimir a árvore
void imprimir(No* raiz) {
    if (raiz != nullptr) {
        imprimir(raiz->esquerda);
        std::cout << raiz->valor << " ";
        imprimir(raiz->direita);
    }
}

int main() {
    No* raiz = nullptr;

    // Inserir valores na árvore
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 2);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 8);

    // Imprimir a árvore
    std::cout << "Árvore: ";
    imprimir(raiz);
    std::cout << std::endl;

    // Buscar um valor na árvore
    int valorBusca = 4;
    No* resultado = buscar(raiz, valorBusca);

    if (resultado != nullptr) {
        std::cout << "Valor encontrado: " << resultado->valor << std::endl;
    } else {
        std::cout << "Valor não encontrado" << std::endl;
    }

    return 0;
}
