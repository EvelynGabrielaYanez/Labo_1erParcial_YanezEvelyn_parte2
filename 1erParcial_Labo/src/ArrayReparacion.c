/*
 * ArrayReparacion.c
 *
 *  Created on: 15 oct. 2020
 *      Author: CLEM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayReparacion.h"


int inicializarReparacion(eReparacion* listaReparacion, int largoReparacion){
	int vRetorno = 0;
	int i;

	if (listaReparacion != NULL && largoReparacion > 0)
	{
		for (i = 0; i < largoReparacion; i++)
		{
			listaReparacion[i].estaVacio = 1;
		}

	} else
	{
		vRetorno = -1;
	}

	return vRetorno;
}

int agregarReparacion(eReparacion *listaReparacion, int largoReparacion, eReparacion reparacionIngresada){

	int i;
	int vRetorno = -1;
	//Controlo si hay o no espacio libre

	if (listaReparacion != NULL && largoReparacion > 0) {

		for (i = 0; i <= largoReparacion; i++) {

			if (listaReparacion[i].estaVacio == 1) { //Controlo si hay alguno libre

				//cargo los parametros recibidos
				listaReparacion[i]=reparacionIngresada;
				vRetorno = 0;
				break;
			}
		}
	}

	return vRetorno;
}

int buscarReparacionPorId(eReparacion* listaReparacion, int largoReparacion,int id){

	int vRetorno = -1;
	int i;

	if (listaReparacion != NULL && largoReparacion > 0) {

		for (i = 0; i < largoReparacion; i++) {

			if (listaReparacion[i].id == id && listaReparacion[i].estaVacio == 0) {
				vRetorno = i;
				break;
			}
		}
	}

	return vRetorno;

}
int removerReparacion(eReparacion* listaReparacion, int largoReparacion, int id){

	int vRetorno = -1;
	int posicion;

	if (listaReparacion != NULL && largoReparacion > 0) {
		posicion = buscarReparacionPorId(listaReparacion, largoReparacion, id);
		if (posicion >= 0) {
			listaReparacion[posicion].estaVacio = 1;
			vRetorno = 0;
		}
	}

	return vRetorno;
}

int imprimirReparaciones(eReparacion * listaReparacion, int largoReparacion,eServicio* listaServicios, int largoServicios, eCliente* listaClientes,int largoClientes)  {

	int vRetorno = -1;
	int i;
	char descServicio[26];
	char nombreCliente[21];
	char apellidoCliente[21];

	if (listaReparacion != NULL && largoReparacion > 0 && listaServicios != NULL && largoServicios>0) {


		printf("+------------+----------+--------------------------+--------------------------+--------------------------+\n");
		printf("|   SERIE    |   FECHA  | DESCRIPCION DEL SERVICIO |      NOMBRE CLIENTE      |     APELLIDO CLIENTE     |\n");
		printf("+------------+----------+--------------------------+--------------------------+--------------------------+\n");

		for (i = 0; i < largoReparacion; i++) {

			if (cargarDescServicio(listaReparacion[i].idServicio, listaServicios, largoServicios, descServicio)==0 &&
					cargarDescCliente(listaReparacion[i].idCliente, listaClientes, largoClientes, nombreCliente, apellidoCliente) == 0) {

				if(listaReparacion[i].estaVacio == 0){
					printf("|%12s|%2d/%2d/%4d|%26s|%26s|%26s|\n",
							listaReparacion[i].serie,listaReparacion[i].fecha.dia,
							listaReparacion[i].fecha.mes, listaReparacion[i].fecha.anio,descServicio, nombreCliente,apellidoCliente);
					printf("+------------+----------+--------------------------+--------------------------+--------------------------+\n");
					vRetorno = 0;
				}
			}
		}
	}
	return vRetorno;
}
int imprimirReparacion(int posicion,eReparacion *listaReparacion, int largoReparacion,
		eServicio* listaServicios, int largoServicios, eCliente* listaClientes,int largoClientes){

	int vRetorno = -1;
	char descServicio[26];
	char nombreCliente[21];
	char apellidoCliente[21];

	if (listaReparacion != NULL && largoReparacion > 0 && listaServicios != NULL && largoServicios>0 && largoClientes>0 && listaClientes != NULL) {

		if (cargarDescServicio(listaReparacion[posicion].idServicio, listaServicios, largoServicios, descServicio)==0 &&
				cargarDescCliente(listaReparacion[posicion].idCliente, listaClientes, largoClientes, nombreCliente, apellidoCliente) == 0) {

			if(listaReparacion[posicion].estaVacio == 0){
				printf("|%12s|%2d/%2d/%4d|%26s|%26s|%26s|\n",
						listaReparacion[posicion].serie,listaReparacion[posicion].fecha.dia,
						listaReparacion[posicion].fecha.mes, listaReparacion[posicion].fecha.anio,descServicio, nombreCliente,apellidoCliente);
				printf("+------------+----------+--------------------------+--------------------------+--------------------------+\n");
				vRetorno = 0;
			}
		}
	}
	return vRetorno;
}
int imprimirReparacionConImporte(int posicion,eReparacion *listaReparacion, int largoReparacion,
		eServicio* listaServicios, int largoServicios, eCliente* listaClientes,int largoClientes){

	int vRetorno = -1;
	char descServicio[26];
	char nombreCliente[21];
	char apellidoCliente[21];
	float precioServicio;

	if (listaReparacion != NULL && largoReparacion > 0 && listaServicios != NULL && largoServicios>0 && largoClientes>0 && listaClientes != NULL) {

		if (cargarDescImporteServicio(listaReparacion[posicion].idServicio, listaServicios, largoServicios, descServicio,&precioServicio)==0 &&
				cargarDescCliente(listaReparacion[posicion].idCliente, listaClientes, largoClientes, nombreCliente, apellidoCliente) == 0) {

			if(listaReparacion[posicion].estaVacio == 0){
				printf("|%12s|%2d/%2d/%4d|%26s|%12.2f|%26s|%26s|\n",
						listaReparacion[posicion].serie,listaReparacion[posicion].fecha.dia,
						listaReparacion[posicion].fecha.mes, listaReparacion[posicion].fecha.anio,descServicio,
						precioServicio, nombreCliente,apellidoCliente);
				printf("+------------+----------+--------------------------+------------+--------------------------+--------------------------+\n");
				vRetorno = 0;
			}
		}
	}
	return vRetorno;
}

int sueldoPromedioReparaciones(eReparacion *listaReparacion, int largoReparacion, float *promedio) {

	int vRetorno = -1;
	int i;
	float suma = 0;
	int contadorEmpelados = 0;

	if (listaReparacion != NULL && promedio != NULL && largoReparacion > 0) {

		for (i = 0; i < largoReparacion; i++) {

			if (listaReparacion[i].estaVacio == 0)
			{
				//suma += listaElectrodomesticos[i].notaPromedio;
				contadorEmpelados++;
			}

		}

		if (contadorEmpelados == 0) {
			printf("\n No hay empleados cargados, no se puede calcular el promedio");
		} else {

			*promedio = suma / contadorEmpelados;
			vRetorno = 0;
		}

	}

	return vRetorno;

}
int hayReparacionCargada(eReparacion *listaReparacion, int largoReparacion) {

	int vRetorno = -1;
	int i;
	if (listaReparacion != NULL && largoReparacion > 0) {
		for (i = 0; i < largoReparacion; i++) {

			if (listaReparacion[i].estaVacio == 0) {
				vRetorno = 0;
				break;
			}

		}
	}

	return vRetorno;
}
int hardcodearReparaciones(eReparacion* listaReparacion ,int largoReparacion , int cantidad){

	int vContador = 0;
	int vRetorno = -1;
	int i;

	if(listaReparacion !=  NULL && largoReparacion>0 && cantidad>0 && cantidad<= largoReparacion && cantidad<11){
		eReparacion listaAuxiliar[] =
		{

				{1,"200C2",{12,5,2018},20001,1,0},
				{2,"2000A",{20,5,2013},20001,2,0},
				{3,"20L07",{4,8,2014},20001,1,0},
				{4,"20008",{20,3,2015},20001,3,0},
				{5,"20009",{11,5,2016},20001,0,0},
				{6,"20L07",{5,1,2019},20001,1,0},
				{7,"20008",{5,10,2017},20001,3,0},
				{8,"20L07",{1,1,2020} ,20001,2,0},
				{9,"2000A",{20,6,2018},20001,0,0},
				{10,"200C2",{12,5,2015},20001,1,0}
		};

			for(i =0; i<cantidad;i++){
				listaReparacion[i] = listaAuxiliar[i];
				vContador++;
			}
			vRetorno = vContador;
	}

	return vRetorno;
}

int removerReparacionPorSerieElectrod(eReparacion* listaReparacion,int largoReparacion,int vIdElectrodomestico, eElectrodomesticos* listaElectrodomestico, int largoElectrodomestico)
{
	int vRetorno = -1;
	int posicionElectrodomestico;
	int i;

	if (listaReparacion != NULL && largoReparacion > 0 && vIdElectrodomestico>0) {

		posicionElectrodomestico = buscarElectrodomesticosPorId(listaElectrodomestico, largoElectrodomestico, vIdElectrodomestico);

		if(posicionElectrodomestico>=0){

			for(i=0;i<largoReparacion;i++){

				if(listaReparacion[i].estaVacio == 0 && strcmp(listaReparacion[i].serie,listaElectrodomestico[posicionElectrodomestico].serie)==0)
				{
					listaReparacion[i].estaVacio = 1;
					vRetorno=0;
				}

			}
		}
	}

	return vRetorno;
}
