#ifndef ESTADOJUEGO_H
#define ESTADOJUEGO_H

#include "Tablero.h"
#include "Jugador.h"
#include <memory>

// Clase base para los estados del juego
class EstadoJuego {
public:
    virtual bool manejarEstado(Tablero& tablero, std::unique_ptr<Jugador>& jugadorActual, bool& finJuego) = 0;
    virtual ~EstadoJuego() = default;
};

// Estado en juego
class EstadoEnJuego : public EstadoJuego {
public:
    bool manejarEstado(Tablero& tablero, std::unique_ptr<Jugador>& jugadorActual, bool& finJuego) override;
};

#endif // ESTADOJUEGO_H