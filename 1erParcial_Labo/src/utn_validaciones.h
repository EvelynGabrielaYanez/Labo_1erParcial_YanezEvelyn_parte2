/*
 * utn_validaciones.h
 *
 *  Created on: 25 sep. 2020
 *      Author: CLEM
 */

#ifndef UTN_VALIDACIONES_H_
#define UTN_VALIDACIONES_H_



#endif /* UTN_VALIDACIONES_H_ */
/**@brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 *
 * @param pResultado Int Puntero al espacio de meoria donde se dejara el resultado de la funcion
 * @param mensaje Es el mensaje a ser mostrado
 * @param mensajeError Es el mensaje de Error a ser mostrado
 * @param minimo Es el numero minimo a ser aceptado (inclusive)
 * @param maximo Es el numero maximo a ser aceptado (inclusive)
 * @param reintentos Int. Es la cantidad de reintentos que tendra el usuario
 * @return Int. Retorna 0 si si se obtuvo el numero (EXITO) y -1 si no (ERROR)
 */
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos) ;
/**@brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 *
 * @param pResultado Int Puntero al espacio de meoria donde se dejara el resultado de la funcion
 * @param mensaje Es el mensaje a ser mostrado
 * @param mensajeError Es el mensaje de Error a ser mostrado
 * @param minimo Es el numero minimo a ser aceptado (Sin incluir)
 * @param reintentos Int. Es la cantidad de reintentos que tendra el usuario
 * @return Int. Retorna 0 si si se obtuvo el numero (EXITO) y -1 si no (ERROR)
 */
int utn_getNumeroMin(int *pResultado, char *mensaje, char *mensajeError, int minimo,  int reintentos);
/**@brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 *
 * @param pResultado Float Puntero al espacio de meoria donde se dejara el resultado de la funcion
 * @param mensaje Es el mensaje a ser mostrado
 * @param mensajeError Es el mensaje de Error a ser mostrado
 * @param minimo Es el numero minimo a ser aceptado (inclusive)
 * @param maximo Es el numero maximo a ser aceptado (inclusive)
 * @param reintentos Int. Es la cantidad de reintentos que tendra el usuario
 * @return Int. Retorna 0 si si se obtuvo el numero (EXITO) y -1 si no (ERROR)
 */
int utn_getNumeroConDecimales(float *pResultado, char *mensaje, char *mensajeError,float minimo, float maximo, int reintentos) ;
/**@brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 *
 * @param pResultado Float Puntero al espacio de meoria donde se dejara el resultado de la funcion
 * @param mensaje Es el mensaje a ser mostrado
 * @param mensajeError Es el mensaje de Error a ser mostrado
 * @param minimo Es el numero minimo a ser aceptado (sin incluir)
 * @param reintentos Int. Es la cantidad de reintentos que tendra el usuario
 * @return Int. Retorna 0 si si se obtuvo el numero (EXITO) y -1 si no (ERROR)
 */
int utn_getNumeroConDecimalesMin(float *pResultado, char *mensaje, char *mensajeError,float minimo, int reintentos);
/**@brief Solicita una cadena de caracteres al usuario, luego de verificarlo devuelve el resultado
 *
 * @param arrayCarateres Array de caracteres donde se dejara el resultado de la funcion
 * @param largo Int. Cantidad de caracteres que se espera del usuario mas 1 (cantidad + 1 )
 * @param mensaje Es el mensaje a ser mostrado
 * @param mensajeError Es el mensaje de Error a ser mostrado
 * @param reintentos Int. Es la cantidad de reintentos que tendra el usuario
 * @return Int. Retorna 0 si si se obtuvo el numero (EXITO) y -1 si no (ERROR)
 */
int utn_getTexto(char * arrayCarateres, int largo, char *mensaje,char *mensajeError, int reintentos);
/**@brief Solicita una cadena de caracteres al usuario, luego de verificarlo devuelve el resultado
 *
 * @param arrayCarateres Array de caracteres donde se dejara el resultado de la funcion
 * @param largo Int. Cantidad de caracteres que se espera del usuario mas 1 (cantidad + 1 )
 * @param mensaje Es el mensaje a ser mostrado
 * @param mensajeError Es el mensaje de Error a ser mostrado
 * @param reintentos Int. Es la cantidad de reintentos que tendra el usuario
 * @return Int. Retorna 0 si si se obtuvo el numero (EXITO) y -1 si no (ERROR)
 */
int utn_getTextoSoloLetras(char * arrayCarateres, int largo, char *mensaje,char *mensajeError, int reintentos);
/**@brief Solicita al usuario el ingreso de uno de los dos caracteres afirmativo o negativo, lo valida
 * 			y retorna verdadero para si y falso para no.
 *
 * @param mensaje Es el mensaje a ser mostrado.
 * @param caracterParaSi Es el caracter afirmativo que se le pedira al usuario.
 * @param caracterParaNo Es el caracter negativo que se le pedira al usuario.
 * @return Int. Retorna 0 para respuesta negativa y 1 para respuesta positiva.
 */
int unt_preguntaRespuestaBinaria(char * mensaje, char caracterParaSi, char caracterParaNo);
/**@brief Solicita al usuario el ingreso de uno de los dos caracteres afirmativo o negativo, lo valida
 * 			y retorna 0 en caso de EXITO y -1 en caso de ERROR [puntero nulo, reintentos invalido o
 * 			sin reintentos]
 *
 * @param mensaje Es el mensaje a ser mostrado.
 * @param caracterParaSi Es el caracter afirmativo que se le pedira al usuario.
 * @param caracterParaNo Es el caracter negativo que se le pedira al usuario.
 * @param reintentos
 * @return
 */
int utn_tomarIngresoBinario(char *pRespuesta, char *mensaje, char *mensajeError,char caracterParaSi, char caracterParaNo, int reintentos) ;
/**@brief Solicita al usuario el ingreso de una fecha de formato dd/mm/aaa, la valida y
 * 		  devuelve el dia, mes y año en caso de ser correctos
 *
 * @param dia Int Puntero al espacio de memoria donde se guardara el dia de la fecha ingresada
 * @param mes Int Puntero al espacio de memoria donde se guardara el mes de la fecha ingresada
 * @param anio Int Puntero al espacio de memoria donde se guardara el anio de la fecha ingresada
 * @param mensaje Es el mensaje a ser mostrado
 * @param mensajeError Es el mensaje de Error a ser mostrado
 * @param reintentos Int. Es la cantidad de reintentos que tendra el usuario
 * @return retorna (0) en caso de EXITO- (-1) en caso de ERROR [puntero nulo, reinteintos invalido
 * 		  y sin reintetos para intentar (no se ingreso correctamente)]
 */
int utn_getFecha(int * dia, int * mes, int * anio, char *mensaje, char *mensajeError,int reintentos);
/**@brief	Solicita al usuario el ingreso de un correo electronico, lo valida y devuelve la cadena ingresada.
 *
 * @param pCorreoElectronico Puntero al arrray de caracteres donde se guardara el correo ingresado
 * @param mensaje Es el mensaje a ser mostrado
 * @param mensajeError Es el mensaje de Error a ser mostrado
 * @param reintentos Int. Es la cantidad de reintentos que tendra el usuario
 * @param largo	Int, largo del array de caracteres del correo esperado
 * @return retorna (0) en caso de EXITO- (-1) en caso de ERROR [puntero nulo, reinteintos invalido
 * 		  y sin reintetos para intentar (no se ingreso correctamente)]
 */
int utn_getCorreoElectronico(char* pCorreoElectronico, char *mensaje,char *mensajeError, int reintentos, int largo) ;
/**	@brief Solicita el ingreso de un cuil, lo valida y devuelve la cadena ingresada.
 *
 * @param pCuit Puntero al arrray de caracteres donde se guardara el cuit ingresado
 * @param mensaje Es el mensaje a ser mostrado
 * @param mensajeError Es el mensaje de Error a ser mostrado
 * @param largo	Int, largo del array de caracteres del correo esperado
 * @param reintentos  Int. Es la cantidad de reintentos que tendra el usuario
 * @return retorna (0) en caso de EXITO- (-1) en caso de ERROR [puntero nulo, reinteintos invalido
 * 		  y sin reintetos para intentar (no se ingreso correctamente)]
 */
int utn_tomarCuit(char *pCuit,char *mensaje,char* mensajeError,int largo, int reintentos);
/**@brief Solicita el ingreso de un DNI, lo valida y devuelve la cadena ingresada.
 *
 * @param pDNI pCuit Puntero al arrray de caracteres donde se guardara el DNI ingresado.
 * @param mensaje Es el mensaje a ser mostrado.
 * @param mensajeError Es el mensaje de Error a ser mostrado.
 * @param largo	Int, largo del array de caracteres del correo esperado.
 * @param reintentos  Int. Es la cantidad de reintentos que tendra el usuario
 * @return retorna (0) en caso de EXITO- (-1) en caso de ERROR [puntero nulo, reinteintos invalido
 * 		  y sin reintetos para intentar (no se ingreso correctamente)]
 */
int utn_tomarDNI(char *pDNI,char *mensaje,char* mensajeError,int largo, int reintentos);
