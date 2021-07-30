#ifndef BICI_H_INCLUDED
#define BICI_H_INCLUDED
#include "LinkedList.h"

typedef struct {
    int id;
	char duenho[128]; // nombre
	char tipo[128]; //
	int tiempo; // tiempo

} eBicicleta;


/** \brief
 *
 * \param this LinkedList*
 * \param id int
 * \return int
 *
 */
int Bicicleta_SearchForId(LinkedList *this, int id);


/** \brief
 *
 * \return eBicicleta*
 *
 */
eBicicleta* Object_new();


/** \brief
 *
 * \param id char*
 * \param duenho char*
 * \param tipo char*
 * \param tiempo char*
 * \return eBicicleta*
 *
 */
eBicicleta* Object_newParam(char *id, char *duenho, char *tipo,	char *tiempo);


/** \brief
 *
 * \param this eBicicleta*
 * \return void
 *
 */
void Object_delete(eBicicleta *this);


/** \brief
 *
 * \param tiempo1 void*
 * \param tiempo2 void*
 * \return int
 *
 */
int Object_sortTiempo(void *tiempo1, void *tiempo2);


/** \brief
 *
 * \param tipo1 void*
 * \param tipo2 void*
 * \return int
 *
 */
int Object_sortTipo(void *tipo1, void *tipo2);
eBicicleta* Object_newParam(char *id, char *duenho, char *tipo,	char *tiempo);

#endif // BICI_H_INCLUDED
