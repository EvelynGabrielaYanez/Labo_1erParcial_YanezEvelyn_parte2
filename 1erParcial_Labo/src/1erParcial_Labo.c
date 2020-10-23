/*
 ============================================================================
 Name        : 1erParcial_Labo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayElectrodomesticos.h"
#include "ArrayReparacion.h"
#include "ArrayServicio.h"
#include "ArrayMarca.h"
#include "ArrayClientes.h"
#include "utn_validaciones.h"
#include "main_modulos.h"

#define ELECTRODOMESTICOS 1000
#define REPARACIONES 1000
#define MARCAS 5
#define SERVICIOS 4
#define CLIENTES 4
int main(void) {

	setbuf(stdout, NULL);

	eElectrodomesticos listaElectrodomesticos[ELECTRODOMESTICOS];
	eReparacion listaReparaciones[REPARACIONES];
	eServicio listaServicios[] = {{20000, "Garantia", 250}, {20001, "Mantenimiento", 500}, {20002, "Repuestos", 400}, {20003, "Refaccion", 600}};
	eMarca listaMarcas[] = {{1000, "Wirpool"}, {1001, "Sony"}, {1002, "Liliana"}, {1003, "Gafa"}, {1004, "Philips"}};
	eCliente listaClientes[] = {{0,"Evelyn","Yanez"},{1,"Camila","Yanez"}, {2,"Juan Carlos","Perez"}, {3,"Claudia Virginia","Albarenga"}};

	int vRespSalir = 0; //0 = no, 1 = si
	int vContadorIdElectrodomestico = 0;
	int vContadorIdReparacion = 0;


	if (inicializarElectrodomesticos(listaElectrodomesticos, ELECTRODOMESTICOS) == 0 &&
			inicializarReparacion(listaReparaciones, REPARACIONES) == 0) {



		//vContadorIdElectrodomestico+= hardcodearElectrodomesticos(listaElectrodomesticos,ELECTRODOMESTICOS, 10);
		//vContadorIdReparacion+= hardcodearReparaciones(listaReparaciones, REPARACIONES, 10);

		do {
			switch (menu()) {
			case 1:
				altasElectrodomestico(listaElectrodomesticos, ELECTRODOMESTICOS, &vContadorIdElectrodomestico, listaMarcas, MARCAS);
				system("pause");
				break;
			case 2:
				modificarElectrodomestico(listaElectrodomesticos, ELECTRODOMESTICOS, listaMarcas, MARCAS);
				break;
			case 3:
				bajaElectrodomesticos(listaElectrodomesticos, ELECTRODOMESTICOS, listaMarcas, MARCAS, listaReparaciones, REPARACIONES);
				system("pause");
				break;
			case 4:
				listarElectrodomesticos(listaElectrodomesticos,ELECTRODOMESTICOS,listaMarcas,MARCAS);
				system("pause");
				break;
			case 5:
				listarMarcas(listaMarcas, MARCAS, listaElectrodomesticos, ELECTRODOMESTICOS);
				system("pause");
				break;
			case 6:
				listarServicios(listaServicios, SERVICIOS, listaElectrodomesticos, ELECTRODOMESTICOS);
				break;
			case 7:
				altaReparacion(listaReparaciones, REPARACIONES, &vContadorIdReparacion, listaServicios, SERVICIOS,
						listaElectrodomesticos, ELECTRODOMESTICOS, listaMarcas , MARCAS,listaClientes, CLIENTES);
				system("pause");
				break;
			case 8:
				listarReparaciones(listaReparaciones,REPARACIONES,listaServicios, SERVICIOS, listaElectrodomesticos, ELECTRODOMESTICOS,listaClientes,CLIENTES);
				break;
			case 9:
				listarClientes(listaClientes,CLIENTES, listaElectrodomesticos, ELECTRODOMESTICOS);
				break;
			case 10:
				informes(listaClientes, CLIENTES, listaReparaciones, REPARACIONES, listaElectrodomesticos,
						ELECTRODOMESTICOS, listaMarcas, MARCAS, listaServicios, SERVICIOS);
				break;
			case 11:
				do{
				//Pregunto si desea salir hasta que ingrese s o n.
				vRespSalir = unt_preguntaRespuestaBinaria("\n Desea Salir?(s/n) ", 's', 'n');
				system("cls");
				}while(vRespSalir==-1);
				break;
			}

		} while (vRespSalir == 0); // Mientras vRespSalir = n continuo en el menu
	}
	return 0;
}
