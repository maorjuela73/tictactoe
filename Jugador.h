// Jugador.h
#ifndef JUGADOR_H
#define JUGADOR_H

#include <utility>   // Para std::pair
#include "Tablero.h" // Asegúrate de que Tablero.h esté en el mismo directorio

// Clase base para los jugadores
class Jugador {
protected:
    Simbolo simbolo;

public:
    // Constructor
    Jugador(Simbolo s);

    // Función virtual pura para obtener el movimiento
    // Declara la función como const ya que no modifica el estado del jugador
    virtual std::pair<int, int> obtenerMovimiento(const Tablero& tablero) const = 0;

    // Getter para el símbolo
    Simbolo getSimbolo() const;

    // Destructor virtual
    virtual ~Jugador();
};

// Jugador humano
class JugadorHumano : public Jugador {
public:
    // Constructor
    JugadorHumano(Simbolo s);

    // Implementación de la función obtenerMovimiento
    std::pair<int, int> obtenerMovimiento(const Tablero& tablero) const override;
};

// Jugador IA simple que elige la primera celda vacía
class JugadorIA : public Jugador {
public:
    // Constructor
    JugadorIA(Simbolo s);

    // Implementación de la función obtenerMovimiento
    std::pair<int, int> obtenerMovimiento(const Tablero& tablero) const override;
};

#endif // JUGADOR_H
