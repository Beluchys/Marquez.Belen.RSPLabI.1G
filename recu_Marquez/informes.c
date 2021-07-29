#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "informes.h"


int getRandom(void)
{
    int aleatorio;
    aleatorio = rand()% 50 + 71;

    return aleatorio;
}

void* tiempoSeteado(void*bici)
{
    eBicicleta* bicicleta = NULL;

    if(bici!=NULL)
    {
        bicicleta = (eBicicleta*)bici;
        Object_setTiempo(bicicleta, getRandom());
    }
    return bicicleta;
}

int filterPASEO(void*bici)
{
    int sucess = 0;

    eBicicleta* bicicleta;
    if(bici!=NULL)
    {
        bicicleta = (eBicicleta*)bici;
        if(strcmp(bicicleta->tipo,"PASEO")==0)
        {
            sucess = 1;
        }
    }

    return sucess;
}

int filterBMX(void*bici)
{
    int sucess = 0;

    eBicicleta* bicicleta;
    if(bici!=NULL)
    {
        bicicleta = (eBicicleta*)bici;
        if(strcmp(bicicleta->tipo,"BMX")==0)
        {
            sucess = 1;
        }
    }
    return sucess;
}

int filterMTB(void*bici)
{
    int sucess = 0;

    eBicicleta* bicicleta;
    if(bici!=NULL)
    {

        bicicleta = (eBicicleta*)bici;
        if(strcmp(bicicleta->tipo,"MTB")==0)
        {
            sucess = 1;
        }
    }
    return sucess;
}

int filterPLAYERA(void*bici)
{
    int sucess = 0;

    eBicicleta* bicicleta;
    if(bici!=NULL)
    {

        bicicleta = (eBicicleta*)bici;
        if(strcmp(bicicleta->tipo,"PLAYERA")==0)
        {
            sucess = 1;
        }
    }
    return sucess;
}
