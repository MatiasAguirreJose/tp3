#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"

int GetString(char mensaje[],char mensajeError[], char cadena[], int tam) {

    int retorno = 0;
    char auxiliarString[500];

        if (cadena != NULL && mensaje != NULL){


        	puts(mensaje);
			fflush(stdin);
			scanf("%s",auxiliarString);


			if(esString(auxiliarString) == -1){
				puts(mensajeError);
				retorno = -1;
			}


        }
        strncpy(cadena,auxiliarString,tam);
    return retorno;

}
int esString(char* cadena){
	int retorno = 0;

	for(int i=0; cadena[i]!='\0';i++){

		if(cadena[i]<'9' && cadena[i]>'0'){
			retorno = -1;
			break;
		}
	}

	return retorno;
}


int getNumero(int* pResultado, char mensaje[]){
	int retorno = -1;
	int auxiliarInt;
	int respuesta;

	if(pResultado!=NULL && mensaje!=NULL){
		do{
			printf("%s",mensaje);

			respuesta = getInt(&auxiliarInt);
			if(respuesta==0){
				*pResultado = auxiliarInt;
				retorno = 0;
			}
		}while(respuesta!=0);
	}

	return retorno;
}

int getNumeroConMinyMax(int* pResultado, char mensaje[],int min,int max){
	int retorno = -1;
		int auxiliarInt;
		int respuesta;

		if(pResultado!=NULL && mensaje!=NULL){


			do{
				printf("%s",mensaje);

				respuesta = getInt(&auxiliarInt);
				if(respuesta==0){
					*pResultado = auxiliarInt;
					retorno = 0;
					if(*pResultado > max || *pResultado < min){
						retorno = -1;
				}
				}
			}while(respuesta!=0);





}
		return retorno;
}
int getNumeroConMin(int* pResultado, char mensaje[],int min){
	int retorno = -1;
		int auxiliarInt;
		int respuesta;

		if(pResultado!=NULL && mensaje!=NULL){


			do{
				printf("%s",mensaje);

				respuesta = getInt(&auxiliarInt);
				if(respuesta==0){
					*pResultado = auxiliarInt;
					retorno = 0;
					if(*pResultado < min){
						retorno = -1;
				}
				}
			}while(retorno!=0);





}
		return retorno;
}

int getInt(int* pResultado){
	int retorno = -1;
	char auxiliarIngresado[1000];

	fflush(stdin);
	scanf("%s",auxiliarIngresado);

	if(esNumerica(auxiliarIngresado)){
		retorno = 0;
		*pResultado = atoi(auxiliarIngresado);
	}
	return retorno;
}

int esNumerica(char* cadena){
	int retorno = 1;
	int i=0;

	if(cadena[0]=='-'){
		i=1;
	}

	for(; cadena[i]!='\0';i++){

		if(cadena[i]>'9' || cadena[i]<'0'){
			retorno = 0;
			break;
		}
	}

	return retorno;
}

float getNumeroFloat(float* pResultado, char mensaje[]){
	int retorno = -1;
	float auxiliarFloat;
	int respuesta;

	if(pResultado != NULL && mensaje != NULL){
		do{
			printf("%s",mensaje);

			respuesta = getFloat(&auxiliarFloat);
			if(respuesta==0){
				*pResultado = auxiliarFloat;
				retorno = 0;
			}
		}while(respuesta!=0);
	}
	return retorno;
}

int getFloat(float* pResultado){
	int retorno = -1;
	char auxiliarIngresado[1000];

	fflush(stdin);
	scanf("%s",auxiliarIngresado);

	if(esNumericaFloat(auxiliarIngresado)){
		retorno = 0;
		*pResultado = atof(auxiliarIngresado);
	}
	return retorno;
}

int esNumericaFloat(char* cadena){
	int retorno = 1;
	int i=0;

	if(cadena[0]=='-'){
		i=1;
	}

	for(; cadena[i]!='\0';i++){

		if(cadena[i]>'9' || cadena[i]<'0'){
			if(cadena[i]!='.'){
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
