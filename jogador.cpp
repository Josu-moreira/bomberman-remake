#include "jogador.h"

Jogador::Jogador(int vida, float velocidade, float x, float y, int sprite)
    : Entidade(vida, velocidade, x, y, sprite) // Call base class constructor
{
    dir_atual = BAIXO;

    carregarSprites();
}

Jogador::~Jogador() {
    delete sprite;
}

void Jogador::carregarSprites() {
    int offset_x = 8;
    int offset_y = 6;
    const char* arquivo = "C:/Users/josue/Desktop/c+/bootcamp/Jogo/imgs/bomberman.png";
    
    sprite = new Sprite(arquivo, 3, 3);

    animacoes["parado"] = new Animation(3, 0.15f, 0, false);
    animacoes["baixo"] = new Animation(3, 0.15f, 0, true);
    animacoes["cima"] = new Animation(3, 0.15f, 1, true);
    animacoes["direita"] = new Animation(3, 0.15f, 2, true);
    animacoes["esquerda"] = animacoes["baixo"];

    animAtual = "parado";
}

void Jogador::setAnim(const string& nome) {
    if(animAtual != nome) {
        animAtual = nome;
        animacoes[animAtual]->reset();
    }
}


void Jogador::andar()
{
    if (IsKeyDown(KEY_W))
    {
        this->y -= velocidade * GetFrameTime();
        setAnim("cima");
    }
    else if (IsKeyDown(KEY_D))
    {
        this->x += velocidade * GetFrameTime();
        setAnim("direita");
    }
    else if (IsKeyDown(KEY_S))
    {
        this->y += velocidade * GetFrameTime();
        setAnim("baixo");
    }
    else if (IsKeyDown(KEY_A))
    {
        this->x -= velocidade * GetFrameTime();
        if (this->x < 0.0)
        {
            this->x = 0.0;
        }

        setAnim("esquerda");
    }
    else {
        setAnim("parado");
    }

    animacoes[animAtual]->update();
}

void Jogador::desenhar() {
    Rectangle src = animacoes[animAtual]->getFrame(*sprite);
    DrawTextureRec(sprite->texture, src, {x, y}, WHITE);
}