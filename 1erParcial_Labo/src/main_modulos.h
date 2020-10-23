/*
 * TP2_modulos.h
 *
 *
 *      Author: Yañez Evelyn Gabriela
 */

#ifndef TP2_MODULOS_H_
#define TP2_MODULOS_H_



#endif /* TP2_MODULOS_H_ */
/**@brief  Muestra el menu de opciones y pide al usuario el ingreso de una de ellas y
 * 		   la retorna luego de validarla
 *
 * @return Int. Opcion seleccionada por el usuario
 */
int menu();
/**@brief Pide el numero de serie del electrodomestico, valida que este no este ya ingresado en la base de datos,
 * 		  muestra el id de las marcas con su descripcion y pide el ingreso de uno de ellos (lo valida),
 * 		  pide el ingreso del modelo (anio), lo valida.
 * 		  En caso de ser todos los datos correctos carga el nuevo electrodomestico asignandole un id autoincremental.
 *
 * @param listaElectrodomesticos Puntero al array de eElectrodomesticos donde se cargara.
 * @param largoElectrodomesticos Int, largo del array de eElectrodomesticos donde se cargara.
 * @param pcontadorIdElect	Int contador del id de electrodomesticos Autoincremental.
 * @param listaMarcas Puntero al array de eMarcas.
 * @param largoMarcas Int largo del array de marcas.
 */
void altasElectrodomestico(eElectrodomesticos *listaElectrodomesticos, int largoElectrodomesticos, int *pcontadorIdElect,
		eMarca* listaMarcas, int largoMarcas) ;
/**@brief Pide el id del electrodomestico que se desea modificar, muestra la informacion del mismo y le pide al usuario la
 * 		  seleccion de la modificacion deseada (Serie o Modelo) en un submenu. Le pide el dato a modificar, lo valida y modifica.
 *
 * @param lista Puntero al array de eElectrodomesticos que se modificara.
 * @param largoElectrodomesticos Int, largo del array de eElectrodomesticos que se modificara.
 * @param listaMarcas Puntero al array de eMarcas.
 * @param largoMarca Int largo del array de marcas.
 */
void modificarElectrodomestico(eElectrodomesticos *lista, int largoElectrodomesticos,eMarca* listaMarcas, int largoMarca);
/**@brief Pide el id del electrodomestico que se desea dar de baja, muestra la informacion del mismo y le pide al usuario la
 * 		  confirmacion para eliminarlo (s/n). En caso afirmativo elimina el electrodomestico y todas las reparaciones que
 * 		  recibio el mismo. Solo si hay un empleado cargado
 *
 * @param listaElectrodomesticos	Puntero al array de eElectrodomesticos del que se eliminara.
 * @param largoElectrodomesticos	Int, largo del array de eElectrodomesticos.
 * @param listaMarcas	Puntero al array de eMarcas.
 * @param largoMarcas	Int largo del array de eMarcas
 * @param listaReparacion	Puntero al array de eReparaciones.
 * @param largoReparacion	Int largo del array de eReparaciones
 */
void bajaElectrodomesticos(eElectrodomesticos *listaElectrodomesticos,int largoElectrodomesticos, eMarca * listaMarcas,
		int largoMarcas, eReparacion * listaReparacion, int largoReparacion);
/**@brief Pide el numero de serie del electrodomestico, valida que este ingresado en  la base de datos mostrandole las opciones
 * 		  de series de electrodomesticos ya existentes en el sistema,muestra el id de los servicios con su descripcion y
 * 		  pide el ingreso de uno de ellos (lo valida), pide el ingreso de la fecha de reparacion (la valida), pide el
 * 		  ingreso del id de cliente y valida su existencia, mostrandole previamente todos los existentes.
 * 		  En caso de ser todos los datos correctos carga la nueva reparacion asignandole un id autoincremental.
 * 		  Solo si hay un empleado cargado.
 *
 * @param listaReparaciones		Puntero al array eReparacion donde se realizara el alta.
 * @param largoReparaciones		Int, largo del array de eReparaciones.
 * @param vContadorIdReparacion		Int contador del id autoincremental de reparaciones
 * @param listaServicios	Puntero al array de eServicios.
 * @param largoServicios	Int, largo del array de eServicios
 * @param listaElectrodomesticos	Puntero al array de eElectrodomesticos
 * @param largoElectrodomesticos	Int, largo del array de eElectrodomesticos
 * @param listaMarca	Puntero al array de eMarcas
 * @param largoMarca	Int, largo del arrya de eMarcas
 * @param listaClientes		Puntero al array de eClientes
 * @param largoClientes		Int, largo del array de eClientes
 */
void altaReparacion(eReparacion *listaReparaciones, int largoReparaciones,
		int *vContadorIdReparacion, eServicio *listaServicios,
		int largoServicios, eElectrodomesticos *listaElectrodomesticos,
		int largoElectrodomesticos, eMarca *listaMarca, int largoMarca,
		eCliente *listaClientes, int largoClientes);
/**@brief	Imprime los electrodomesticos del array eElectrodomesticos con su descripcion de marca de eMarca correspondiente por idMarca,
 * 			Ordenandolo por serie y modelo(de manera ascendente o descendete segun el usuario desee).
 * 			Solo si hay un empleado cargado.
 *
 * @param listaElectrodomesticos	Puntero al array eElectrodomesticos a listar.
 * @param largoElectrodomesticos	Int largo del array eElectrodomesticos.
 * @param listaMarcas	Puntero al array eMarcas.
 * @param largoMarcas	Int, largo del array eMarcas.
 */
void listarElectrodomesticos(eElectrodomesticos* listaElectrodomesticos,int largoElectrodomesticos,eMarca *listaMarcas,int largoMarcas);
/**@brief	Imprime el listado de marcas con su Id y su descripcion.
 *			 Solo si hay un empleado cargado.
 *
 * @param listaMarcas	Puntero al array de eMarcas a listar.
 * @param largoMarcas	Int, largo del array de eMarcas.
 * @param listaElectrodomesticos	Puntero al array de eElectrodomesticos.
 * @param largoElectrodomesticos	Int, largo del array eElectrodomesticos.
 */
void listarMarcas(eMarca* listaMarcas, int largoMarcas, eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos);
/**@brief	Imprime el listado de servicios con su id, descripcion e importe.
 * 			Solo si hay un empleado cargado.
 *
 * @param listaServicios Puntero al array de eServicio
 * @param largoServicios	Int largo del array eServicios
 * @param listaElectrodomesticos	Puntero al array de eElectrodomesticos
 * @param largoElectrodomesticos	Int, largo del array de eElectrodomesticos
 */
void listarServicios(eServicio* listaServicios, int largoServicios, eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos);
/**@brief Imprime el listado de reparaciones junto con su descripcion correspondiente al id de servicios.
 *			Solo si hay un empleado cargado.
 *
 * @param listaReparaciones	Puntero al array de eReparaciones
 * @param largoReparaciones	Int largo del array eReparaciones
 * @param listaServicios	Puntero al array de eServicio
 * @param largoServicios	Int largo del array eServicios
 * @param listaElectrodomesticos	Puntero al array de eElectrodomesticos
 * @param largoElectrodomesticos	Int, largo del array de eElectrodomesticos
 * @param listaClientes		Puntero al array de eClientes
 * @param largoClientes		Largo al array de Clientes
 */
void listarReparaciones(eReparacion* listaReparaciones,int largoReparaciones,eServicio* listaServicios, int largoServicios
		,eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos, eCliente *listaClientes, int largoClientes);
/**@brief	Imprime el listado de servicios con su id, nombre, apellido.
 * 			Solo si hay un empleado cargado.
 *
 * @param listaClientes	Puntero al array de eClientes
 * @param largoClientes	Largo al array de Clientes
 * @param listaElectrodomesticos	Puntero al array de eElectrodomesticos
 * @param largoElectrodomesticos	Int, largo del array de eElectrodomesticos
 */
void listarClientes(eCliente* listaClientes,int largoClientes, eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos);
/**@brief	Desplega un submenu para que el usuario seleccione el tipo de informe que desea e
 * 			imprime el mismo.
 *
 * @param listaClientes	Puntero al array de eClientes
 * @param largoClientes	Largo al array de Clientes
 * @param listaReparacion	Puntero al array de eReparacion
 * @param largoReparacion	Largo al array de eReparacion
 * @param listaElectrodomesticos	Puntero al array de eElectrodomesticos
 * @param largoElectrodomesticos 	Largo al array de eElectrodomesticos
 * @param listaMarcas	Puntero al array de eMarca
 * @param largoMarcas	Largo al array de eMarcas
 * @param listaServicios	Puntero al array de eServicio
 * @param largoServicios	Largo al array de eServicio
 */
void informes(eCliente* listaClientes, int largoClientes, eReparacion* listaReparacion, int largoReparacion,
		eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos, eMarca* listaMarcas,
		int largoMarcas, eServicio* listaServicios, int largoServicios);
