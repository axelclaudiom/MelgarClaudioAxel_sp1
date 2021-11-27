#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED

#endif // INPUTS_H_INCLUDED

/**
* \brief Solicita un numero al usuario , leuego de verificarlo devuelve el resultado
* \ param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \ param mensaje Es el mensaje a ser mostrado
* \ param mensajeError Es el mensaje de Error a ser mostrado
* \ param minimo Es el numero maximo a ser aceptado
* \ param maximo Es el minimo minimo a ser aceptado
* \return Retorna 0 si se obtuvo el numero y -1 si no
*/

int utn_getNumeroEntero( int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/**
* \brief Solicita un numero flotante al usuario , luego de verificarlo devuelve el resultado
* \ param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \ param mensaje Es el mensaje a ser mostrado
* \ param mensajeError Es el mensaje de Error a ser mostrado
* \ param minimo Es el numero maximo a ser aceptado
* \ param maximo Es el minimo minimo a ser aceptado
* \return Retorna 0 si se obtuvo el numero flotante y -1 si no
*/
int utn_getNumeroFlotante( float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);


/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);


/**
 * \brief Solicita una descripcion al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);


/**
 * \brief Solicita ingreso alfanumerico al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el valor alfanumerico y -1 si no
 *
 */
int utn_getAlfaNum(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);


/**
 * \brief Solicita ingreso alfanumerico al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el valor alfanumerico y -1 si no
 *
 */
int utn_getChar(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
