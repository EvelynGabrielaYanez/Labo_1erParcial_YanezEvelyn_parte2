/*
 * ArrayServicio.c
 *
 *  Created on: 15 oct. 2020
 *      Author: CLEM
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayServicio.h"
#include "utn_validaciones.h"

int buscarServicio(eServicio* lista,int largo, int id){

	int vRetorno = -1;
	int i;

	if (lista != NULL && largo > 0) {
		for (i = 0; i < largo; i++) {
			if (lista[i].id == id) {
				vRetorno = i;
				break;
			}
		}

	}

	return vRetorno;
}
int mostrarServicio(eServicio *lista, int largo, int id) {

	int vRetorno = -1;
	int vPosicion;

	if (lista != NULL && largo > 0) {
		vPosicion = buscarServicio(lista, largo, id);
		if (vPosicion >= 0) {
			printf("|%20d|%50s|%20.2f|\n", lista[vPosicion].id, lista[vPosicion].descripcion,lista[vPosicion].precio);
			vRetorno = 0;
		}
	}
	return vRetorno;
}
int mostrarServicios(eServicio* lista,int  largo) {
	int vRetorno = -1;
	int i;

	if (lista != NULL && largo > 0) {
		printf(
				"+--------------------+--------------------------------------------------+--------------------+\n");
		printf(
				"|         ID         |                    DESCRIPCION                   |       PRECIO       |\n");
		printf(
				"+--------------------+--------------------------------------------------+--------------------+\n");
		for (i = 0; i < largo; i++) {
			printf("|%20d|%50s|%20.2f|\n", lista[i].id, lista[i].descripcion,lista[i].precio);
			printf(
					"+--------------------+--------------------------------------------------+--------------------+\n");
		}
		vRetorno = 0;
	}
	return vRetorno;
}
int validarIdServicio(eServicio *listadoServicios, int largoServicios, int idServicio) {

	int vRetorno = -1;
	int i;

	if (listadoServicios != NULL && largoServicios > 0 && idServicio >= 0) {
		for (i = 0; i < largoServicios; i++) {

			if (listadoServicios[i].id == idServicio) {
				vRetorno = 0;
				break;
			}
		}
	}

	return vRetorno;
}

int pedirServicioPorID(int *pIdResultado, char *mensaje, char *mensajeError ,eServicio *listadoServicios,
		int largoServicios, int reintentos) {

	int vRetorno = -1;
	int vBufferId;

	if (pIdResultado != NULL && listadoServicios != NULL && largoServicios > 0
			&& reintentos >= 0) {
		do {
			system("cls");
			if (mostrarServicios(listadoServicios, largoServicios) == 0
					&& utn_getNumeroMin(&vBufferId, mensaje, mensajeError, -1, 0) == 0
					&& validarIdServicio(listadoServicios, largoServicios, vBufferId) == 0) {
				*pIdResultado = vBufferId;
				vRetorno = 0;
				system("cls");
				break;
			}
			reintentos--;
		} while (reintentos >= 0);

	}

	return vRetorno;
}
int cargarDescServicio(int idServicio,eServicio* listadoServicios,int largoServicios, char * descServicio)
{
	int vRetorno = -1;
	int i;

	if(idServicio>=0 && listadoServicios!=NULL && largoServicios>0 && descServicio != NULL)
	{


		for(i=0; i<largoServicios;i++)
		{

			if(listadoServicios[i].id == idServicio){
				strncpy(descServicio,listadoServicios[i].descripcion,26);
				vRetorno=0;
				break;
			}
		}
	}

	return vRetorno;
}
int cargarImporteServicio(int idServicio,eServicio* listadoServicios,int largoServicios, float* importe)
{
	int vRetorno = -1;
	int i;

	if(idServicio>=0 && listadoServicios!=NULL && largoServicios>0 && importe>0)
	{
		for(i=0; i<largoServicios;i++)
		{
			if(listadoServicios[i].id == idServicio){
				*importe = listadoServicios[i].precio;
				vRetorno=0;
				break;
			}
		}
	}

	return vRetorno;
}

int cargarDescImporteServicio(int idServicio,eServicio* listadoServicios,int largoServicios, char * descServicio, float* precioServicio)
{
	int vRetorno = -1;
	int i;

	if(idServicio>=0 && listadoServicios!=NULL && largoServicios>0 && descServicio != NULL)
	{


		for(i=0; i<largoServicios;i++)
		{

			if(listadoServicios[i].id == idServicio){
				strncpy(descServicio,listadoServicios[i].descripcion,26);
				*precioServicio = listadoServicios[i].precio;
				vRetorno=0;
				break;
			}
		}
	}

	return vRetorno;
}

