#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "validaciones_marquez.h"
#include "bici.h"
#include "parser.h"


//MENUS
int menuOpciones()
{
    int opcion=-1;
    printf("    -----------------------  MENU PRINCIPAL  -----------------------\n");
    printf("    ----------------------------------------------------------------\n");
    printf("1- Cargar archivo.\n");
    printf("2- Imprimir lista.\n");
    printf("3- Asignar tiempos.\n");
    printf("4- Filtrar por tipo.\n");
    printf("5- Mostrar posiciones.\n");
    printf("6- Guardar posiciones.\n");
    printf("7- Salir.\n");
    printf("    ----------------------------------------------------------------\n");

    utn_getNumero(&opcion, "\nOpcion: ", "Error, opcion incorrecta.", 1, 7, 3);
    return opcion;
}



int controller_loadFromText(char *path, LinkedList *this)
{
    FILE *pFile; // para leer la lista
    int sucess = 0;
    pFile = fopen(path, "r");
    if (pFile != NULL)
    {
        if(parser_ObjectFromText(pFile, this))
        {
            fclose(pFile);
            sucess = 1;
        }
        else
        {
            printf("ERROR NULL DE PARSER");
        }

    }
    else
    {
        printf("ERROR NULL DE CONTROLLER");
    }

    return sucess;
}

int controller_ListObject(LinkedList *this)
{
    eBicicleta *pObject;
    int sucess = 0;
    int id;
    char tipo[128];
    char duenho[128];
    int tiempo;

    if (this == NULL)
    {
        printf("\n\nNo hay bicis para listar.\n");
    }
    else
    {
        printf("    ---------------------------------------------\n"
               "      ID        Dueno        Tipo       Tiempo   \n"
               "    ---------------------------------------------\n");
        sucess = 1;

        for (int i = 0; i < ll_len(this); i++)
        {
            pObject = ll_get(this, i);
            Object_getDuenho(pObject, duenho);
            Object_getID(pObject, &id);
            Object_getTiempo(pObject, &tiempo);
            Object_getTipo(pObject, tipo);
            printf("    %03d        %-10s     %-7s      %03d\n", id, duenho, tipo, tiempo);
        }
    }
    return sucess;
}

int saveAsTextFormat_Csv(FILE *pFile, LinkedList *this)
{
    eBicicleta *Object;

    int ID;
    char tipo[20];
    char duenho[20];
    int tiempo;
    int len_LL;
    int sucess = 0;
    int flagHeader = 1;

    if (pFile != NULL && this != NULL)
    {
        len_LL = ll_len(this); // obtengo el tam

        for (int i = 0; i < len_LL; i++)  	// recorro el array.
        {
            Object = ll_get(this, i);
            Object_getID(Object, &ID);
            Object_getDuenho(Object, duenho);
            Object_getTipo(Object, tipo);
            Object_getTiempo(Object, &tiempo);

            if (flagHeader)
            {
                fprintf(pFile, "%s,%s,%s,%s\n", "ID", "duenho", "tipo", "tiempo");
                flagHeader = 0;
            }
            fprintf(pFile, "%d,%s,%s,%d\n", ID, duenho,tipo, tiempo);
            sucess = 1;
        }
    }
    return sucess;
}

int controller_saveAsText(char *path, LinkedList *this)
{
    int sucess = 0;
    FILE *pFile = fopen(path, "w");

    if (pFile != NULL && saveAsTextFormat_Csv(pFile, this))
    {
        sucess = 1;
    }
    fclose(pFile);
    ll_clear(this);
    return sucess;
}
