#ifndef CONTROL_H_INCLUDED
#define CONTROL_H_INCLUDED
#include "LinkedList.h"



/** \brief carga la lista
 *
 * \param path char*
 * \param this LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *this);


/** \brief imprime la lista
 *
 * \param this LinkedList*
 * \return int
 *
 */
int controller_ListObject(LinkedList *this);


/** \brief Guarda en Texto
 *
 * \param path char*
 * \param this LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *this);


#endif // CONTROL_H_INCLUDED
