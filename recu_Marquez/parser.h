#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "LinkedList.h"


/** \brief
 *
 * \param pFile FILE*
 * \param this LinkedList*
 * \return int
 *
 */
int parser_ObjectFromText(FILE *pFile, LinkedList *this);


#endif // PARSER_H_INCLUDED
