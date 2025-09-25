#pragma once

#include "entidade.h"

enum ESTADO{
    PARADO,
    ANDANDO,
    MORTO
}


class Inimigo:public Entidade{
    public:
    std::string tipo;
    ESTADO estado;

    void criarBloco(pos);
    
}