#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Participante.h"
#include "Parser.h"
#include "utn.h"

/** \brief Crea un nuevo elemento Empleado
 *
 * \param
 * \param
 * \return Devuelve el puntero al nuevo elemento
 *
 */
Employee* employee_new()
{
	return malloc(sizeof(Employee));
}

/** \brief Configura el nuevo empleado con los valores de las variables
 *
 * \param idStr recibe el id del empleado en formatos tring
 * \param nombreStr recibe el nombre del empleado en formatos tring
 * \param horasTrabajadasStr recibe las horas trabajadas del empleado en formatos tring
 * \param sueldo recibe el sueldo del empleado en formatos tring
 * \return Devuelve la direccion de memoria al elemento configurado en la LinkedList
 *
 */
Employee* employee_newParametros(char* numeroConcursante,char* anio, char* nombreStr,char* dni,char* fechaPresentacion,char* temaPresentacion,char* puntajePrimeraRonda)
{
    int cargaOk;
    Employee* retorno;
	retorno = NULL;
	Employee* this;
	this = employee_new();
	cargaOk = 0;
	printf(" XX 3 \n");
	if(this != NULL)
	{
	    printf(" XX 4 \n");
		/*if(	employee_setId(this, numeroConcursante) == 0 &&
                employee_setAnio(this, anio) == 0 &&
                employee_setNombre(this,nombreStr) == 0 &&
                employee_setDni(this,dni) == 0 &&
                employee_setFechaPresentacion(this,fechaPresentacion) == 0 &&
				employee_setTemaPresentacion(this,temaPresentacion) == 0 &&
				//employee_setHorasTrabajadas(this,horasTrabajadasStr) == 0 &&
                employee_setPuntaje(this,puntajePrimeraRonda) == 0)
            {
                retorno = this;
            }*/
                employee_setId(this, numeroConcursante);
                cargaOk++;
                employee_setAnio(this, anio);
                cargaOk++;
                employee_setNombre(this,nombreStr);
                cargaOk++;
                employee_setDni(this,dni);
                cargaOk++;
                employee_setFechaPresentacion(this,fechaPresentacion);
                cargaOk++;
				employee_setTemaPresentacion(this,temaPresentacion);
				cargaOk++;
                employee_setPuntaje(this,puntajePrimeraRonda);
                cargaOk++;
                employee_setSegundaRonda(this,0);
                cargaOk++;
                employee_setPromedio(this,0);
                cargaOk++;
                printf(" XX 5 \n");
            if(cargaOk==9)
            {
                retorno = this;
            }
            else
            {
                employee_delete(this);
            }
	}
	return retorno;
}

/** \brief Libera el espacio en memoria de un empleado
 *
 * \param this es la direccion de memoria del empleado a borrar
 * \return void
 *
 */
void employee_delete(Employee* this)
{
	free(this);
}

/** \brief Configura el id de un empleado
 *
 * \param this es la direccion de memoria de un empleado
 * \param id es el id que se configurara al empleado recibido
 * \return
 *
 */
/*int employee_setId(Employee* this,char* id)
{
    int retorno;
	int bId;
	retorno = -1;
	if(this!=NULL && isValidId(this,id))
	{
		bId=atoi(id);
		this->id = bId;
		retorno = 0;
	}
	return retorno;
}*/
int employee_setId(Employee* this,char* id)
{
    int retorno;
	int bId;
	retorno = -1;
	if(this!=NULL && isValidId(this,id))
	{
		bId=atoi(id);
		this->id = bId;
		retorno = 0;
	}
	return retorno;
}

/** \brief Configura el anio de un concursante
 *
 * \param this es la direccion de memoria de un empleado
 * \param anio es el id que se configurara al empleado recibido
 * \return
 *
 */
int employee_setAnio(Employee* this,char* anio)
{
    int retorno;
	int bId;
	retorno = -1;
	if(this!=NULL)// && isValidId(this,id))
	{
		bId=atoi(anio);
		this->anioNacimiento = bId;
		retorno = 0;
	}
	return retorno;
}



/** \brief Recupera el id de un empleado en la lista
 *
 * \param this es la direccion de memoria del elemento
 * \param id es el campo donde se almacenara el dato recuperado
 * \return -1 si hubo algun error, 0 si fue exitoso
 *
 */
int employee_getId(Employee* this,int *id)
{
	int retorno;
	retorno = -1;
	if(this != NULL)
	{
	    *id=this->id;
        retorno = 0;
    }
	return retorno;
}

/** \brief Configura el nombre de un empleado
 *
 * \param this es la direccion de memoria de un empleado
 * \param nombre es el nombre que se configurara al empleado recibido
 * \return
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno;
	retorno = -1;
	if(this!=NULL)// && isValidNombre(this,nombre))
	{
		strncpy(this->nombre,nombre,sizeof(this->nombre));
		retorno = 0;
	}
	return retorno;
}

/** \brief Configura el dni de un empleado
 *
 * \param this es la direccion de memoria de un empleado
 * \param nombre es el nombre que se configurara al empleado recibido
 * \return
 *
 */
int employee_setDni(Employee* this,char* dni)
{
	int retorno;
	retorno = -1;
	if(this!=NULL)// && isValidNombre(this,nombre))
	{
		strncpy(this->dni,dni,sizeof(this->dni));
		retorno = 0;
	}
	return retorno;
}

/** \brief Configura el nombre de un empleado
 *
 * \param this es la direccion de memoria de un empleado
 * \param nombre es el nombre que se configurara al empleado recibido
 * \return
 *
 */
int employee_setFechaPresentacion(Employee* this,char* fechaPresentacion)
{
	int retorno;
	retorno = -1;
	if(this!=NULL)// && isValidNombre(this,nombre))
	{
		strncpy(this->fechaPresentacion,fechaPresentacion,sizeof(this->fechaPresentacion));
		retorno = 0;
	}
	return retorno;
}

/** \brief Configura el nombre de un empleado
 *
 * \param this es la direccion de memoria de un empleado
 * \param nombre es el nombre que se configurara al empleado recibido
 * \return
 *
 */
int employee_setTemaPresentacion(Employee* this,char* temaPresentacion)
{
	int retorno;
	retorno = -1;
	if(this!=NULL)// && isValidNombre(this,nombre))
	{
		strncpy(this->temaPresentacion,temaPresentacion,sizeof(this->temaPresentacion));
		retorno = 0;
	}
	return retorno;
}

/** \brief Recupero el nombre de un elemento existente
 *
 * \param this es la direccion de memoria del elemento
 * \param nombre donde almaceno el valor que busco
 * \return -1 si hubo un error, 0 si fue exitoso
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno;
	retorno = -1;
	if(this != NULL && nombre != NULL)
	{
	    strncpy(nombre,this->nombre,50);
        retorno = 0;
    }
	return retorno;
}

/** \brief Configura las hs trabajadas de un empleado
 *
 * \param this es la direccion de memoria de un empleado
 * \param horasTrabajadasStr es el valor que se configurara al empleado recibido
 * \return
 *
 */
/*int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadasStr)
{
	int retorno;
	int bHsTrabajadas;
	retorno = -1;
	if(this != NULL && isValidHsTrabajadas(this,horasTrabajadasStr))
	{
        bHsTrabajadas=atoi(horasTrabajadasStr);
		this->horasTrabajadas = bHsTrabajadas;
		retorno = 0;
	}
	return retorno;
}
*/
/** \brief Recupero el valor de Hs trabajadas de un elemento existente
 *
 * \param this es la direccion de memoria del elemento
 * \param horasTrabajadas donde almaceno el valor que busco
 * \return -1 si hubo un error, 0 si fue exitoso
 *
 */
/*int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno;
	retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
	return retorno;
}*/

/** \brief Configura el sueldo de un empleado
 *
 * \param this es la direccion de memoria de un empleado
 * \param sueldo es el valor que se configurara al empleado recibido
 * \return
 *
 */
/*int employee_setSueldo(Employee* this,char* sueldo)
{
	int retorno;
	int bSueldo;
	retorno = -1;
	if(this != NULL && isValidSueldo(this,sueldo))
	{
        bSueldo=atoi(sueldo);
		this->sueldo = bSueldo;
		retorno = 0;
	}
	return retorno;
}
*/
/** \brief Configura el sueldo de un empleado
 *
 * \param this es la direccion de memoria de un empleado
 * \param sueldo es el valor que se configurara al empleado recibido
 * \return
 *
 */
int employee_setPuntaje(Employee* this,char* puntajePrimeraRonda)
{
	int retorno;
	int bSueldo;
	retorno = -1;
	if(this != NULL)// && isValidSueldo(this,sueldo))
	{
        bSueldo=atoi(puntajePrimeraRonda);
		this->puntajePrimeraRonda = bSueldo;
		retorno = 0;
	}
	return retorno;
}

/** \brief Recupero el sueldo de un elemento existente
 *
 * \param this es la direccion de memoria del elemento
 * \param sueldo donde almaceno el valor que busco
 * \return -1 si hubo un error, 0 si fue exitoso
 *
 */
/*int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno;
	retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
        *sueldo = this->sueldo;
        retorno = 0;
    }
	return retorno;
}*/

/** \brief Valida que el valor recibido es un nombre valido
 *
 * \param this es la direccion de memoria de un empleado
 * \param nombreStr es el valor a analizar
 * \return
 *
 */
int isValidNombre(Employee* this, char* nombreStr)
{
    int retorno;
	if(this != NULL && nombreStr != NULL)
	{
		retorno = -1;
        if(esAlfaNumerico(nombreStr))
        {
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Valida que el valor recibido es un ID valido
 *
 * \param this es la direccion de memoria de un empleado
 * \param id es el valor a analizar
 * \return
 *
 */
int isValidId(Employee* this, char* id)
{
    int retorno;
	if(this != NULL && id != NULL)
	{
		retorno = -1;
        if(esNumerico(id))
        {
            retorno = 0;
        }
    }
	return retorno;
}

/** \brief Valida que el valor recibido son horas validas
 *
 * \param this es la direccion de memoria de un empleado
 * \param horasTrabajadasStr es el valor a analizar
 * \return
 *
 */
int isValidHsTrabajadas(Employee* this, char* horasTrabajadasStr)
{
    int retorno;
	if(this != NULL && horasTrabajadasStr != NULL)
	{
		retorno = -1;
        if(esNumerico(horasTrabajadasStr))
        {
            retorno = 0;
        }
	}
    return retorno;
}

/** \brief Valida que el valor recibido es un sueldo valido
 *
 * \param this es la direccion de memoria de un empleado
 * \param sueldo es el valor a analizar
 * \return
 *
 */
int isValidSueldo(Employee* this, char* sueldo)
{
    int retorno;
	if(this != NULL && sueldo != NULL)
	{
		retorno = -1;
        if(esNumerico(sueldo))
        {
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Capturo del usuario el campo ID del elemento Empleado dentro de la estructura
 *
 * \param bName es la direccion de memoria donde almacenaremos el resultado de la consulta
 * \param pMensaje es la consigna que le brindaremos al usuario
 * \param pMensajeError es el mensaje de error que se le dara al usuario en caso de un ingreso erroneo
 * \param minimo es el valor minimo aceptado por la funcion
 * \param maximo es el valor maximo aceptado por la funcion
 * \param reintentos es la cantidad de reintentos que tendra el usuario en caso de un ingreso erroneo
 * \return Devuelve 0 si pudo capturar el dato o -1 si hubo algun error
 *
 */
int getIdStr(char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno = -1;
	char buffer[6];

	if(		pResultado != NULL &&
			pMensaje != NULL &&
			pMensajeError != NULL &&
			minimo < maximo &&
			reintentos > 0)
	{
		do
		{
			printf("%s",pMensaje);
			fflush(stdin);
			fgets(buffer,sizeof(buffer),stdin);
			buffer[strlen(buffer)-1]='\0';
			if(strlen(buffer)<=maximo && strlen(buffer)>=minimo)
			{
                if((esNumerico(buffer)==0) && (atoi(buffer)>= minimo) && (atoi(buffer)<=maximo))
                {
                    strncpy(pResultado,buffer,strlen(buffer));
                    retorno = 0;
                    break;
                }

			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

/** \brief Capturo del usuario el campo nombre del elemento Empleado dentro de la estructura
 *
 * \param bName es la direccion de memoria donde almacenaremos el resultado de la consulta
 * \param pMensaje es la consigna que le brindaremos al usuario
 * \param pMensajeError es el mensaje de error que se le dara al usuario en caso de un ingreso erroneo
 * \param minimo es el valor minimo aceptado por la funcion
 * \param maximo es el valor maximo aceptado por la funcion
 * \param reintentos es la cantidad de reintentos que tendra el usuario en caso de un ingreso erroneo
 * \return Devuelve 0 si pudo capturar el dato o -1 si hubo algun error
 *
 */
int getNombreStr(char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno = -1;
	char buffer[120];

	if(		pResultado != NULL &&
			pMensaje != NULL &&
			pMensajeError != NULL &&
			minimo < maximo &&
			reintentos > 0)
	{
		do
		{
			printf("%s",pMensaje);
			fflush(stdin);
			fgets(buffer,sizeof(buffer),stdin);
			buffer[strlen(buffer)-1]='\0';
			if(strlen(buffer)<=maximo && strlen(buffer)>=minimo)
			{

				if(isCharOrSpace(buffer)==0)
                {
                    strncpy(pResultado,buffer,maximo+1);
                    retorno = 0;
                    break;
                }
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

/** \brief Capturo del usuario el campo horas trabajadas del elemento Empleado dentro de la estructura
 *
 * \param bNombre es la direccion de memoria donde almacenaremos el resultado de la consulta
 * \param pMensaje es la consigna que le brindaremos al usuario
 * \param pMensajeError es el mensaje de error que se le dara al usuario en caso de un ingreso erroneo
 * \param minimo es el valor minimo aceptado por la funcion
 * \param maximo es el valor maximo aceptado por la funcion
 * \param reintentos es la cantidad de reintentos que tendra el usuario en caso de un ingreso erroneo
 * \return Devuelve 0 si pudo capturar el dato o -1 si hubo algun error
 *
 */
int getHsTrabajadasStr(char *bNombre,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno = -1;
	char buffer[7];

	if(		bNombre != NULL &&
			pMensaje != NULL &&
			pMensajeError != NULL &&
			minimo < maximo &&
			reintentos > 0)
	{
		do
		{
			printf("%s",pMensaje);
			fflush(stdin);
			fgets(buffer,sizeof(buffer),stdin);
			buffer[strlen(buffer)-1]='\0';
			if(strlen(buffer)<=maximo && strlen(buffer)>=minimo)
			{
                if((esNumerico(buffer)==0) && (atoi(buffer)>= minimo) && (atoi(buffer)<=maximo))
                {
                    strncpy(bNombre,buffer,strlen(buffer));
                    retorno = 0;
                    break;
                }

			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

/** \brief Capturo del usuario el campo sueldo del elemento Empleado dentro de la estructura
 *
 * \param pResultado es la direccion de memoria donde almacenaremos el resultado de la consulta
 * \param pMensaje es la consigna que le brindaremos al usuario
 * \param pMensajeError es el mensaje de error que se le dara al usuario en caso de un ingreso erroneo
 * \param minimo es el valor minimo aceptado por la funcion
 * \param maximo es el valor maximo aceptado por la funcion
 * \param reintentos es la cantidad de reintentos que tendra el usuario en caso de un ingreso erroneo
 * \return Devuelve 0 si pudo capturar el dato o -1 si hubo algun error
 *
 */
int getSueldoStr(char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno = -1;
	char buffer[7];

	if(		pResultado != NULL &&
			pMensaje != NULL &&
			pMensajeError != NULL &&
			minimo < maximo &&
			reintentos > 0)
	{
		do
		{
			printf("%s",pMensaje);
			fflush(stdin);
			fgets(buffer,sizeof(buffer),stdin);
			buffer[strlen(buffer)-1]='\0';
			if(strlen(buffer)<=maximo && strlen(buffer)>=minimo)
			{
                if((esNumerico(buffer)==0) && (atoi(buffer)>= minimo) && (atoi(buffer)<=maximo))
                {
                    strcpy(pResultado,buffer);
                    retorno = 0;
                    break;
                }

			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

/** \brief Ordena los empleados por Nombre de Manera Ascendente
 *
 * \param dato1 es el puntero a un elemento de la LinkedList
 * \param dato1 es el puntero a un elemento de la LinkedList
 * \return Devuelve 0 si los nombres son iguales, 1 si Nombre A > Nombre B o -1 si Nombre A < Nombre B; -2 si hubo un error
 *
 */
int employee_sortByName(void* dato1,void* dato2)
{

    Employee* a = (Employee*) dato1;
    Employee* b = (Employee*) dato2;
    char nombreStructOne[128];
    char nombreStructTwo[128];
    int retorno = -2;

    if(dato1 != NULL && dato2 != NULL)
    {
        retorno = -2;
        employee_getNombre(a,nombreStructOne);
        employee_getNombre(b,nombreStructTwo);

        if(strcmp(nombreStructOne, nombreStructTwo) == 0)
        {
            retorno = 0;
        }
        else if(strcmp(nombreStructOne, nombreStructTwo) > 0)
        {
            retorno = 1;
        }
        else
        {
            retorno = -1;
        }
    }
    return retorno;
}

/** \brief Esta funcion recorre la lista de empleados ordenada e inserta un nuevo empleado previo al que se busco
 *
 * \param this es la direccion de memoria de la LinkedList
 * \return Devuelve 0 si fue exitosa o -1 si hubo algun error.
 *
 */
int findPushEmployeeByName(LinkedList* this)
{
    int retorno = -1;
    int maxLen;
    int auxId;
    int employeeId;
    char auxNombre[256];
    char replace = 'n';
    char employeeName[256];
    Employee* auxEmployee;

    if(this != NULL)
    {
        if(getNombreStr(auxNombre,"\nIngrese el nombre del Empleado a buscar:\n","\nHa ingresado un nombre Invalido. Reintente\n",2,sizeof(auxNombre),3)==0)
        {
            maxLen = ll_len(this);
            for(int i = 0; i<maxLen;i++)
            {
                auxEmployee = ll_get(this,i);
                employee_getNombre(auxEmployee,employeeName);
                if(strcmp(employeeName,auxNombre)==0)
                {
                    employee_getId(auxEmployee,&employeeId);
                    printf("\n\nEl empleado se encuentra con el ID %d en la posicion Nro %d en la lista.\n\n",employeeId,i);
                    retorno = 0;
                    getChar(&replace,"Desea anteponer otro empleado? (s/n)\n","\nHa ingresado una respuesta Invalida. Reintente.\n",'n','s',3);
                    if(replace == 's')
                    {
                        auxId = employeeId;
                        controller_pushEmployee(this,auxId,auxEmployee);
                    }
                    break;
                }
            }
        }
        if(retorno != 0)
        {
            printf("\n\t\tNo se encontro el empleado. \n\n");
        }
    }
    return retorno;
}

/** \brief Inserta un empleado previamente al buscado
 *
 * \param pArrayListEmployee es la direccion de memoria de la LinkedList
 * \param auxId es el Id del empleado que se busca empujar una posicion
 * \param replaceEmployee es la direccion de memoria del empleado que se desea desplazar una posicion
 * \return Devuelve 0 si fue exitosa o -1 si hubo algun error
 *
 */
int controller_pushEmployee(LinkedList* pArrayListEmployee,int auxId, Employee* replaceEmployee)
{
	Employee* aEmployee;

    int retorno = -1;
	int maxLen;
	int maxId;
	int replaceIndex;
    int employeeId;
	char bufferAuxId[8];
	char bId[8];
	char bNombre[128];
	char bHorasTrabajadas[8];
	char bSueldo[8];
	char bufferId[8];
	char bufferNombre[128];
	char bufferHorasTrabajadas[8];
	char bufferSueldo[8];

	char numeroConcursante[255];
	char anio[255];
	char nombre[255];
	char dni[255];
	char fechaPresentacion[255];
	char temaPresentacion[255];
	char puntajePrimeraRonda[255];

	if(pArrayListEmployee != NULL)
	{
		maxLen = ll_len(pArrayListEmployee);
		maxId = 0;

		for(int i=0;i<maxLen;i++)
		{
			aEmployee = ll_get(pArrayListEmployee,i);
			employee_getId(aEmployee,&employeeId);
			if(employeeId > maxId)
			{
				maxId = employeeId;
			}
		}
			maxId++;
			sprintf(bId,"%d",maxId);
            strcpy(bufferId,bId);

		if(getNombreStr(bNombre, "Ingrese el nombre del Empleado: \n", "Ha ingresado un nombre invalido. Reintente\n",2,sizeof(bNombre),3)==0)
        {
            strcpy(bufferNombre,bNombre);
            if(getHsTrabajadasStr(bHorasTrabajadas, "\nIngrese las horas trabajadas del nuevo empleado.\n","Ha ingresado un valor invalido, reingrese.\n",0,99000,3)==0)
            {
                strcpy(bufferHorasTrabajadas,bHorasTrabajadas);
                if(getSueldoStr(bSueldo, "\nIngrese el sueldo del nuevo empleado.\n","Ha ingresado un valor invalido, reingrese.\n",0,999999,3)==0)
                {
                    strcpy(bufferSueldo,bSueldo);
                    sprintf(bufferAuxId,"%d",auxId);
//                    aEmployee = employee_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
                    aEmployee = employee_newParametros(numeroConcursante,anio,nombre,dni,fechaPresentacion,temaPresentacion,puntajePrimeraRonda);
                    replaceIndex = ll_indexOf(pArrayListEmployee,replaceEmployee);
                    ll_push(pArrayListEmployee, replaceIndex, aEmployee);
                    retorno = 0;
                }
            }
        }
		if(retorno != 0)
		{
			printf("\n\tNo se pudo completar la carga del empleado, reintente.\n\n");
		}
	}
	return retorno;
}

/** \brief Esta funcion recorre la lista de empleados ordenada e inserta un nuevo empleado previo al que se busco
 *
 * \param this es la direccion de memoria de la LinkedList
 * \return Devuelve 0 si fue exitosa o -1 si hubo algun error.
 *
 */
int findDeleteEmployeeByName(LinkedList* this)
{
    int retorno = -1;
    int maxLen;
    char auxNombre[256];
    char replace = 'n';
    char employeeName[256];

    Employee* auxEmployee;

    if(this != NULL)
    {
        if(getNombreStr(auxNombre,"\nIngrese el nombre del Empleado a buscar:\n","\nHa ingresado un nombre Invalido. Reintente\n",2,sizeof(auxNombre),3)==0)
        {
            maxLen = ll_len(this);
            for(int i = 0; i<maxLen;i++)
            {
                auxEmployee = ll_get(this,i);
                employee_getNombre(auxEmployee,employeeName);
                if(strcmp(employeeName,auxNombre)==0)
                {
                    printf("\n\nEl empleado se encuentra con el ID %d en la posicion Nro %d en la lista.\n\n",auxEmployee->id,i);
                    retorno = 0;
                    getChar(&replace,"Desea Eliminar el empleado de la lista? (s/n)\n","\nHa ingresado una respuesta Invalida. Reintente.\n",'n','s',3);
                    if(replace == 's')
                    {
                        ll_pop(this,i);
                    }
                    break;
                }
            }
        }
        if(retorno != 0)
        {
            printf("\n\t\tNo se encontro el empleado. \n\n");
        }
    }
    return retorno;
}

/** \brief Recupera el INT de un empleado en la lista
 *
 * \param this es la direccion de memoria del elemento
 * \param id es el campo donde se almacenara el dato recuperado
 * \return -1 si hubo algun error, 0 si fue exitoso
 *
 */
/*int employee_getInt(Employee* this,int *number)
{
	int retorno;
	retorno = -1;
	if(this != NULL)
	{
	    *number=this->id;
        retorno = 0;
    }
	return retorno;
}*/

/** \brief Recupero el STRING de un elemento existente
 *
 * \param this es la direccion de memoria del elemento
 * \param nombre donde almaceno el valor que busco
 * \return -1 si hubo un error, 0 si fue exitoso
 *
 */
/*int employee_getStr(Employee* this,char* cadena)
{
	int retorno;
	retorno = -1;
	if(this != NULL && nombre != NULL)
	{
	    strncpy(this->nombre,string,sizeof(this->nombre));
        retorno = 0;
    }
	return retorno;
}*/

/** \brief Configura el INT de un empleado
 *
 * \param this es la direccion de memoria de un empleado
 * \param id es el id que se configurara al empleado recibido
 * \return
 *
 */

/*int employee_setInt(Employee* this,char* number)
{
    int retorno;
	int bId;
	retorno = -1;
	if(this!=NULL)// && isValidId(this,id))
	{
		bId=atoi(number);
		this->id = bId;
		retorno = 0;
	}
	return retorno;
}*/

/** \brief Configura el nombre de un empleado
 *
 * \param this es la direccion de memoria de un empleado
 * \param nombre es el nombre que se configurara al empleado recibido
 * \return
 *
 */
/*int employee_setStr(Employee* this,char* cadena)
{
	int retorno;
	retorno = -1;
	if(this!=NULL)// && isValidNombre(this,nombre))
	{
		strncpy(cadena,this->nombre,sizeof(this->nombre));
		retorno = 0;
	}
	return retorno;
}
*/
/** \brief Recupero el STRING de un elemento existente
 *
 * \param this es la direccion de memoria del elemento
 * \param nombre donde almaceno el valor que busco
 * \return -1 si hubo un error, 0 si fue exitoso
 *
 */
int employee_getDni(Employee* this,char* dni)
{
	int retorno;
	retorno = -1;
	if(this != NULL && dni != NULL)
	{
	    strncpy(dni,this->dni,sizeof(this->dni));
        retorno = 0;
    }
	return retorno;
}

/** \brief Recupera el ANIO de un empleado en la lista
 *
 * \param this es la direccion de memoria del elemento
 * \param id es el campo donde se almacenara el dato recuperado
 * \return -1 si hubo algun error, 0 si fue exitoso
 *
 */
int employee_getAnio(Employee* this,int* anio)
{
	int retorno;
	retorno = -1;
	if(this != NULL && anio != NULL)
	{
	    *anio=this->anioNacimiento;
        retorno = 0;
    }
	return retorno;
}
/** \brief Recupero el STRING de un elemento existente
 *
 * \param this es la direccion de memoria del elemento
 * \param nombre donde almaceno el valor que busco
 * \return -1 si hubo un error, 0 si fue exitoso
 *
 */
int employee_getFechaPresentacion(Employee* this,char* fecha)
{
	int retorno;
	retorno = -1;
	if(this != NULL && fecha != NULL)
	{
	    strncpy(fecha,this->fechaPresentacion,10);
        retorno = 0;
    }
	return retorno;
}
/** \brief Recupero el STRING de un elemento existente
 *
 * \param this es la direccion de memoria del elemento
 * \param nombre donde almaceno el valor que busco
 * \return -1 si hubo un error, 0 si fue exitoso
 *
 */
int employee_getTemaPresentacion(Employee* this,char* tema)
{
	int retorno;
	retorno = -1;
	if(this != NULL && tema != NULL)
	{
	    strncpy(tema,this->temaPresentacion,30);
        retorno = 0;
    }
	return retorno;
}

/** \brief Recupera el id de un empleado en la lista
 *
 * \param this es la direccion de memoria del elemento
 * \param id es el campo donde se almacenara el dato recuperado
 * \return -1 si hubo algun error, 0 si fue exitoso
 *
 */
int employee_getPuntajePrimeraRonda(Employee* this,int *number)
{
	int retorno;
	retorno = -1;
	if(this != NULL)
	{
	    *number=this->puntajePrimeraRonda;
        retorno = 0;
    }
	return retorno;
}

int employee_juradoCalculaPuntaje(void* this)
{
    int retorno;
    Employee* auxEmployee;
    retorno=-1;
    if(this != NULL)
    {
        auxEmployee=(Employee*)this;
        if(employee_calculoSegundaRonda(auxEmployee)==0)
        {
            if(employee_calculoPromedioPuntaje(auxEmployee)==0)
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}

int employee_calculoSegundaRonda(Employee* this)
{
    int retorno;
    int puntaje_random;
    if(this!=NULL)
    {
        retorno = -1;
        puntaje_random=rand()%101;
        if(employee_setSegundaRonda(this,puntaje_random)==0)
        {
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Configura el sueldo de un empleado
 *
 * \param this es la direccion de memoria de un empleado
 * \param sueldo es el valor que se configurara al empleado recibido
 * \return
 *
 */
int employee_setSegundaRonda(Employee* this,int puntajeSegundaRonda)
{
	int retorno;
	retorno = -1;
	if(this != NULL)// && isValidSueldo(this,sueldo))
	{
		this->puntajeSegundaRonda = puntajeSegundaRonda;
		retorno = 0;
	}
	return retorno;
}

int employee_calculoPromedioPuntaje(Employee* this)
{
    int retorno;
    float promedio;
    int primeraRonda;
    int segundaRonda;
    retorno = -1;
    if(this!=NULL)
    {
        if(employee_getPuntajePrimeraRonda(this,&primeraRonda)==0)
        {
            if(employee_getPuntajeSegundaRonda(this,&segundaRonda)==0)
            {
                promedio=(float)((primeraRonda+segundaRonda)/2.00);
            }
            else
            {
            promedio=(float)primeraRonda;
            }
            employee_setPromedio(this,promedio);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Recupera el id de un empleado en la lista
 *
 * \param this es la direccion de memoria del elemento
 * \param id es el campo donde se almacenara el dato recuperado
 * \return -1 si hubo algun error, 0 si fue exitoso
 *
 */
int employee_getPuntajeSegundaRonda(Employee* this,int *number)
{
	int retorno;
	retorno = -1;
	if(this != NULL)
	{
	    *number=this->puntajeSegundaRonda;
        retorno = 0;
    }
	return retorno;
}

int employee_setPromedio(Employee* this,float promedio)
{
	int retorno;
	retorno = -1;
	if(this != NULL)
	{
        this->promedioPuntaje= promedio;
		retorno = 0;
	}
	return retorno;
}

int employee_getPromedioPuntaje(Employee* this,float* promedio)
{
	int retorno;
	retorno = -1;
	if(this != NULL)
	{
        //this->promedioPuntaje= promedio;
        *promedio = this->promedioPuntaje;
		retorno = 0;
	}
	return retorno;
}

int employee_countMinusTen(void* this)
{
    int retorno;
    int puntajePrimerRonda;
    char* dni=NULL;
    Employee* auxEmployee;
    retorno=0;
    dni=(char*)malloc(sizeof(char)*12);
    if(this != NULL)
    {
        auxEmployee=(Employee*)this;
        employee_getPuntajePrimeraRonda(auxEmployee,&puntajePrimerRonda);
        employee_getDni(auxEmployee,dni);
        if(puntajePrimerRonda<10)
        {
            retorno++;
            strcat(dni,".csv");
            //printf("XX %s\n",dni);
            controller_saveOneAsText(dni,auxEmployee);
        }
    }
    return retorno;
}
