// Tablero.h
#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include <utility>

/*
    Métodos como mostrar(), verificarGanador(), estaLleno() 
    y obtenerCeldasVacias() se declaran como const porque no 
    modifican el estado interno del objeto Tablero. Esto permite 
    que puedan ser llamadas en objetos const y asegura que no 
    alteran el tablero.
*/

// Enumeración para los símbolos del tablero
enum class Simbolo { VACIO, X, O };

// Clase que representa el tablero del juego
class Tablero {
private:
    std::vector<std::vector<Simbolo>> celdas;

public:
    // Constructor
    Tablero();

    // Mostrar el tablero en la consola
    void mostrar() ; // Función constante

    // Realizar un movimiento en la posición (fila, columna)
    bool realizarMovimiento(int fila, int columna, Simbolo jugador);

    // Verificar si hay un ganador
    Simbolo verificarGanador() const; // Función constante

    // Verificar si el tablero está lleno (empate)
    bool estaLleno() const; // Función constante

    // Obtener todas las celdas vacías
    std::vector<std::pair<int, int>> obtenerCeldasVacias() const; // Función constante
};

#endif // TABLERO_H
