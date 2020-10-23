/*
 * utn_validaciones.c
 *
 *  Created on: 25 sep. 2020
 *      Author: CLEM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

static int myGets(char *cadena, int longitud);
static int esNumerica(char *cadena);
static int getInt(int *pResultado);

static int getFloat(float *pResultado);
static int esNumeroDecimal(char *cadena);

static int getString(char *pResultado, int largo);
static int getStringSoloLetras(char *pResultado, int largo);
static int esSoloLetras(char *cadena);

static int esFecha(char *cadena, int *dia, int *mes, int *anio);
static int getStringFecha(int *pResultadoDia, int *pResultadoMes,int *pResultadoAnio);


static int esCorreoElectronico(char *pCorreoElectronico);
static int getCorreoElectronico(char *pCorreoElectronico, int largo);

static int getCuit(char *pCuit,int largo);

static int getDNI(char *pCuit, int largo);

/**@brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 *		  un maximo de 'longitud -1' caracteres
 * @param cadena Puntero al espacio de memoria donde se copia la cadena obtenida
 * @param longitud Define el tamaño de la cadena
 * @return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 */
static int myGets(char *cadena, int longitud) {

	int vRetorno = 1;

	if (cadena != NULL && longitud > 0
			&& fgets(cadena, longitud, stdin) == cadena && cadena[0]!='\n') {

		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n') {

			cadena[strlen(cadena) - 1] = '\0';

		}
		vRetorno = 0;
	}
	return vRetorno;
}


/**@brief Obtiene un numero entero desde la terminal
 *
 * @param pResultado Int. Puntero al espacio de meoria donde se dejara el resultado de la funcion
 * @return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int getInt(int *pResultado) {

	int vRetorno = -1;
	char buffer[64];
	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)) {
			*pResultado = atoi(buffer);
			vRetorno = 0;
		}
	}
	return vRetorno;

}
/**@brief Verifica dsi la cadena ingresada es numerica
 *
 * @param Cadena. Cadena de caracteres a ser analizada
 * @return Retorna 1 (verdadero) si la cadena es numerica y 0 (falso) si no lo es
 */
static int esNumerica(char *cadena) {

	int i = 0;
	int vRetorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {

		if (cadena[i] == '-') {
			i = 1;
		}

		while (cadena[i] != '\0') {
			if (cadena[i] < '0' || cadena[i] > '9') {
				vRetorno = 0;
				break;
			}
			i++;
		}
	}
	return vRetorno;
}

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {

	int vRetorno = -1;
	int vBuffer;
	int vBanderaReintentos = 1;

	if (reintentos == 0) {
		vBanderaReintentos = 0;
	}

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
		do {
			printf(mensaje);

			if (vBanderaReintentos == 1) {

				printf("(tiene %d intentos) ", reintentos);

			}

			if (getInt(&vBuffer) == 0 && vBuffer >= minimo && vBuffer <= maximo) {
				*pResultado = vBuffer;
				vRetorno = 0;
				break;
			}
			reintentos--;
			printf(mensajeError);
			printf("\n");
			system("pause");

		} while (reintentos >= 0);

	}

	return vRetorno;
}
int utn_getNumeroMin(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int reintentos) {

	int vRetorno = -1;
	int vBuffer;
	int vBanderaReintentos = 1;

	if (reintentos == 0) {
		vBanderaReintentos = 0;
	}

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& reintentos >= 0) {
		do {
			printf(mensaje);

			if (vBanderaReintentos == 1) {

				printf("(tiene %d intentos) ", reintentos);

			}

			if (getInt(&vBuffer) == 0) {
				if (vBuffer > minimo) {
					*pResultado = vBuffer;
					vRetorno = 0;
					break;
				}
			}
			reintentos--;
			printf(mensajeError);
			printf("\n");
			system("pause");

		} while (reintentos >= 0);

	}

	return vRetorno;
}
/**@brief Obtiene un numero entero desde la terminal
 *
 * @param pResultado Float. Puntero al espacio de meoria donde se dejara el resultado de la funcion
 * @return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int getFloat(float *pResultado) {

	int vRetorno = -1;
	char vBuffer[4096];

	if (pResultado != NULL) {
		if (myGets(vBuffer, sizeof(vBuffer)) == 0 && esNumeroDecimal(vBuffer)) {

			*pResultado = atof(vBuffer);
			vRetorno = 0;

		}
	}
	return vRetorno;
}
/**@brief Verifica dsi la cadena ingresada es numerica decimal
 *
 * @param Cadena. Cadena de caracteres a ser analizada
 * @return Retorna 1 (verdadero) si la cadena es numerica y 0 (falso) si no lo es
 */
static int esNumeroDecimal(char *cadena) {

	int vRetorno = 1;
	int i = 0;
	int vContadorPuntos = 0;

	if (cadena != NULL && strlen(cadena) > 0) {

		if (cadena[i] == '-') {
			i = 1;
		}

		while (cadena[i] != '\0') {

			if (cadena[i] == '.') {
				vContadorPuntos++;
			}

			if ((cadena[i] < '0' || cadena[i] > '9' || vContadorPuntos > 1)
					&& cadena[i] != '.') {
				vRetorno = 0;
				break;
			}
			i++;
		}
	}

	return vRetorno;
}

int utn_getNumeroConDecimales(float *pResultado, char *mensaje,
		char *mensajeError, float minimo, float maximo, int reintentos) {

	int vRetorno = -1;
	float vBuffer;
	int vBanderaReintentos = 1;

	if (reintentos == 0) {

		vBanderaReintentos = 0;
	}

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
		do {
			printf(mensaje);

			if (vBanderaReintentos == 1) {

				printf("(tiene %d intentos) ", reintentos);

			}

			if (getFloat(&vBuffer) == 0) {
				if (vBuffer >= minimo && vBuffer <= maximo) {
					*pResultado = vBuffer;
					vRetorno = 0;
					break;
				}
			}
			reintentos--;
			printf(mensajeError);
			printf("\n");
			system("pause");

		} while (reintentos >= 0);

	}

	return vRetorno;

}

int utn_getNumeroConDecimalesMin(float *pResultado, char *mensaje,
		char *mensajeError, float minimo, int reintentos) {

	int vRetorno = -1;
	float vBuffer;
	int vBanderaReintentos = 1;

	if (reintentos == 0) {

		vBanderaReintentos = 0;
	}

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& reintentos >= 0) {
		do {
			printf(mensaje);

			if (vBanderaReintentos == 1) {

				printf("(tiene %d intentos) ", reintentos);

			}

			if (getFloat(&vBuffer) == 0) {
				if (vBuffer >= minimo) {
					*pResultado = vBuffer;
					vRetorno = 0;
					break;
				}
			}
			reintentos--;
			printf(mensajeError);
			printf("\n");
			system("pause");

		} while (reintentos >= 0);

	}

	return vRetorno;

}
/**@brief Obtiene una cadena de caracteres desde la terminal
 *
 * @param pResultado Cadena de caracteres. Puntero al espacio de meoria donde se dejara el resultado de la funcion
 * @param largo int largo de la cadena que espero recibir
 * @return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int getString(char *pResultado, int largo) {

	int vRetorno = -1;
	char vBuffer[4096];

	if (pResultado != NULL) {
		if (myGets(vBuffer, sizeof(vBuffer)) == 0 && strlen(vBuffer) < largo) {

			strcpy(pResultado, vBuffer);

			vRetorno = 0;

		}
	}
	return vRetorno;
}
int utn_getTexto(char *arrayCarateres, int largo, char *mensaje,
		char *mensajeError, int reintentos) {

	char vBuffer[255];
	int vRetorno = -1;
	int vBanderaReintentos = 1;

	if (reintentos == 0) {
		vBanderaReintentos = 0;
	}

	if (arrayCarateres != NULL && mensaje != NULL && mensajeError != NULL
			&& largo > 0 && reintentos >= 0) {

		do {

			printf("%s", mensaje);

			if (vBanderaReintentos == 1) {

				printf(" (tiene %d intentos) ", reintentos);

			}

			if (getString(vBuffer, largo) == 0) {
				strcpy(arrayCarateres, vBuffer);
				vRetorno = 0;
				break;
			}
			reintentos--;
			printf(mensajeError);
			printf("\n");
			system("pause");
		} while (reintentos >= 0);
	}

	return vRetorno;
}
/**@brief Obtiene un numero entero desde la terminal
 *
 * @param pResultado Cadena de caracteres. Puntero al espacio de meoria donde se dejara el resultado de la funcion
 * @param largo int largo de la cadena que espero recibir
 * @return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int getStringSoloLetras(char *pResultado, int largo) {

	int vRetorno = -1;
	char vBuffer[4096];

	if (pResultado != NULL) {
		if (myGets(vBuffer, sizeof(vBuffer)) == 0 && esSoloLetras(vBuffer) == 1
				&& strlen(vBuffer) < largo) {

			strcpy(pResultado, vBuffer);

			vRetorno = 0;

		}
	}

	return vRetorno;

}
/**@brief Verifica dsi la cadena ingresada es solo de letras
 *
 * @param Cadena. Cadena de caracteres a ser analizada
 * @return Retorna 1 (verdadero) si la cadena es numerica y 0 (falso) si no lo es
 */
static int esSoloLetras(char *cadena) {

	int vRetorno = 1;
	int i = 1;

	if (cadena != NULL && strlen(cadena) > 0) {

		while (cadena[i] != '\0') {

			if (cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z')
					&& (cadena[i] < 'a' || cadena[i] > 'z')) {
				vRetorno = 0;
				break;
			}
			i++;
		}
	}

	return vRetorno;
}
int utn_getTextoSoloLetras(char *arrayCarateres, int largo, char *mensaje,
		char *mensajeError, int reintentos) {

	char vBuffer[255];
	int vRetorno = -1;
	int vBanderaReintentos = 1;

	if (reintentos == 0) {
		vBanderaReintentos = 0;
	}

	if (arrayCarateres != NULL && mensaje != NULL && mensajeError != NULL
			&& largo > 0 && reintentos >= 0) {

		do {

			printf("%s", mensaje);

			if (vBanderaReintentos == 1) {

				printf("(tiene %d intentos) ", reintentos);

			}

			if (getStringSoloLetras(vBuffer, largo) == 0) {
				strcpy(arrayCarateres, vBuffer);
				vRetorno = 0;
				break;
			}

			reintentos--;
			printf("%s", mensajeError);
			printf("\n");
			system("pause");
		} while (reintentos >= 0);
	}

	return vRetorno;
}
int unt_preguntaRespuestaBinaria(char *mensaje, char caracterParaSi,
		char caracterParaNo)
{

	char vRespuestaVolver;
	int vRetorno = 0;

	printf("%s ( %c / %c ):", mensaje, caracterParaSi, caracterParaNo);
	fflush(stdin);
	vRespuestaVolver = getch();

	if (vRespuestaVolver == caracterParaSi) {
		vRetorno = 1;
	} else if (vRespuestaVolver == caracterParaNo) {
		vRetorno = 0;
	} else {
		vRetorno = -1;
	}

	return vRetorno;
}

int utn_tomarIngresoBinario(char *pRespuesta, char *mensaje, char *mensajeError,
		char caracterParaSi, char caracterParaNo, int reintentos) {

	char vRespuestaBinaria;
	int vRetorno = -1;
	int vBanderaReintentos = 1;

	if (reintentos == 0) {
		vBanderaReintentos = 0;
	}

	if (pRespuesta != NULL && mensaje != NULL && reintentos > 0) {
		do {

			printf("%s ( %c / %c ):", mensaje, caracterParaSi, caracterParaNo);
			if (vBanderaReintentos == 1) {

				printf(" (tiene %d intentos) ", reintentos);

			}
			fflush(stdin);

			vRespuestaBinaria = getch();

			if (vRespuestaBinaria == caracterParaSi
					|| vRespuestaBinaria == caracterParaNo) {
				*pRespuesta = vRespuestaBinaria;
				vRetorno = 0;
				break;
			}

			printf(mensajeError);
			reintentos--;
		} while (reintentos >= 0);
	}
	return vRetorno;

}

static int esFecha(char *cadena, int *dia, int *mes, int *anio) {

	int vRetorno = 0;
	int i = 0;
	char vDia[3];
	char vMes[3];
	char vAnio[5];
	int numDia;
	int numMes;
	int numAnio;
	//char prueba;

	if (cadena != NULL && strlen(cadena) > 0) {

		while (cadena[i] != '\0') {

			if ((i != 2 && i != 5 && (cadena[i] < '0' || cadena[i] > '9'))
					|| (i > 10 || ((i == 2 || i == 5) && cadena[i] != '/'))) {
				vRetorno = -1;
				break;
			}


			switch (i) {
			case 0:
			case 1:
				vDia[i]= cadena[i];
				break;
			case 2:
				vDia[i]= '\0';
				break;
			case 3:
			case 4:
				vMes[i-3]= cadena[i];
				break;
			case 5:
				vMes[i-3]= '\0';
				break;
			case 6:
				strcpy(vAnio, &cadena[i]);
				break;
			}

			i++;
		}

		if (vRetorno == 0) {//si pasó la primer parte del control
			numDia = atoi(vDia);
			numMes = atoi(vMes);
			numAnio = atoi(vAnio);

			if (numMes >= 1 && numMes <= 12) {
				switch (numMes) {
				case 4:
				case 6:
				case 9:
				case 11:
					if (numDia < 1 && numDia > 30) {
						vRetorno = -1;
					}
					break;
				case 2:
					if (numAnio % 4 == 0 && numDia < 1 && numDia > 28) {
						vRetorno = -1;
					} else if (numAnio % 4 != 0 && numDia < 1 && numDia > 29) {
						vRetorno = -1;
					}
					break;
				default:
					if (numDia < 1 || numDia > 31) {
						vRetorno = -1;
					}
					break;
				}

				if (vRetorno == 0)
				{
					*dia = numDia;
					*mes = numMes;
					*anio = numAnio;
				}

			}
		}
	}

	return vRetorno;
}

static int getStringFecha(int *pResultadoDia, int *pResultadoMes,int *pResultadoAnio) {

	int vRetorno = -1;
	char vBuffer[4096];
	int vBufferDia;
	int vBufferMes;
	int vBufferAnio;

	if (pResultadoDia != NULL && pResultadoMes != NULL && pResultadoAnio != NULL) {
		if (myGets(vBuffer, sizeof(vBuffer)) == 0
				&& esFecha(vBuffer, &vBufferDia, &vBufferMes, &vBufferAnio) == 0
				&& strlen(vBuffer) < 11) {

			*pResultadoDia = vBufferDia;
			*pResultadoMes = vBufferMes;
			*pResultadoAnio = vBufferAnio;
			vRetorno=0;
		}
	}

	return vRetorno;

}
int utn_getFecha(int *dia, int *mes, int *anio, char *mensaje,
		char *mensajeError, int reintentos) {

	int vRetorno = -1;
	int vBanderaReintentos = 1;

	if (reintentos == 0) {
		vBanderaReintentos = 0;
	}


	if (dia != NULL && mes != NULL && anio != NULL && mensaje != NULL
			&& mensajeError != NULL && reintentos >= 0) {

		do {
			printf(mensaje);
			if (vBanderaReintentos == 1) {

				printf(" (tiene %d intentos) ", reintentos);

			}

			if (getStringFecha(dia, mes, anio) == 0)
			{
				vRetorno = 0;
				break;
			}

			printf(mensajeError);
			reintentos--;

		} while (reintentos >= 0);
	}
	return vRetorno;

}
static int esCorreoElectronico(char *pCorreoElectronico)
{
	int vRetorno = 0;
	int i = 0;
	int vBanderaArroba ;
	int vPosicionPunto;

	if (pCorreoElectronico != NULL && strlen(pCorreoElectronico) > 0) {

		vPosicionPunto = strlen(pCorreoElectronico)-4;

		while (pCorreoElectronico[i] != '\0') {

			if ((pCorreoElectronico[i] < 'A' || pCorreoElectronico[i] > 'Z') &&
					(pCorreoElectronico[i] < 'a' || pCorreoElectronico[i] > 'z') &&
					(pCorreoElectronico[i] < '0' || pCorreoElectronico[i] > '9') &&
					(((pCorreoElectronico[i] == '@' || pCorreoElectronico[i] == '.') && i==0 ) ||
					( (pCorreoElectronico[i] != '_' && pCorreoElectronico[i] != '.' ) &&
							(pCorreoElectronico[i] == '@' && vBanderaArroba == 1 ) && i>0 )))
			{
					vRetorno = -1;
					break;
			}

			if(pCorreoElectronico[i]== '@' &&  vBanderaArroba == 0 )
			{
				vBanderaArroba = 1;
			}
			if(i == vPosicionPunto && !strstr(&pCorreoElectronico[vPosicionPunto], ".com")){
				vRetorno = -1;
				break;
			}
		}
		i++;
	}

	return vRetorno;
}
static int getCorreoElectronico(char *pCorreoElectronico, int largo)
{
	int vRetorno = -1;
	char vBuffer[4096];

	if (pCorreoElectronico != NULL) {
		if (myGets(vBuffer, sizeof(vBuffer)) == 0
				&& esCorreoElectronico(vBuffer) == 0
				&& strlen(vBuffer)<largo) {

			strcpy(pCorreoElectronico,vBuffer);

			vRetorno = 0;

		}
	}

	return vRetorno;
}

int utn_getCorreoElectronico(char* pCorreoElectronico, char *mensaje,
		char *mensajeError, int reintentos, int largo) {

	int vRetorno = -1;
	int vBanderaReintentos = 1;

	if (reintentos == 0) {
		vBanderaReintentos = 0;
	}


	if (pCorreoElectronico != NULL && mensaje != NULL
			&& mensajeError != NULL && reintentos >= 0 && largo>0) {

		do {
			printf(mensaje);
			if (vBanderaReintentos == 1) {

				printf(" (tiene %d intentos) ", reintentos);

			}

			if (getCorreoElectronico(pCorreoElectronico,largo) == 0)
			{
				vRetorno = 0;
				break;
			}

			printf(mensajeError);
			reintentos--;

		} while (reintentos >= 0);

	}

	return vRetorno;
}
static int getCuit(char *pCuit,int largo)
{
	int vRetorno = -1;
	char vBuffer[4096];

	if (pCuit != NULL && largo>0) {
		if (myGets(vBuffer, sizeof(vBuffer)) == 0
				&& strlen(vBuffer) == 11 && esNumerica(vBuffer) == 0
				&& strlen(vBuffer)<largo)
		{
			strcpy(pCuit,vBuffer);
			vRetorno = 0;
		}
	}

	return vRetorno;
}

int utn_tomarCuit(char *pCuit,char *mensaje,char* mensajeError,int largo, int reintentos){

	int vRetorno = -1;

    if( pCuit!=NULL && mensaje!=NULL && largo>0 && reintentos >= 0 && mensajeError!= NULL){

    	do {
    		printf("%s",mensaje);
    		if(getCuit(pCuit,largo)==1){
    			vRetorno=0;
    			break;
    		}
			printf("%s",mensajeError);
    		reintentos--;
    	} while(reintentos>=0);

    }

    return vRetorno;
}

static int getDNI(char *pCuit, int largo)
{
	int vRetorno = -1;
	char vBuffer[4096];

	if (pCuit != NULL && largo>0)
	{
		if (myGets(vBuffer, sizeof(vBuffer)) == 0
				&& strlen(vBuffer) == 8
				&& esNumerica(vBuffer) == 0
				&& strlen(vBuffer)<largo)
		{
			strcpy(pCuit,vBuffer);
			vRetorno = 0;
		}
	}

	return vRetorno;
}

int utn_tomarDNI(char *pDNI,char *mensaje,char* mensajeError,int largo, int reintentos){

	int vRetorno = -1;

    if( pDNI!=NULL && mensaje!=NULL && largo>0 && reintentos >= 0 && mensajeError!=NULL){

    	do {
    		printf("%s",mensaje);
    		if(getDNI(pDNI,largo)==1){
    			vRetorno=0;
    			break;
    		}
			printf("%s",mensajeError);
    		reintentos--;
    	} while(reintentos>=0);

    }

    return vRetorno;
}
