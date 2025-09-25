#include <iostream>
#include <fstream>
#include <string>
#include "include/raylib.h"
#include "entidade.h"
#include "jogador.h"
#include "mapa.h"
#include "sprite.h"

using namespace std;

int main()
{
    const int larguraJanela = 800;
    const int alturaJanela = 650;

    //char teclaPressionada;
    //bool JogoTerminou = false;

    // Entidade *entidade = new Entidade(100, 2.0, 0, 0, 0);

    InitWindow(larguraJanela, alturaJanela, "raylib [core] example - basic window");

    Jogador *jogador = new Jogador(100, 200.0f, 0.0f, 0.0f, 0);

    Mapa *mapa = new Mapa();
    mapa->iniciarMapa((int)larguraJanela/6, (int)alturaJanela/6, 15, 15);
    mapa->setJogador(jogador);
    
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        
        mapa->atualizar();
        BeginDrawing();

            ClearBackground(BLUE);
            mapa->mostrarMapa();

        EndDrawing();
        //-----------------
    }

    delete mapa;
    CloseWindow();        // Close window and OpenGL context
}
