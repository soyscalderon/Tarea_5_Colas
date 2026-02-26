#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct nodo
{
    char dato;
    struct nodo *siguiente;
} NODO;

char solicitar_caracter();
int solicitar_entero();

void agregar_frente(NODO **);
void eliminar_final(NODO **);
void agregar_preferencial(NODO **);
void abandonar_cola(NODO **);

void imprimir_cola(NODO *);
void limpiar_cola(NODO *);

int main()
{
    NODO *cabecera = NULL;
    int op = 0;

    do
    {
        system("cls");

        printf("ESTRUCTURA DE DATOS: COLAS\n\n"
               "1.Formarse en la cola.\n"
               "2.Atender siguiente en cola.\n"
               "3.Entrada preferencial.\n"
               "4.Abandonar cola.\n"
               "5.Imprimir cola.\n"
               "6.Salir.\n");
        op = solicitar_entero();

        switch (op)
        {
        case 1:
            agregar_frente(&cabecera);
            break;
        case 2:
            eliminar_final(&cabecera);
            break;
        case 3:
            agregar_preferencial(&cabecera);
            break;
        case 4:
            abandonar_cola(&cabecera);
            break;
        case 5:
            imprimir_cola(cabecera);
            break;
        case 6:
            printf("\nSaliendo del programa...\n");
            system("pause");
            system("cls");
            break;
        default:
            printf("\nOpcion invalida.\n");
            system("pause");
            break;
        }
    } while (op != 6);

    limpiar_cola(cabecera);
    return 0;
}

char solicitar_caracter()
{
    char Aux[' '];
    do
    {
        printf("\nIntroduzca un caracter: ");
        fflush(stdin);
        scanf(" %s", Aux); // se leen los datos introducidos
        fflush(stdin);

        if (strlen(Aux) == 1 && isalpha(Aux[0]))
        {
            return Aux[0];
        }
        else
        {
            printf("\n\n Error, dato mal introducido\n\n ");
            system("pause");
        }
    } while (1);
}

int solicitar_entero()
{
    char Aux[' '];
    int i, p, y, num;
    do
    {
        printf("\nIntroduzca un valor: ");
        fflush(stdin);
        scanf(" %s", Aux); // se lee los datos introducidos
        fflush(stdin);
        y = strlen(Aux);

        for (i = 0; i < y; i++)
        {
            if (isdigit(Aux[i])) /*Con una bandera valida que el caracter leido de una cadena sea un digito*/
                p = 1;
            else
                p = 0;

            if (p == 0)
            {
                printf("\n\n Error. El dato no es un numero.\n\n ");
                break;
            }
        }
        if (y == 0)
            p = 0;
    } while (p == 0);

    num = atoi(Aux); /*Regresa la conversion de la cadena introducida a un digito */
    return num;
}

void agregar_frente(NODO **cabecera)
{
    NODO *nuevo = malloc(sizeof(NODO));

    // Verificar que se halla alocado memoria
    if (nuevo == NULL)
    {
        printf("Error de alocacion de memoria.\n");
        system("pause");
        return;
    }
    else
    {
        printf("\nFORMARSE EN LA COLA");
        nuevo->dato = solicitar_caracter();
        nuevo->siguiente = *cabecera;
        *cabecera = nuevo;
        imprimir_cola(*cabecera);
        return;
    }
}

void eliminar_final(NODO **cabecera)
{
    NODO *actual, *previo;
    previo = NULL;
    actual = *cabecera;

    // La lista esta vacia
    if (actual == NULL)
    {
        printf("Error. La cola esta vacia.\n");
        system("pause");
        return;
    }

    // La lista contiene al menos un elemento
    else
    {
        while (actual->siguiente != NULL)
        {
            previo = actual;
            actual = actual->siguiente;
        }

        if (previo == NULL)
        {
            *cabecera = NULL;
            free(actual);
            imprimir_cola(*cabecera);
            return;
        }
        else
        {
            previo->siguiente = NULL;
            free(actual);
            imprimir_cola(*cabecera);
            return;
        }
    }
}

void agregar_preferencial(NODO **cabecera)
{
    NODO *nuevo = malloc(sizeof(NODO));

    // Verificar que se halla alocado memoria
    if (nuevo == NULL)
    {
        printf("Error de alocacion de memoria.\n");
        system("pause");
        return;
    }
    else
    {
        NODO *actual, *previo;
        previo = NULL;
        actual = *cabecera;

        printf("\nENTRADA PREFERENCIAL");
        // La lista esta vacia
        if (actual == NULL)
        {
            nuevo->dato = solicitar_caracter();
            nuevo->siguiente = NULL;
            *cabecera = nuevo;
            imprimir_cola(*cabecera);
            return;
        }

        // La lista contiene al menos un elemento
        else
        {
            while (actual != NULL)
            {
                previo = actual;
                actual = actual->siguiente;
            }
            nuevo->dato = solicitar_caracter();
            nuevo->siguiente = NULL;
            previo->siguiente = nuevo;
            imprimir_cola(*cabecera);
            return;
        }
    }
}

void abandonar_cola(NODO **cabecera)
{
    NODO *previo, *actual;
    previo = NULL;
    actual = *cabecera;

    // La cola esta vacia
    if (actual == NULL)
    {
        printf("Error. La cola esta vacia.\n");
        system("pause");
        return;
    }
    else
    {
        char caracter;
        printf("\nABANDONAR COLA");
        caracter = solicitar_caracter();

        // Recorrido de busqueda
        while (actual->dato != caracter && actual->siguiente != NULL)
        {
            previo = actual;
            actual = actual->siguiente;
        }

        // El caracter encontrado es el primero en la cola
        if (actual->dato == caracter && previo == NULL)
        {
            *cabecera = actual->siguiente;
            free(actual);
            imprimir_cola(*cabecera);
            return;
        }
        // El caracter encontrado esta en medio o al final de la cola
        else if (actual->dato == caracter)
        {
            previo->siguiente = actual->siguiente;
            free(actual);
            imprimir_cola(*cabecera);
            return;
        }
        // No se encontro
        else
        {
            printf("No se encontro el caracter\n");
            system("pause");
            return;
        }
    }
}

void imprimir_cola(NODO *cabecera)
{
    NODO *actual;
    actual = cabecera;

    // La lista esta vacia
    if (actual == NULL)
    {
        printf("\nLa cola esta vacia.\n\n");
        system("pause");
        return;
    }

    // La lista contiene al menos un elemento
    else
    {
        printf("\nCOLA:\n\n");
        while (actual != NULL)
        {
            printf(" %c ->", actual->dato);
            actual = actual->siguiente;
        }
        printf(" NULL\n\n");
        system("pause");
        return;
    }
}

void limpiar_cola(NODO *cabecera)
{
    NODO *previo, *actual;
    previo = NULL;
    actual = cabecera;

    // La lista esta vacia
    if (actual == NULL)
    {
        return;
    }

    // La lista contiene al menos un elemento
    else
    {
        while (actual != NULL)
        {
            previo = actual;
            actual = actual->siguiente;
            free(previo);
        }
        return;
    }
}