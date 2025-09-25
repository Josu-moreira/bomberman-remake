#include <stdio.h>
#include <iostream>
#include "sprite.h"

SpriteEstatico::SpriteEstatico() {

}

SpriteEstatico::~SpriteEstatico() {
    UnloadTexture(textura);
}

bool SpriteEstatico::carregar(const char *nome_arquivo, float x, float y, int l, int a) {
    textura = LoadTexture(nome_arquivo);
    rect = { x, y, (float)l, (float)a };
    
    return true;
}

void SpriteEstatico::desenhar(float x, float y){
    DrawTextureRec(textura, rect, {x, y}, WHITE);
}

// SPRITE ANIMADO IMPL
SpriteAnimado::SpriteAnimado() {
    frame_atual = 0;
}

SpriteAnimado::~SpriteAnimado() {
    UnloadTexture(textura);
}


Rectangle SpriteAnimado::recortaSprite(float x, float y, float l, float a) {
    Rectangle rect;

    rect = {x, y, l, a};

    return rect;
}

bool SpriteAnimado::carregar(const char *nome_arquivo) {
    std::cout << "Tentando carregar: " << nome_arquivo << std::endl;
    textura = LoadTexture(nome_arquivo);
    std::cout << "Entrei aqui" << std::endl;
    std::cout << "ID da textura: " << textura.id << std::endl;
    if (textura.id == 0) {
        std::cout << "Erro ao carregar textura!" << std::endl;
        return false;
    }
    return true;
}

void SpriteAnimado::setNumFrames(int num_frames) {
    this->num_frames = num_frames;
}

void SpriteAnimado::desenhar(float x, float y, int index) {
    
    DrawTextureRec(textura, anims[index][frame_atual], {x, y}, WHITE);

    if (frame_atual > num_frames) frame_atual = 0;
    else frame_atual++;

}