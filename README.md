# Tic-Tac-Toe en C++

![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)
![C++](https://img.shields.io/badge/C++-17-blue.svg)
![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)

¡Bienvenido al proyecto de **Tic-Tac-Toe** (Tres en Raya) implementado en C++! Este proyecto te permite jugar al clásico juego de Tic-Tac-Toe contra una inteligencia artificial sencilla directamente desde la consola.

## 📋 Tabla de Contenidos

- [Tic-Tac-Toe en C++](#tic-tac-toe-en-c)
  - [📋 Tabla de Contenidos](#-tabla-de-contenidos)
  - [📝 Descripción](#-descripción)
  - [🔍 Descripción de los Componentes](#-descripción-de-los-componentes)
    - [1. Enumeración `Simbolo`](#1-enumeración-simbolo)
    - [2. Clase `Tablero`](#2-clase-tablero)
    - [3. Clase Base `Jugador`](#3-clase-base-jugador)
    - [4. Clase `JugadorHumano`](#4-clase-jugadorhumano)
    - [5. Clase `JugadorIA`](#5-clase-jugadoria)
    - [6. Clase Base `EstadoJuego`](#6-clase-base-estadojuego)
    - [7. Clase `EstadoEnJuego`](#7-clase-estadoenjuego)
    - [8. Clase `Juego`](#8-clase-juego)
    - [9. Función `main`](#9-función-main)
  - [📦 Compilación y Ejecución](#-compilación-y-ejecución)
    - [Requisitos](#requisitos)
    - [Pasos para Compilar y Ejecutar](#pasos-para-compilar-y-ejecutar)

## 📝 Descripción

Este proyecto consiste en una implementación en C++ del juego **Tic-Tac-Toe** donde un jugador humano puede enfrentarse a una IA que selecciona la primera celda vacía disponible. Todas las clases y sus implementaciones están incluidas directamente en un único archivo `main.cpp`, lo que simplifica la estructura del proyecto.

El juego comienza con un tablero vacío de 3x3 celdas, y los jugadores (X y O) alternan turnos para colocar sus símbolos en el tablero. El juego continúa hasta que un jugador gana o se produce un empate. Al final del juego, se muestra el resultado y se da la opción de jugar otra partida.

## 🔍 Descripción de los Componentes



### 1. Enumeración `Simbolo`

Define los posibles símbolos en el tablero:

- `VACIO`: Celda vacía.
- `X`: Símbolo del jugador X.
- `O`: Símbolo del jugador O.

### 2. Clase `Tablero`

Gestiona el estado del tablero del juego, incluyendo:

- **Inicialización del tablero**: Crea un tablero 3x3 vacío.
- **Mostrar el tablero en la consola**: Visualiza el estado actual del tablero.
- **Realizar movimientos**: Permite colocar un símbolo en una posición específica.
- **Verificar ganadores y empates**: Comprueba si hay un ganador o si el tablero está lleno.
- **Obtener celdas vacías y símbolos en posiciones específicas**: Facilita la lógica de la IA y la validación de movimientos.

### 3. Clase Base `Jugador`

Define la interfaz para los jugadores, con:

- **Un símbolo asociado**: `X` o `O`.
- **Función virtual pura `obtenerMovimiento`**: Debe ser implementada por las clases derivadas para determinar el movimiento del jugador.

### 4. Clase `JugadorHumano`

Implementa un jugador humano que ingresa sus movimientos manualmente a través de la consola.

### 5. Clase `JugadorIA`

Implementa una inteligencia artificial simple que selecciona la primera celda vacía disponible en el tablero.

### 6. Clase Base `EstadoJuego`

Define la interfaz para los diferentes estados del juego.

### 7. Clase `EstadoEnJuego`

Maneja el estado actual del juego, gestionando los movimientos de los jugadores, verificando ganadores y empates.

### 8. Clase `Juego`

Gestiona el flujo del juego, alternando entre los jugadores y manteniendo el estado del juego hasta que termina.

### 9. Función `main`

Punto de entrada del programa que inicializa los jugadores, crea el juego y lo inicia.

## 📦 Compilación y Ejecución

### Requisitos

- **Compilador de C++**: Debe soportar al menos C++17 (por ejemplo, `g++`).

### Pasos para Compilar y Ejecutar

1. **Clonar el Repositorio**

   ```bash
   git clone https://github.com/tu_usuario/tic-tac-toe-cpp.git
   cd tic-tac-toe-cpp
