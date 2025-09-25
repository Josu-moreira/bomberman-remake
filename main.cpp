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
    const int alturaJanela = 450;

    //char teclaPressionada;
    //bool JogoTerminou = false;

    // Entidade *entidade = new Entidade(100, 2.0, 0, 0, 0);

    InitWindow(larguraJanela, alturaJanela, "raylib [core] example - basic window");

    Jogador *jogador = new Jogador(100, 200.0f, 0.0f, 0.0f, 0);


    Mapa *mapa = new Mapa();
    mapa->iniciarMapa();
    
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        
        jogador->andar();

        BeginDrawing();

            ClearBackground(RAYWHITE);
            mapa->mostrarMapa();

            jogador->desenhar();

        EndDrawing();
        //-----------------
    }

    delete jogador;
    CloseWindow();        // Close window and OpenGL context
}
