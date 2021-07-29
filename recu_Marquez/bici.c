#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bici.h"
#include "informes.h"

eBicicleta* Object_new()
{
    eBicicleta *newObject;
    newObject = (eBicicleta*) calloc(sizeof(eBicicleta), 1);

    return newObject;
}

eBicicleta* Object_newParam(char *id, char *duenho, char *tipo,	char *tiempo)
{
    eBicicleta *newObject;
    newObject = Object_new();

    int auxId;
    int auxTiempo;

    auxId = atoi(id);
    auxTiempo = atoi(tiempo);

    if (newObject != NULL && id != NULL && tipo != NULL && duenho != NULL && tiempo != NULL )
    {
        Object_setDuenho(newObject, duenho);
        Object_setTiempo(newObject, auxTiempo);
        Object_setTipo(newObject, tipo);
        Object_setID(newObject, &auxId);
    }
    return newObject;
}

// Searchers
int Bicicleta_SearchForId(LinkedList *this, int id)
{
    int retorno = -1;
    int idAux;
    eBicicleta *pObject;

    for (int index = 0; index < ll_len(this); index++)
    {
        pObject = ll_get(this, index);
        if (Object_getID(pObject, &idAux) == 1 &&
                idAux == id)
        {
            retorno = index;
        }
    }
    return retorno;
}

//Destructors
void Object_delete(eBicicleta *this)
{
    if (this != NULL)
    {
        free(this);
        this = NULL;
    }
}

/* Funcion/Sort por Tipo */
int Object_sortTipo(void *tipo1, void *tipo2)
{
    char tipo_1[20];
    char tipo_2[20];
    int sucess = 0;

    Object_getTipo(tipo1, tipo_1);
    Object_getTipo(tipo2, tipo_2);

    if (strcmp(tipo_1, tipo_2) > 0)
    {
        sucess = 1;
    }
    else if (strcmp(tipo_1, tipo_2) < 0)
    {
        sucess = -1;
    }

    return sucess;
}

/* Funcion/Sort por tiempo */
int Object_sortTiempo(void *tiempo1, void *tiempo2)
{
    int tiempo_1;
    int tiempo_2;
    int sucess = 0;

    Object_getTiempo(tiempo1, &tiempo_1);
    Object_getTiempo(tiempo2, &tiempo_2);

    if (tiempo_1 > tiempo_2)
    {
        sucess = 1;
    }
    else if (tiempo_1 < tiempo_2)
    {
        sucess = -1;
    }
    return sucess;
}
