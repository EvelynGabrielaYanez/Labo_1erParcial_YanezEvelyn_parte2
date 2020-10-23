/*
 * ArrayClientes.c
 *
 *  Created on: 17 oct. 2020
 *      Author: CLEM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayClientes.h"
#include "utn_validaciones.h"


int buscarCliente(eCliente* lista,int largo, int id){

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
int mostarCliente(eCliente* lista,int largo, int id) {

	int vRetorno = -1;
	int vPosicion;

	if (lista != NULL && largo > 0) {


		printf("+--------------------+------------------------------+------------------------------+\n");
		printf("|         ID         |            NOMBRE            |           APELLIDO           |\n");
		printf("+--------------------+------------------------------+------------------------------+\n");
		vPosicion = buscarCliente(lista, largo, id);

		if (vPosicion >= 0) {
			printf("|%20d|%30s|%30s|", lista[vPosicion].id, lista[vPosicion].nombre,  lista[vPosicion].apellido);
			printf("+--------------------+------------------------------+------------------------------+\n");
			vRetorno = 0;
		}
	}
	return vRetorno;
}
int mostarClientes(eCliente* lista,int  largo){
	int vRetorno = -1;
	int i;

	if (lista != NULL && largo > 0) {
		printf("+--------------------+------------------------------+------------------------------+\n");
		printf("|         ID         |            NOMBRE            |           APELLIDO           |\n");
		printf("+--------------------+------------------------------+------------------------------+\n");

		for (i = 0; i < largo; i++) {
			printf("|%20d|%30s|%30s|\n", lista[i].id,lista[i].nombre, lista[i].apellido);
			printf("+--------------------+------------------------------+------------------------------+\n");
		}
		vRetorno = 0;
	}
	return vRetorno;
}
int validarIdCliente(eCliente *listadoClientes, int largoClientes, int idCliente) {

	int vRetorno = -1;
	int i;

	if (listadoClientes != NULL && largoClientes > 0 && idCliente >= 0) {
		for (i = 0; i < largoClientes; i++) {

			if (listadoClientes[i].id == idCliente) {
				vRetorno = 0;
				break;
			}
		}
	}

	return vRetorno;
}

int pedirClientePorId(int *pIdResultado, char *mensaje, char *mensajeError ,eCliente *listadoClientes,int largoClientes, int reintentos){

	int vRetorno = -1;
	int vBufferId;

	if (pIdResultado != NULL && mensaje != NULL && mensajeError != NULL && listadoClientes != NULL /*&& largoClientes >0 && reintentos>=0*/)
	{
		do {
			system("cls");
			if (mostarClientes(listadoClientes, largoClientes) == 0
					&& utn_getNumeroMin(&vBufferId, mensaje, mensajeError, -1, 0) == 0
					&& validarIdCliente(listadoClientes, largoClientes, vBufferId) == 0) {
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
int cargarDescCliente(int idCliente, eCliente* listadoClientes,int largoClientes, char * nomCliente, char * apellCliente)
{
	int vRetorno = -1;
	int i;

	if(idCliente>=0 && listadoClientes!=NULL && largoClientes>0 && nomCliente != NULL && apellCliente!= NULL )
	{
		for(i=0; i<(largoClientes);i++)
		{
			if(listadoClientes[i].id == idCliente){
				strncpy(nomCliente,listadoClientes[i].nombre,21);
				strncpy(apellCliente,listadoClientes[i].apellido,21);
				vRetorno=0;
				break;
			}
		}
	}

	return vRetorno;
}


