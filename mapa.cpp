#include <iostream>
#include <random>
#include "mapa.h"

using namespace std;

Mapa::Mapa() {};

void Mapa::iniciarMapa()
{
    carregaSprite();
    listaBloco.resize(altura);

    random_device rd;
    mt19937 motor(rd());
    uniform_int_distribution<int> distribuicao(0, 2);

    for (int i = 0; i < altura; ++i)
    {

        listaBloco[i].resize(largura);

        for (int j = 0; j < largura; ++j)
        {
            int tipoBloco = distribuicao(motor);
            listaBloco[i][j] = BLOCO_DE_FUNDO;
        }
    }

    for (int j = 0; j < largura; ++j)
    {
        listaBloco[0][j] = BLOCO_INDESTRUTIVEL;
    }

    for (int j = 0; j < largura; ++j)
    {
        listaBloco[altura - 1][j] = BLOCO_INDESTRUTIVEL;
    }

    for (int j = 0; j < altura; ++j)
    {
        listaBloco[j][0] = BLOCO_INDESTRUTIVEL;
    }
    for (int j = 0; j < altura; ++j)
    {
        listaBloco[j][altura - 1] = BLOCO_INDESTRUTIVEL;
    }

    
}

void Mapa::mostrarMapa()
{
    
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
           if (listaBloco[i][j] == BLOCO_DE_FUNDO)
           {
             DrawTexture(sprite->texture, j*35, i*35, WHITE);
           }
           
        }
    
    }

   

}

void Mapa::carregaSprite(){
    char *nome_arquivo = "C:/Users/josue/Desktop/c+/bootcamp/Jogo/imgs/fundo.png";
    sprite = new Sprite(nome_arquivo, 1, 1);
}