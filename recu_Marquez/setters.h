#ifndef SETTERS_H_INCLUDED
#define SETTERS_H_INCLUDED
#include "bici.h"


/** \brief Coloca el tiempo
 *
 * \param this eBicicleta*
 * \param tiempo int
 * \return int
 *
 */
int Object_setTiempo(eBicicleta *this, int tiempo);


/** \brief coloca el tipo
 *
 * \param this eBicicleta*
 * \param tipo char*
 * \return int
 *
 */
int Object_setTipo(eBicicleta *this, char *tipo);


/** \brief coloca el dueño
 *
 * \param this eBicicleta*
 * \param duenho char*
 * \return int
 *
 */
int Object_setDuenho(eBicicleta *this, char *duenho);


/** \brief coloca el ID
 *
 * \param this eBicicleta*
 * \param id int*
 * \return int
 *
 */
int Object_setID(eBicicleta *this, int *id);

#endif // SETTERS_H_INCLUDED
