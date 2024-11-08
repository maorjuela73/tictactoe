#include "EstadoJuego.h"
#include <iostream>

bool EstadoEnJuego::manejarEstado(Tablero& tablero, std::unique_ptr<Jugador>& jugadorActual, bool& finJuego) {
    tablero.mostrar();
    auto movimiento = jugadorActual->obtenerMovimiento(tablero);
    // Ya se realizó el movimiento dentro de obtenerMovimiento

    // Verificar si el movimiento es válido
    if (!tablero.realizarMovimiento(movimiento.first, movimiento.second, jugadorActual->getSimbolo())) {
        std::cout << "Movimiento inválido. Intenta de nuevo.\n";
        return false; // El turno no se completó, no cambiar de jugador
    }

    // Verificar si hay un ganador
    Simbolo ganador = tablero.verificarGanador();
    if (ganador != Simbolo::VACIO) {
        tablero.mostrar();
        std::cout << "Jugador " << (ganador == Simbolo::X ? "X" : "O") << " ha ganado!\n";
        finJuego = true;
        return true;
    }

    // Verificar si hay empate
    if (tablero.estaLleno()) {
        tablero.mostrar();
        std::cout << "El juego ha terminado en empate.\n";
        finJuego = true;
        return true;
    }

    return true;  // Turno completado exitosamente
}