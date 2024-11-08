// main.cpp
#include <iostream>
#include <memory>
#include "Tablero.h"
#include "Jugador.h"

int main() {
    // Crear el tablero
    Tablero tablero;

    // Crear jugadores: JugadorHumano con 'X' y JugadorIA con 'O'
    std::unique_ptr<Jugador> jugador1 = std::make_unique<JugadorHumano>(Simbolo::X);
    std::unique_ptr<Jugador> jugador2 = std::make_unique<JugadorIA>(Simbolo::O);

    // Arreglo de punteros a jugadores para facilitar la alternancia
    Jugador* jugadores[2] = {jugador1.get(), jugador2.get()};
    int turno = 0;

    while (true) {
        tablero.mostrar();
        Jugador* jugadorActual = jugadores[turno % 2];
        std::pair<int, int> movimiento = jugadorActual->obtenerMovimiento(tablero);

        // Verificar si el movimiento es válido
        if (movimiento.first == -1 && movimiento.second == -1) {
            std::cout << "No hay movimientos válidos disponibles.\n";
            break;
        }

        // Realizar el movimiento en el tablero
        bool exito = tablero.realizarMovimiento(movimiento.first, movimiento.second, jugadorActual->getSimbolo());
        if (!exito) {
            std::cout << "Movimiento inválido. Intenta de nuevo.\n";
            continue; // Permitir al jugador intentar nuevamente
        }

        // Verificar si hay un ganador
        Simbolo ganador = tablero.verificarGanador();
        if (ganador != Simbolo::VACIO) {
            tablero.mostrar();
            std::cout << "Jugador " << (ganador == Simbolo::X ? "X" : "O") << " ha ganado!\n";
            break;
        }

        // Verificar si el tablero está lleno (empate)
        if (tablero.estaLleno()) {
            tablero.mostrar();
            std::cout << "El juego ha terminado en empate.\n";
            break;
        }

        turno++;
    }

    return 0;
}
