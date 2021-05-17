/*
 ============================================================================
 Name        : 1g.c
 Author      : Rodrigo Katz
 Version     : 1.0.0
 Description : 1er parcial programacion 1G
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
	int id;
	char procesador[50];
	char marca[50];
	float precio;
} Notebook;

float aplicarDescuento(float precio);
int contarCaracteres(char cadena[], char caracter);
int ordenarArray(Notebook nList[], int nLen);

int main(void) {
	char cadena[10] = "diezcaract";
	char caracter = 'a';
	int resultado = contarCaracteres(cadena, caracter);

	Notebook notebooks[3] = {
			{100, "core 2", "intel", 2000 },
			{101, "core 4", "amd", 4000 },
			{102, "core 3", "amd", 3000 }
	};

	printf("\ncon descuento %.2f",aplicarDescuento(10));
	printf("\ncantidad de veces que aparece el caracter %d", resultado);

	ordenarArray(notebooks, 3);

	return EXIT_SUCCESS;
}


float aplicarDescuento(float precio){
	return precio - ((float) precio * 5 / 100);
}

int contarCaracteres(char cadena[], char caracter){
	int cantidadDeVeces = 0;
	if(cadena != NULL ){
		for(int i = 0; i < 10; i++){
			if(cadena[i] == caracter){
				cantidadDeVeces++;
			}
		}
	}
	return cantidadDeVeces;
}

int ordenarArray(Notebook nList[], int nLen){
	int ret = 0;

	if(nList != NULL && nLen > 0){
		char auxChar[50];
		for(int i = 0; i < nLen - 1; i++){
			for(int j = i + 1; j < nLen; j++){
				if(strcmp(nList[i].marca,nList[j].marca)>0){
					strcpy(auxChar, nList[i].marca);
					strcpy(nList[i].marca ,nList[j].marca);
					strcpy(nList[j].marca, auxChar);
				}
			}
		}
	}
	return ret;
}
