#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/**
* \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
* un máximo de ' longitud - 1' caracteres .
* \ param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
* \ param longitud Define el tamaño de cadena
* \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*
*/
static int myGets ( char * cadena, int longitud);


/**
* \brief Obtiene un numero entero
* \ param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*
*/
static int getInt ( int * pResultado);


/**
* \brief Verifica si la cadena ingresada es numerica
* \ param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 ( vardadero ) si la cadena es numerica y 0 ( falso ) si no lo es
*/
static int esNumerica ( char * cadena, int limite);


/**
* \brief Obtiene un numero flotante
* \ param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
*
*/
static int getFloat ( float * pResultado);


/**
* \brief Verifica si la cadena ingresada es flotante
* \ param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 ( vardadero ) si la cadena es flotante y 0 ( falso ) si no lo es
*/
static int esFlotante ( char * cadena, int limite);


/**
 * \brief Obtiene un string valido como nombre
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getNombre(char* pResultado,int longitud);


/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esNombre(char* cadena,int longitud);


/**
 * \brief Obtiene un string valido como descripcion
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getDescripcion(char* pResultado, int longitud);


/**
 * \brief Verifica si la cadena ingresada es una descripcion valida
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esDescripcion(char* cadena,int longitud);


/**
 * \brief Obtiene un string alfanumerico valido
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getAlfaNum(char* pResultado, int longitud);


/**
 * \brief Verifica si la cadena ingresada es alfanumerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esAlfaNum(char* cadena,int longitud);


/**
 * \brief Obtiene un string valido como caracter
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getChar(char* pResultado, int longitud);


/**
 * \brief Verifica si la cadena ingresada es un caracter (letra) valida
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esChar(char* cadena,int longitud);



static int myGets ( char * cadena, int longitud)
{
    int retorno = -1;
    char bufferString [4096];


    if (cadena != NULL && longitud >0)
    {
        fflush (stdin); // LINUX-> __fpurge o WIN-> fflush o MAC-> fpurge

        if(fgets(bufferString, sizeof(bufferString),stdin) != NULL)
        {
            if (bufferString[ strnlen (bufferString, sizeof(bufferString))-1] == '\n')
            {
                bufferString[ strnlen (bufferString, sizeof(bufferString))-1] = '\0';
            }
            if (strnlen(bufferString, sizeof(bufferString)) <= longitud)
            {
                strncpy(cadena,bufferString,longitud);
                retorno=0;
            }
        }
    }

    return retorno;
}



static int getInt ( int * pResultado)
{
    int retorno=-1;
    char buffer[64];
    if (pResultado != NULL &&
            myGets(buffer, sizeof (buffer))==0 &&
            esNumerica(buffer, sizeof (buffer)))
    {
        *pResultado = atoi (buffer);
        retorno = 0;
    }
    return retorno;
}




static int esNumerica ( char * cadena, int limite)
{
    int i=0;
    int retorno = 1;

    for(i=0; i<limite && cadena[i] != '\0'; i++)
    {
        if (i==0 && (cadena[i] == '+' || cadena[i] == '-'))
        {
            continue;
        }
        if (cadena[i] < '0' || cadena[i] > '9' )
        {
            retorno = 0;
            break ;
        }
    }

    return retorno;
}





int utn_getNumeroEntero( int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{

    int retorno = -1;
    int bufferInt;

    if(pResultado != NULL && mensaje != NULL &&  mensajeError != NULL && minimo <= maximo && reintentos >=0)
    {

        do
        {
            printf("%s", mensaje);
            if(getInt(&bufferInt) == 0 &&
                    bufferInt >= minimo &&
                    bufferInt <= maximo
              )

            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;
            }

        }
        while(reintentos >= 0);

    }

    return retorno;
}





static int getFloat ( float * pResultado)
{
    int retorno=-1;
    char buffer[64];
    if (pResultado != NULL &&
            myGets(buffer, sizeof (buffer))==0 &&
            esFlotante(buffer, sizeof (buffer)))
    {
        *pResultado = atof (buffer);
        retorno = 0;
    }
    return retorno;
}





static int esFlotante ( char * cadena, int limite)
{
    int i=0;
    int retorno = 1;
    int contadorPuntos=0;

    if(cadena != NULL && strlen(cadena)>0)
    {
        for(i=0; i<limite && cadena[i] != '\0'; i++)
        {
            if (i==0 && (cadena[i] == '+' || cadena[i] == '-' ))
            {
                continue;
            }
            if (cadena[i] < '0' || cadena[i] > '9' )
            {
                if(cadena[i] == '.' && contadorPuntos==0)
                {
                    contadorPuntos++;
                }
                else
                {
                    retorno = 0;
                    break ;
                }

            }
        }

    }

return retorno;
}



int utn_getNumeroFlotante( float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{

    int retorno = -1;
    float bufferFloat;

    if(pResultado != NULL && mensaje != NULL &&  mensajeError != NULL && minimo <= maximo && reintentos >=0)
    {

        do
        {
            printf("%s", mensaje);
            if(getFloat(&bufferFloat) == 0 &&
                    bufferFloat >= minimo &&
                    bufferFloat <= maximo
              )

            {
                *pResultado = bufferFloat;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;
            }

        }
        while(reintentos >= 0);

    }

    return retorno;
}


static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	myGets(buffer,sizeof(buffer))==0 &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}



static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}



static int getDescripcion(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	myGets(buffer,sizeof(buffer))==0 &&
    		esDescripcion(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}


static int esDescripcion(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != '.' && cadena[i] != '_' && cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9' ) )
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}



int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getDescripcion(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}




static int getAlfaNum(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	myGets(buffer,sizeof(buffer))==0 &&
    		esAlfaNum(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}


static int esAlfaNum(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


int utn_getAlfaNum(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getAlfaNum(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}



static int getChar(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	myGets(buffer,sizeof(buffer))==0 &&
    		esChar(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}



static int esChar(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


int utn_getChar(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getChar(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}
