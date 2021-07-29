#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "control.h"
#include "validaciones_marquez.h"
#include "LinkedList.h"
#include "setters.h"
#include "bici.h"


int Object_setID(eBicicleta *this, int *id)
{
    int sucess = 0;

    if (this != NULL)
    {
        if (id >= 0)
        {
            this->id = *id;
            sucess = 1;
        }
    }
    return sucess;
}

int Object_setDuenho(eBicicleta *this, char *duenho)
{
    int sucess = 0;

    if (this != NULL && duenho != NULL)
    {
        strncpy(this->duenho, duenho, 10);
        sucess = 1;
    }
    return sucess;
}

int Object_setTipo(eBicicleta *this, char *tipo)
{
    int sucess = 0;

    if (this != NULL && tipo != NULL)
    {
        strncpy(this->tipo, tipo, 10);
        sucess = 1;
    }
    return sucess;
}

int Object_setTiempo(eBicicleta *this, int tiempo)
{
    int sucess = 0;

    if (this != NULL)
    {
        if (tiempo >= 0)
        {
            this->tiempo = tiempo;
            sucess = 1;
        }
    }
    return sucess;
}

