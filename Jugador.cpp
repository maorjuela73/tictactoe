// Jugador.cpp
#include "Jugador.h"
#include <iostream>
#include <limits>
#include <algorithm>

// Implementación del constructor de Jugador
Jugador::Jugador(Simbolo s) : simbolo(s) {}

// Implementación del getter para el símbolo
Simbolo Jugador::getSimbolo() const {
    return simbolo;
}

// Implementación del destructor de Jugador
Jugador::~Jugador() = default;

// Implementación del constructor de JugadorHumano
JugadorHumano::JugadorHumano(Simbolo s) : Jugador(s) {}

// Implementación de obtenerMovimiento para JugadorHumano
std::pair<int, int> JugadorHumano::obtenerMovimiento(const Tablero& tablero) const {
    int fila, columna;
    while (true) {
        std::cout << "Jugador " << (simbolo == Simbolo::X ? "X" : "O") 
                  << ", ingresa tu movimiento (fila y columna 1-3): ";
        std::cin >> fila >> columna;
        fila -= 1;
        columna -= 1;

        // Validar entrada
        if (fila >= 0 && fila < 3 && columna >= 0 && columna < 3 &&
            tablero.obtenerCeldasVacias().end() != 
                std::find(tablero.obtenerCeldasVacias().begin(), tablero.obtenerCeldasVacias().end(), 
                          std::make_pair(fila, columna))) {
            return {fila, columna};
        }

        std::cout << "Movimiento inválido. Intenta de nuevo.\n";
        // Limpiar el estado de cin en caso de entrada no válida
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
    }
}

// Implementación del constructor de JugadorIA
JugadorIA::JugadorIA(Simbolo s) : Jugador(s) {}

// Implementación de obtenerMovimiento para JugadorIA
std::pair<int, int> JugadorIA::obtenerMovimiento(const Tablero& tablero) const {
    auto vacias = tablero.obtenerCeldasVacias();
    if (!vacias.empty()) {
        // Selecciona la primera celda vacía
        auto movimiento = vacias.front();
        std::cout << "IA elige: " << (movimiento.first + 1) 
                  << " " << (movimiento.second + 1) << "\n";
        return movimiento;
    }
    return {-1, -1}; // No hay movimientos válidos
}
