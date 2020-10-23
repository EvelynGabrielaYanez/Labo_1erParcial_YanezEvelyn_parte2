/*
 * ArrayClientes.h
 *
 *  Created on: 17 oct. 2020
 *      Author: CLEM
 */

#ifndef ARRAYCLIENTES_H_
#define ARRAYCLIENTES_H_

typedef struct{

	int id;
	char nombre[21];
	char apellido[21];

}eCliente;


#endif /* ARRAYCLIENTES_H_ */

/**@brief	Busca el cliente por id y retorna la posicion en caso de EXITO
 * 			y retorna -1 en caso de ERROR (no existe dicho id, puntero nulo, largo invalido
 * 			o id invalido)
 *
 * @param lista		Puntero al array eCliente
 * @param largo		Int, largo de array eCliente
 * @param id		Int, id del cliente a buscar
 * @return	Retorna (-1) en caso de ERROR - posicion en caso de EXITO
 */
int buscarCliente(eCliente* lista,int largo, int id);
/**@brief	Mostar el cliente (id, nombre, apellido) del id ingresado.
 *
 * @param lista		Puntero al array eCliente
 * @param largo		Int, largo de array eCliente
 * @param id		Int, id del cliente a imprimir
 * @return	Retorna (0) EXITO - (-1) ERROR (id inexistente en el listado
 * 			, puntero nulo, id invalido o largo invalido )
 */
int mostarCliente(eCliente* lista,int largo, int id);
/**@brief	Imprime los clientes del Array eClientes
 *
 * @param lista		Puntero al array eCliente
 * @param largo		Int, largo de array eCliente
 * @return Retorna (0) EXITO - (-1) ERROR (puntero nulo,
 * 			id invalido o largo invalido )
 */
int mostarClientes(eCliente* lista,int  largo);
/**@brief	Valida la existencia del Id en el Array Clientes.
 *
 *
 * @param listadoClientes		Puntero al array eCliente.
 * @param largoClientes		Int, largo de array eCliente.
 * @param idCliente		Int, id del cliente a validar.
 * @return	Retorna (0) EXITO el id es valido - (-1) ERROR (puntero nulo,
 * 			id invalido o largo invalido )
 */
int validarIdCliente(eCliente *listadoClientes, int largoClientes, int idCliente);
/**@brief	Pide al usuario el ingreso de un id de cliente, valida la existencia del mismo
 * 			dentro del Array eClientes, y retorna el ingreso en el puntero pRetorno.
 *
 * @param pIdResultado	Puntero Int donde se devuelve el resultado.
 * @param mensaje	Puntero al mensaje de ingreso que vera el usuario
 * @param mensajeError	Puntero al mensaje de error que vera el usuario.
 * @param listadoClientes		Puntero al array eCliente.
 * @param largoClientes		Int, largo de array eCliente.
 * @param reintentos	Int, cantidad de reintentos para el ingreso.
 * @return	Retorna (0) EXITO - (-1) ERROR
 */
int pedirClientePorId(int *pIdResultado, char *mensaje, char *mensajeError ,eCliente *listadoClientes,int largoClientes, int reintentos);
/**@brief	Busca con el id el nombre y el apellido correspondiente al cliente y
 * 			la retorna en las cadenas de caracteres nomCliente y apellCliente.
 *
 * @param idCliente		Int, Id del Cliente.
 * @param listadoClientes	Puntero al array de Clientes
 * @param largoClientes		Int, largo del array de clientes
 * @param nomCliente	Puntero a la cadena de caracteres donde retorno del nombre
 * @param apellCliente	Puntero a la cadena de caracteres donde retorno del nombre
 * @return
 */
int cargarDescCliente(int idCliente, eCliente* listadoClientes,int largoClientes, char * nomCliente, char * apellCliente);
