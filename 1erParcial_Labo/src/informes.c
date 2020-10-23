/*
 * informes.c
 *
 *  Created on: 18 oct. 2020
 *      Author: CLEM
 */
#include "informes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int informeMostrarReparacionPorCliente(eCliente *listaClientes,
		int largoClientes, eReparacion *listaReparciones, int largoReparaciones,
		eServicio *listaServicios, int largoServicios) {

	int vRetorno = -1;
	int i;
	int j;
	int vBanderaHayCliente = 0;

	if (listaClientes != NULL && largoClientes > 0 && listaReparciones != NULL
			&& largoReparaciones > 0 && listaServicios != NULL
			&& largoServicios > 0) {

		for (i = 0; i < largoClientes; i++) {

			printf("Reparaciones de: %s %s \n", listaClientes[i].nombre,
					listaClientes[i].apellido);

			for (j = 0; j < largoReparaciones; j++) {

				if (listaClientes[i].id == listaReparciones[j].idCliente
						&& listaReparciones[j].estaVacio == 0)
				{
					if(vBanderaHayCliente == 0){

						printf("+------------+----------+--------------------------+--------------------------+--------------------------+\n");
						printf("|   SERIE    |   FECHA  | DESCRIPCION DEL SERVICIO |      NOMBRE CLIENTE      |     APELLIDO CLIENTE     |\n");
						printf("+------------+----------+--------------------------+--------------------------+--------------------------+\n");
						vBanderaHayCliente = 1;
					}
					imprimirReparacion(j, listaReparciones, largoReparaciones,
							listaServicios, largoServicios, listaClientes,
							largoClientes);
				}
			}
			if(vBanderaHayCliente==0)
			{
				printf(" No tiene.\n");
			}
			vBanderaHayCliente = 0;

		}
		vRetorno = 0;
	}
	return vRetorno;
}

int informeMostrarReparacionDeCliente(int idCliente, eCliente *listaClientes,
		int largoClientes, eReparacion *listaReparciones, int largoReparaciones,
		eServicio *listaServicios, int largoServicios) {

	int vRetorno = -1;
	int vPosicionCliente;
	int j;
	int vBanderaHayCliente=0;

	if (listaClientes != NULL && largoClientes > 0 && listaReparciones != NULL
			&& largoReparaciones > 0 && listaServicios != NULL
			&& largoServicios > 0) {

		vPosicionCliente = buscarCliente(listaClientes, largoClientes,
				idCliente);

		if (vPosicionCliente >= 0) {
			printf("Reparaciones de: %s %s \n", listaClientes[vPosicionCliente].nombre,
					listaClientes[vPosicionCliente].apellido);

			for (j = 0; j < largoReparaciones; j++) {

				if (listaClientes[vPosicionCliente].id == listaReparciones[j].idCliente
						&& listaReparciones[j].estaVacio == 0)
				{
					if(vBanderaHayCliente == 0){
						printf("+------------+----------+--------------------------+--------------------------+--------------------------+\n");
						printf("|   SERIE    |   FECHA  | DESCRIPCION DEL SERVICIO |      NOMBRE CLIENTE      |     APELLIDO CLIENTE     |\n");
						printf("+------------+----------+--------------------------+--------------------------+--------------------------+\n");
						vBanderaHayCliente = 1;
					}
					imprimirReparacion(j, listaReparciones, largoReparaciones,listaServicios, largoServicios, listaClientes,largoClientes);
				}
			}
			if(vBanderaHayCliente==0)
			{
				printf(" No tiene.\n");
			}
			vRetorno = 0;

		}
	}
	return vRetorno;
}

int informeMostrarReparacionPorSerie(eElectrodomesticos *listaElectrodomesticos,
		int largoElectrodomesticos, eReparacion *listaReparciones, int largoReparaciones,
		eServicio *listaServicios, int largoServicios, eCliente* listaClientes, int largoClientes) {

	int vRetorno = -1;
	int i;
	int j;
	int vBanderaHayCliente= 0;

	if (listaElectrodomesticos != NULL && largoElectrodomesticos > 0 && listaReparciones != NULL
			&& largoReparaciones > 0 && listaServicios != NULL
			&& largoServicios > 0 && listaClientes != NULL && largoClientes > 0 ) {

		for (i = 0; i < largoElectrodomesticos; i++) {
			if(listaElectrodomesticos[i].estaVacio == 0){
				printf("Electrodomestico serie: %s \n", listaElectrodomesticos[i].serie);

				for (j = 0; j < largoReparaciones; j++) {

					if (strcmp(listaElectrodomesticos[i].serie,listaReparciones[j].serie)==0
							&& listaReparciones[j].estaVacio == 0  ) {

						if(vBanderaHayCliente == 0){
							printf("+------------+----------+--------------------------+--------------------------+--------------------------+\n");
							printf("|   SERIE    |   FECHA  | DESCRIPCION DEL SERVICIO |      NOMBRE CLIENTE      |     APELLIDO CLIENTE     |\n");
							printf("+------------+----------+--------------------------+--------------------------+--------------------------+\n");
							vBanderaHayCliente = 1;
						}

						imprimirReparacion(j, listaReparciones, largoReparaciones,
								listaServicios, largoServicios, listaClientes,
								largoClientes);
					}
				}
				if(vBanderaHayCliente==0)
				{
					printf(" No tiene reparaciones.\n");
				}
				vBanderaHayCliente = 0;
			}

		}
		vRetorno = 0;
	}
	return vRetorno;
}

int informeMostrarReparacionDeSerie(char* serie, eCliente *listaClientes,
		int largoClientes, eReparacion *listaReparciones, int largoReparaciones,
		eServicio *listaServicios, int largoServicios,eElectrodomesticos* listaElectrodomesticos,
		int largoElectrodomesticos) {

	int vRetorno = -1;
	int vPosicionElectrodomestico;
	int j;
	int vBanderaHayReparaciones = 0;

	if (listaClientes != NULL && largoClientes > 0 && listaReparciones != NULL
			&& largoReparaciones > 0 && listaServicios != NULL
			&& largoServicios > 0 && listaElectrodomesticos!= NULL && largoElectrodomesticos>0) {

		vPosicionElectrodomestico = buscarElectrodomesticosPorSerie(listaElectrodomesticos, largoElectrodomesticos, serie);
		if (vPosicionElectrodomestico >= 0)
		{
			printf("Reparaciones de: %s \n", listaElectrodomesticos[vPosicionElectrodomestico].serie);

			for (j = 0; j < largoReparaciones; j++) {

				if (strcmp(listaElectrodomesticos[vPosicionElectrodomestico].serie, listaReparciones[j].serie)==0
						&& listaReparciones[j].estaVacio == 0)
				{
					if(vBanderaHayReparaciones == 0){
						printf("+------------+----------+--------------------------+--------------------------+--------------------------+\n");
						printf("|   SERIE    |   FECHA  | DESCRIPCION DEL SERVICIO |      NOMBRE CLIENTE      |     APELLIDO CLIENTE     |\n");
						printf("+------------+----------+--------------------------+--------------------------+--------------------------+\n");
						vBanderaHayReparaciones = 1;
					}

					imprimirReparacion(j, listaReparciones, largoReparaciones,
							listaServicios, largoServicios, listaClientes,
							largoClientes);
				}

			}
			if(vBanderaHayReparaciones==0)
			{
				printf(" No tiene.\n");
			}
			vRetorno = 0;
		}
	}
	return vRetorno;
}
int informeReparacionesPorImporte( eCliente *listaClientes,
		int largoClientes, eReparacion *listaReparciones, int largoReparaciones,
		eServicio *listaServicios, int largoServicios,eElectrodomesticos* listaElectrodomesticos,
		int largoElectrodomesticos, float importeIngresado)
{
	int vRetorno = -1;
	int i;
	float importe;
	int vBanderaHayReparaciones = 0;

	if(listaClientes != NULL && largoClientes>0 && listaReparciones != NULL && largoReparaciones>0 &&
			listaClientes != NULL && largoClientes>0 && listaElectrodomesticos != NULL
			&& largoElectrodomesticos>0 && importeIngresado>0)
	{

		for(i=0;i<largoReparaciones;i++)
		{


			if(cargarImporteServicio(listaReparciones[i].idServicio, listaServicios, largoServicios, &importe) == 0 &&
					importe >= importeIngresado)
			{
				if(vBanderaHayReparaciones == 0){
					printf("+------------+----------+--------------------------+------------+--------------------------+--------------------------+\n");
					printf("|   SERIE    |   FECHA  | DESCRIPCION DEL SERVICIO |   IMPORTE  |      NOMBRE CLIENTE      |     APELLIDO CLIENTE     |\n");
					printf("+------------+----------+--------------------------+------------+--------------------------+--------------------------+\n");
					vBanderaHayReparaciones = 1;
				}

				if(imprimirReparacionConImporte(i, listaReparciones, largoReparaciones, listaServicios, largoServicios, listaClientes, largoClientes)==0)
				{
					vRetorno = 0;
				}
			}
		}

	}
	return vRetorno;
}

int informeCantidadRepPorCliente(eCliente *listaClientes,
		int largoClientes, eReparacion *listaReparciones, int largoReparaciones,
		eServicio *listaServicios, int largoServicios) {

	int vRetorno = -1;
	int i;
	int j;
	int contadorReparciones=0;

	if (listaClientes != NULL && largoClientes > 0 && listaReparciones != NULL
			&& largoReparaciones > 0 && listaServicios != NULL
			&& largoServicios > 0) {

		for (i = 0; i < largoClientes; i++) {

			contadorReparciones = 0;

			for (j = 0; j < largoReparaciones; j++) {

				if (listaClientes[i].id == listaReparciones[j].idCliente
						&& listaReparciones[j].estaVacio == 0)
				{
					contadorReparciones++;
				}
			}
			if(contadorReparciones>0){
				printf("\n El Cliente  %s %s tiene %d reparaciones.\n ", listaClientes[i].nombre,
						listaClientes[i].apellido, contadorReparciones);
			}else{
				printf("\n El Cliente  %s %s no tiene reparaciones.\n ", listaClientes[i].nombre,
						listaClientes[i].apellido);
			}

		}
		vRetorno = 0;
	}
	return vRetorno;
}
int informeCantidadRepPorSerie(eReparacion* listaReparacion,int largoReparacion,
						eElectrodomesticos* listaElectrodomesticos,int largoElectrodomesticos)
{

	int vRetorno = -1;
	int i;
	int j;
	int contadorReparciones=0;

	if (listaReparacion != NULL && listaElectrodomesticos != NULL
			&& largoElectrodomesticos>0 && largoReparacion>0) {

		for (i = 0; i < largoElectrodomesticos; i++) {

			if(listaElectrodomesticos[i].estaVacio == 0 ){
				contadorReparciones = 0;

				for (j = 0; j < largoReparacion; j++) {

					if (strcmp(listaElectrodomesticos[i].serie,listaReparacion[j].serie)==0
							&& listaReparacion[j].estaVacio == 0 )
					{
						contadorReparciones++;
					}
				}
				if(contadorReparciones>0)
				{
					printf("\n La Serie  %s tiene %d reparaciones.\n ", listaElectrodomesticos[i].serie,contadorReparciones);
				}else
				{
					printf("\n La Serie %s no tiene reparaciones.\n ",listaElectrodomesticos[i].serie);
				}
			}
		}
		vRetorno = 0;
	}
	return vRetorno;
}
int informarSerieConMasRep(eReparacion* listaReparacion,int largoReparacion,
						eElectrodomesticos* listaElectrodomesticos,int largoElectrodomesticos)
{
	int vRetorno = -1;
	int i;
	int j;
	int contadorReparciones[largoElectrodomesticos];
	int max=0;
	char serieMax[11];


	if (listaReparacion != NULL && listaElectrodomesticos != NULL
			&& largoElectrodomesticos>0 && largoReparacion>0) {

		for(i=0;i<largoElectrodomesticos;i++)
		{
				contadorReparciones[i]=0;
		}

		for (i = 0; i < largoElectrodomesticos; i++) {

			if(listaElectrodomesticos[i].estaVacio == 0 ){

				for (j = 0; j < largoReparacion; j++) {

					if (strcmp(listaElectrodomesticos[i].serie,listaReparacion[j].serie)==0
							&& listaReparacion[j].estaVacio == 0 )
					{
						contadorReparciones[i]++;
					}
				}
			}
		}
		for(i=0;i<largoElectrodomesticos;i++)
		{
			if(max<contadorReparciones[i])
			{
				max = contadorReparciones[i];
				strcpy(serieMax ,listaElectrodomesticos[i].serie);
			}

		}
		if(contadorReparciones>0)
		{
			printf("\n La serie con mas reparaciones es  %s tiene %d reparaciones.\n ", serieMax,max);
		}else
		{
			printf("\n No hay ninguna reparacion.\n ");
		}
		vRetorno = 0;

	}
	return vRetorno;

}
int informarClienteConMasRep(eReparacion* listaReparacion,int largoReparacion,
						eCliente* listaClientes,int largoClientes)
{

	int vRetorno = -1;
	int i;
	int j;
	int contadorReparciones[largoClientes];
	int max=0;
	char apellidoMax[21];
	char nombreMax[21];


	if (listaReparacion != NULL && listaClientes != NULL
			&& largoClientes>0 && largoReparacion>0) {

		for(i=0;i<largoClientes;i++)
		{
				contadorReparciones[i]=0;
		}

		for (i = 0; i < largoClientes; i++) {


			for (j = 0; j < largoReparacion; j++) {

				if (listaClientes[i].id == listaReparacion[j].idCliente
						&& listaReparacion[j].estaVacio == 0 )
				{
					contadorReparciones[i]++;
				}
			}

		}
		for(i=0;i<largoClientes;i++)
		{
			if(max<contadorReparciones[i])
			{
				max = contadorReparciones[i];
				strcpy(apellidoMax ,listaClientes[i].apellido);
				strcpy(nombreMax ,listaClientes[i].nombre);
			}

		}
		if(contadorReparciones>0)
		{
			printf("\n El Cliente con mas reparaciones es  %s %s y tiene %d reparaciones.\n ", nombreMax, apellidoMax ,max);
		}else
		{
			printf("\n No hay ninguna reparacion.\n ");
		}

		vRetorno = 0;
	}
	return vRetorno;
}
int informarElectPorMarca(eElectrodomesticos* listaElectrodomesticos,int largoElectrodomesticos,eMarca* listaMarcas,int largoMarcas)
{
	int vRetorno = -1;
	int i;
	int j;
	int vBanderaHayElectrodomestico = 0;

	if (listaElectrodomesticos != NULL && largoElectrodomesticos > 0 && listaMarcas != NULL
			&& largoMarcas > 0 ) {

		for (i = 0; i < largoMarcas; i++) {

			printf("Los electrodomesticos de la marca %s son: \n", listaMarcas[i].descripcion);

			for (j = 0; j < largoElectrodomesticos; j++) {

				if (listaElectrodomesticos[j].idMarca == listaMarcas[i].id
						&& listaElectrodomesticos[j].estaVacio == 0)
				{
					if(vBanderaHayElectrodomestico == 0){

						printf("+------------+------------+--------------------------+--------------------------+\n");
						printf("|    ID      |   SERIE    |          MODELO          |    DESCRIPCION MARCA     |\n");
						printf("+------------+------------+--------------------------+--------------------------+\n");
						vBanderaHayElectrodomestico = 1;
					}
					imprimirElectrodomestico(j, listaElectrodomesticos, largoElectrodomesticos, listaMarcas, largoMarcas);

				}
			}
			if(vBanderaHayElectrodomestico==0)
			{
				printf(" No tiene.\n");
			}
			vBanderaHayElectrodomestico = 0;

		}
		vRetorno = 0;
	}
	return vRetorno;
}
int informarElectDeMarca(int idMarca, eElectrodomesticos* listaElectrodomesticos,int largoElectrodomesticos,eMarca* listaMarcas,int largoMarcas)
{

	int vRetorno = -1;
	int j;
	int vBanderaHayElectrodomestico = 0;
	int vPosicion;

	if (listaElectrodomesticos != NULL && largoElectrodomesticos > 0 && listaMarcas != NULL
			&& largoMarcas > 0 ) {

		vPosicion = buscarMarca(listaMarcas, largoMarcas, idMarca);




			for (j = 0; j < largoMarcas; j++) {

				if (listaElectrodomesticos[j].idMarca == listaMarcas[vPosicion].id
						&& listaElectrodomesticos[j].estaVacio == 0)
				{
					if(vBanderaHayElectrodomestico == 0){
						printf("Los electrodomesticos de la marca %s son: \n", listaMarcas[vPosicion].descripcion);
						printf("+------------+------------+--------------------------+--------------------------+\n");
						printf("|    ID      |   SERIE    |          MODELO          |    DESCRIPCION MARCA     |\n");
						printf("+------------+------------+--------------------------+--------------------------+\n");
						vBanderaHayElectrodomestico = 1;
					}
					imprimirElectrodomestico(j, listaElectrodomesticos, largoElectrodomesticos, listaMarcas, largoMarcas);
				}
			}
			if(vBanderaHayElectrodomestico==0)
			{
				printf("Los electrodomesticos de la marca %s no tiene electrodomesticos.\n", listaMarcas[vPosicion].descripcion);
			}
			vBanderaHayElectrodomestico = 0;

		vRetorno = 0;
	}
	return vRetorno;
}
int informarCantElectPorMarca(eElectrodomesticos* listaElectrodomesticos,int largoElectrodomesticos,
		eMarca*	listaMarcas,int largoMarcas)
{
	int vRetorno = -1;
	int i;
	int j;
	int vContador=0;

	if (listaElectrodomesticos != NULL && largoElectrodomesticos > 0 && listaMarcas != NULL
			&& largoMarcas > 0 ) {

		for (i = 0; i < largoMarcas; i++) {

			printf("Los electrodomesticos de la marca %s son: \n", listaMarcas[i].descripcion);

			for (j = 0; j < largoElectrodomesticos; j++) {

				if (listaElectrodomesticos[j].idMarca == listaMarcas[i].id
						&& listaElectrodomesticos[j].estaVacio == 0)
				{
					vContador++;
				}
			}
			if(vContador>0)
			{
				printf("\n La Marca  %s tiene %d electrodomesticos.\n ", listaMarcas[i].descripcion,vContador);
			}else
			{
				printf("\n La Marca %s no tiene electrodomesticos.\n ", listaMarcas[i].descripcion);
			}

		}
		vRetorno = 0;
	}
	return vRetorno;

}
int informarMarcaMayCantElect(eElectrodomesticos* listaElectrodomesticos,int largoElectrodomesticos, eMarca* listaMarcas,int largoMarcas)
{
	int vRetorno = -1;
	int i;
	int j;
	int contadorElectrodomesticos[largoMarcas];
	int max=-1;
	char descripcionMarcaMax[21];


	if (listaMarcas != NULL && listaElectrodomesticos != NULL
			&& largoElectrodomesticos>0 && largoMarcas>0) {

		for(i=0;i<largoMarcas;i++)
		{
			contadorElectrodomesticos[i]=0;
		}

		for (i = 0; i < largoMarcas; i++) {

			for (j = 0; j < largoElectrodomesticos; j++) {

				if (listaElectrodomesticos[j].idMarca == listaMarcas[i].id
					&& listaElectrodomesticos[j].estaVacio == 0 )
				{
					contadorElectrodomesticos[i]++;
				}
			}
		}

		for(i=0;i<largoMarcas;i++)
		{
			if(max<contadorElectrodomesticos[i])
			{
				max = contadorElectrodomesticos[i];
				strcpy(descripcionMarcaMax ,listaMarcas[i].descripcion);
			}
		}

		if(contadorElectrodomesticos>0)
		{
			printf("\n La serie con mas reparaciones es  %s tiene %d reparaciones.\n ", descripcionMarcaMax,max);
		}else
		{
			printf("\n No hay ningun electrodomestico.\n ");
		}
		vRetorno = 0;

	}
	return vRetorno;
}
int informarPromedioElectrodPorMarca(eElectrodomesticos* listaElectrodomesticos,int largoElectrodomesticos, eMarca* listaMarcas,int largoMarcas)
{
	int vRetorno = -1;
	int i;
	int j;
	int contadorElectrodomesticos=0;
	float promedio;


	if (listaMarcas != NULL && listaElectrodomesticos != NULL
			&& largoElectrodomesticos>0 && largoMarcas>0) {

		for (i = 0; i < largoMarcas; i++) {

			for (j = 0; j < largoElectrodomesticos; j++) {

				if (listaElectrodomesticos[j].idMarca == listaMarcas[i].id
					&& listaElectrodomesticos[j].estaVacio == 0 )
				{
					contadorElectrodomesticos++;
				}
			}
		}


		if(largoMarcas>0)
		{
			promedio = (float)contadorElectrodomesticos/largoMarcas ;
			printf("\n El promedio de electrodomesticos por marca es: %.2f.\n ",promedio);
		}else
		{
			printf("\n No hay ninguna marca cargada.\n ");
		}
		vRetorno = 0;

	}
	return vRetorno;
}
int informarPromedioRepaPorElect(eReparacion* listaReparacion,int largoReparacion,eElectrodomesticos* listaElectrodomesticos,int largoElectrodomesticos)
{
	int vRetorno = -1;
	int i;
	int j;
	int contadorElectrodomesticos=0;
	int contadorReparaciones =0;
	float promedio;


	if (listaElectrodomesticos != NULL && listaReparacion != NULL
			&& largoReparacion>0 && largoElectrodomesticos>0) {

		for (i = 0; i < largoElectrodomesticos; i++) {

			if(listaElectrodomesticos[i].estaVacio == 0){
				for (j = 0; j < largoReparacion; j++) {

					if(strcmp(listaReparacion[j].serie,listaElectrodomesticos[i].serie) == 0
							&& listaReparacion[j].estaVacio == 0  )
					{
						contadorReparaciones++;
					}
				}
			contadorElectrodomesticos++;
			}
		}


		if(contadorElectrodomesticos>0)
		{
			promedio = (float)contadorReparaciones/contadorElectrodomesticos ;
			printf("\n El promedio de reparaciones por electrodomestico es: %.2f.\n ",promedio);
		}else
		{
			printf("\n No hay ningun electrodomestico cargado.\n ");
		}
		vRetorno = 0;

	}
	return vRetorno;

}
int informarPromedioRepaPorCliente(eReparacion* listaReparaciones, int largoReparaciones, eCliente* listaClientes, int largoClientes)
{
	int vRetorno = -1;
		int i;
		int j;
		int contadorElectrodomesticos=0;
		float promedio;


		if (listaClientes != NULL && listaReparaciones != NULL
				&& largoReparaciones>0 && largoClientes>0) {

			for (i = 0; i < largoClientes; i++) {

				for (j = 0; j < largoReparaciones; j++) {

					if(listaReparaciones[j].idCliente ==listaClientes[i].id
						&& listaReparaciones[j].estaVacio == 0)
					{
						contadorElectrodomesticos++;
					}
				}
			}


			if(largoClientes>0)
			{
				promedio = (float)contadorElectrodomesticos/largoClientes ;
				printf("\n El promedio de reparaciones por cliente es: %.2f.\n ",promedio);
			}else
			{
				printf("\n No hay ningun cliente.\n ");
			}
			vRetorno = 0;

		}
		return vRetorno;
}
int informarElectrdomesticos2020(eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos, eMarca* listaMarcas, int largoMarcas)
{


	int vRetorno = -1;
	int i =0;
	int vBanderaHayElectrodomestico =0;

	if(listaElectrodomesticos != NULL &&  largoElectrodomesticos>0){


		for(i=0;i<largoElectrodomesticos;i++){

			if(listaElectrodomesticos[i].estaVacio == 0 && listaElectrodomesticos[i].modelo == 2020){
				if(vBanderaHayElectrodomestico == 0){
					printf("Los electrodomesticos de modelo 2020 son: \n");
					printf("+------------+------------+--------------------------+--------------------------+\n");
					printf("|    ID      |   SERIE    |          MODELO          |    DESCRIPCION MARCA     |\n");
					printf("+------------+------------+--------------------------+--------------------------+\n");
					vBanderaHayElectrodomestico = 1;
				}
				imprimirElectrodomestico(i, listaElectrodomesticos, largoElectrodomesticos, listaMarcas, largoMarcas);
			}
		}
		if(vBanderaHayElectrodomestico == 0)
		{
			printf("No hay ningun electrodomestico de modelo 2020");

		}
		vRetorno=0;

	}

	return vRetorno;
}
int informarElectrodomesticosSinRep(eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos, eMarca* listaMarca, int largoMarca,eReparacion* listaReparacion, int largoReparacion)
{
	int vRetorno = -1;
	int i;
	int j;
	int vBanderaHayReparacion=0;
	int vBanderaHayElectrodomestico=0;

	if(listaElectrodomesticos!= NULL && largoElectrodomesticos>0 && listaMarca!= NULL && largoMarca>0){
		for(i=0;i<largoElectrodomesticos;i++)
		{
			vBanderaHayReparacion=0;
			if(listaElectrodomesticos[i].estaVacio==0){
				for(j=0;j<largoReparacion;j++)
				{
					if(listaReparacion[i].estaVacio==0 && strcmp(listaElectrodomesticos[i].serie, listaReparacion[j].serie)==0){
						vBanderaHayReparacion=1;
						break;
					}
				}
				if(vBanderaHayReparacion==0 && vBanderaHayElectrodomestico==0){
					printf("+------------+------------+--------------------------+--------------------------+\n");
					printf("|    ID      |   SERIE    |          MODELO          |    DESCRIPCION MARCA     |\n");
					printf("+------------+------------+--------------------------+--------------------------+\n");
				imprimirElectrodomestico(i, listaElectrodomesticos, largoElectrodomesticos, listaMarca, largoMarca);
				vBanderaHayElectrodomestico=1;
				}
			}
		}
		vRetorno=0;
	}
	return vRetorno;
}
int informarImporteRepDelElect(char* serieElectrodomestico,eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos, eServicio* listaSerivicio, int largoServicio,eReparacion* listaReparacion, int largoReparacion)
{
	int vRetorno = -1;
	int j;
	int vPosicionElectrodomestico;
	float sumaImporte=0;
	float importe;


	if(listaElectrodomesticos!= NULL && largoElectrodomesticos>0 && listaSerivicio!= NULL && largoServicio>0 && listaReparacion!=NULL && largoReparacion>0)
	{
		vPosicionElectrodomestico = buscarElectrodomesticosPorSerie(listaElectrodomesticos, largoElectrodomesticos, serieElectrodomestico);


		if(vPosicionElectrodomestico>0)
		{
			if(listaElectrodomesticos[vPosicionElectrodomestico].estaVacio==0){
				for(j=0;j<largoReparacion;j++){
					if(listaReparacion[j].estaVacio==0 && strcmp(listaReparacion[j].serie,listaElectrodomesticos[vPosicionElectrodomestico].serie)==0)
					{
						if(cargarImporteServicio(listaReparacion[j].idServicio, listaSerivicio, largoServicio, &importe)==0)
						{
							sumaImporte+=importe;
						}
					}
				}
			}
			if(sumaImporte>0)
			{
				printf(" El electrodomestico de serie %s suma un importe de %.2f en reparaciones.", serieElectrodomestico,sumaImporte);

			}else
			{
				printf(" El electrodomestico de serie %s no tiene reparaciones y por lo tanto la suma del importe es 0.",serieElectrodomestico);
			}
			vRetorno = 0;
		}
	}

	return vRetorno;
}
int informarServicioMasPedido(eReparacion* listaReparaciones, int largoReparaciones, eServicio* listaServicios, int largoServicios)
{
	int vRetorno = -1;
	int i;
	int j;
	int contadorServicios[largoServicios];
	int max=-1;
	int vPosiconMax;

	if(listaReparaciones!= NULL && largoReparaciones>0 && listaServicios!= NULL && largoServicios>0){

		for(i=0;i<largoServicios;i++)
		{
			contadorServicios[i]=0;
		}

		for(i=0;i<largoServicios;i++){

			for(j=0;j<largoReparaciones;j++){

				if(listaReparaciones[j].estaVacio==0 && listaServicios[i].id == listaReparaciones[j].idServicio)
				{
					contadorServicios[i]++;
				}
			}
		}

		for(i=0;i<largoServicios;i++)
		{
			if(max<contadorServicios[i]){
				max= contadorServicios[i];
				vPosiconMax = i;
			}
		}
		if(max >0){
			printf(" El servicio %s fue el mas requerido con un total de %d pedidos.", listaServicios[vPosiconMax].descripcion, max);
		}else{
			printf( " Ningun servicio fue pedido.");
		}
		vRetorno=0;
	}
	return vRetorno;
}
int informarRecaudacionDeFecha(eReparacion* listaReparaciones, int largoReparaciones, eServicio* listaServicios, int largoServicios, eFecha fechaIngresada)
{
	int vRetorno = -1;
	int j;
	float sumaImporte = 0;
	float importe;

	if(listaReparaciones!=NULL && largoReparaciones>0 && listaServicios!= NULL && largoServicios>0)
	{

		for(j=0;j<largoReparaciones;j++)
		{
			if(listaReparaciones[j].estaVacio==0 && listaReparaciones[j].fecha.dia == fechaIngresada.dia &&
					listaReparaciones[j].fecha.mes == fechaIngresada.mes && listaReparaciones[j].fecha.anio == fechaIngresada.anio)
			{
				if(cargarImporteServicio(listaReparaciones[j].idServicio, listaServicios, largoServicios, &importe)==0)
				{
					sumaImporte+=importe;
				}
			}
		}
		if(sumaImporte>0){
			printf(" La recaudacion para el %d/%d/%d es de: %.2f", fechaIngresada.dia,fechaIngresada.mes, fechaIngresada.anio, sumaImporte);
		}else{
			printf(" No hay recarudacion para la fecha ingresada.");
		}
		vRetorno=0;

	}
	return vRetorno;
}
int informarElectrodConGaranta(eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos
		,eReparacion* listaReparaciones, int largoReparaciones, eServicio* listaServicios, int largoServicios)
{
	int vRetorno=-1;
	int i;
	int j;
	char descripcion[26];
	int vBanderaHayReparacion=0;

	if(listaElectrodomesticos!= NULL && largoElectrodomesticos>0 && listaReparaciones!= NULL && largoReparaciones>0 && listaServicios != NULL
			&& largoServicios>0 )
	{

		for(i=0;i<largoElectrodomesticos;i++){
			if(listaElectrodomesticos[i].estaVacio==0){
				for(j=0;j<largoReparaciones;j++)
				{

					if(listaReparaciones[j].estaVacio==0 && strcmp(listaReparaciones[j].serie,listaElectrodomesticos[i].serie)==0
							&& cargarDescServicio(listaReparaciones[j].idServicio, listaServicios, largoServicios, descripcion)==0)
					{
						if(listaReparaciones[j].idServicio==20000)
						{
							if(vBanderaHayReparacion==0 ){
							printf("+------------+------------+----------+\n");
							printf("|    ID      |   SERIE    |  FECHA	 |\n");
							printf("+------------+------------+----------+\n");
							vBanderaHayReparacion=1;
							}
							printf("|%12d|%12s|%2d/%2d/%4d|\n",
												listaElectrodomesticos[i].id,listaElectrodomesticos[i].serie,
												listaReparaciones[j].fecha.dia,listaReparaciones[j].fecha.mes,
												listaReparaciones[j].fecha.anio);
							printf("+------------+------------+----------+\n");
						}
					}
				}
			}
		}
		if(vBanderaHayReparacion==0){
			printf(" No hay reparaciones con garantia");
		}

		vRetorno=0;
	}
	return vRetorno;
}
int informarTrabajos2020(eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos
		,eReparacion* listaReparaciones, int largoReparaciones, eServicio* listaServicios, int largoServicios, eCliente* listaCliente, int largoCliente)
{
	int vRetorno = -1;
	int i =0;
	int j=0;
	int vBanderaHayReparaciones =0;

	if(listaElectrodomesticos != NULL &&  largoElectrodomesticos>0 && listaReparaciones!= NULL && largoReparaciones>0 && listaServicios!=  NULL &&
			largoServicios>0 && listaCliente != NULL && largoCliente>0){


		for(i=0;i<largoElectrodomesticos;i++){

			if(listaElectrodomesticos[i].estaVacio == 0 && listaElectrodomesticos[i].modelo == 2018){

				for(j=0;j<largoReparaciones;j++){
					if (strcmp(listaElectrodomesticos[i].serie,listaReparaciones[j].serie)==0
							&& listaReparaciones[j].estaVacio == 0  ) {

						if(vBanderaHayReparaciones == 0){
							printf("+------------+----------+--------------------------+--------------------------+--------------------------+\n");
							printf("|   SERIE    |   FECHA  | DESCRIPCION DEL SERVICIO |      NOMBRE CLIENTE      |     APELLIDO CLIENTE     |\n");
							printf("+------------+----------+--------------------------+--------------------------+--------------------------+\n");
							vBanderaHayReparaciones = 1;
						}

						imprimirReparacion(j, listaReparaciones, largoReparaciones,
								listaServicios, largoServicios, listaCliente,
								largoCliente);
					}
				}
			}
		}
		if(vBanderaHayReparaciones == 0)
		{
			printf("No hay ninguna reparacion para el modelo 2018.");

		}
		vRetorno=0;

	}

	return vRetorno;
}

int informarFactTotalMantenimiento(eReparacion* listaReparaciones, int largoReparaciones, eServicio* listaServicios, int largoServicios)
{
	int vRetorno=-1;
	int j;
	char descripcion[26];
	float facturacion;
	float totalFacturacion=0;

	if(listaReparaciones!= NULL && largoReparaciones>0 && listaServicios != NULL
			&& largoServicios>0 )
	{


		for(j=0;j<largoReparaciones;j++)
		{
			if(listaReparaciones[j].estaVacio==0
				&& cargarDescServicio(listaReparaciones[j].idServicio, listaServicios, largoServicios, descripcion)==0)
			{
				if(strcmp(descripcion,"Mantenimiento")==0)
				{
					cargarImporteServicio(listaReparaciones[j].idServicio, listaServicios, largoServicios, &facturacion);
					totalFacturacion+=facturacion;
				}
			}
		}
		if(totalFacturacion>0){

			printf(" El total facturado para mantenimiento es de %.2f", totalFacturacion);

		}else{
			printf(" No hay reparaciones con mantenimiento. ");
		}

		vRetorno=0;
	}
	return vRetorno;
}
int informarMarcaElectConMasRep(eReparacion* listaReparacion,int largoReparacion,
						eElectrodomesticos* listaElectrodomesticos,int largoElectrodomesticos, eMarca* listaMarcas, int largoMarcas)
{
	int vRetorno = -1;
	int i;
	int j;
	int contadorRefacciones[largoElectrodomesticos];
	int max=0;
	char marcaMax[21];


	if (listaReparacion != NULL && listaElectrodomesticos != NULL
			&& largoElectrodomesticos>0 && largoReparacion>0) {

		for(i=0;i<largoElectrodomesticos;i++)
		{
			contadorRefacciones[i]=0;
		}

		for (i = 0; i < largoElectrodomesticos; i++) {

			if(listaElectrodomesticos[i].estaVacio == 0 ){

				for (j = 0; j < largoReparacion; j++) {

					if (strcmp(listaElectrodomesticos[i].serie,listaReparacion[j].serie)==0
							&& listaReparacion[j].estaVacio == 0 && listaReparacion[j].idServicio== 20003)
					{
						contadorRefacciones[i]++;
					}
				}
			}
		}
		for(i=0;i<largoElectrodomesticos;i++)
		{
			if(max<contadorRefacciones[i] && listaElectrodomesticos[i].estaVacio==0)
			{
				max = contadorRefacciones[i];
				cargarDescMarca(listaElectrodomesticos[i].idMarca, listaMarcas, largoMarcas, marcaMax);
			}

		}
		if(max>0)
		{
			printf("\n La marca con mas refacciones es  %s tiene %d reparaciones.\n ", marcaMax,max);
		}else
		{
			printf("\n No hay ninguna refaccion.\n ");
		}
		vRetorno = 0;

	}
	return vRetorno;

}
int informarElectConRepEnFecha(eReparacion* listaReparaciones, int largoReparaciones, eServicio* listaServicios,
		int largoServicios, eFecha fechaIngresada, eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos,
		eMarca* listaMarcas, int largoMarcas)
{
	int vRetorno = -1;
	int j;
	int i;
	int vBanderaHayReparacion=0;

	if(listaReparaciones!=NULL && largoReparaciones>0 && listaServicios!= NULL && largoServicios>0 && listaElectrodomesticos!= NULL && largoElectrodomesticos>0)
	{


		for(i=0;i<largoElectrodomesticos;i++){

			if(listaElectrodomesticos[i].estaVacio==0){
				for(j=0;j<largoReparaciones;j++)
				{
					if(listaReparaciones[j].estaVacio==0 && listaReparaciones[j].fecha.dia == fechaIngresada.dia &&
							listaReparaciones[j].fecha.mes == fechaIngresada.mes && listaReparaciones[j].fecha.anio == fechaIngresada.anio)
					{
						if(vBanderaHayReparacion==0){
							printf("+------------+------------+--------------------------+--------------------------+\n");
							printf("|    ID      |   SERIE    |          MODELO          |    DESCRIPCION MARCA     |\n");
							printf("+------------+------------+--------------------------+--------------------------+\n");
							vBanderaHayReparacion=1;
						}
						imprimirElectrodomestico(i, listaElectrodomesticos, largoElectrodomesticos, listaMarcas, largoMarcas);
					}
				}
			}
		}
		if(vBanderaHayReparacion==0)
		{
			printf(" Ningun electrodomestico recibio reparaciones en dicha fecha.");
		}
		vRetorno=0;

	}
	return vRetorno;
}
