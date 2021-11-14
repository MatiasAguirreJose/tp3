#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "inputs.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{setbuf(stdout,NULL);
int option = 0;


 LinkedList* listaEmpleados = ll_newLinkedList();
  menu();
do{


	if (getNumeroConMinyMax(&option, "\n　!!ingrese una opcion!!　",1,10)!=0){
		puts("ERROR Ingrese bien los datos ");
	}


    switch(option)
    {
        case 1:
            if(controller_loadFromText("data.csv",listaEmpleados)== 0){

            	puts("-- SE CARGO EXITOSAMENTE --");

            }else{

            	puts("真error de carga Reinicie No hay datos en data.csv, agregue y cargue nuevos 真");
            }

            break;

        case 2:
        	if(controller_loadFromBinary("data.bin" ,listaEmpleados)!=0){
        		puts("真error de carga, verifique si cargo los datos en binario y vuelva a intentar真");
        	}else{
        		puts("Se agrego correctamente");
        	}
        	break;

        case 3:
                  	if( controller_addEmployee(listaEmpleados)==0){
                  		puts("se agrego correctamente");
                  	}else{
                  		puts("no se agrego");
                  	}
                  	break;
        case 4:
                            	if( controller_editEmployee(listaEmpleados)==0){
                            		puts("se modifico correctamente");
                            	}else{
                            		puts("no hay forma de modificarlo");
                            	}
                            	break;

        case 5:
                            if( controller_removeEmployee(listaEmpleados)!=0){
                            	puts("no hay forma de Eliminarlo");
                                	}else{
                                		puts("se modifico correctamente");
                                	}
                                	break;
        case 6:
                    	if( controller_ListEmployee(listaEmpleados)!=0){
                    		puts("error Usted no cargo nada, cargue y Reinicie el Programa");
                    	}
                    	break;

        case 7:
        	 if (controller_sortEmployee(listaEmpleados)==5){

        		 menu();
        	 }

        	break;
        case 8:
                 	 if ( controller_saveAsText("data.csv",listaEmpleados)!= 0){

                 		puts("error Usted no cargo nada, cargue y Reinicie el Programa");
                 	 }else{
                 		 puts("Los cambios se guardaron Correctamente");
                 	 }


                 	break;
        case 9:

        			if(controller_saveAsBinary("data.bin" , listaEmpleados)!=0){
        				puts("error Usted no cargo nada,cargue y  Reinicie el Programa");
        			}else{
        				puts("Los cambios se guardaron Correctamente");
        			}
                 	break;
    }
}while(option != 10);
puts("Adios profe no me desapruebeeeee.....");

return 0;
}

