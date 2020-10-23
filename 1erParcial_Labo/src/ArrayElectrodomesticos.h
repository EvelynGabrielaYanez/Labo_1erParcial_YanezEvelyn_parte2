/*
 * ArrayElectrodomesticos.h
 *
 *  Created on: 15 oct. 2020
 *      Author: CLEM
 */
#include "ArrayMarca.h"

#ifndef ARRAYELECTRODOMESTICOS_H_
#define ARRAYELECTRODOMESTICOS_H_

 typedef struct{

	int id;
	char serie[11];
	int idMarca;
	int modelo;
	int estaVacio;

} eElectrodomesticos;

#endif /* ARRAYELECTRODOMESTICOS_H_ */

/** @brief Para indicar que todas las posiciones en el array estan vacias,
 * 		   esta funcion pone la bandera (isEmty) en verdadero (1) en todas
 *         las posiciones del array.
 *
 * @param listaElectrodomesticos  Puntero al array de electrodomesticos
 * @param largoMarcas int Array Largo del array de electrodomesticos
 * \return int Retorna (-1) en caso de ERROR [largo invalido o puntero nulo] - (0) en caso de EXITO
 *
 */
int inicializarElectrodomesticos(eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos);
/** @brief Añade a una lista existente de electrodomesticos los valores recibidos como parametros
 *		   en la primer posicion vacia.
 *
 * @param listaElectrodomesticos Puntero al array de electrodomesticos
 * @param largoElectrodomesticos Largo del array de electrodomesticos
 * @param electrodomesticoIngresado eElectrodomestico. Electrodometico ingresado.
 * @return int Retorna (-1) en caso de ERROR [Largo invalido, puntero nulo o sin espacio libre]
 */
int agregarElectrodomesticos(eElectrodomesticos *listaElectrodomesticos, int largoElectrodomesticos, eElectrodomesticos electrodomesticoIngresado);
/** @brief Busca un Electrodomesticos por Id y devuelve la posicion del indice del Array.
 *
 * @param listaElectrodomesticos Puntero al array de Electrodomesticos
 * @param largoElectrodomesticos Int Largo del array de Electrodomesticos
 * @param id Int ID del electrodomestico a agregar
 * @return  Int Retorna la posicion del indice del Electrodomesticos o (-1) si [Largo invalido o puntero
 *  nulo o empleado no encontrado]
 *
 */
int buscarElectrodomesticosPorId(eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos,int id);
/** @brief Remueve a un Empleado por Id (pone la bandera isEmpty en 1).
 *
 * @param listaElectrodomesticos Puntero al array de Electrodomesticos
 * @param largoElectrodomesticos int Largo del array de Electrodomesticos
 * @param id int ID del electrodomestico a eliminar
 * @return int Retorna (-1) si ERROR [Largo invalido o puntero nulo o
 * si no puede encontrar el empleado]  - (0) en caso de EXITO
 */
int removerElectrodomesticos(eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos, int id);
/**@brief   Ordena los elementos en el Array de Electrodomesticos, el argumento
 * de orden indica orden ascendente u orden descendente.
 *
 * @param listaElectrodomesticos  Puntero al array de Electrodomesticos.
 * @param largoElectrodomesticos Int Largo del array de Electrodomesticos.
 * @param listadoMarcas  Puntero al array de Marcas.
 * @param largoMarcas Int Largo del array de Marcas.
 * @param orden int [1] indica ASCENDENTE - [0] indica DESCENDENTE
 * @return int Retorna (-1) en caso de ERROR [Largo invalido o puntero
 * nulo] - (0) en caso de EXITO
 */
int ordenarElectrodomesticos(eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos, eMarca* listadoMarcas,int largoMarcas, int orden);
/**@brief Imprime el contenido del Array de Electrodomesticos.
 *
 * @param listaElectrodomesticos  Puntero al array de Electrodomesticos.
 * @param largoElectrodomesticos Int Largo del array de Electrodomesticos.
 * @param listaMarcas Puntero al array de Marcas.
 * @param largoMarcas Int Largo del array de Marcas.
 * @return int Retorna (-1) en caso de ERROR [Largo invalido, puntero nulo
 * u orden invalido]
 */
int imprimirElectrodomesticos(eElectrodomesticos *listaElectrodomesticos, int largoElectrodomesticos,eMarca* listaMarcas, int largoMarcas) ;
/**@brief Imprime el electrodomestico de la posicion que le pasan.
 *
 * @param posicion	Int posicion a mostrar
 * @param listaElectrodomesticos  Puntero al array de Electrodomesticos.
 * @param largoElectrodomesticos Int Largo del array de Electrodomesticos.
 * @param listaMarcas Puntero al array de Marcas.
 * @param largoMarcas Int Largo del array de Marcas.
 * @return int Retorna (-1) en caso de ERROR [Largo invalido, puntero nulo
 * u orden invalido]
 */
int imprimirElectrodomestico(int posicion,eElectrodomesticos *listaElectrodomesticos, int largoElectrodomesticos,eMarca* listaMarcas, int largoMarcas);
/**@brief Retorna el precio promedio del Array de Electrodomesticos
 *
 * @param listaElectrodomesticos  Puntero al array de Electrodomesticos.
 * @param largoElectrodomesticos Int Largo del array de Electrodomesticos.
 * @param promedio Puntero a entero donde retorna el promedio de precio
 * @return int Retorna (-1) en caso de ERROR [Largo invalido, puntero nulo
 * u orden invalido]
 */
int sueldoPromedioElectrodomesticos(eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos, float *promedio);
/**@brief Busca si hay algun electrodomestico cargado en el array y devuelve true (1)
 * si lo encuentra y (0)false si no
 *
 * @param listaElectrodomesticos Puntero al array de empleados
 * @param largoElectrodomesticos int Largo del array de empleados
 * @return  Retorna (-1) en caso de Error [Largo invalido o puntero nulo o si no
 * 		   hay empleado cargado] - (0) en caso de encontrar al menos un empeleado
 * 		   cargado.
 */
int hayElectrodomesticoCargado(eElectrodomesticos *listaElectrodomesticos, int largoElectrodomesticos);
/**@brief	Hardcodea un maximo de 10 electrodomesticos y retorna la cantidad hardodeada.
 *
 * @param lista Puntero al array de empleados
 * @param largo int Largo del array de empleados
 * @param cantidad	Int Cantidad de electrodomesticos que se van a hardcodear
 * @return Retorna	(-1) en caso de error - (cantiadad de hardcodeados) en caso de EXITO
 */
int hardcodearElectrodomesticos(eElectrodomesticos* listaElectrodomesticos ,int largoElectrodomesticos , int cantidad);
/**@brief	Valida la existencia del numero de serie dentro del listado de electrodomesticos
 *
 * @param listadoElectrodomestico Puntero al array de empleados
 * @param largoElectrodomestico Int Largo del array de empleados
 * @param serie	Cadena de caracteres de la serie a validar.
 * @return Retorna	(-1) en caso de error - (cantiadad de hardcodeados) en caso de EXITO
 */
int validarSerieElectrodomestico(eElectrodomesticos *listadoElectrodomestico, int largoElectrodomestico,
		char* serie) ;
/**@brief	Pide el ingreso de la serie del electrodomestico por pantalla mostrando las opciones,
 * 			valida su existencia en la tabla de empleados. Y retorna el ingreso por el puntero deretorno.
 *
 * @param pSerieResultado Puntero donde retornara la serie ingresada
 * @param mensaje	Cadena de caracetres con el mensaje a mostrar
 * @param mensajeError	Cadena de caracetres con el mensaje de error a mostrar
 * @param listadoElectrodomestico Puntero al array de electrodomesticos
 * @param largoElectrodomestico Int Largo del array de electrodomesticos
 * @param reintentos	Int cantidad de reintentos que tendra el usuario para ingresar
 * @param listadoMarcas	Puntero al array de marcas.
 * @param largoMarcas	Int,largo del array de marcas.
 * @return Retorna	(-1) en caso de error - (0) en caso de EXITO
 */
int pedirElectrodomesticoPorSerie(char *pSerieResultado, char *mensaje, char *mensajeError ,eElectrodomesticos *listadoElectrodomestico,
		int largoElectrodomestico, int reintentos,eMarca * listadoMarcas,int largoMarcas);
/**@brief	Pide la serie por pantalla, valida que no este cargado en el listado de electrodomestico y
 *			que sea un numero de serie valido. De ser asñi lo devuelve por puntero. Caso contrario devuelve error.
 *
 * @param listadoElectrodomesticos Puntero al array de electrodomesticos.
 * @param largoElectrodomesticos Int Largo del array de electrodomesticos.
 * @param largoSerie	Int largo del array de series.
 * @param mensaje	Cadena de caracetres con el mensaje a mostrar.
 * @param mensajeError	Cadena de caracetres con el mensaje de error a mostrar.
 * @param reintentos	Int cantidad de reintentos que tendra el usuario para ingresar.
 * @param pRetornoSerie Puntero donde retornara la serie ingresada.
 * @return Retorna	(-1) en caso de error - (0) en caso de EXITO
 */
int pedirSeriePorPantalla(eElectrodomesticos* listadoElectrodomesticos, int largoElectrodomesticos, int largoSerie,
							char * mensaje, char * mensajeError, int reintentos, char * pRetornoSerie);
/**@brief Busca la posicion del electrodomestico segun su serie y en caso de existir la retorna.
 *
 * @param listaElectrodomesticos Puntero al array de electrodomesticos.
 * @param largoElectrodomesticos Int Largo del array de electrodomesticos.
 * @param serie	Cadena de caracteres del numero de serie del electrodomestico
 * @return Retorna	(-1) en caso de error - (posicion) en caso de EXITO
 */
int buscarElectrodomesticosPorSerie(eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos,char* serie);
/**@brief Pide el id del electrodomestico, muestra los id que puede ingresar y valida que este dentro de este grupo
 *
 * @param pIdResultado	Int, resultado id del electrodomestico
 * @param mensaje	Cadena de caracetres con el mensaje a mostrar.
 * @param mensajeError	Cadena de caracetres con el mensaje de error a mostrar.
 * @param listaElectrodomesticos Puntero al array de electrodomesticos.
 * @param largoElectrodomesticos Int Largo del array de electrodomesticos.
 * @param listaMarcas Puntero al array de eMarca.
 * @param largoMarcas Int Largo del array de eMarca.
 * @param reintentos Int, cantidad de reintentos
 * @return Retorna	(-1) en caso de error - (posicion) en caso de EXITO
 */
int pedirElectrodonesticoPorID(int *pIdResultado, char *mensaje, char *mensajeError ,eElectrodomesticos *listaElectrodomesticos,
		int largoElectrodomesticos ,eMarca *listaMarcas,int largoMarcas, int reintentos);
