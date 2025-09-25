#include <iostream>
#include <random>
#include "mapa.h"

using namespace std;

Mapa::Mapa() {}

Mapa::~Mapa() {
    liberarSprites();

    delete jogador;
}

void Mapa::iniciarMapa(int x, int y, int largura, int altura)
{
    carregaSprite();

    this->x = x;
    this->y = y;
    this->altura = altura;
    this->largura = largura;

    matBloco.resize(altura);
    
    random_device rd;
    mt19937 motor(rd());
    uniform_int_distribution<int> distribuicao(0, 2);

    for (int i = 0; i < altura; ++i)
    {

        matBloco[i].resize(largura);

        for (int j = 0; j < largura; ++j)
        {
            int tipoBloco = distribuicao(motor);
            matBloco[i][j] = BLOCO_DE_FUNDO;
        }
    }

    for (int j = 0; j < largura; ++j)
    {
        matBloco[0][j] = BLOCO_INDESTRUTIVEL;
    }

    for (int j = 0; j < largura; ++j)
    {
        matBloco[altura - 1][j] = BLOCO_INDESTRUTIVEL;
    }

    for (int j = 0; j < altura; ++j)
    {
        matBloco[j][0] = BLOCO_INDESTRUTIVEL;
    }
    for (int j = 0; j < altura; ++j)
    {
        matBloco[j][altura - 1] = BLOCO_INDESTRUTIVEL;
    }

    
}

void Mapa::atualizar() {
    jogador->andar();
    
    if(jogador->getX() < x) {
        jogador->setX(x);
    }
    else if(jogador->getX() >= x + (largura-1)*LARGURA_BLOCO) {
        jogador->setX(x  + (largura-1)*LARGURA_BLOCO);
    } else if(jogador->getY() < y){
        jogador->setY(y);
    } else if(jogador->getY() >= y + (altura-1)*ALTURA_BLOCO) {
        jogador->setY(y + (altura-1)*ALTURA_BLOCO);
    }
}

void Mapa::mostrarMapa()
{
    
    for (int i = 0; i < largura; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            DrawTexture(spriteFundo->texture, x + (i*LARGURA_BLOCO), y + (j*ALTURA_BLOCO), WHITE);
        }
    }

    jogador->desenhar();
}

void Mapa::carregaSprite(){
    const char *nome_arquivo = "./imgs/fundo.png";
    spriteFundo = new Sprite(nome_arquivo, 1, 1);
}

void Mapa::liberarSprites() {
    delete spriteFundo;
}

void Mapa::setJogador(Jogador* jogador) {
    this->jogador = jogador;
}