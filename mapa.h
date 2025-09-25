#pragma once
#include <vector>
#include "include/raylib.h"
#include "sprite.h"
using namespace std;

#define BLOCO_DE_FUNDO 0
#define BLOCO_INDESTRUTIVEL 1
#define BLOCO_DESTRUTIVEL 2

class Mapa
{
private:
    const int largura = 10;
    const int altura = 10;
    // vector<Entidades> listaEntidades;
    // vector<Objetos> listaObjetos;
    vector<vector<int>> listaBloco;
    Rectangle fundo, indestrutivel, destrutivel;
    Sprite *sprite;
    

public:
    Mapa();
    void mostrarMapa();
    void iniciarMapa();
    void atualizar();
    void desenhar();
    void carregaSprite();

};
