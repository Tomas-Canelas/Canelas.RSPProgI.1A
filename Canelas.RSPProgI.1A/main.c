#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int id;
	char marca[20];
	int tipo;
	float peso;
}eVehiculo;

eVehiculo* veh_new();
eVehiculo* veh_newParam();
int veh_setId(eVehiculo* this,int id);
int veh_getId(eVehiculo* this,int* id);
int veh_setMarca(eVehiculo* this,char* marca);
int veh_getMarca(eVehiculo* this,char* marca);
int veh_setTipo(eVehiculo* this,int tipo);
int veh_getTipo(eVehiculo* this,int* tipo);
int veh_setPeso(eVehiculo* this,float peso);
int veh_getPeso(eVehiculo* this,float* peso);
int punto2();

int main(void)
{

	punto2();

	return EXIT_SUCCESS;
}


int veh_setId(eVehiculo* this,int id)
{
    int todoOk = 0;

    if(this != NULL && id >= 1)
    {
    	this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int veh_getId(eVehiculo* this,int* id)
{
    int todoOk = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int veh_setMarca(eVehiculo* this,char* marca)
{
	int todoOk=0;


	if(this!=NULL)
	{

		strcpy(this->marca,marca);
		todoOk=1;
	}
	return todoOk;
}


int veh_getMarca(eVehiculo* this,char* marca)
{
	int todoOk=0;
	if(this!=NULL && marca)
	{
		strcpy(marca,this->marca);
		todoOk=1;
	}
	return todoOk;
}

int veh_setTipo(eVehiculo* this,int tipo)
{
    int todoOk = 0;

    if(this != NULL)
    {
    	this->tipo = tipo;
        todoOk = 1;
    }
    return todoOk;
}

int veh_getTipo(eVehiculo* this,int* tipo)
{
    int todoOk = 0;

    if(this != NULL && tipo != NULL)
    {
        *tipo = this->tipo;
        todoOk = 1;
    }
    return todoOk;
}


int veh_setPeso(eVehiculo* this,float peso)
{
    int todoOk = 0;

    if(this != NULL)
    {
    	this->peso = peso;
        todoOk = 1;
    }
    return todoOk;
}

int veh_getPeso(eVehiculo* this,float* peso)
{
    int todoOk = 0;

    if(this != NULL && peso != NULL)
    {
        *peso = this->peso;
        todoOk = 1;
    }
    return todoOk;
}

eVehiculo* veh_new()
{
		eVehiculo* vehiculo = (eVehiculo*) malloc(sizeof(eVehiculo));
		if(vehiculo!=NULL)
		{
			vehiculo->id=0;
			*(vehiculo->marca)='\0';
			vehiculo->tipo=0;
			vehiculo->peso=0;
		}

		return vehiculo;
}

eVehiculo* veh_newParam(char* marca,char* id, char* peso, char* tipo)
{
	eVehiculo* vehiculo = veh_new();
	if(vehiculo!=NULL)
	{
		if(!  (veh_setMarca(vehiculo, marca) && (veh_setId(vehiculo, atoi(id))) && veh_setPeso(vehiculo, atof(peso)) && veh_setTipo(vehiculo, atoi(tipo))))
		{
			free(vehiculo);
			vehiculo=NULL;
		}
	}
	return vehiculo;
}


int punto2()
{
	int todoOk=0;
	int id;
	char marca[20];
	int tipo;
	float peso;
	eVehiculo* v=NULL;
	v=veh_newParam("Toyota", "4", "2000.50", "3");
	FILE* f= fopen("archivo.csv","w");

	if(f!=NULL)
	{
		veh_getMarca(v, marca);
		veh_getId(v, &id);
		veh_getPeso(v, &peso);
		veh_getTipo(v, &tipo);
		fprintf(f,"%d,%s,%.2f,%d\n",id,marca,peso,tipo);
		todoOk=1;
	}

	fclose(f);
	return todoOk;

}
