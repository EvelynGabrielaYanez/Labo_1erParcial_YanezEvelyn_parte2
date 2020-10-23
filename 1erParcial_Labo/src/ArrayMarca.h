/*
 * ArrayMarca.h
 *
 *  Created on: 15 oct. 2020
 *      Author: CLEM
 */

#ifndef ARRAYMARCA_H_
#define ARRAYMARCA_H_

typedef struct{

	int id;
	char descripcion[21];

}eMarca;


#endif /* ARRAYMARCA_H_ */

/**@brief	Busca la marca por id y retorna la posicion en caso de EXITO
 * 			y retorna -1 en caso de ERROR (no existe dicho id, puntero nulo, largo invalido
 * 			o id invalido)
 *
 * @param lista		Puntero al array eMarca
 * @param largo		Int, largo de array eMarca
 * @param id		Int, id de la marca a buscar
 * @return Retorna (-1) en caso de ERROR - posicion en caso de EXITO
 */
int buscarMarca(eMarca* lista,int largo, int id);
/**@brief Mostar la eMarca (id, descripcion) del id ingresado.
 *
 * @param lista	Puntero al array eMarca
 * @param largo		Int, largo de array eMarca
 * @param id		Int, id de la marca a imprimir
 * @return	Retorna (0) EXITO - (-1) ERROR (id inexistente en el listado
 * 			, puntero nulo, id invalido o largo invalido )
 */
int mostrarMarca(eMarca* lista,int largo, int id);
/**@brief	Imprime las marcas del Array eMarca
 *
 * @param lista Puntero al array eMarca
 * @param largo	Int, largo de array eMarca
 * @return Retorna (0) EXITO - (-1) ERROR (puntero nulo,
 * 			id invalido o largo invalido )
 */
int mostrarMarcas(eMarca* lista,int  largo);
/**@brief	Valida la existencia del Id en el Array eMarca.
 *
 * @param listadoMarcas Puntero al array eMarca
 * @param largoMarcas	Int, largo de array eMarca.
 * @param idMarca Int, id de la marca a validar.
 * @return Retorna (0) EXITO el id es valido - (-1) ERROR (puntero nulo,
 * 			id invalido o largo invalido )
 */
int validarIdMarca(eMarca *listadoMarcas, int largoMarcas, int idMarca);
/**@brief Pide al usuario el ingreso de un id de la marca, valida la existencia del mismo
 * 			dentro del Array eMarcas, y retorna el ingreso en el puntero pRetorno.
 *
 * @param pIdResultado Puntero Int donde se devuelve el resultado.
 * @param mensaje 	Puntero al mensaje de ingreso que vera el usuario
 * @param mensajeError	Puntero al mensaje de error que vera el usuario.
 * @param listaMarcas		Puntero al array eMarca.
 * @param largoMarcas	Int, largo de array eMarca.
 * @param reintentos	Int, cantidad de reintentos para el ingreso.
 * @return	Retorna (0) EXITO - (-1) ERROR
 */
int pedirMarcaPorID(int *pIdResultado, char *mensaje, char *mensajeError ,eMarca *listaMarcas,int largoMarcas, int reintentos);
/**@brief	Busca con el id la descripcion de la marca  y
 * 			la retorna en la cadena de caracteres descCarrera.
 *
 * @param idCarrera Int, Id del eMarcas.
 * @param listadoCarreras Puntero al array de eMarcas
 * @param largoCarreras 	Int, largo del array de eMarcas
 * @param descCarrera	Puntero a la cadena de caracteres donde retorno de la descripcion
 * @return Retorna (0) EXITO - (-1) ERROR
 */
int cargarDescMarca(int idMarca,eMarca* listadoMarcas,int largoMarcas, char * descMarca);
