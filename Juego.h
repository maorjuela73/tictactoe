#ifndef JUEGO_H
#define JUEGO_H

#include "Tablero.h"
#include "Jugador.h"
#include "EstadoJuego.h"
#include <memory>

// Clase principal que gestiona el flujo del juego
class Juego {
private:
    Tablero tablero;
    std::unique_ptr<Jugador> jugador1;
    std::unique_ptr<Jugador> jugador2;
    std::unique_ptr<EstadoJuego> estadoActual;
    bool finJuego;

public:
    Juego(std::unique_ptr<Jugador> j1, std::unique_ptr<Jugador> j2);

    void iniciar();
};

#endif // JUEGO_H