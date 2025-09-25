#include "entidade.h"
#include <iostream>

using namespace std;

 Entidade::Entidade(int vida, float velocidade, float x, float y, int sprite)
{
    this->vida = vida;
    this->velocidade = velocidade;
    this->x = x;
    this->y = y;
    this->sprite = sprite;
};
 
Entidade::~Entidade() {

}

void Entidade::andar() {
 
    cout << "Entidade base não tem movimento definido." << endl;
}

void Entidade::desenhar() // método virtual
{
    cout << "Indice sprite: " << sprite << " na posicao" << x << " " << y << endl;
}