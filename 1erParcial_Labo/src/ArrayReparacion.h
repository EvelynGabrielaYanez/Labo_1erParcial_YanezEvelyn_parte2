/*
 * ArrayReparacion.h
 *
 *  Created on: 15 oct. 2020
 *      Author: CLEM
 */
#include "ArrayServicio.h"
#include "ArrayClientes.h"
#include "ArrayElectrodomesticos.h"

#ifndef ARRAYREPARACION_H_
#define ARRAYREPARACION_H_

 typedef struct{

	int dia;
	int mes;
	int anio;

} eFecha;


 typedef struct{

	int id;
	char serie[11];
	eFecha fecha;
	int idServicio;
	int idCliente;
	int estaVacio;

} eReparacion;

#endif /* ARRAYREPARACION_H_ */
/**@brief Para indicar que todas las posiciones en el array estan vacias,
 * 		   esta funcion pone la bandera (isEmty) en verdadero (1) en todas
 *         las posiciones del array.
 *
 * @param listaReparacion Puntero al array de reparaciones
 * @param largoReparacion Int largo del array de reparacion
 * @return int Retorna (-1) en caso de ERROR [largo invalido o puntero nulo] - (0) en caso de EXITO
 */
int inicializarReparacion(eReparacion* listaReparacion, int largoReparacion);
/**@brief  Añade a una lista existente de reparaciones los valores recibidos como parametros
 *		   en la primer posicion vacia.
 *
 * @param listaReparacion Puntero al array de reparaciones
 * @param largoReparacion Largo del array de reparaciones
 * @param reparacionIngresada eElectrodomestico. Electrodometico ingresado.
  * @return int Retorna (-1) en caso de ERROR [Largo invalido, puntero nulo o sin espacio libre]
  *
 */
int agregarReparacion(eReparacion *listaReparacion, int largoReparacion, eReparacion reparacionIngresada);
/** @brief Busca un Electrodomesticos por Id y devuelve la posicion del indice del Array.
 *
 * @param listaReparacion Puntero al array de reparaciones
 * @param largoReparacion Int Largo del array de reparaciones
 * @param id Int ID de la reparacion a agregar
 * @return Int Retorna la posicion del indice del Electrodomesticos o (-1) si [Largo invalido o puntero
 *  nulo o empleado no encontrado]
 */
int buscarReparacionPorId(eReparacion* listaReparacion, int largoReparacion,int id);
/** @brief Remueve a un Empleado por Id (pone la bandera isEmpty en 1).
 *
 * @param listaReparacion Puntero al array de reparaciones
 * @param largoReparacion Int Largo del array de reparaciones
 * @param id Int ID de la reparacion a agregar
 * @return int Retorna (-1) si ERROR [Largo invalido o puntero nulo o
 * si no puede encontrar el empleado]  - (0) en caso de EXITO
 *
 */
int removerReparacion(eReparacion* listaReparacion, int largoReparacion, int id);

//int ordenarElectrodomesticos(eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos, int orden);
/**@brief  Imprime el contenido del Array de reparaciones.
 *
 * @param listaReparacion Puntero al array de eReparaciones.
 * @param largoReparacion Int Largo del array de eReparaciones.
 * @param listaServicios Puntero al array de eServicio.
 * @param largoServicios	Int, largo del array eServicio.
 * @param listaClientes	Puntero al array de eCliente.
 * @param largoClientes	Int, largo del array eCliente
 * @return int Retorna (-1) en caso de ERROR [Largo invalido, puntero nulo
 * u orden invalido]
 */
int imprimirReparaciones(eReparacion * listaReparacion, int largoReparacion,eServicio* listaServicios, int largoServicios, eCliente* listaClientes,int largoClientes);
/**@brief Imprime la reparacion de la posicion que le pasan.
 *
 * @param posicion
 * @param listaReparacion  Puntero al array de reparacion.
 * @param largoReparacion Int Largo del array de reparacion.
 * @param listaServicios Puntero al array de Servicios.
 * @param largoServicios Int Largo del array de Servicios.
 * @param listaClientes Puntero al array de Clientes.
 * @param largoClientes	Int, largo del array eCliente
 * @return int Retorna (-1) en caso de ERROR [Largo invalido, puntero nulo
 * u orden invalido]
 */
int imprimirReparacion(int posicion,eReparacion *listaReparacion, int largoReparacion,eServicio* listaServicios, int largoServicios, eCliente* listaClientes,int largoClientes);
/**@brief Retorna el precio promedio del Array de Reparacion
 *
 * @param listaReparacion  Puntero al array de Reparacion.
 * @param largoReparacion Int Largo del array de Reparacion.
 * @param promedio	float promedio de los precios de las reparaciones
 * @return	int Retorna (-1) en caso de ERROR [Largo invalido, puntero nulo
 * u orden invalido]
 */
int sueldoPromedioReparaciones(eReparacion* listaReparacion, int largoReparacion, float *promedio);
/**@brief Busca si hay algun empelado cargado en el array y devuelve true (1)
 * si lo encuentra y (0)false si no
 *
 * @param lista Empleado* Puntero al array de empleados
 * @param largo int Largo del array de empleados
 * @return Retorna (-1) en caso de Error [Largo invalido o puntero nulo o si no
 * 		   hay empleado cargado] - (0) en caso de encontrar al menos un empeleado
 * 		   cargado.
 *
 */
/**@brief Busca si hay alguna Reparacion cargada en el array y devuelve true (1)
 * si lo encuentra y (0)false si no
 *
 * @param listaReparacion  Puntero al array de Reparacion.
 * @param largoReparacion Int Largo del array de Reparacion.
 * @return Retorna (-1) en caso de Error [Largo invalido o puntero nulo o si no
 * 		   hay empleado cargado] - (0) en caso de encontrar al menos un empeleado
 * 		   cargado.
 */
int hayReparacionCargada(eReparacion *listaReparacion, int largoReparacion);
/**@brief	Hardcodea un maximo de 10 reproducciones y retorna la cantidad hardodeada.
 *
 * @param listaReparacion Puntero al array de reparacion
 * @param largoReparacion Int Largo del array de reparacion
 * @param cantidad	Int Cantidad de reparaciones que se van a hardcodear
 * @return Retorna	(-1) en caso de error - (cantiadad de hardcodeados) en caso de EXITO
 */
int hardcodearReparaciones(eReparacion* listaReparacion ,int largoReparacion , int cantidad);
/**@brief	Elimina todas las reparaciones (estaVacio=1) con numero de serie igual al del electrodomestico
 * 			pasado por numero de id
 *
 * @param listaReparacion Puntero al array de reparacion
 * @param largoReparacion Int Largo del array de reparacion
 * @param vIdElectrodomestico	Int, Id del electrodomestico del que deseo eliminar reparaciones
 * @param listaElectrodomestico Puntero al array de electrodomesticos
 * @param largoElectrodomestico Int Largo del array de electrodomesticos
 * @return
 */
int removerReparacionPorSerieElectrod(eReparacion* listaReparacion,int largoReparacion,int vIdElectrodomestico, eElectrodomesticos* listaElectrodomestico, int largoElectrodomestico);
/**
 * @brief 	Imprime la reparcion que le pasan por posicion, incluyendo en esta el dato del importe del cliente de serivicio
 *
 * @param posicion
 * @param listaReparacion  Puntero al array de reparacion.
 * @param largoReparacion Int Largo del array de reparacion.
 * @param listaServicios Puntero al array de Servicios.
 * @param largoServicios Int Largo del array de Servicios.
 * @param listaClientes Puntero al array de Clientes.
 * @param largoClientes	Int, largo del array eCliente
 * @return int Retorna (-1) en caso de ERROR [Largo invalido, puntero nulo
 * u orden invalido]
 */
int imprimirReparacionConImporte(int posicion,eReparacion *listaReparacion, int largoReparacion,eServicio* listaServicios, int largoServicios, eCliente* listaClientes,int largoClientes);
