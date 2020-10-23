/*
 * ArrayMarca.c
 *
 *  Created on: 15 oct. 2020
 *      Author: CLEM
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayMarca.h"
#include "utn_validaciones.h"


int buscarMarca(eMarca *lista, int largo, int id) {

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
int mostrarMarca(eMarca *lista, int largo, int id) {

	int vRetorno = -1;
	int vPosicion;

	if (lista != NULL && largo > 0) {
		vPosicion = buscarMarca(lista, largo, id);
		if (vPosicion >= 0) {
			printf("|%20d|%50s|", id, lista[vPosicion].descripcion);
			vRetorno = 0;
		}
	}
	return vRetorno;
}
int mostrarMarcas(eMarca *lista, int largo) {
	int vRetorno = -1;
	int i;

	if (lista != NULL && largo > 0) {
		printf("+--------------------+--------------------------------------------------+\n");
		printf("|         ID         |                    DESCRIPCION                   |\n");
		printf("+--------------------+--------------------------------------------------+\n");
		for (i = 0; i < largo; i++) {
			printf("|%20d|%50s|\n", lista[i].id, lista[i].descripcion);
			printf("+--------------------+--------------------------------------------------+\n");
		}
		vRetorno = 0;
	}
	return vRetorno;
}
int validarIdMarca(eMarca *listadoMarcas, int largoMarcas,
		int idMarca) {

	int vRetorno = -1;
	int i;

	if (listadoMarcas != NULL && largoMarcas > 0 && idMarca >= 0) {
		for (i = 0; i < largoMarcas; i++) {

			if (listadoMarcas[i].id == idMarca) {
				vRetorno = 0;
				break;
			}
		}
	}

	return vRetorno;
}

int pedirMarcaPorID(int *pIdResultado, char *mensaje, char *mensajeError ,eMarca *listadoMarcas,
		int largoMarcas, int reintentos) {

	int vRetorno = -1;
	int vBufferId;

	if (pIdResultado != NULL && listadoMarcas != NULL && largoMarcas > 0
			&& reintentos >= 0) {
		do {
			system("cls");
			if (mostrarMarcas(listadoMarcas, largoMarcas) == 0
					&& utn_getNumeroMin(&vBufferId, mensaje, mensajeError, -1, 0) == 0
					&& validarIdMarca(listadoMarcas, largoMarcas, vBufferId) == 0) {
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
int cargarDescMarca(int idMarca,eMarca* listadoMarcas,int largoMarcas, char * descMarca)
{
	int vRetorno = -1;
	int i;

	if(idMarca>=0 && listadoMarcas!=NULL && largoMarcas>0 && descMarca != NULL)
	{
		for(i=0; i<(largoMarcas);i++)
		{
			if(listadoMarcas[i].id == idMarca){
				strncpy(descMarca,listadoMarcas[i].descripcion,21);
				vRetorno=0;
				break;
			}
		}
	}

	return vRetorno;
}
