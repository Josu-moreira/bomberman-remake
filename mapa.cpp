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

    // Colocar blocos indestrutíveis em todas as posições pares da matriz (exceto bordas)
    for (int i = 2; i < altura - 1; i += 2) {
        for (int j = 2; j < largura - 1; j += 2) {
            matBloco[i][j] = BLOCO_INDESTRUTIVEL;
        }
    }
}

void Mapa::atualizar() {
    jogador->andar();
    
    if(jogador->getX() < x + LARGURA_BLOCO) {
        jogador->setX(x + LARGURA_BLOCO);
    }
    else if(jogador->getX() >= x + (largura - 2)*LARGURA_BLOCO) {
        jogador->setX(x  + (largura - 2)*LARGURA_BLOCO);
    }

    if(jogador->getY() < y + ALTURA_BLOCO){
        jogador->setY(y + ALTURA_BLOCO);
    }
    else if(jogador->getY() >= y + (altura - 2)*ALTURA_BLOCO) {
        jogador->setY(y + (altura - 2)*ALTURA_BLOCO);
    }
}

void Mapa::mostrarMapa()
{
    
    for (int i = 0; i < largura; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            switch(matBloco[i][j]) {
                case BLOCO_DE_FUNDO:
                    DrawTexture(spriteFundo->texture, x + (i*LARGURA_BLOCO), y + (j*ALTURA_BLOCO), WHITE);
                    break;
                case BLOCO_INDESTRUTIVEL:
                    DrawTexture(spriteIndestrutivel->texture, x + (i*LARGURA_BLOCO), y + (j*ALTURA_BLOCO), WHITE);
                    break;
                default:
                    DrawTexture(spriteFundo->texture, x + (i*LARGURA_BLOCO), y + (j*ALTURA_BLOCO), WHITE);
                    break;
            }
        }
    }

    jogador->desenhar();
}

void Mapa::carregaSprite(){
    string nome_arquivo = "./imgs/fundo.png";

    spriteFundo = new Sprite(nome_arquivo.c_str(), 1, 1);

    nome_arquivo = "./imgs/indestrutivel.png";

    spriteIndestrutivel = new Sprite(nome_arquivo.c_str(), 1, 1);
}

void Mapa::liberarSprites() {
    delete spriteFundo;
    delete spriteIndestrutivel;
}

void Mapa::setJogador(Jogador* jogador) {
    this->jogador = jogador;
}