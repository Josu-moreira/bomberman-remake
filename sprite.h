#pragma once
#include "include/raylib.h"
#include <vector>
#include <map>

using namespace std;

class SpriteEstatico {
private:
    Texture2D textura;
    Rectangle rect;
public:
    SpriteEstatico();
    ~SpriteEstatico();

    bool carregar(const char *nome_arquivo, float x, float y, int l, int a);
    void desenhar(float x, float y);
};

class SpriteAnimado {
private:
    int num_frames;
    int frame_atual;
    
    Texture2D textura;
public:
    SpriteAnimado();
    ~SpriteAnimado();

    bool carregar(const char *nome_arquivo);
    Rectangle recortaSprite(float x, float y, float l, float a);
    void desenhar(float x, float y, int index);
    void setIndex(int index);
    void setNumFrames(int num_frames);

    map<int, vector<Rectangle>> anims;
};

class Sprite {
public:
    Texture2D texture;
    int frameWidth;
    int frameHeight;

    Sprite(const char* filename, int cols, int rows) {
        texture = LoadTexture(filename);
        frameWidth = texture.width / cols;
        frameHeight = texture.height / rows;
    }

    ~Sprite() {
        UnloadTexture(texture);
    }
};