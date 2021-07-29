#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "bici.h"


/** \brief
 *
 * \param void*bici
 * \return void*
 *
 */
void* tiempoSeteado(void*bici);

/** \brief
 *
 * \param void*bici
 * \return int
 *
 */
int filterBMX(void*bici);

/** \brief
 *
 * \param void*bici
 * \return int
 *
 */
int filterMTB(void*bici);

/** \brief
 *
 * \param void*bici
 * \return int
 *
 */
int filterPLAYERA(void*bici);

/** \brief
 *
 * \param void*bici
 * \return int
 *
 */
int filterPASEO(void*bici);


#endif // INFORMES_H_INCLUDED
