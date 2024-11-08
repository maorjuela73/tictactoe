#include <iostream>
#include <vector>
#include <utility>
#include <memory>
#include <limits>
#include <algorithm>

// Enumeración para los símbolos del tablero
enum class Simbolo { VACIO, X, O };

// Clase que representa el tablero del juego
class Tablero {
private:
    std::vector<std::vector<Simbolo>> celdas;

public:
    // Constructor
    Tablero() : celdas(3, std::vector<Simbolo>(3, Simbolo::VACIO)) {}

    // Mostrar el tablero en la consola
    void mostrar() const {
        std::cout << "\n";
        for (size_t i = 0; i < celdas.size(); ++i) {
            for (size_t j = 0; j < celdas[i].size(); ++j) {
                char simbolo;
                switch (celdas[i][j]) {
                    case Simbolo::VACIO: simbolo = ' '; break;
                    case Simbolo::X: simbolo = 'X'; break;
                    case Simbolo::O: simbolo = 'O'; break;
                    default: simbolo = ' '; break;
                }
                std::cout << " " << simbolo << " ";
                if (j != celdas[i].size() - 1) std::cout << "|";
            }
            std::cout << "\n";
            if (i != celdas.size() - 1) std::cout << "---+---+---\n";
        }
        std::cout << "\n";
    }

    // Realizar un movimiento en la posición (fila, columna)
    bool realizarMovimiento(int fila, int columna, Simbolo jugador) {
        if (fila < 0 || fila >= 3 || columna < 0 || columna >= 3 || celdas[fila][columna] != Simbolo::VACIO) {
            return false;
        }
        celdas[fila][columna] = jugador;
        return true;
    }

    // Verificar si hay un ganador
    Simbolo verificarGanador() const {
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

    // Verificar si el tablero está lleno (empate)
    bool estaLleno() const {
        for (const auto& fila : celdas) {
            for (const auto& celda : fila) {
                if (celda == Simbolo::VACIO) {
                    return false;
                }
            }
        }
        return true;
    }

    // Obtener todas las celdas vacías
    std::vector<std::pair<int, int>> obtenerCeldasVacias() const {
        std::vector<std::pair<int, int>> vacias;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (celdas[i][j] == Simbolo::VACIO)
                    vacias.emplace_back(i, j);
        return vacias;
    }

    // Obtener el símbolo en una posición específica
    Simbolo obtenerSimbolo(int fila, int columna) const {
        if (fila < 0 || fila >= 3 || columna < 0 || columna >= 3) {
            return Simbolo::VACIO;
        }
        return celdas[fila][columna];
    }
};

// Clase base para los jugadores
class Jugador {
protected:
    Simbolo simbolo;

public:
    // Constructor
    Jugador(Simbolo s) : simbolo(s) {}

    // Función virtual pura para obtener el movimiento
    virtual std::pair<int, int> obtenerMovimiento(const Tablero& tablero) const = 0;

    // Getter para el símbolo
    Simbolo getSimbolo() const {
        return simbolo;
    }

    // Destructor virtual
    virtual ~Jugador() = default;
};

// Jugador humano
class JugadorHumano : public Jugador {
public:
    // Constructor
    JugadorHumano(Simbolo s) : Jugador(s) {}

    // Implementación de la función obtenerMovimiento
    std::pair<int, int> obtenerMovimiento(const Tablero& tablero) const override {
        int fila, columna;
        while (true) {
            std::cout << "Jugador " << (simbolo == Simbolo::X ? "X" : "O")
                      << ", ingresa tu movimiento (fila y columna 1-3): ";
            std::cin >> fila >> columna;
            fila -= 1;
            columna -= 1;

            // Validar entrada
            if (fila >= 0 && fila < 3 && columna >= 0 && columna < 3 &&
                tablero.obtenerSimbolo(fila, columna) == Simbolo::VACIO) {
                return {fila, columna};
            }

            std::cout << "Movimiento inválido. Intenta de nuevo.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
};

// Jugador IA simple que elige la primera celda vacía
class JugadorIA : public Jugador {
public:
    // Constructor
    JugadorIA(Simbolo s) : Jugador(s) {}

    // Implementación de la función obtenerMovimiento
    std::pair<int, int> obtenerMovimiento(const Tablero& tablero) const override {
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
};

// Clase base para los estados del juego
class EstadoJuego {
public:
    virtual bool manejarEstado(Tablero& tablero, std::unique_ptr<Jugador>& jugadorActual, bool& finJuego) = 0;
    virtual ~EstadoJuego() = default;
};

// Estado en juego
class EstadoEnJuego : public EstadoJuego {
public:
    bool manejarEstado(Tablero& tablero, std::unique_ptr<Jugador>& jugadorActual, bool& finJuego) override {
        tablero.mostrar();
        auto movimiento = jugadorActual->obtenerMovimiento(tablero);

        if (!tablero.realizarMovimiento(movimiento.first, movimiento.second, jugadorActual->getSimbolo())) {
            std::cout << "Movimiento inválido. Intenta de nuevo.\n";
            return false;  // El turno no se completó, no cambiar de jugador
        }

        // Verificar si hay un ganador
        Simbolo ganador = tablero.verificarGanador();
        if (ganador != Simbolo::VACIO) {
            tablero.mostrar();
            std::cout << "¡Jugador " << (ganador == Simbolo::X ? "X" : "O") << " ha ganado!\n";
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
};

// Clase principal que gestiona el flujo del juego
class Juego {
private:
    Tablero tablero;
    std::unique_ptr<Jugador> jugador1;
    std::unique_ptr<Jugador> jugador2;
    std::unique_ptr<EstadoJuego> estadoActual;
    bool finJuego;

public:
    Juego(std::unique_ptr<Jugador> j1, std::unique_ptr<Jugador> j2)
        : jugador1(std::move(j1)), jugador2(std::move(j2)),
          estadoActual(std::make_unique<EstadoEnJuego>()), finJuego(false) {}

    void iniciar() {
        std::unique_ptr<Jugador>* jugadorActualPtr = &jugador1;

        while (!finJuego) {
            bool turnoCompletado = estadoActual->manejarEstado(tablero, *jugadorActualPtr, finJuego);
            if (finJuego) break;
            if (turnoCompletado) {
                // Cambiar al siguiente jugador
                jugadorActualPtr = (jugadorActualPtr == &jugador1) ? &jugador2 : &jugador1;
            } else {
                // No cambiar de jugador, permitir que intente nuevamente
                std::cout << "Intenta nuevamente.\n";
            }
        }
    }
};
