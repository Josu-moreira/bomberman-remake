#pragma once
#include <vector>
#include "include/raylib.h"
#include "sprite.h"
#include "jogador.h"
using namespace std;

#define BLOCO_DE_FUNDO 0
#define BLOCO_INDESTRUTIVEL 1
#define BLOCO_DESTRUTIVEL 2

#define LARGURA_BLOCO 35
#define ALTURA_BLOCO 35

class Mapa
{
private:
    int x, y;
    int altura;
    int largura;
    // vector<Entidades> listaEntidades;
    // vector<Objetos> listaObjetos;
    vector<vector<int>> matBloco;
    Sprite *spriteFundo, *spriteIndestrutivel;
    Jogador *jogador;


    void liberarSprites();
public:
    Mapa();
    ~Mapa();

    void mostrarMapa();
    void iniciarMapa(int x, int y, int largura, int altura);
    void atualizar();
    void desenhar();
    void carregaSprite();
    void setJogador(Jogador* jogador);
};
