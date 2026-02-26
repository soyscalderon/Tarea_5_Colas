# 📚 Estructura de Datos - Colas Dinámicas en C

## 📌 Descripción

Este proyecto fue desarrollado como parte de la **Tarea 5 de la materia
de Estructura de Datos**, cuyo objetivo es implementar una **cola
dinámica lineal** utilizando el lenguaje **C** y memoria dinámica.

El programa simula el comportamiento de una cola, permitiendo agregar,
eliminar y gestionar elementos, incluyendo funcionalidades especiales
como **entrada preferencial** y **abandono de la cola**.

------------------------------------------------------------------------

## 🎯 Objetivos

-   Implementar una cola utilizando estructuras dinámicas (listas
    enlazadas).
-   Utilizar memoria dinámica con `malloc` y `free`.
-   Aplicar operaciones fundamentales de una cola.
-   Implementar funcionalidades adicionales solicitadas en la tarea.

------------------------------------------------------------------------

## ⚙️ Características del Programa

El sistema permite realizar las siguientes operaciones desde un menú
interactivo:

1.  **Formarse en la cola** → Agrega un elemento al inicio de la cola.
2.  **Atender siguiente en cola** → Elimina el último elemento de la
    cola.
3.  **Entrada preferencial** → Agrega un elemento al final de la cola.
4.  **Abandonar cola** → Elimina un elemento específico de la cola.
5.  **Imprimir cola** → Muestra el estado actual de la cola.
6.  **Salir** → Termina el programa.

------------------------------------------------------------------------

## 🧱 Estructura de Datos

Se utiliza la siguiente estructura:

``` c
typedef struct nodo
{
    char dato;
    struct nodo *siguiente;
} NODO;
```

------------------------------------------------------------------------

## 💻 Requisitos

-   Compilador de C (GCC recomendado)
-   Sistema operativo Windows, Linux o Mac

------------------------------------------------------------------------

## ▶️ Compilación

Para compilar el programa, utiliza el siguiente comando:

``` bash
gcc colas.c -o colas
```

------------------------------------------------------------------------

## ▶️ Ejecución

Ejecuta el programa con:

``` bash
./colas
```

En Windows:

``` bash
colas.exe
```

------------------------------------------------------------------------

## 🖥️ Ejemplo de funcionamiento

``` text
ESTRUCTURA DE DATOS: COLAS

1. Formarse en la cola
2. Atender siguiente en cola
3. Entrada preferencial
4. Abandonar cola
5. Imprimir cola
6. Salir
```

------------------------------------------------------------------------

## 📂 Archivos del Proyecto

    📁 Proyecto-Colas
     ├── colas.c
     └── README.md

------------------------------------------------------------------------

## 🧠 Conceptos aplicados

-   Listas enlazadas
-   Colas (Queue)
-   Memoria dinámica
-   Punteros
-   Estructuras en C

------------------------------------------------------------------------

## 👨‍💻 Autor

Sebastian Calderon

------------------------------------------------------------------------

## 📘 Materia

Estructura de Datos

------------------------------------------------------------------------

## 📅 Tarea

Tarea 5 - Colas Dinámicas

------------------------------------------------------------------------

## 📄 Licencia

Este proyecto es solo para fines educativos.
