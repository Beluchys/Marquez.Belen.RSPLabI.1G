#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "LinkedList.h"
#include "bici.h"
#include "parser.h"


int parser_ObjectFromText(FILE *pFile, LinkedList *this)
{
    eBicicleta *pObject;

    char auxID[128];
    char tipo[128];
    char duenho[128];
    char tiempo[128];

    int sucess = 0;
    int firstElement = 1;

    if (pFile != NULL)
    {
        while (!feof(pFile))
        {
            if (firstElement)
            {
                fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxID,	duenho, tipo, tiempo);
                firstElement = 0;
            }
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxID,duenho, tipo, tiempo);
            pObject = Object_newParam(auxID, duenho,tipo, tiempo);

            if (pObject != NULL)
            {
                ll_add(this, pObject);
                sucess = 1;
            }
        }
    }
    return sucess;
}

