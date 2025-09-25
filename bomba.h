#pragma once

class Bomba
{
private:
    int dano;
    float posicao;
    int tempoExplosao;
    int tempoCriacao;

    enum ESTADO_BOMBA
    {
        ATIVADA,
        DESATIVADA,
        EXPLODIDA,
        DESAPARECER
    }

    public:

    void atualizar();
    void desenhar();
    void explodir();
}