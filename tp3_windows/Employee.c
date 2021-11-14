


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "Employee.h"
int employee_setId(Employee* this,int id){

	int retorno = -1;
	if(this != NULL){

		this->id = id;
		retorno = 0;
	}

	return retorno;
}


int employee_setNombre(Employee* this,char* nombre){

	int retorno = -1;
	if(this != NULL){

		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){


	int retorno = -1;
	if(this != NULL){

		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo){

	int retorno = -1;
	if(this != NULL){

		this->sueldo = sueldo;
		retorno = 0;
	}

	return retorno;
}

int employee_getId(Employee* this,int* id){
	int retorno = -1;
		if(this != NULL && id != NULL){

			*id = this->id;
			retorno = 0;
		}

		return retorno;

}


int employee_getNombre(Employee* this,char* nombre){
	int retorno = -1;
		if(this != NULL && nombre != NULL){

			strcpy( nombre, this->nombre);
			retorno = 0;
		}

		return retorno;

}




int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int retorno = -1;
		if(this != NULL && horasTrabajadas != NULL){

			*horasTrabajadas = this->horasTrabajadas;
			retorno = 0;
		}

		return retorno;

}




int employee_getSueldo(Employee* this,int* sueldo){
	int retorno = -1;
		if(this != NULL && sueldo != NULL){

			*sueldo = this->sueldo;
			retorno = 0;
		}

		return retorno;

}


Employee* employee_new()
{
	    Employee* newEmployee;
	    newEmployee = (Employee*)malloc(sizeof(Employee));

	    if(newEmployee != NULL)
	    {
	        newEmployee->id = 0;
	        strcpy(newEmployee->nombre, " ");
	        newEmployee->horasTrabajadas = 0;
	        newEmployee->sueldo = 0;
	    }

	    return newEmployee;
	}



Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmployee;
    newEmployee = employee_new();

    int id;
    int horas;
    int sueldo;

    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL && newEmployee != NULL  ){
		id= atoi(idStr);
		horas= atoi(horasTrabajadasStr);
		sueldo= atoi(sueldoStr);


    	employee_setId(newEmployee, id);
        employee_setNombre(newEmployee, nombreStr);
        employee_setSueldo(newEmployee, sueldo);
        employee_setHorasTrabajadas(newEmployee, horas);

    }

    return newEmployee;
}



int employee_CompareByName(void* e1,void* e2){
	int retorno;

	Employee* PrimerEmpleado;
	Employee* SegundoEmpleado;

	PrimerEmpleado = (Employee*) e1;
	SegundoEmpleado = (Employee*) e2;

	retorno = strcmp(PrimerEmpleado->nombre, SegundoEmpleado->nombre);

	return retorno;
}

int employee_CompareById(void* e1,void* e2){
	int retorno;

	Employee* PrimerEmpleado;
	Employee* SegundoEmpleado;

	PrimerEmpleado = (Employee*) e1;
	SegundoEmpleado = (Employee*) e2;

	if(PrimerEmpleado->id>SegundoEmpleado->id){
		retorno = 0;
	}

	return retorno;
}

int employee_CompareByHoras(void* e1,void* e2){
	int retorno;

	Employee* PrimerEmpleado;
	Employee* SegundoEmpleado;

	PrimerEmpleado = (Employee*) e1;
	SegundoEmpleado = (Employee*) e2;

	if(PrimerEmpleado->horasTrabajadas>SegundoEmpleado->horasTrabajadas){
		retorno = 0;
	}

	return retorno;
}
int employee_CompareBySueldo(void* e1,void* e2){
	int retorno;

	Employee* PrimerEmpleado;
	Employee* SegundoEmpleado;

	PrimerEmpleado = (Employee*) e1;
	SegundoEmpleado = (Employee*) e2;

	if(PrimerEmpleado->sueldo>SegundoEmpleado->sueldo){
		retorno = 0;
	}

	return retorno;
}


