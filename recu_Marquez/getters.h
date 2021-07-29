#ifndef GETTERS_H_INCLUDED
#define GETTERS_H_INCLUDED



/** \brief obtengo los datos TIPO
 *
 * \param this eBicicleta*
 * \param tipo char*
 * \return int
 *
 */
int Object_getTipo(eBicicleta *this, char *tipo);


/** \brief obtengo dato TIEMPO
 *
 * \param this eBicicleta*
 * \param tiempo int*
 * \return int
 *
 */
int Object_getTiempo(eBicicleta *this, int *tiempo);


/** \brief Obtengo dato Duenho
 *
 * \param this eBicicleta*
 * \param duenho char*
 * \return int
 *
 */
int Object_getDuenho(eBicicleta *this, char *duenho);


/** \brief
 *
 * \param this eBicicleta*
 * \param id int*
 * \return int
 *
 */
int Object_getID(eBicicleta *this, int *id);


#endif // GETTERS_H_INCLUDED
