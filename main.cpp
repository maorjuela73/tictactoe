#include <iostream>
#include "Juego.h"
#include "Jugador.h"

// Función principal
int main() {
    std::cout << "Bienvenido al Juego de Tic-Tac-Toe!\n";

    // Crear jugadores: jugador1 es humano, jugador2 es IA
    std::unique_ptr<Jugador> jugador1 = std::make_unique<JugadorHumano>(Simbolo::X);
    std::unique_ptr<Jugador> jugador2 = std::make_unique<JugadorIA>(Simbolo::O);

    // Crear y iniciar el juego
    Juego juego(std::move(jugador1), std::move(jugador2));
    juego.iniciar();

    return 0;
}