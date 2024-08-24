#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Movel {
public:
    Movel(const string& n){
        nome = n;
    }

    string nome;
};

class Comodo {
public:
    Comodo(const string& n, float a, float l, float c){
        nome = n;
        altura = a;
        largura = l;
        comprimento = c;
    }

    void adicionarMovel(const Movel& m) {
        moveis.push_back(m);
    }

    void exibirMoveis() const {
        cout << "Móveis do(a) " << nome << ":" << endl;
        for (const auto& movel : moveis) {
            cout << movel.nome << endl;
        }
    }

    void exibirDimensoes() const {
        cout << "Dimensões do(a) " << nome << ":" << endl;
        cout << "Altura: " << altura << endl;
        cout << "Largura: " << largura << endl;
        cout << "Comprimento: " << comprimento << endl;
    }

    string nome;
    float altura;
    float largura;
    float comprimento;
    vector<Movel> moveis;
};

class Quarto : public Comodo {
public:
    Quarto(float a, float l, float c) : Comodo("Quarto", a, l, c) {}

    void dormir() {
        cout << "Dormindo no " << nome << "..." << endl;
    }
};

class Cozinha : public Comodo {
public:
    Cozinha(float a, float l, float c) : Comodo("Cozinha", a, l, c) {}

    void cozinhar() {
        cout << "Cozinhando na " << nome << "..." << endl;
    }
};


class Sala : public Comodo {
public:
    Sala(float a, float l, float c) : Comodo("Sala", a, l, c) {}

    void assistirTv() {
        cout << "Assistindo televisão na " << nome << "..." << endl;
    }
};

int main() {
    Quarto q(5, 5, 5); //parâmetros Altura, Largura e Comprimento
    Sala s(6, 6, 6);
    Movel cama("cama");
    Movel cadeira("cadeira");
    Movel tv("televisão");

    q.adicionarMovel(cama);
    q.adicionarMovel(cadeira);
    q.exibirDimensoes();
    q.dormir();
    q.exibirMoveis();

    s.adicionarMovel(tv);
    s.exibirDimensoes();
    s.assistirTv();
    s.exibirMoveis();

    return 0;
}