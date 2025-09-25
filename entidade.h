#pragma once

class Entidade
{
protected:
    int vida;
    float velocidade;
    float x;
    float y;
    int sprite;

public:
    Entidade(int vida, float velocidade, float x, float y, int sprite); //Método construtor 
    virtual ~Entidade();
    void atualizar();
    virtual void andar();
    virtual void desenhar();
    float getX() const { return this->x; }
    float getY() const { return this->y; }
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
};