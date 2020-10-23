/*
 * ArrayServicio.h
 *
 *  Created on: 15 oct. 2020
 *      Author: CLEM
 */

#ifndef ARRAYSERVICIO_H_
#define ARRAYSERVICIO_H_

typedef struct{

	int id;
	char descripcion[26];
	float precio;

}eServicio;

#endif /* ARRAYSERVICIO_H_ */

/**@brief	Busca el servicio por id y retorna la posicion en caso de EXITO
 * 			y retorna -1 en caso de ERROR (no existe dicho id, puntero nulo, largo invalido
 * 			o id invalido)
 *
 * @param lista Puntero al array eServicio
 * @param largo	Int, largo de array eServicio
 * @param id Int, id de la marca a buscar
 * @return Retorna (-1) en caso de ERROR - posicion en caso de EXITO
 */
int buscarServicio(eServicio* lista,int largo, int id);
/**@brief  Mostar el eServicio (id, descripcion) del id ingresado.
 *
 * @param lista Puntero al array eServicio
 * @param largo Int, largo de array eServicio
 * @param id Int, id del servicio a imprimir
 * @return	Retorna (0) EXITO - (-1) ERROR (id inexistente en el listado
 * 			, puntero nulo, id invalido o largo invalido )
 */
int mostrarServicio(eServicio* lista,int largo, int id);
/**@brief	Imprime los servicios del Array eServicio
 *
 * @param lista Puntero al array eServicio
 * @param largo Int, largo de array eServicio
 * @return
 */
int mostrarServicios(eServicio* lista,int  largo);
/**@brief	Valida la existencia del Id en el Array eServicio.
 *
 * @param listadoServicios Puntero al array eServicio
 * @param largoServicios Int, largo de array eServicio
 * @param idServicio Int, id del servicio a validar.
 * @return Retorna (0) EXITO el id es valido - (-1) ERROR (puntero nulo,
 * 			id invalido o largo invalido )
 */
int validarIdServicio(eServicio *listadoServicios, int largoServicios, int idServicio);
/**@brief Pide al usuario el ingreso de un id del servicio, valida la existencia del mismo
 * 			dentro del Array eMarcas, y retorna el ingreso en el puntero pRetorno.
 *
 * @param pIdResultado Puntero Int donde se devuelve el resultado.
 * @param mensaje 	Puntero al mensaje de ingreso que vera el usuario
 * @param mensajeError	Puntero al mensaje de error que vera el usuario.
 * @param listadoServicios Puntero al array eServicio
 * @param largoServicios Int, largo de array eServicio
 * @param reintentos Int, cantidad de reintentos para el ingreso.
 * @return Retorna (0) EXITO - (-1) ERROR
 */
int pedirServicioPorID(int *pIdResultado, char *mensaje, char *mensajeError ,eServicio *listadoServicios,int largoServicios, int reintentos);
/**@brief	Busca con el id la descripcion del servicio  y
 * 			la retorna en la cadena de caracteres .
 *
 * @param idServicio Int, Id del eServicio.
 * @param listadoServicios Puntero al array de eServicio
 * @param largoServicios	Int, largo del array de eServicio
 * @param descServicio Puntero a la cadena de caracteres donde retorno de la descripcion
 * @return Retorna (0) EXITO - (-1) ERROR
 */
int cargarDescServicio(int idServicio,eServicio* listadoServicios,int largoServicios, char * descServicio);
/**@brief Busca con el id el importe del servicio  y
 * 		  lo retorna en el parametro improte.
 *
 * @param idServicio	Int, Id del eServicio.
 * @param listadoServicios	Puntero al array de eServicio
 * @param largoServicios	Int, largo del array de eServicio
 * @param importe	Float,importe del id ingresado
 * @return Retorna (0) EXITO - (-1) ERROR
 */
int cargarImporteServicio(int idServicio,eServicio* listadoServicios,int largoServicios, float* importe);
/**
 * @brief	Busca con el id la descripcion del servicio  y
 * 			la retorna en la cadena de caracteres.
 *
 * @param idServicio Int, Id del eServicio.
 * @param listadoServicios Puntero al array de eServicio
 * @param largoServicios	Int, largo del array de eServicio
 * @param descServicio Puntero a la cadena de caracteres donde retorno de la descripcion
 * @param precioServicio	Puntero al flotante donde retornara el precio del servicio
 * @return Retorna (0) EXITO - (-1) ERROR
 */
int cargarDescImporteServicio(int idServicio,eServicio* listadoServicios,int largoServicios, char * descServicio, float* precioServicio);
