/*
 * TP2_modulos.c
 *
 *
 *      Author: Yañez Evelyn Gabriela
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayElectrodomesticos.h"
#include "ArrayReparacion.h"
#include "ArrayServicio.h"
#include "ArrayClientes.h"
#include "ArrayMarca.h"
#include "informes.h"
#include "utn_validaciones.h"

#include "utn_validaciones.h"
#define REINTENTOS 5
#define CANTIDAD_CARACTERES_SERVICIO 26
#define CANTIDAD_CARACTERES_MARCA 21
#define CANTIDAD_CARACTERES_SERIE 11

int menu() {

	int vOpcionMenu;	  //va a contener la opcion del menu seleccionada
	int vResultadoIngreso;// va a ser 0 si el usuario ingreso la opcion de menu deseada correctamente y -1 si no

	do {
		//Imprimo el menu
		system("cls");
		printf("----------------ELECTRODOMESTICOS---------------\n");
		printf(" 1.ALTA ELECTRODOMESTICO\n");
		printf(" 2.MODIFICAR ELECTRODOMESTICO\n");
		printf(" 3.BAJA ELECTRODOMESTICOS\n");
		printf(" 4.LISTAR ELECTRODOMESTICOS\n");
		printf(" 5.LISTAR MARCAS\n");
		printf(" 6.LISTAR SERVICIOS\n");
		printf(" 7.ALTA REPARACION\n");
		printf(" 8.LISTAR REPARACIONES\n");
		printf(" 9.LISTAR CLIENTES\n");
		printf(" 10.INFORMES\n");
		printf(" 11.SALIR\n");
		printf("-----------------------------------------------\n");

		//Pido el ingreso de un numero entero entre 1 y 5 para seleccionar la opcion de menu
		vResultadoIngreso = utn_getNumero(&vOpcionMenu,
				" Ingrese la opcion deseada: ",
				" No ingreso una opcion valida.\n Vuelva a intentarlo.\n", 1,
				11, 0);

	} while (vResultadoIngreso == -1);//Mientras que el el ingreso sea erroneo continuo pidiendolo

	system("cls");

	return vOpcionMenu;
}
void altasElectrodomestico(eElectrodomesticos *listaElectrodomesticos,
		int largoElectrodomesticos, int *pcontadorIdElect, eMarca *listaMarcas,
		int largoMarcas) {

	int vBanderaReintentos = 1;	// (1) se quedo sin reintentos (0) cargo correctamente
	eElectrodomesticos electrodomesticoIngresado;// contendra la informacion del alumno que ingresa el usuario

	if (listaElectrodomesticos != NULL && largoElectrodomesticos > 0
			&& *pcontadorIdElect >= 0 && listaMarcas != NULL
			&& largoMarcas > 0) {

		if (pedirSeriePorPantalla(listaElectrodomesticos,
				largoElectrodomesticos, CANTIDAD_CARACTERES_SERIE,
				" Ingrese el numero de serie \n",
				" Ingreso un numero de serie invalido\n", REINTENTOS,
				electrodomesticoIngresado.serie) == 0) {
			system("cls");

			if (pedirMarcaPorID(&electrodomesticoIngresado.idMarca,
					" Ingrese el id de la marca: ", " Id ingresado invalido. ",
					listaMarcas, largoMarcas, REINTENTOS) == 0) {
				system("cls");
				if (utn_getNumero(&electrodomesticoIngresado.modelo,
						" Ingrese el ano del modelo: ",
						" Ingreso un ano invalido", 1000, 2020, REINTENTOS)
						== 0) {
					system("cls");

					electrodomesticoIngresado.id = *pcontadorIdElect + 1;
					electrodomesticoIngresado.estaVacio = 0;
					vBanderaReintentos = 0;
					system("cls");

					if (agregarElectrodomesticos(listaElectrodomesticos,
							largoElectrodomesticos, electrodomesticoIngresado)
							== 0) {
						(*pcontadorIdElect)++;
						printf("\n Se le ha asignado el legajo: %d \n Alta exitosa.\n ",
								*pcontadorIdElect);

					} else {
						printf("\n Hay %d electrodomesticos cargados, no es posible cargar mas.\n No se ha dado el alta.\n ",
								largoElectrodomesticos);
					}

				}
			}
		}

		if (vBanderaReintentos == 1) {
			printf("\n No tiene mas reintentos.\n No se ha dado el alta.\n ");
		}
	}
	return;
}

void modificarElectrodomestico(eElectrodomesticos *listaElectrodomesticos,
		int largoElectrodomesticos, eMarca *listaMarcas, int largoMarca) {

	int vIdElectrodomestico;//Contendra el Id que ingresa el electrodomestico para modificar
	int vOpcionSubMenu;			//Contendra la opcion seleccionada en el submenu
	int vPosicionElectrodomestico;//Contendra el estado de la opcion ingresada en el submenu 0 EXITO, -1 ERROR
	int vRespuestaVolver = 0;//Contendra la respuesta del usuario 0 (NO) o 1 (SI) a la pregunta 'desea volver?'

	if (listaElectrodomesticos != NULL && largoElectrodomesticos > 0
			&& listaMarcas != NULL && largoMarca > 0) {

		if (hayElectrodomesticoCargado(listaElectrodomesticos, largoMarca) == 0) {
			//Si se ingreso el ID de manera correcta, es decir, si es igual a 0.
			if (pedirElectrodonesticoPorID(&vIdElectrodomestico, " Ingrese el ID del electrodomestico que desea modificar: "
					, " Tiene que ingresar un número mayor a cero.",listaElectrodomesticos,
						largoElectrodomesticos, listaMarcas, largoMarca, REINTENTOS) == 0 ) {	//Buso el Id en el listado de alumnos
				vPosicionElectrodomestico = buscarElectrodomesticosPorId(
						listaElectrodomesticos, largoElectrodomesticos,
						vIdElectrodomestico);
				//Si no se encontro el ID del alunbi en el listado comunico y vuelvo al menu inicial
				if (vPosicionElectrodomestico == -1) {
					printf(
							"\n No se ha ingresado ningun electrodomestico de Id %d ",
							vIdElectrodomestico);
				} else // Si se encontro el ID del alumnos en el listado
				{
					do {

						do { //Menu de modificacion. Sigo iterando mientras la opcion ingresada sea incorrecta
							system("cls");
							printf(
									"-----INFORMACION DEL ELECTRODOMESTICO------\n\n");

							printf("+------------+------------+--------------------------+--------------------------+\n");
							printf("|    ID      |   SERIE    |          MODELO          |    DESCRIPCION MARCA     |\n");
							printf("+------------+------------+--------------------------+--------------------------+\n");
							imprimirElectrodomestico(vPosicionElectrodomestico,
									listaElectrodomesticos,
									largoElectrodomesticos, listaMarcas,
									largoMarca);

							printf(
									"\n\n----------------MODIFICAR---------------\n");
							printf(" 1.SERIE\n");
							printf(" 2.MODELO\n");
							printf(" 3.VOLVER\n");
							printf(
									"--------------------------------------------\n");

						} while (utn_getNumero(&vOpcionSubMenu,
								" Ingrese la opcion deseada modificar: ",
								" No ingreso una opcion valida.\n Vuelva a intentarlo.\n",
								1, 4, 0) == -1);

						system("cls");

						switch (vOpcionSubMenu) { //Analizo caso por caso de la opcion seleccionada del menu
						case 1:
							//Pido el ingreso del nombre modificado (solo dejo ingresar letras), si es correcto lo modifico
							if (pedirSeriePorPantalla(listaElectrodomesticos,
									largoElectrodomesticos,
									CANTIDAD_CARACTERES_SERIE,
									" Ingrese la serie del electrodomestico \n",
									" Ingreso un numero de serie invalido\n",
									REINTENTOS,
									listaElectrodomesticos[vPosicionElectrodomestico].serie)
									== 0) {
								system("cls");
								printf("\n Modificacion realizada.\n ");
							} else {
								system("cls");
								printf("\n No se realizo la modificacion.\n ");
							}
							system("pause");
							break;
						case 2:
							if (utn_getNumero(
									&listaElectrodomesticos[vPosicionElectrodomestico].modelo,
									" Ingrese el modelo modificado: ",
									" No ingreso un ano valida (1000-2020) ",
									1000, 2020, REINTENTOS) == 0) {
								system("cls");
								printf("\n Modificacion realizada.\n ");
							} else {
								system("cls");
								printf("\n No se realizo la modificacion.\n ");
							}
							system("pause");
							break;
						case 3:
							//Pregunto si desea volver al menu
							do {
								vRespuestaVolver = unt_preguntaRespuestaBinaria(
										" Desea volver?(s/n) ", 's', 'n');
								system("cls");
							} while (vRespuestaVolver == -1);
							break;
						}

					} while (vRespuestaVolver == 0); //Siempre que la respuesta de salida sea 0 vuelvo a iterar

					system("cls");
				}
			} else {
				system("cls");
				printf("\n Ya no tiene reintentos.\n ");
				system("pause");
			}
		} else {
			system("cls");
			printf("\n No puede modificar, no hay electrodomesticos cagados.\n ");
			system("pause");

		}
	}

	return;
}

void bajaElectrodomesticos(eElectrodomesticos *listaElectrodomesticos,
		int largoElectrodomesticos, eMarca *listaMarcas, int largoMarcas,
		eReparacion *listaReparacion, int largoReparacion) {

	int vIdElectrodomestico;//Contendra el ID que el usuario ingresa para eliminar
	int vRetornoRespuestaEliminar = 0; /* (1) si desea eliminar (0) si no desea eliminar
	 (-1) si no ingreso una opcion correcta*/
	int vPosicionElectrodomestico; //posicion del empleado que desea eliminar

	if (listaElectrodomesticos != NULL && largoElectrodomesticos > 0
			&& listaMarcas != NULL && largoMarcas > 0) {
		if (hayElectrodomesticoCargado(listaElectrodomesticos,
				largoElectrodomesticos) == 0) {
			//Pido al usuario que ingrese el ID y veo si ingreso el usuario correctamente (EXITO)
			if (pedirElectrodonesticoPorID(&vIdElectrodomestico, " Ingrese el ID del usuario que desea eliminar: "
					," No ingreso un Id valido.",listaElectrodomesticos,
						largoElectrodomesticos, listaMarcas, largoMarcas, REINTENTOS) == 0) {
				system("cls");

				vPosicionElectrodomestico = buscarElectrodomesticosPorId(
						listaElectrodomesticos, largoElectrodomesticos,
						vIdElectrodomestico);

				if (vPosicionElectrodomestico >= 0) {
					//Pido el usuario confirmacion 's' o 'n' para eliminar y veo is confirma la eliminacion
					do {
						printf("----------------ELIMINAR---------------\n \n");
						printf("+------------+------------+--------------------------+--------------------------+\n");
						printf("|    ID      |   SERIE    |          MODELO          |    DESCRIPCION MARCA     |\n");
						printf("+------------+------------+--------------------------+--------------------------+\n");
						if (imprimirElectrodomestico(vPosicionElectrodomestico,
								listaElectrodomesticos, largoElectrodomesticos,
								listaMarcas, largoMarcas) == 0) {
							vRetornoRespuestaEliminar =
									unt_preguntaRespuestaBinaria(
											"\n Esta seguro que desea eliminarlo?(s/n) ",
											's', 'n');
							system("cls");
						}
					} while (vRetornoRespuestaEliminar == -1);

					if (vRetornoRespuestaEliminar == 1) {
						//Si se elimino exitosamente pongo la variable de retorno en 0 (EXITO)
						if (removerReparacionPorSerieElectrod(listaReparacion, largoReparacion,
								vIdElectrodomestico,listaElectrodomesticos,	largoElectrodomesticos) == 0)
						{
							if(removerElectrodomesticos(listaElectrodomesticos,
											largoElectrodomesticos, vIdElectrodomestico) == 0){
								printf("\n Electrodomestico eliminado. ");
								printf("\n Reparaciones del electrodomestico eliminadas.\n ");
							}

						}else{

							if(removerElectrodomesticos(listaElectrodomesticos,
											largoElectrodomesticos, vIdElectrodomestico) == 0){
								printf("\n Electrodomestico eliminado. ");
								printf("\n No hay reparaciones para eliminar.\n ");
							}else
							{
								printf("\n No se elimino el electrodomestico.\n ");
							}
						}


					} else {
						printf("\n No se elimino el electrodomestico.\n ");
					}

				} else {
					printf("\n No se ha ingresado ningun empleado de Id %d ",vIdElectrodomestico);
				}

			} else {
				printf("\n Ya no tiene reintentos.\n ");
			}

		} else {
			printf("\n No puede eliminar, no hay empleados cagados.\n ");
		}
	}

	return;
}

void altaReparacion(eReparacion *listaReparaciones, int largoReparaciones,
		int *vContadorIdReparacion, eServicio *listaServicios,
		int largoServicios, eElectrodomesticos *listaElectrodomesticos,
		int largoElectrodomesticos, eMarca *listaMarca, int largoMarca,
		eCliente *listaClientes, int largoClientes) {

	int vBanderaReintentos = 1;	// (1) se quedo sin reintentos (0) cargo correctamente
	eReparacion reparacionIngresado;// contendra la informacion del alumno que ingresa el usuario

	if (listaReparaciones != NULL
			&& largoReparaciones
					> 0&& *vContadorIdReparacion >= 0 &&
					listaServicios!= NULL && largoServicios>0 && listaElectrodomesticos!=NULL && largoElectrodomesticos>0 && largoMarca>0 && listaMarca !=NULL && listaClientes != NULL
					&& largoClientes>0) {
		if (hayElectrodomesticoCargado(listaElectrodomesticos,
				largoElectrodomesticos) == 0) {

			if (pedirElectrodomesticoPorSerie(reparacionIngresado.serie,
					" Ingrese la serie del electrodomestico: ",
					" La serie ingresada es invalida ", listaElectrodomesticos,
					largoElectrodomesticos, REINTENTOS, listaMarca, largoMarca)
					== 0) {
				system("cls");
				if (pedirServicioPorID(&reparacionIngresado.idServicio,
						" Ingrese el id del servicio: ",
						" Ingreso un id invalido", listaServicios,
						largoServicios, REINTENTOS) == 0) {
					system("cls");

					if (utn_getFecha(&reparacionIngresado.fecha.dia,
							&reparacionIngresado.fecha.mes,
							&reparacionIngresado.fecha.anio,
							" Ingrese la fecha de reparacion (dd/mm/aaaa)",
							" Ingreso una fecha invalida.", REINTENTOS) == 0) {
						system("cls");

						if (pedirClientePorId(&reparacionIngresado.idCliente,
								" Ingrese el id del cliente",  " Id ingresado invalido ", listaClientes, largoClientes, REINTENTOS) == 0)
						{

							reparacionIngresado.id = *vContadorIdReparacion + 1;
							reparacionIngresado.estaVacio = 0;
							vBanderaReintentos = 0;
							system("cls");

							if (agregarReparacion(listaReparaciones,
									largoReparaciones, reparacionIngresado)
									== 0)
							{
								(*vContadorIdReparacion)++;
								printf("\n Se le ha asignado el legajo: %d \n Alta exitosa.\n ",
										*vContadorIdReparacion);

							} else
							{
								printf("\n Hay %d reparaciones cargados, no es posible cargar mas.\n No se ha dado el alta.\n ",
										largoReparaciones);
							}
						}
					}
				}
			}

			if (vBanderaReintentos == 1) {
				printf(
						"\n No tiene mas reintentos.\n No se ha dado el alta.\n ");
			}
		} else {
			system("cls");
			printf(
					"\n No puede dar de alta reparaciones, no hay electrodomesticos cagados.\n ");
		}

	}
	return;
}
void listarElectrodomesticos(eElectrodomesticos *listaElectrodomesticos,
		int largoElectrodomesticos, eMarca *listaMarcas, int largoMarcas) {

	int vOpcionSubMenu;				//Contendra la opcion del menu seleccionada

	if (listaElectrodomesticos != NULL && largoElectrodomesticos > 0
			&& listaMarcas != NULL && largoMarcas > 0) {

		if (hayElectrodomesticoCargado(listaElectrodomesticos,
				largoElectrodomesticos) == 0) {

			do {
				system("cls");

				printf(
						"----------------LISTA DE ELECTRODONESTICOS----------------\n");
				printf(" 1.ORDENADA POR SERIE Y MODELO DE MANERA ASCENDENTE\n");
				printf(
						" 2.ORDENADA POR SERIE Y MODELO DE MANERA DESCENDENTE\n");
				printf(
						"-----------------------------------------------------------\n");

			} while (utn_getNumero(&vOpcionSubMenu,
					" Ingrese la opcion que desea: ",
					" No ingreso una opcion valida.\n Vuelva a intentarlo.\n",
					1, 2, 0) == -1);
			system("cls");

			switch (vOpcionSubMenu) {
			case 1:
				if (ordenarElectrodomesticos(listaElectrodomesticos,
						largoElectrodomesticos, listaMarcas, largoMarcas, 1)
						== 0
						&& imprimirElectrodomesticos(listaElectrodomesticos,
								largoElectrodomesticos, listaMarcas,
								largoMarcas) == 0) {
					printf("\n Informe finalizado.\n ");
				}
				break;
			case 2:

				if (ordenarElectrodomesticos(listaElectrodomesticos,
						largoElectrodomesticos, listaMarcas, largoMarcas, 0)
						== 0
						&& imprimirElectrodomesticos(listaElectrodomesticos,
								largoElectrodomesticos, listaMarcas,
								largoMarcas) == 0) {
					printf("\n Informe finalizado.\n ");
				}

				break;
			}

		} else {
			system("cls");
			printf(
					"\n No puede informar, no hay electrodomesticos cagados.\n ");
		}
	}

	return;
}
void listarMarcas(eMarca *listaMarcas, int largoMarcas,
		eElectrodomesticos *listaElectrodomesticos, int largoElectrodomesticos) {

	if (listaMarcas != NULL && largoMarcas > 0 && listaElectrodomesticos != NULL
			&& largoElectrodomesticos > 0) {
		if (hayElectrodomesticoCargado(listaElectrodomesticos,
				largoElectrodomesticos) == 0) {

			mostrarMarcas(listaMarcas, largoMarcas);

		} else {

			system("cls");
			printf(
					"\n No puede informar, no hay electrodomesticos cagados.\n ");

		}

	}

	return;
}
void listarServicios(eServicio *listaServicios, int largoServicios,
		eElectrodomesticos *listaElectrodomesticos, int largoElectrodomesticos) {

	if (listaServicios != NULL && largoServicios > 0
			&& listaElectrodomesticos != NULL && largoElectrodomesticos > 0) {
		if (hayElectrodomesticoCargado(listaElectrodomesticos,
				largoElectrodomesticos) == 0) {

			if (mostrarServicios(listaServicios, largoServicios) == 0) {
				printf("\n Listado finalizado.");
				system("pause");
			}

		} else {

			system("cls");
			printf(
					"\n No puede informar, no hay electrodomesticos cagados.\n ");
			system("pause");
		}

	}

	return;
}
void listarReparaciones(eReparacion *listaReparaciones, int largoReparaciones,
		eServicio *listaServicios, int largoServicios,
		eElectrodomesticos *listaElectrodomesticos, int largoElectrodomesticos,
		eCliente *listaClientes, int largoClientes) {

	if (listaServicios != NULL && largoServicios > 0
			&& listaElectrodomesticos != NULL && largoElectrodomesticos > 0
			&& listaReparaciones != NULL && largoReparaciones > 0) {
		if (hayElectrodomesticoCargado(listaElectrodomesticos,
				largoElectrodomesticos) == 0) {

			if (imprimirReparaciones(listaReparaciones, largoReparaciones,
					listaServicios, largoServicios, listaClientes,
					largoClientes) == 0) {
				printf("\n Listado finalizado.\n");
				system("pause");
			}

		} else {

			system("cls");
			printf(
					"\n No puede informar, no hay electrodomesticos cagados.\n ");
			system("pause");
		}

	}

	return;

}
void listarClientes(eCliente *listaClientes, int largoClientes,
		eElectrodomesticos *listaElectrodomesticos, int largoElectrodomesticos) {

	if (listaClientes != NULL && largoClientes > 0
			&& listaElectrodomesticos != NULL && largoElectrodomesticos > 0) {
		if (hayElectrodomesticoCargado(listaElectrodomesticos,
				largoElectrodomesticos) == 0) {

			if (mostarClientes(listaClientes, largoClientes) == 0) {
				printf("\n Listado finalizado.\n");
				system("pause");
			}

		} else {

			system("cls");
			printf("\n No puede informar, no hay electrodomesticos cagados.\n ");
			system("pause");
		}
	}
	return;
}
void informes(eCliente* listaClientes, int largoClientes, eReparacion* listaReparacion, int largoReparacion,
		eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos, eMarca* listaMarcas,
		int largoMarcas, eServicio* listaServicios, int largoServicios)
{
	int vOpcionSubMenu;				//Contendra la opcion del menu seleccionada
	int vIdIngresado;
	char serie[CANTIDAD_CARACTERES_SERIE];
	int vRespuestaVolver = 0;
	eFecha fechaIngresada;


	if (hayElectrodomesticoCargado(listaElectrodomesticos,
					largoElectrodomesticos) == 0) {
		do{
			do {
				system("cls");

				printf(
						"------------------------LISTA DE ELECTRODOMESTICOS------------------------\n");
				printf(" 1.INFORMAR LOS ELECTRODOMESTICOS DEL MODELO 2020.\n");
				printf(" 2.INFORMAR LOS ELECTRODOMESTICOS DE UNA MARCA. \n");
				printf(" 3.INFORMAR LAS REPARACIONES DE UN ELECTRODOMESTICO.\n");
				printf(" 4.INFORMAR LOS ELECTRODOMESTICOS QUE NO TUVIERON REPARACIONES.\n");
				printf(" 5.INFORMAR EL IMPORTE TOTAL DE LAS REPARACIONES EFECTUADAS A UN ELECTRODOMESTICO\n");
				printf(" 6.INFORMAR EL SERVICIO MAS PEDIDO.\n");
				printf(" 7.INFORMAR LA RECAUDACION DE LA FECHA INGRESADA.\n");
				printf(" 8.INFORMAR LOS ELECTRODOMESTICOS QUE REALIZARON UNA GARANTIA Y LA FECHA.\n");
				printf(" 9.INFORMAR TRABAJOS REALIZADOS AL ELECTRODOMESTICO DE MODELO 2018.\n");
				printf(" 10.INFORMAR FACTURACION TOTAL POR LOS MANTENIMIENTOS.\n");
				printf(" 11.INFORMAR LA MARCA DE ELECTRODOMESTICOS CON MAS REFACCIONES.\n");
				printf(" 12.INFORMAR LOS ELECTRODOMESTIOCOS QUE RECIBIERON REPARACION A UNA FECHA.\n");
				printf(" 13.VOLVER\n");
				printf("---------------------------------------------------------------------------\n");

			} while (utn_getNumero(&vOpcionSubMenu,
					" Ingrese la opcion que desea: ",
					" No ingreso una opcion valida.\n Vuelva a intentarlo.\n",
					1, 13, 0) == -1);
			system("cls");

			switch(vOpcionSubMenu){
			case 1:
				if(informarElectrdomesticos2020(listaElectrodomesticos, largoElectrodomesticos, listaMarcas, largoMarcas)==0){
					printf(" Informe finalizado. \n ");
					system("pause");
				}
				break;
			case 2:
				if(pedirMarcaPorID(&vIdIngresado," Ingrese el id de la marca deseada: "
						," El id ingresado es invalido.",listaMarcas, largoMarcas, REINTENTOS)==0)
				{
					if(informarElectDeMarca(vIdIngresado, listaElectrodomesticos, largoElectrodomesticos, listaMarcas, largoMarcas) ==0)
					{
						printf(" Informe finalizado. \n ");
						system("pause");
					}else{
						printf("La marca ingresada no tiene electrodomesticos para informar.\n ");
						system("pause");
					}
				}
				break;
			case 3:
				if(pedirElectrodomesticoPorSerie(serie, " Ingrese la serie del electrodomestico del que desea el informe: ",
						" No ingreso una serie valida. ",
						listaElectrodomesticos, largoElectrodomesticos, REINTENTOS,
						listaMarcas, largoMarcas)==0)
				{
					if(informeMostrarReparacionDeSerie(serie, listaClientes, largoClientes,
							listaReparacion, largoReparacion, listaServicios, largoServicios,
							listaElectrodomesticos, largoElectrodomesticos) == 0)
					{
						printf(" Informe finalizado. \n ");
						system("pause");
					}else{
						printf(" El electrodomestico ingresado no tiene reparaciones para informar.\n ");
						system("pause");
					}
				}
				break;
			case 4:
				if(informarElectrodomesticosSinRep(listaElectrodomesticos, largoElectrodomesticos, listaMarcas, largoMarcas, listaReparacion, largoReparacion) == 0)
								{
										printf(" Informe finalizado. \n ");
										system("pause");
								}
				break;
			case 5:
				if(pedirElectrodomesticoPorSerie(serie, " Ingrese la serie del electrodomestico que desea: ",
						" La serie ingresada es incorrecta", listaElectrodomesticos, largoElectrodomesticos, REINTENTOS, listaMarcas, largoMarcas)==0)
				{
					if(informarImporteRepDelElect(serie, listaElectrodomesticos, largoElectrodomesticos, listaServicios, largoServicios, listaReparacion, largoReparacion)==0)
					{
						printf(" Informe finalizado. \n ");
						system("pause");
					}
				}
				break;
			case 6:
				if(informarServicioMasPedido(listaReparacion, largoReparacion, listaServicios, largoServicios)==0)
				{
					printf(" Informe finalizado. \n ");
					system("pause");
				}
				break;
			case 7:
				if(utn_getFecha(&fechaIngresada.dia,&fechaIngresada.mes, &fechaIngresada.anio, " Ingrese la fecha que desea: ",
						" La fecha ingresada es invalida,", REINTENTOS) == 0 )
				{
					if(informarRecaudacionDeFecha(listaReparacion, largoReparacion, listaServicios, largoServicios, fechaIngresada)==0){
						printf(" Informe finalizado. \n ");
						system("pause");
					}
				}
				break;
			case 8:
				if(informarElectrodConGaranta(listaElectrodomesticos, largoElectrodomesticos, listaReparacion, largoReparacion, listaServicios, largoServicios)==0){
					printf(" Informe finalizado. \n ");
					system("pause");
				}
				break;
			case 9:
				if(informarTrabajos2020(listaElectrodomesticos, largoElectrodomesticos, listaReparacion,
						largoReparacion, listaServicios, largoServicios, listaClientes, largoClientes)==0)
				{
					printf(" Informe finalizado. \n ");
					system("pause");
				}
				break;
			case 10:
				if(informarFactTotalMantenimiento(listaReparacion, largoReparacion, listaServicios, largoServicios)==0){
					printf(" Informe finalizado. \n ");
					system("pause");
				}
				break;
			case 11:

				if(informarMarcaElectConMasRep(listaReparacion, largoReparacion, listaElectrodomesticos, largoElectrodomesticos, listaMarcas, largoMarcas)==0){
					printf(" Informe finalizado. \n ");
					system("pause");
				}
				break;
			case 12:
				if(utn_getFecha(&fechaIngresada.dia,&fechaIngresada.mes, &fechaIngresada.anio, " Ingrese la fecha que desea: ",
										" La fecha ingresada es invalida,", REINTENTOS) == 0 )
								{
					if(informarElectConRepEnFecha(listaReparacion, largoReparacion, listaServicios,
							largoServicios, fechaIngresada, listaElectrodomesticos, largoElectrodomesticos, listaMarcas, largoMarcas)==0)
					{
						printf(" Informe finalizado. \n ");
						system("pause");
					}
				}
				break;
			case 13://Pregunto si desea volver al menu
				do {
					vRespuestaVolver = unt_preguntaRespuestaBinaria(
							" Desea volver?(s/n) ", 's', 'n');
					system("cls");
				} while (vRespuestaVolver == -1);
				break;
			}

		} while (vRespuestaVolver == 0); //Siempre que la respuesta de salida sea 0 vuelvo a iterar


	}else
	{
		system("cls");
		printf("\n No puede informar, no hay electrodomesticos cagados.\n ");
		system("pause");
	}

	return;
}
