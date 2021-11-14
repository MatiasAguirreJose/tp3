#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "inputs.h"
#include "Controller.h"
#include "Parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
void menu (void){
	puts("1-Cargar los datos de los empleados desde el archivo data.csv (modo texto) \n");
		    	 puts("2- Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
		    	 puts("3-dar de alta\n");
		    	 puts("4-Modificar datos de empleado\n");
		    	 puts("5-Baja de empleado\n");
		    	 puts("6-Listar empleados\n");
		    	 puts("7-Ordenar empleados\n");
		         puts("8-Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
		         puts("9-Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
		         puts("10-Salir");
		         puts("----------------------------------------------------------------------------------");


}

int idDisponible(LinkedList* pArrayListEmployee){

	Employee* idDis =  employee_new();
	int id ;
	id = 0;
	int len;
	int idAux;
	int flag = 1;



	len = ll_len(pArrayListEmployee);

	for(int i = 0; i<len; i++){

		idDis = ll_get(pArrayListEmployee, i);
		employee_getId(idDis, &idAux);

		if(idAux>id || flag == 1){

			flag = 0;
			id = idAux;
		}
		id++;

	}

	return id;


}
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pArchivo;
       if(path!= NULL && pArrayListEmployee != NULL){

    	pArchivo = fopen(path,"r");

       	if(pArchivo!=NULL && parser_EmployeeFromText(pArchivo,pArrayListEmployee) == 0){
       		retorno = 0;
       	}
       fclose(pArchivo);


       }
       return retorno;

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	FILE* empleadosB;

	empleadosB = fopen (path, "rb");

	 if(empleadosB != NULL && path != NULL && pArrayListEmployee!=NULL ){

	 retorno = parser_EmployeeFromBinary(empleadosB,pArrayListEmployee);
	 fclose (empleadosB);

	 }else{
			 puts("ERROR");
		 }


    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
		int id;
		int horas;
		int sueldo;
		char nombre[100];
		int verificar ;
		int nunMin = 0;
		int len;
		int option;
		Employee* empleado = employee_new();
		len = ll_len(pArrayListEmployee);
		if (len == 0){
		puts("Aviso!! usted esta ingresando empleados sin ingresar a la lista ");
		}
		puts("1. Seguir");
		puts("2- Salir ");
		if (getNumeroConMinyMax(&option, "\n　!!ingrese una opcion!!　",1,2)!=0){
				puts("ERROR Ingrese bien los datos ");
			}
		   switch(option){
		   case 1:
		if( pArrayListEmployee != NULL && empleado != NULL){

		id = idDisponible(pArrayListEmployee);
		do{
		verificar = GetString("ingrese el nombre","ERROR", nombre, 100);
		}while(verificar !=0);

		 getNumero(&horas,"Ingrese las horas del cliente");

		 getNumeroConMin(&sueldo, "Ingrese el sueldo",nunMin);


		 retorno =0;

		}



	 employee_setId(empleado, id);
	 employee_setNombre(empleado, nombre);
	 employee_setHorasTrabajadas(empleado, horas);
	 employee_setSueldo(empleado,sueldo);


	 ll_add( pArrayListEmployee, empleado);
	 break;
		   case 2:
			   puts("adios....");
			   break;
}

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* Empleado;
	int id;
	int len;
	int idAux;
	char nombre[100];
	int horas;
	int sueldo;
	int retorno = -1;
	int verificar;
	if( pArrayListEmployee != NULL){
	getNumero(&id,"Ingrese el id a modificar");
	len = ll_len(pArrayListEmployee);
	for(int i = 0; i<len; i++){
		Empleado = (Employee*) ll_get(pArrayListEmployee , i);
		employee_getId(Empleado, &idAux);

		if(id == idAux){



			do{
				verificar = GetString("ingrese el nombre","ERROR", nombre, 100);
				}while(verificar !=0);

			getNumero(&horas,"Ingrese las horas del cliente");

			getNumero(&sueldo,"Ingrese el sueldo del cliente");

			employee_setId(Empleado, id);
			employee_setNombre(Empleado, nombre);
			employee_setHorasTrabajadas(Empleado, horas);
			employee_setSueldo(Empleado,sueldo);



			retorno = 0;
			break;

		}

	}
	}


    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	Employee* Empleado;
		int id;
		int len;
		int idAux;
		int retorno = -1;
		getNumero(&id,"Ingrese el id que quiere eliminar");
		len =  ll_len(pArrayListEmployee ) ;

		for (int i = 0; i < len; ++i) {
			Empleado = (Employee*) ll_get( pArrayListEmployee , i) ;
			employee_getId(Empleado,&idAux);
			if (idAux == id){
				 ll_remove(pArrayListEmployee , i );
				 retorno = 0;

			}



		}

    return retorno ;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	Employee* empleados;
	int len;
	int retorno = -1;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	int id;
	len = ll_len(pArrayListEmployee);
	if(pArrayListEmployee != NULL && len > 0){

	retorno = 0;

	for(int i = 0; i<len ; i++){

		empleados = ll_get(pArrayListEmployee , i);
		employee_getId(empleados,&id);
		employee_getNombre(empleados, nombre);
		employee_getHorasTrabajadas(empleados,&horasTrabajadas);
		employee_getSueldo(empleados,&sueldo);

		printf("-----------------------\n %d,    %s,     %d,      %d \n",id,nombre,horasTrabajadas,sueldo);



	}
	}

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

	int option;
	Employee* aux;
	int len = ll_len(pArrayListEmployee);

	if( pArrayListEmployee != NULL && len>0){

	do{

		puts("-----------Ordenamiento-----------");
		puts("1-Por Id");
		puts("2-Por Nombre");
		puts("3-Por Horas");
		puts("4-Por Sueldo");
		puts("5-salir");
		puts("----------------------------------");

		if (getNumeroConMinyMax(&option, "\n---------　!!ingrese una opcion del Menu!!　--------- \n",1,5)!=0){
		    puts("ERROR Ingrese bien los datos ");
		  }

	switch(option){



	case 1:
		puts("!!　Ordenado por ID!!　");
		puts("Aguarde, Cargando Archivo...");
		for(int i = 0;i<len; i++){

		ll_sort(pArrayListEmployee, employee_CompareById, 0);
		aux = (Employee*) ll_get(pArrayListEmployee,i);


		printf("-----------------------\n %d,    %s,     %d,      %d \n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);

		}

		break;
	case 2:
		puts("!!　Ordenado por NOMBRE!!　");
		puts("Aguarde, Cargando Archivo...");
		for(int i = 0;i<len; i++){

		ll_sort(pArrayListEmployee, employee_CompareByName, 1);
		aux = (Employee*) ll_get(pArrayListEmployee,i);

		printf("-----------------------\n %d,    %s,     %d,      %d \n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);

		}
		break;
	case 3:
		puts("!!　Ordenado por HORAS TRABAJADAS!!　");
		puts("Aguarde, Cargando Archivo...");
		for(int i = 0;i<len; i++){

		ll_sort(pArrayListEmployee,  employee_CompareByHoras, 0);
		aux = (Employee*) ll_get(pArrayListEmployee,i);


		printf("-----------------------\n %d,    %s,     %d,      %d \n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);

		}
		break;
	case 4:
		puts("!!　Ordenado por SUELDO !!　");
		puts("Aguarde, Cargando Archivo...");
		for(int i = 0;i<len; i++){

		ll_sort(pArrayListEmployee,  employee_CompareBySueldo, 0);
		aux = (Employee*) ll_get(pArrayListEmployee,i);

		printf("-----------------------\n %d,    %s,     %d,      %d \n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);

		}

		break;

	}
	}while(option !=5 );
	}else{
		puts("Error No ingreso nada, Elija una Opcion");
	}

    return  option;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* Archivo;
	Employee* Empleado;
	int retorno = -1;
	int len;
	char nombre [100];
	int id;
	int sueldo;
	int horas;

	len =  ll_len(pArrayListEmployee);


	if(pArrayListEmployee != NULL && len > 0){

	Archivo = fopen(path,"w");



	for (int i=0; i<len ; i++){

	Empleado = (Employee*)ll_get(pArrayListEmployee, i);

			employee_getId(Empleado,&id);
			employee_getNombre(Empleado,nombre);
			employee_getHorasTrabajadas(Empleado,&horas);
			employee_getSueldo(Empleado,&sueldo);

		fprintf(Archivo,"%d, %s,  %d, %d \n",id,nombre,horas,sueldo);

		retorno = 0;

	}
	fclose(Archivo);
	}

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
		Employee* Empleados;
		FILE* Archivos;
		int retorno = -1;
		int len;
		int i;


		if(pArrayListEmployee!=NULL){
			Archivos = fopen(path,"wb");
			len = ll_len(pArrayListEmployee);
			if(Archivos!=NULL && len > 0){


				for(i=0; i<len; i++){
					Empleados = (Employee*) ll_get(pArrayListEmployee, i);
					if(Empleados != NULL){

						fwrite(Empleados,sizeof(Employee),1,Archivos);

					}else{
							puts("Error");
						break;
					}

				}

			}
			fclose(Archivos);
		}

	    return retorno;

}


