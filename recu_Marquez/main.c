#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "control.h"
#include "validaciones_marquez.h"
#include "informes.h"


int main()
{
    int option = 0;
    char path[128];
    int loadOrWrite = 0;
    int type;
    LinkedList* lista = NULL;
    LinkedList* filtrada= ll_newLinkedList();
    do
    {
        option = menuOpciones();
        switch(option)
        {
        case 1:
            lista = ll_newLinkedList();
            utn_getNombre(path, 128, "Ingrese el nombre del archivo que desea abrir (sin la extension del archivo): \n"
                          "    Prueba con: bicicletas: ", "    Nombre incorrecto, reintente.\n", 3);
            strMinuscula(path);
            strcat(path,".csv");
            printf("\n\n El archivo a abrir sera: %s\n",path);
            controller_loadFromText(path, lista);
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            controller_ListObject(lista);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            lista = ll_map(lista, tiempoSeteado);
            if(controller_ListObject(lista))
            {
                printf("\n\nTiempos asignados con exito.\n\n");
            }
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            utn_getNumero(&type, "\n---------------------------------------------\n"
                          "Seleccione un numero correspondiente al tipo.\n"
                          "---------------------------------------------\n"
                          "    1 - BMX.\n"
                          "    2 - MTB.\n"
                          "    3 - Paseo.\n"
                          "    4 - Playera.\n"
                          "    \nOpcion Elegida: ",
                          "    Opcion incorrecta, seleccione entre [1-4].\n", 1, 4, 3);
            printf("\n\n");
            switch(type)
            {
            case 1:
                system("cls");
                filtrada = ll_filter(lista, filterBMX);
                if(controller_ListObject(filtrada))
                {
                    controller_saveAsText("BMX.csv", filtrada);
                    printf("\n     ---------------------------------------------\n"
                           "        Lista filtrada y guardada como BMX.csv\n"
                           "     ---------------------------------------------\n");
                }
                break;
            case 2:
                system("cls");
                filtrada = ll_filter(lista, filterMTB);
                if(controller_ListObject(filtrada))
                {
                    controller_saveAsText("MTB.csv", filtrada);
                    printf("\n     ---------------------------------------------\n"
                           "        Lista filtrada y guardada como MTB.csv\n"
                           "     ---------------------------------------------\n");
                }
                break;
            case 3:
                system("cls");
                filtrada = ll_filter(lista, filterPASEO);
                if(controller_ListObject(filtrada))
                {
                    controller_saveAsText("PASEO.csv", filtrada);
                    printf("\n     ---------------------------------------------\n"
                           "        Lista filtrada y guardada como PASEO.csv\n"
                           "     ---------------------------------------------\n");
                }
                break;
            case 4:
                system("cls");
                filtrada = ll_filter(lista, filterPLAYERA);
                if(controller_ListObject(filtrada))
                {
                    controller_saveAsText("PLAYERA.csv", filtrada);
                    printf("\n     ---------------------------------------------\n"
                           "        Lista filtrada y guardada como PLAYERA.csv\n"
                           "     ---------------------------------------------\n");
                }
                break;
            default:
                break;
            }
            system("pause");
            system("cls");
            break;
        case 5:
            if(lista!=NULL)
            {
                if(!ll_Megasort(lista, Object_sortTipo, Object_sortTiempo, 1))
                {
                    controller_ListObject(lista);
                    printf("\n     ---------------------------------------------\n"
                           "        Lista Ordenada por tipo y Tiempo.\n"
                           "     ---------------------------------------------\n");
                }
            }
            system("pause");
            system("cls");
            break;
        case 6:
            if (lista!=NULL)
            {
                controller_saveAsText("posiciones.csv", lista);
                printf("\n\n     ---------------------------------------------\n"
                       "        Guardado con exito como posiciones.csv\n"
                       "     ---------------------------------------------\n");
            }
            system("pause");
            system("cls");
            break;
        }
    }
    while(option != 7);
    return 0;
}
