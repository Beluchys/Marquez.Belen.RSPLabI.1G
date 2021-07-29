#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bici.h"


int Object_getID(eBicicleta *this, int *id)
{
    int sucess = 0;

    if (this != NULL && id != NULL)
    {
        *id = this->id;
        sucess = 1;
    }
    return sucess;
}

int Object_getTipo(eBicicleta *this, char *tipo)
{
    int sucess = 0;

    if (this != NULL && tipo != NULL)
    {
        strcpy(tipo, this->tipo);
        sucess = 1;
    }
    return sucess;
}

int Object_getDuenho(eBicicleta *this, char *duenho)
{
    int sucess = 0;

    if (this != NULL && duenho != NULL)
    {
        strcpy(duenho, this->duenho);
        sucess = 1;
    }
    return sucess;
}

int Object_getTiempo(eBicicleta *this, int *tiempo)
{
    int sucess = 0;

    if (this != NULL && tiempo != NULL)
    {
        *tiempo = this->tiempo;
        sucess = 1;
    }
    return sucess;
}

