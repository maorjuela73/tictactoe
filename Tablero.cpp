// Tablero.cpp
#include "Tablero.h"
#include <iostream>
#include <algorithm>

// Constructor: Inicializa el tablero con todas las celdas vacías
Tablero::Tablero() : celdas(3, std::vector<Simbolo>(3, Simbolo::VACIO)) {}

// Método para mostrar el tablero en la consola
void Tablero::mostrar()  {
    std::cout << "\n";
    for (const auto& fila : celdas) {
        for (size_t i = 0; i < fila.size(); ++i) {
            char simbolo;
            switch (fila[i]) {
                case Simbolo::VACIO: simbolo = ' '; break;
                case Simbolo::X: simbolo = 'X'; break;
                case Simbolo::O: simbolo = 'O'; break;
                default: simbolo = ' '; break;
            }
            std::cout << " " << simbolo << " ";
            if (i != fila.size() - 1) std::cout << "|";
        }
        std::cout << "\n";
        if (&fila != &celdas.back()) std::cout << "---+---+---\n";
    }
    std::cout << "\n";
}

// Método para realizar un movimiento en una posición específica
bool Tablero::realizarMovimiento(int fila, int columna, Simbolo jugador) {
    if (fila < 0 || fila >= 3 || columna < 0 || columna >= 3 || celdas[fila][columna] != Simbolo::VACIO) {
        return false;
    }
    celdas[fila][columna] = jugador;
    return true;
}

std::pair<int, int> validarEntrada(int fila, int columna, const Tablero& tablero) {
    // Validar entrada
    if (fila >= 0 && fila < 3 && columna >= 0 && columna < 3 &&
        tablero.obtenerCeldasVacias().end() != 
            std::find(tablero.obtenerCeldasVacias().begin(), tablero.obtenerCeldasVacias().end(), 
                      std::make_pair(fila, columna))) {
        return {fila, columna};
    }
    // Manejo de caso cuando la entrada no es válida
    return {-1, -1}; // o algún otro valor que indique una entrada no válida
}

// Método para verificar si hay un ganador
Simbolo Tablero::verificarGanador() const {
    // Verificar filas y columnas
    for (int i = 0; i < 3; ++i) {
        if (celdas[i][0] != Simbolo::VACIO &&
            celdas[i][0] == celdas[i][1] && celdas[i][1] == celdas[i][2]) {
            return celdas[i][0];
        }
        if (celdas[0][i] != Simbolo::VACIO &&
            celdas[0][i] == celdas[1][i] && celdas[1][i] == celdas[2][i]) {
            return celdas[0][i];
        }
    }
    // Verificar diagonales
    if (celdas[0][0] != Simbolo::VACIO &&
        celdas[0][0] == celdas[1][1] && celdas[1][1] == celdas[2][2]) {
        return celdas[0][0];
    }
    if (celdas[0][2] != Simbolo::VACIO &&
        celdas[0][2] == celdas[1][1] && celdas[1][1] == celdas[2][0]) {
        return celdas[0][2];
    }
    return Simbolo::VACIO;
}

// Método para verificar si el tablero está lleno (empate)
bool Tablero::estaLleno() const {
    for (const auto& fila : celdas) {
        for (const auto& celda : fila) {
            if (celda == Simbolo::VACIO) {
                return false;
            }
        }
    }
    return true;
}

// Método para obtener todas las celdas vacías
std::vector<std::pair<int, int>> Tablero::obtenerCeldasVacias() const {
    std::vector<std::pair<int, int>> vacias;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (celdas[i][j] == Simbolo::VACIO)
                vacias.emplace_back(i, j);
    return vacias;
}
