#pragma once
#include <iostream>
#include <map>
#include <string>
#include "entidade.h"
#include "sprite.h"
#include "anim.h"

using namespace std;

enum DIRECOES {
    CIMA = 0,
    BAIXO = 1,
    ESQUERDA = 2,
    DIREITA = 3
};

class Jogador : public Entidade
{

private:
    Sprite *sprite; 
    DIRECOES dir_atual;
    map<string, Animation*> animacoes;
    string animAtual;
public:

    Jogador(int vida, float velocidade, float x, float y, int sprite);
    ~Jogador();

    void andar() override;

    void desenhar() override;
    void soltarBomba(float x, float y);

private:
    void setAnim(const string& nome);
    void carregarSprites();
};