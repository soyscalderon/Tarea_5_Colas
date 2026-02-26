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

void agregar_frente(NODO **, NODO **);
void eliminar_final(NODO **, NODO **);
void agregar_preferencial(NODO **, NODO **);
void abandonar_cola(NODO **, NODO **);

void imprimir_cola(NODO *, NODO *);
void limpiar_cola(NODO *, NODO *);

int main()
{
    NODO *cabecera_normal = NULL;
    NODO *cabecera_preferencial = NULL;
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
            agregar_frente(&cabecera_preferencial, &cabecera_normal);
            break;
        case 2:
            eliminar_final(&cabecera_preferencial, &cabecera_normal);
            break;
        case 3:
            agregar_preferencial(&cabecera_preferencial, &cabecera_normal);
            break;
        case 4:
            abandonar_cola(&cabecera_preferencial, &cabecera_normal);
            break;
        case 5:
            imprimir_cola(cabecera_preferencial, cabecera_normal);
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

    limpiar_cola(cabecera_preferencial, cabecera_normal);
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

void agregar_frente(NODO **cabecera_preferencial, NODO **cabecera_normal)
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
        nuevo->siguiente = *cabecera_normal;
        *cabecera_normal = nuevo;
        imprimir_cola(*cabecera_preferencial, *cabecera_normal);
        return;
    }
}

void eliminar_final(NODO **cabecera_preferencial, NODO **cabecera_normal)
{
    NODO *previo_preferencial, *actual_preferencial;
    previo_preferencial = NULL;
    actual_preferencial = *cabecera_preferencial;

    NODO *previo_normal, *actual_normal;
    previo_normal = NULL;
    actual_normal = *cabecera_normal;

    // La lista esta vacia
    if (actual_normal == NULL && actual_preferencial == NULL)
    {
        printf("Error. La cola esta vacia.\n");
        system("pause");
        return;
    }

    // La lista contiene al menos un elemento
    else
    {
        if (actual_preferencial != NULL)
        {
            // Recorrer hasta encontrar el ultimo nodo
            while (actual_preferencial->siguiente != NULL)
            {
                previo_preferencial = actual_preferencial;
                actual_preferencial = actual_preferencial->siguiente;
            }
            // Solo hay un nodo
            if (previo_preferencial == NULL)
            {
                *cabecera_preferencial = NULL;
                free(actual_preferencial);
                imprimir_cola(*cabecera_preferencial, *cabecera_normal);
                return;
            }
            // Hay dos o mas nodos
            else
            {
                previo_preferencial->siguiente = NULL;
                free(actual_preferencial);
                imprimir_cola(*cabecera_preferencial, *cabecera_normal);
                return;
            }
        }
        else
        {
            // Recorrer hasta encontrar el ultimo nodo
            while (actual_normal->siguiente != NULL)
            {
                previo_normal = actual_normal;
                actual_normal = actual_normal->siguiente;
            }
            // Solo hay un nodo
            if (previo_normal == NULL)
            {
                *cabecera_normal = NULL;
                free(actual_normal);
                imprimir_cola(*cabecera_preferencial, *cabecera_normal);
                return;
            }
            // Hay dos o mas nodos
            else
            {
                previo_normal->siguiente = NULL;
                free(actual_normal);
                imprimir_cola(*cabecera_preferencial, *cabecera_normal);
                return;
            }
        }
    }
}

void agregar_preferencial(NODO **cabecera_preferencial, NODO **cabecera_normal)
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
        printf("\nAGREGAR PREFERENCIAL");
        nuevo->dato = solicitar_caracter();
        nuevo->siguiente = *cabecera_preferencial;
        *cabecera_preferencial = nuevo;
        imprimir_cola(*cabecera_preferencial, *cabecera_normal);
        return;
    }
}

void abandonar_cola(NODO **cabecera_preferencial, NODO **cabecera_normal)
{
    NODO *previo_preferencial, *actual_preferencial;
    previo_preferencial = NULL;
    actual_preferencial = *cabecera_preferencial;

    NODO *previo_normal, *actual_normal;
    previo_normal = NULL;
    actual_normal = *cabecera_normal;

    // La cola esta vacia
    if (actual_normal == NULL && actual_preferencial == NULL)
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

        // Normal contiene al menos un elemento
        if (actual_normal != NULL)
        {
            // Recorrido de busqueda
            while (actual_normal->dato != caracter && actual_normal->siguiente != NULL)
            {
                previo_normal = actual_normal;
                actual_normal = actual_normal->siguiente;
            }

            // El caracter encontrado es el primero en la cola
            if (actual_normal->dato == caracter && previo_normal == NULL)
            {
                *cabecera_normal = actual_normal->siguiente;
                free(actual_normal);
                imprimir_cola(*cabecera_preferencial, *cabecera_normal);
                return;
            }
            // El caracter encontrado esta en medio o al final de la cola
            else if (actual_normal->dato == caracter)
            {
                previo_normal->siguiente = actual_normal->siguiente;
                free(actual_normal);
                imprimir_cola(*cabecera_preferencial, *cabecera_normal);
                return;
            }
            // No se encontro en la fila normal
        }

        // Buscar en la fila preferencial
        if (actual_preferencial != NULL)
        {
            // Recorrido de busqueda
            while (actual_preferencial->dato != caracter && actual_preferencial->siguiente != NULL)
            {
                previo_preferencial = actual_preferencial;
                actual_preferencial = actual_preferencial->siguiente;
            }

            // El caracter encontrado es el primero en la cola
            if (actual_preferencial->dato == caracter && previo_preferencial == NULL)
            {
                *cabecera_preferencial = actual_preferencial->siguiente;
                free(actual_preferencial);
                imprimir_cola(*cabecera_preferencial, *cabecera_normal);
                return;
            }
            // El caracter encontrado esta en medio o al final de la cola
            else if (actual_preferencial->dato == caracter)
            {
                previo_preferencial->siguiente = actual_preferencial->siguiente;
                free(actual_preferencial);
                imprimir_cola(*cabecera_preferencial, *cabecera_normal);
                return;
            }
            // No se encontro
        }
        printf("No se encontro el caracter\n");
        system("pause");
        return;
    }
}

void imprimir_cola(NODO *cabecera_preferencial, NODO *cabecera_normal)
{
    NODO *actual_normal, *actual_preferencial;
    actual_normal = cabecera_normal;
    actual_preferencial = cabecera_preferencial;

    // La lista esta vacia
    if (actual_normal == NULL && actual_preferencial == NULL)
    {
        printf("\nLa cola esta vacia.\n\n");
        system("pause");
        return;
    }

    // La lista contiene al menos un elemento
    else
    {
        printf("\nCOLA:\n\n");
        while (actual_normal != NULL)
        {
            printf(" %c ->", actual_normal->dato);
            actual_normal = actual_normal->siguiente;
        }
        while (actual_preferencial != NULL)
        {
            printf(" %c ->", actual_preferencial->dato);
            actual_preferencial = actual_preferencial->siguiente;
        }
        printf(" NULL\n\n");
        system("pause");
        return;
    }
}

void limpiar_cola(NODO *cabecera_preferencial, NODO *cabecera_normal)
{
    NODO *previo_preferencial, *actual_preferencial;
    previo_preferencial = NULL;
    actual_preferencial = cabecera_preferencial;

    NODO *previo_normal, *actual_normal;
    previo_normal = NULL;
    actual_normal = cabecera_normal;

    // La lista esta vacia
    if (actual_normal == NULL && actual_preferencial == NULL)
    {
        return;
    }

    // La lista contiene al menos un elemento
    else
    {
        while (actual_preferencial != NULL)
        {
            previo_preferencial = actual_preferencial;
            actual_preferencial = actual_preferencial->siguiente;
            free(previo_preferencial);
        }
        while (actual_normal != NULL)
        {
            previo_normal = actual_normal;
            actual_normal = actual_normal->siguiente;
            free(previo_normal);
        }
        return;
    }
}