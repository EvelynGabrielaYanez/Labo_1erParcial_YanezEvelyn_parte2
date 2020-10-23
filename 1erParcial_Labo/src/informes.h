/*
 * informes.h
 *
 *  Created on: 18 oct. 2020
 *      Author: CLEM
 */

#include "ArrayClientes.h"
#include "ArrayElectrodomesticos.h"
#include "ArrayMarca.h"
#include "ArrayServicio.h"
#include "ArrayReparacion.h"

#ifndef INFORMES_H_
#define INFORMES_H_



#endif /* INFORMES_H_ */
/**@brief Imprime el listado de reparaciones por cliente.
 *
 * @param listaClientes	Puntero al Array de eClientes
 * @param largoClientes	Int, largo del Array de eClientes
 * @param listaReparciones	Puntero al Array de eReparaciones
 * @param largoReparaciones	Int, largo del Array de eReparaciones
 * @param listaServicios	Puntero al Array de eServicios
 * @param largoServicios	Int, largo del Array de eServicios
 * @return	Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 			no pudo imprimir)
 */
int informeMostrarReparacionPorCliente(eCliente* listaClientes, int largoClientes, eReparacion* listaReparciones, int largoReparaciones, eServicio* listaServicios, int largoServicios);
/**@ brief Imprime el listado de reparaciones del cliente ingresado
 *
 * @param listaClientes	Puntero al Array de eClientes
 * @param largoClientes	Int, largo del Array de eClientes
 * @param listaReparciones	Puntero al Array de eReparaciones
 * @param largoReparaciones	Int, largo del Array de eReparaciones
 * @param listaServicios	Puntero al Array de eServicios
 * @param largoServicios	Int, largo del Array de eServicios
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 			no pudo imprimir)
 */
int informeMostrarReparacionDeCliente(int idCliente,eCliente* listaClientes, int largoClientes, eReparacion* listaReparciones, int largoReparaciones, eServicio* listaServicios, int largoServicios);
/**@brief Imprime el listado de reparaciones por electrodomestico.
 *
 * @param listaElectrodomesticos	Puntero al Array de eElectrodomestico
 * @param largoElectrodomesticos	Int, largo del Array de eElectrodomestico
 * @param listaReparciones	Puntero al Array de eReparacion
 * @param largoReparaciones	Int, largo del Array de eReparacion
 * @param listaServicios	Puntero al Array de eServicio
 * @param largoServicios	Int, largo del Array de eServicio
 * @param listaClientes	Puntero al Array de eClientes
 * @param largoClientes	Int, largo del Array de eClientes
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 			no pudo imprimir)
 */
int informeMostrarReparacionPorSerie(eElectrodomesticos *listaElectrodomesticos,
		int largoElectrodomesticos, eReparacion *listaReparciones, int largoReparaciones,
		eServicio *listaServicios, int largoServicios, eCliente* listaClientes, int largoClientes);
/**@brief Imprime el listado de reparaciones del electrodomestico de serie ingresado.
 *
 * @param serie
 * @param listaClientes	Puntero al Array de eClientes
 * @param largoClientes	Int, largo del Array de eClientes
 * @param listaReparciones	Puntero al Array de eReparacion
 * @param largoReparaciones	Int, largo del Array de eReparacion
 * @param listaServicios	Puntero al Array de eServicio
 * @param largoServicios	Int, largo del Array de eServicio
 * @param listaElectrodomesticos	Puntero al Array de eElectrodomestico
 * @param largoElectrodomesticos	Int, largo del Array de eElectrodomestico
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 			no pudo imprimir, no existe la serie, no tiene reparaciones)
 */
int informeMostrarReparacionDeSerie(char* serie, eCliente *listaClientes,
		int largoClientes, eReparacion *listaReparciones, int largoReparaciones,
		eServicio *listaServicios, int largoServicios,eElectrodomesticos* listaElectrodomesticos,
		int largoElectrodomesticos);
/**@brief Imprime el listado de reparaciones de importe mayor o igual al ingresado.
 *
 * @param listaClientes		Puntero al Array de eClientes
 * @param largoClientes		Int, largo del Array de eClientes
 * @param listaReparciones	Puntero al Array de eReparacion
 * @param largoReparaciones		Int, largo del Array de eReparacion
 * @param listaServicios	Puntero al Array de eServicio
 * @param largoServicios	Int, largo del Array de eServicio
 * @param listaElectrodomesticos	Puntero al Array de eElectrodomestico
 * @param largoElectrodomesticos	Int, largo del Array de eElectrodomestico
 * @param importeIngresado	Float, importe contra el que voy a comparar.
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 			no pudo imprimir, importe invalido)
 */
int informeReparacionesPorImporte( eCliente *listaClientes,
		int largoClientes, eReparacion *listaReparciones, int largoReparaciones,
		eServicio *listaServicios, int largoServicios,eElectrodomesticos* listaElectrodomesticos,
		int largoElectrodomesticos, float importeIngresado);
/**@brief	Informa la cantidad de reportes por clientes.
 *
 * @param listaClientes		Puntero al Array de eClientes
 * @param largoClientes		Int, largo del Array de eClientes
 * @param listaReparciones	Puntero al Array de eReparacion
 * @param largoReparaciones		Int, largo del Array de eReparacion
 * @param listaServicios	Puntero al Array de eServicio
 * @param largoServicios	Int, largo del Array de eServicio
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 			no pudo imprimir)
 */
int informeCantidadRepPorCliente(eCliente *listaClientes,
		int largoClientes, eReparacion *listaReparciones, int largoReparaciones,
		eServicio *listaServicios, int largoServicios);
/**@brief	Informa la cantidad de reportes por serie.
 *
 * @param listaReparacion	Puntero al Array de eReparacion.
 * @param largoReparacion		Int, largo del Array de eReparacion.
 * @param listaElectrodomesticos	Puntero al Array de eElectrodomestico.
 * @param largoElectrodomesticos	Int, largo del Array de eElectrodomestico.
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 			no pudo imprimir)
 */
int informeCantidadRepPorSerie(eReparacion* listaReparacion,int largoReparacion,
						eElectrodomesticos* listaElectrodomesticos,int largoElectrodomesticos);
/**
 * @brief	Informa el electrodomestico con mas reparaciones.
 *
 * @param listaReparacion	Puntero al Array de eReparacion.
 * @param largoReparacion		Int, largo del Array de eReparacion.
 * @param listaElectrodomesticos	Puntero al Array de eElectrodomestico.
 * @param largoElectrodomesticos	Int, largo del Array de eElectrodomestico.
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 			no pudo imprimir)
 */
int informarSerieConMasRep(eReparacion* listaReparacion,int largoReparacion,
						eElectrodomesticos* listaElectrodomesticos,int largoElectrodomesticos);
/**
 * @brief	Informa el cliente con mas reparaciones.
 *
 * @param listaReparacion	Puntero al Array de eReparacion.
 * @param largoReparacion	Int, largo del Array de eReparacion.
 * @param listaElectrodomesticos	Puntero al Array de eElectrodomestico.
 * @param largoElectrodomesticos	Int, largo del Array de eElectrodomestico.
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 			no pudo imprimir)
 */
int informarClienteConMasRep(eReparacion* listaReparacion,int largoReparacion,
						eCliente* listaClientes,int largoClientes);
/**
 * @brief	Informa los electrodomesticos por marca
 *
 * @param listaElectrodomesticos	Puntero al Array de eElectrodomesticos
 * @param largoElectrodomesticos	Int, largo del Array eElectrodomesticos
 * @param listaMarcas	Puntero al Array de eMarcas
 * @param largoMarcas	Int, largo del Array de eMarcas
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 		  no pudo imprimir)
 */
int informarElectPorMarca(eElectrodomesticos* listaElectrodomesticos,int largoElectrodomesticos,eMarca* listaMarcas,int largoMarcas);
/**
 * @brief	Informa los electrodomesticos de la marca de id pasado por parametro
 *
 * @param listaElectrodomesticos	Puntero al Array de eElectrodomesticos
 * @param largoElectrodomesticos	Int, largo del Array eElectrodomesticos
 * @param listaMarcas	Puntero al Array de eMarcas
 * @param largoMarcas	Int, largo del Array de eMarcas
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 		  no pudo imprimir)
 */
int informarElectDeMarca(int idMarca, eElectrodomesticos* listaElectrodomesticos,int largoElectrodomesticos,eMarca* listaMarcas,int largoMarcas);
/**
 * @brief	Informa la cantidad de electrodomesticos que tiene cada marca
 *
 * @param listaElectrodomesticos	Puntero al Array de eElectrodomesticos
 * @param largoElectrodomesticos	Int, largo del Array eElectrodomesticos
 * @param listaMarcas	Puntero al Array de eMarcas
 * @param largoMarcas	Int, largo del Array de eMarcas
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 		  no pudo imprimir)
 */
int informarCantElectPorMarca(eElectrodomesticos* listaElectrodomesticos,int largoElectrodomesticos, eMarca* listaMarcas,int largoMarcas);
/**
 * @brief	Informa la marca con mayor cantidad de electrodomesticos.
 *
 * @param listaElectrodomesticos	Puntero al Array de eElectrodomesticos
 * @param largoElectrodomesticos	Int, largo del Array eElectrodomesticos
 * @param listaMarcas	Puntero al Array de eMarcas
 * @param largoMarcas	Int, largo del Array de eMarcas
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 		  no pudo imprimir)
 */
int informarMarcaMayCantElect(eElectrodomesticos* listaElectrodomesticos,int largoElectrodomesticos, eMarca* listaMarcas,int largoMarcas);
/**
 * @brief 	Informa el promedio de electrodomesticos por marca.
 *
 * @param listaElectrodomesticos	Puntero al Array de eElectrodomesticos
 * @param largoElectrodomesticos	Int, largo del Array eElectrodomesticos
 * @param listaMarcas	Puntero al Array de eMarcas
 * @param largoMarcas	Int, largo del Array de eMarcas
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 		  no pudo imprimir)
 */
int informarPromedioElectrodPorMarca(eElectrodomesticos* listaElectrodomesticos,int largoElectrodomesticos, eMarca* listaMarcas,int largoMarcas);
/**
 * @brief 	Informa el promedio de reparaciones por electrodomesticos.
 *
 * @param listaReparacion	Puntero al Arrray de eReparaciones
 * @param largoReparacion	Int, largo del Array de eReparaciones
 * @param listaElectrodomesticos		Puntero al Array de eElectrodomesticos
 * @param largoElectrodomesticos		Int, largo del Array de eElectrodomesticos
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 		  no pudo imprimir)
 */
int informarPromedioRepaPorElect(eReparacion* listaReparacion,int largoReparacion,eElectrodomesticos* listaElectrodomesticos,int largoElectrodomesticos);
/**
 * @brief	Informa el promedio de reparaciones por Clientes
 *
 * @param listaReparaciones	Puntero al Arrray de eReparaciones
 * @param largoReparaciones	Int, largo del Array de eReparaciones
 * @param listaClientes	Puntero al Arrray de eClientes
 * @param largoClientes	Int, largo del Array de eClientes
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 		  no pudo imprimir)
 */
int informarPromedioRepaPorCliente(eReparacion* listaReparaciones, int largoReparaciones, eCliente* listaClientes, int largoClientes);
/**
 * @brief 	Informa los electrodomesticos de modelo 2020
 *
 * @param listaElectrodomesticos	Puntero al Arrray de eElectrodomesticos
 * @param largoElectrodomesticos	Int, largo del Array de eElectrodomesticos
 * @param listaMarcas	Puntero al Array de eMarcas
 * @param largoMarcas	Int, largo del Array de eMarcas
 * @return	Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 		  no pudo imprimir)
 */
int informarElectrdomesticos2020(eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos, eMarca* listaMarcas, int largoMarcas);
/**
 * @brief Imprime los electrodomesticos que no tengan ninguna reparacion
 *
 * @param listaElectrodomesticos	Puntero al Arrray de eElectrodomesticos
 * @param largoElectrodomesticos	Int, largo del Array de eElectrodomesticos
 * @param listaMarca	Puntero al Array de eMarcas
 * @param largoMarca	Int, largo del Array de eMarcas
 * @param listaReparacion	Puntero al Array de eElectrodomesticos
 * @param largoReparacion	Int, largo del Array de eElectrodomesticos
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 		  no pudo imprimir)
 */
int informarElectrodomesticosSinRep(eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos, eMarca* listaMarca, int largoMarca,eReparacion* listaReparacion, int largoReparacion);
/**
 * @brief Imprime el importe total de las reparaciones realizadas al electrodomestico de serie igual a la ingresada por parametro
 *
 * @param serieElectrodomestico	Cadena de caractacteres de la serie del electrodomestico
 * @param listaElectrodomesticos	Puntero al Arrray de eElectrodomesticos
 * @param largoElectrodomesticos Int, largo del Array de eElectrodomesticos
 * @param listaSerivicio	Puntero al Arrray de eServicio
 * @param largoServicio Int, largo del Array de eServicio
 * @param listaReparacion	Puntero al Arrray de eReparacion
 * @param largoReparacion Int, largo del Array de eReparacion
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 		  no pudo imprimir, no existe la serie ingresada)
 */
int informarImporteRepDelElect(char* serieElectrodomestico,eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos, eServicio* listaSerivicio, int largoServicio,eReparacion* listaReparacion, int largoReparacion);
/**
 * @brief 	Informa el servicio mas requerido en caso de haberlo, caso contrario informa que ninguno fue pedido.
 *
 * @param listaReparaciones	Puntero al Arrray de eReparacion
 * @param largoReparaciones Int, largo del Array de eReparacion
 * @param listaServicios	Puntero al Arrray de eServicio
 * @param largoServicios Int, largo del Array de eServicio
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 		  no pudo imprimir)
 */
int informarServicioMasPedido(eReparacion* listaReparaciones, int largoReparaciones, eServicio* listaServicios, int largoServicios);
/**
 * @brief	Informa el importe total para la fecha pasada por parametro en caso de que lo tenga, caso contrario alerta que no hay.
 *
 * @param listaReparaciones	Puntero al Arrray de eReparacion
 * @param largoReparaciones Int, largo del Array de eReparacion
 * @param listaServicios	Puntero al Arrray de eServicio
 * @param largoServicios Int, largo del Array de eServicio
 * @param fechaIngresada	eFecha de la que se desea informar
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 		  no pudo imprimir)
 */
int informarRecaudacionDeFecha(eReparacion* listaReparaciones, int largoReparaciones, eServicio* listaServicios, int largoServicios, eFecha fechaIngresada);
/**
 * @brief Imprime todos los electrodomesticos que recibieron garantia con su fecha
 *
 * @param listaElectrodomesticos	Puntero al Arrray de eElectrodomesticos
 * @param largoElectrodomesticos Int, largo del Array de eElectrodomesticos
 * @param listaReparaciones	Puntero al Arrray de eReparacion
 * @param largoReparaciones Int, largo del Array de eReparacion
 * @param listaServicios	Puntero al Arrray de eServicio
 * @param largoServicios Int, largo del Array de eServicio
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 		  no pudo imprimir)
 */
int informarElectrodConGaranta(eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos,eReparacion* listaReparaciones, int largoReparaciones, eServicio* listaServicios, int largoServicios);
/**
 * @brief Imprime las reparaciones realizadas al modelo 2020
 *
 * @param listaElectrodomesticos	Puntero al Arrray de eElectrodomesticos
 * @param largoElectrodomesticos Int, largo del Array de eElectrodomesticos
 * @param listaReparaciones	Puntero al Arrray de eReparacion
 * @param largoReparaciones Int, largo del Array de eReparacion
 * @param listaServicios	Puntero al Arrray de eServicio
 * @param largoServicios Int, largo del Array de eServicio
 * @param listaCliente	Puntero al Arrray de eCliente
 * @param largoCliente Int, largo del Array de eCliente
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 		  no pudo imprimir)
 */
int informarTrabajos2020(eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos
		,eReparacion* listaReparaciones, int largoReparaciones, eServicio* listaServicios, int largoServicios, eCliente* listaCliente, int largoCliente);

/**
 * @brief Imprime la facturacion total de los mantenimientos realizados
 *
 * @param listaReparaciones	Puntero al Arrray de eReparacion
 * @param largoReparaciones Int, largo del Array de eReparacion
 * @param listaServicios	Puntero al Arrray de eServicio
 * @param largoServicios Int, largo del Array de eServicio
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 		  no pudo imprimir)
 */
int informarFactTotalMantenimiento(eReparacion* listaReparaciones, int largoReparaciones, eServicio* listaServicios, int largoServicios);
/**
 * @brief	 informa la marca del electrodomestico que efectuo mas refacciones
 *
 * @param listaReparacion	Puntero al Arrray de eReparacion
 * @param largoReparacion Int, largo del Array de eReparacion
 * @param listaElectrodomesticos	Puntero al Arrray de eElectrodomesticos
 * @param largoElectrodomesticos Int, largo del Array de eElectrodomesticos
 * @param listaMarcas	Puntero al Arrray de eMarcas
 * @param largoMarcas Int, largo del Array de eMarcas
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 		  no pudo imprimir)
 */
int informarMarcaElectConMasRep(eReparacion* listaReparacion,int largoReparacion,
						eElectrodomesticos* listaElectrodomesticos,int largoElectrodomesticos, eMarca* listaMarcas, int largoMarcas);
/**
 * @brief 	 informa los electrodomesticos que recibieron reparacion en una fecha determinada.
 *
 * @param listaReparaciones	Puntero al Arrray de eReparacion
 * @param largoReparaciones Int, largo del Array de eReparacion
 * @param listaServicios	Puntero al Arrray de eServicio
 * @param largoServicios Int, largo del Array de eServicio
 * @param fechaIngresada	eFecha de la que se quiere infromar
 * @param listaElectrodomesticos	Puntero al Arrray de eElectrodomesticos
 * @param largoElectrodomesticos Int, largo del Array de eElectrodomesticos
 * @param listaMarcas	Puntero al Arrray de eMarcas
 * @param largoMarcas Int, largo del Array de eMarcas
 * @return Retorna (0) en caso de EXITO - (-1) en caso de ERROR (puntero nulo, largo invalido,
 * 		  no pudo imprimir)
 */
int informarElectConRepEnFecha(eReparacion* listaReparaciones, int largoReparaciones, eServicio* listaServicios,
		int largoServicios, eFecha fechaIngresada, eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos,
		eMarca* listaMarcas, int largoMarcas);
