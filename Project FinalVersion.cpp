#include <iostream>
#include <stdlib.h>
#include <locale.h>

using namespace std;

struct nodoCuentaUsuario{
	
	string nombreUsuario;
	string contrasena;
	string tipoCuenta;
	string estadoCuenta;
	bool status;
	nodoCuentaUsuario *siguiente; //apuntador 
};

typedef struct nodoCuentaUsuario *listaCuentas;

//Aqui se almacenan los usuarios
nodoCuentaUsuario *crearNodo(string nomUs, string pwd, string tipo, string estado,bool status){
	
	nodoCuentaUsuario *aux = new (struct nodoCuentaUsuario);  
	aux->nombreUsuario=nomUs;
	aux->contrasena=pwd;
	aux->estadoCuenta=estado;
	aux->tipoCuenta=tipo;
	aux->status=status;
	aux->siguiente=NULL;
	return aux;
}

void IngresarFinal(listaCuentas &cabeza ,string nomUs, string pwd, string tipo, string estado,bool status){
	nodoCuentaUsuario *nuevo;
	listaCuentas aux;
	
	nuevo = crearNodo(nomUs,pwd,tipo,estado,status);
	
	if (cabeza == NULL)
	cabeza=nuevo;
	else {
		
		aux = cabeza;
		while (aux-> siguiente!=NULL)
		aux = aux->siguiente;
		
		aux->siguiente=nuevo;
		
	}
}
void Mostrar(listaCuentas cabeza)
{
    listaCuentas aux;

    if(cabeza==NULL)
    cout <<"Lista vacia"<<endl;
    else
    {
        aux=cabeza;
        while(aux!=NULL)
        {
        cout << "Nombre de Usuario: " << aux->nombreUsuario <<endl;
        cout << "Contrasena: " << aux->contrasena <<endl;
        cout << "Estado de la cuenta: " << aux->estadoCuenta <<endl;
        cout << "Tipo de cuenta " << aux->tipoCuenta << endl;
        cout << "Status: " << aux->status <<endl;
        cout << "*****************************"<<endl;
        aux=aux->siguiente;
        }
    }
}
void ModificarPasswordUser(listaCuentas cabeza,string nom,string pwd)
{
    listaCuentas aux;

    if(cabeza==NULL)
    cout <<"Lista vacia" << endl;
    else
    {
        aux=cabeza;
        while (aux!=NULL)
        {
               if(aux->nombreUsuario==nom)
              {  
                aux->nombreUsuario=nom;
                   aux->contrasena=pwd;
            }
                aux=aux->siguiente;
            }
    }
}

void ModificarEstadoCuenta(listaCuentas cabeza,string nom,string estado)
{
    listaCuentas aux;

    if(cabeza==NULL)
    cout <<"Lista vacia" << endl;
    else
    {
        aux=cabeza;
        while (aux!=NULL)
        {
               if(aux->nombreUsuario==nom)
              {  
                aux->nombreUsuario=nom;
                   aux->estadoCuenta=estado;
            }
                aux=aux->siguiente;
            }
    }
}

void verificarExisteUsuario(listaCuentas cabeza, string nom,string pwd)
{
	listaCuentas aux;
	int contadorIntentos;
	bool flag = true;
	
	if(cabeza == NULL)
	cout << " Lista Vacia "<< endl;
	else 
	{
		aux=cabeza;
		while (flag==true)
		{		
			//IF para verificar si el usuario digitado existe en la memorio
			if(aux->nombreUsuario!=nom)
			{	
				cout<<" Usuario no existe, puede utilizar este nombre para registrar " << endl;
				aux=aux->siguiente;
			}
			else
			{
				cout<< "Usuario ya existe, por favor digite otro nombre de usuario "<<endl;
				cout<< "........."<<endl;
				flag=false;
			}
		}
	}
}

bool verificarPassword(listaCuentas cabeza,string nom,string pwd)
{
	listaCuentas aux;
	int contadorIntentos=0;
	bool flag = true;
	bool estado=false;
	
	if(cabeza == NULL)
	cout << " Lista Vacia "<< endl;
	else 
	{
		aux=cabeza;
		while (aux!=NULL)
		{
			if (aux->nombreUsuario==nom)	
			{		
				while (flag==true)
				{
					if(aux->contrasena!=pwd)
					{
						cout << "Password incorrecto" << endl;
						contadorIntentos++;
						cout<< "intente nuevamente" <<endl;
						cin>>pwd;			
					}
					else if (aux->nombreUsuario==nom && aux->contrasena==pwd)
					{
						cout<<"Password correcto"<<endl;
						contadorIntentos=0;
						flag=false;
					}
					
					if(contadorIntentos == 3 )
					{
						cout << "Cuenta Bloqueada! "<<endl;
						cout << "Contacte a un admin "<<endl;
						estado=true; //bloqueada
						flag=false;
					}
				}
				aux=NULL;
			}
			else{
				aux=aux->siguiente;
			}
		}
	}
	return estado;
}

bool verificarEstadoCuenta(listaCuentas cabeza,string nom)
{
	listaCuentas aux;
	int contadorIntentos;
	bool flag = true;
	bool estado;
	
	if(cabeza == NULL)
	cout << " Lista Vacia "<< endl;
	else 
	{
		aux=cabeza;
			while (aux!=NULL)
		{
			if (aux->nombreUsuario==nom)
			{
				while (flag==true)
				{
					if(aux->estadoCuenta=="Activo")
					{
						cout << " Cuenta de usuario Activa"<< endl;
						cout <<	" Iniciando Sesion de " << aux->nombreUsuario<< endl;
						estado = true;
						flag =false;
						aux=NULL;
					}
					else
					{
						cout<< " Acceso denegado!"<< endl;
						cout<< " Cuenta de usuario Inactiva "<<endl;
						cout<< "Por favor contacta al administrador, para activar la cuenta "<<endl;
						estado = false;
						flag = false;
						aux=NULL;
					}
				}
			}
			else{
				aux=aux->siguiente;
			}
		}		
	}
	return estado;
}

struct nodoCita
{
   string nombrePaciente;
   string nombreDoctor;
   string sintoma;
   string especialidad;
   int mes;
   int dia;
   int ano;
   nodoCita *siguiente;
};
typedef struct nodoCita *listaC;
nodoCita *crearNodoC(string np,string nd,string s,string e, int m, int d, int a) 
{
	nodoCita *aux = new (struct nodoCita);
	aux->nombrePaciente = np;
	aux->nombreDoctor = nd;
	aux->sintoma = s;
	aux->especialidad = e;
	aux->mes = m;
	aux->dia = d;
	aux->ano = a;
	aux->siguiente = NULL;
	return aux; 
};

struct nodoCuenta
{
   string nombre;
   int codigo;
   char tipoUsuario;
   string cuentaUsuario;
   string contra;
   string estado;
   nodoCuenta *siguiente;
};
typedef struct nodoCuenta *lista;

nodoCuenta *crearNodo(string n, int cod, char t, string cU, string c, string e) 
{
	nodoCuenta *aux = new (struct nodoCuenta);
	aux->nombre = n;
	aux->codigo = cod;
	aux->tipoUsuario = t;
	aux->cuentaUsuario = cU;
	aux->contra = c;
	aux->estado = e;
	aux->siguiente = NULL;
	return aux; 
};


struct nodoDoctor
{
   string nombreDoc;
   string especialidad;
   int codigoDoc;
   
   nodoDoctor *siguiente;
};
typedef struct nodoDoctor *listaD;

nodoDoctor *crearNodoD(string n, string esp, int c) 
{
	nodoDoctor *aux = new (struct nodoDoctor);
	aux->nombreDoc = n;
	aux->especialidad = esp;
	aux->codigoDoc = c;
	aux->siguiente = NULL;
	return aux; 
};


struct nodoPaciente
{
   string nombrePaciente;
   int cedula;
   int numeroTelefono;
   string sintomas;
   string fechaIngreso;
   
   nodoPaciente *siguiente;
};
typedef struct nodoPaciente *listaP;

nodoPaciente *crearNodoP(string n, int ced, int nT, string s, string fI) 
{
	nodoPaciente *aux = new (struct nodoPaciente);
	aux->nombrePaciente = n;
	aux->cedula = ced;
	aux->numeroTelefono = nT;
	aux->sintomas = s;
	aux->fechaIngreso = fI;
	aux->siguiente = NULL;
	return aux; 
};
			
void ingresarFinal (lista &cabeza, string n, int cod, char t, string cU, string c, string e)
{					
	nodoCuenta *nuevo;
	nuevo = crearNodo (n, cod, t, cU, c, e);
	lista aux;
			
	//aqui va el if que compara si la cuenta es admin o no, si es admin puede crear otras acc
	if (cabeza==NULL)
	cabeza=nuevo;
	else
	{	
		aux=cabeza;
		while(aux->siguiente!=NULL)	
		aux=aux->siguiente;
		aux->siguiente=nuevo;
	}
	
	//si no, ponemos en else con un msj que diga, "la cuenta no tiene permisos o algo asi"
			
};
void ingresarCita(listaC &cabeza,string np,string nd,string s,string e, int m, int d, int a)
{					
	int contador ;
	nodoCita *nuevo;
	nuevo = crearNodoC (np, nd, s,e,m,d,a);
	listaC aux;
			
	if (cabeza==NULL)
	cabeza=nuevo;
	else
	{	
		
		aux=cabeza;
		while(aux->siguiente!=NULL)	
		aux=aux->siguiente;
		aux->siguiente=nuevo;
	}
			
};

void ingresarDoctor(listaD &cabeza, string n, string esp, int c)
{					
	nodoDoctor *nuevo;
	nuevo = crearNodoD (n, esp, c);
	listaD aux;
			
	//aqui va el if que compara si la cuenta es admin o no, si es admin puede crear otras acc
	if (cabeza==NULL)
	cabeza=nuevo;
	else
	{	
		aux=cabeza;
		while(aux->siguiente!=NULL)	
		aux=aux->siguiente;
		aux->siguiente=nuevo;
	}
	
	//si no, ponemos en else con un msj que diga, "la cuenta no tiene permisos o algo asi"
			
};

void ingresarPaciente (listaP &cabeza, string n, int ced, int nT, string s, string fI)
{					
	nodoPaciente *nuevo;
	nuevo = crearNodoP(n, ced, nT, s, fI);
	listaP aux;
			
	//aqui va el if que compara si la cuenta es admin o no, si es admin puede crear otras acc
	if (cabeza==NULL)
	cabeza=nuevo;
	else
	{	
		aux=cabeza;
		while(aux->siguiente!=NULL)	
		aux=aux->siguiente;
		aux->siguiente=nuevo;
	}
	
	//si no, ponemos en else con un msj que diga, "la cuenta no tiene permisos o algo asi"
			
};

void Eliminar(lista &cabeza, string cU)
{
	lista aux,ant;
	
	//aqui hacemos el if haciendo la comparacion para ver si la acc es admin
	if(cabeza==NULL)
	cout <<"Lista vacia" << endl;
	else
	{
		aux=cabeza;

		if(aux->cuentaUsuario==cU)
		{
         	cabeza=aux->siguiente;
          	aux->siguiente=NULL;
         	delete(aux);
         	aux=cabeza;
		}
		else
			{ 	
    			while(aux!=NULL)
     			{  
						if((aux->cuentaUsuario==cU) && (aux->siguiente!=NULL))
         				{
							ant->siguiente=aux->siguiente;
               				aux->siguiente=NULL;
							delete(aux);
							aux=ant->siguiente;
          				}
        				else
        					{
								if((aux->cuentaUsuario==cU) && (aux->siguiente==NULL))
          						ant->siguiente=NULL;
         					
        					}
   				ant=aux;
   				aux=aux->siguiente;
				}	
			}
	}
	
	//aqui iria el else con un msj que diga, "la cuenta no tiene permisos o algo asi"
	
}

void EliminarDoctor(listaD &cabeza,int cod)
{
	listaD aux,ant;
	
	if(cabeza==NULL)
	cout <<"Lista vacia" << endl;
	else
	{
		aux=cabeza;

		if(aux->codigoDoc==cod)
		{
         	cabeza=aux->siguiente;
          	aux->siguiente=NULL;
         	delete(aux);
         	aux=cabeza;
		}
		else
			{ 	
    			while(aux!=NULL)
     			{  
						if((aux->codigoDoc==cod) && (aux->siguiente!=NULL))
         				{
							ant->siguiente=aux->siguiente;
               				aux->siguiente=NULL;
							delete(aux);
							aux=ant->siguiente;
          				}
        				else
        					{
								if((aux->codigoDoc==cod) && (aux->siguiente==NULL))
          						ant->siguiente=NULL;
         					
        					}
   				ant=aux;
   				aux=aux->siguiente;
				}	
			}
	}
	
}

void MostrarPacientesEspecialidad(listaC cabeza, string e)
{
	listaC aux;
	string nombre, espec;
	int especialidad;
	int cant_pacientes =0 ;
	
	if(cabeza==NULL)
	cout <<"Lista vacia" << endl;
	else
	{
		aux=cabeza;
		while (aux!=NULL)
		{
   			if(aux->especialidad==e)
  			{   
				cout << "Nombre Paciente: " << aux->nombrePaciente <<endl;
				cout << "Especialidad: " << aux->especialidad <<endl;
				cout << "*****************************"<<endl;
				cant_pacientes++;
			}
				aux=aux->siguiente;
			
		}
		cout <<"Cantidad de pacientes en la especialidad buscada: "<<cant_pacientes <<endl;
	}
}

void MostrarDoctoresClinica(listaD cabeza)
{
	listaD aux;
	int contador = 0;
	
	if(cabeza==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=cabeza;
		while(aux!=NULL)
		{
		cout << "Nombre: " << aux->nombreDoc <<endl;
		cout << "Especialidad: " << aux->especialidad <<endl;
		cout << "Codigo: " << aux->codigoDoc <<endl;
		cout << "*****************************"<<endl;
		contador++;
		aux=aux->siguiente;
		}
		cout << "Cantidad de doctores en la clinica: " <<contador <<endl;
	}
}
void verificarCita(listaC cabeza, int m, int d)
{
	listaC aux;
	int contador = 0;
	
	if(cabeza==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=cabeza;
		while(aux!=NULL)
		{
			if((aux->mes==m) && (aux->dia==d))
	{
		cout << "Nombre Doctor: " << aux->nombreDoctor <<endl;
		cout << "Nombre Paciente: " << aux->nombrePaciente <<endl;
		cout << "Especialidad: " << aux->especialidad <<endl;
		cout << "Sintomas: " << aux->sintoma <<endl;
		cout << "Mes de la cita: " << aux->mes <<endl;
		cout << "Dia de la cita: " << aux->dia <<endl;
		cout << "*****************************"<<endl;
		
	}
	aux=aux->siguiente;
		}
	}
}
void MostrarDoctoresEspecialidad(listaD cabeza, string e)
{
	listaD aux;
	string nombre, espec;
	int especialidad;
	int cant_doctores =0 ;
	
	if(cabeza==NULL)
	cout <<"Lista vacia" << endl;
	else
	{
		aux=cabeza;
		while (aux!=NULL)
		{
   			if(aux->especialidad==e)
  			{   
				cout << "Codigo: " << aux->codigoDoc <<endl;
				cout << "Nombre Doctor: " << aux->nombreDoc <<endl;
				cout << "Especialidad: " << aux->especialidad <<endl;
				cout << "*****************************"<<endl;
				cant_doctores++;
			}
				aux=aux->siguiente;
			
		}
		cout <<"Cantidad de doctores en la especialidad buscada: "<<cant_doctores <<endl;
	}
}


void MostrarPacientesDoctor(listaC cabeza, string n)
{
	listaC aux;
	string nombreDoctor, espec;
	int especialidad;
	int cant_pacientes =0 ;
	
	if(cabeza==NULL)
	cout <<"Lista vacia" << endl;
	else
	{
		aux=cabeza;
		while (aux!=NULL)
		{
   			if(aux->nombreDoctor==n)
  			{   
				
				cout << "Nombre Paciente: " << aux->nombrePaciente <<endl;
				cout << "Sintomas: " << aux->sintoma <<endl;
				cout << "Nombre Doctor: " << aux->nombreDoctor <<endl;
				cout << "Especialidad: " << aux->especialidad <<endl;
				cout << "Mes: " << aux->mes <<endl;
				cout << "Dia: " << aux->dia <<endl;
				cout << "*****************************"<<endl;
				cant_pacientes++;
			}
				aux=aux->siguiente;
			
			
		}
		cout <<"Cantidad de pacientes atendidos: "<<cant_pacientes <<endl;
	}
}


void MostrarCitasporMes(listaC cabeza, int m)
{
	listaC aux;
	string nombre, espec;
	int mes;
	int contador =0 ;
	
	if(cabeza==NULL)
	cout <<"Lista vacia" << endl;
	else
	{
		aux=cabeza;
		while (aux!=NULL)
		{
   			if(aux->mes==m)
  			{   
				cout << "Nombre Paciente: " << aux->nombrePaciente <<endl;
				cout << "Nombre Doctor: " << aux->nombreDoctor <<endl;
				cout << "Mes: " << aux->mes <<endl;
				cout << "Dia: " << aux->dia <<endl;
				cout << "*****************************"<<endl;
				contador++;
			}
				aux=aux->siguiente;		
		}
		cout <<"Cantidad de citas en el mes buscado: " <<contador <<endl;
	}
}

void ModificarInfoDoctor(listaD cabeza, int cod)
{
	listaD aux;
	string nombre, espec;
	int codigo;
	
	if(cabeza==NULL)
	cout <<"Lista vacia" << endl;
	else
	{
		aux=cabeza;
		while (aux!=NULL)
		{
   			if(aux->codigoDoc==cod)
  			{   
			    int opc;
					do{
						system("cls");
						cout << "1. Modificar nombre del doctor" << endl;
						cout << "2. Modificar especialidad del doctor" << endl;
						cout << "3. Modificar codigo del doctor" << endl;
						cout << "4. Salir" << endl;
						cout << "Cual opcion desea: ";
						cin >> opc;
		
						switch(opc)
						{
							case 1:
							cout << "Digite el nombre" << endl;
							cin >> nombre;
							aux->nombreDoc=nombre; 
							break;
			
							case 2: 
							cout << "Digite la especialidad" << endl;
							cin >> espec;
							aux->especialidad=espec; 
							break;
			
							case 3:
							cout << "Digite el codigo" << endl;
							cin >> codigo;
							aux->codigoDoc=codigo; 
							break;
						
						}
		
					}
					while(opc != 4);
			}
				aux=aux->siguiente;
		}

	}
}

void EliminarPaciente(listaP &cabeza,int ced)
{
	listaP aux,ant;
	
	if(cabeza==NULL)
	cout <<"Lista vacia" << endl;
	else
	{
		aux=cabeza;

		if(aux->cedula==ced)
		{
         	cabeza=aux->siguiente;
          	aux->siguiente=NULL;
         	delete(aux);
         	aux=cabeza;
		}
		else
			{ 	
    			while(aux!=NULL)
     			{  
						if((aux->cedula==ced) && (aux->siguiente!=NULL))
         				{
							ant->siguiente=aux->siguiente;
               				aux->siguiente=NULL;
							delete(aux);
							aux=ant->siguiente;
          				}
        				else
        					{
								if((aux->cedula==ced) && (aux->siguiente==NULL))
          						ant->siguiente=NULL;
         					
        					}
   				ant=aux;
   				aux=aux->siguiente;
				}	
			}
	}
	
}

void ModificarInfoPaciente(listaP cabeza, int ced)
{
	listaP aux;
	string nombre, sint;
	int cedu, numeroTel;
	
	if(cabeza==NULL)
	cout <<"Lista vacia" << endl;
	else
	{
		aux=cabeza;
		while (aux!=NULL)
		{
   			if(aux->cedula==ced)
  			{   
			    int opc;
					do{
						system("cls");
						cout << "1. Modificar nombre del paciente" << endl;
						cout << "2. Modificar sintomas del paciente" << endl;
						cout << "3. Modificar cedula del paciente" << endl;
						cout << "4. Modificar numero de telefono del paciente" << endl;
						cout << "5. Salir" << endl;
						cout << "Cual opcion desea: ";
						cin >> opc;
		
						switch(opc)
						{
							case 1:
							cout << "Digite el nombre" << endl;
							cin >> nombre;
							aux->nombrePaciente=nombre; 
							break;
			
							case 2: 
							cout << "Digite los sintomas" << endl;
							cin >> sint;
							aux->sintomas=sint; 
							break;
			
							case 3:
							cout << "Digite la cedula del paciente" << endl;
							cin >> cedu;
							aux->cedula=cedu; 
							break;
							
							case 4:
							cout << "Digite el numero de telefono del paciente" << endl;
							cin >> numeroTel;
							aux->numeroTelefono=numeroTel; 
							break;
						
						}
		
					}
					while(opc != 5);
			}
				aux=aux->siguiente;
		}
		//aqui se puede poner un cout diciendo que el doctor no existe...
	}
}

void Mostrar(lista cabeza)
{
	lista aux;
	
	if(cabeza==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=cabeza;
		while(aux!=NULL)
		{
		cout << "Nombre: " << aux->nombre <<endl;
		cout << "Codigo: " << aux->codigo <<endl;
		cout << "Tipo de usuario: " << aux->tipoUsuario <<endl;
		cout << "Cuenta del usuario: " << aux->cuentaUsuario <<endl;
		cout << "Contraseña: " << aux->contra <<endl;
		cout << "Estado: " << aux->estado <<endl;
		cout << "*****************************"<<endl;
		aux=aux->siguiente;
		}
	}
}

void MostrarDoctores(listaD cabeza)
{
	listaD aux;
	
	if(cabeza==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=cabeza;
		while(aux!=NULL)
		{
		cout << "Nombre: " << aux->nombreDoc <<endl;
		cout << "Especialidad: " << aux->especialidad <<endl;
		cout << "Codigo: " << aux->codigoDoc <<endl;
		cout << "*****************************"<<endl;
		aux=aux->siguiente;
		}
	}
}

void MostrarPacientes(listaP cabeza)
{
	listaP aux;
	
	if(cabeza==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=cabeza;
		while(aux!=NULL)
		{
		cout << "Nombre: " << aux->nombrePaciente <<endl;
		cout << "Cedula: " << aux->cedula <<endl;
		cout << "Numero de telefono: " << aux->numeroTelefono <<endl;
		cout << "Sintomas: " << aux->sintomas <<endl;
		cout << "Fecha de ingreso: " << aux->fechaIngreso <<endl;
		cout << "*****************************"<<endl;
		aux=aux->siguiente;
		string nombrePaciente;
   		int cedula;
   		int numeroTelefono;
   		string sintomas;
   		string fechaIngreso;
		}
	}
}
void MostrarCitas(listaC cabeza)
{
	listaC aux;
	
	if(cabeza==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=cabeza;
		while(aux!=NULL)
		{	
		cout << "Nombre Paciente: " << aux->nombrePaciente <<endl;
		cout << "Nombre Doctor: " << aux->nombreDoctor <<endl;
		cout << "Sintomas: " << aux->sintoma <<endl;
		cout << "Especialidad: " << aux->especialidad <<endl;
		cout << "Fecha de ingreso: " << endl;
		cout << "Mes: " << aux->mes <<endl;
		cout << "Dia: " << aux->dia <<endl;
		cout << "Ano: " << aux->ano <<endl;
		cout << "*****************************"<<endl;
		aux=aux->siguiente;
		string nombrePaciente;
		string nombreDoctor;
   		string sintomas;
   		string especialidad;
   		string mes;
   		string dia;
   		string ano;
		}
	}
}
	
int main() 
{
	//se inician las listas
	listaCuentas list = NULL;
	listaC citas = NULL;
	lista cuentas =NULL;
	listaD doctores = NULL;
	listaP pacientes = NULL;
	
	// variables citas
	string nombrePaciente;
	string nombreDoctor;
	 int mes;
	 int dia;
	 int ano;
	
	//variables para el sistema
	string nombre;
	int codigo;
	char tipoUsuario;
	string cuentaUsuario;
	string contra;
	string estado;
	string cuenta;
	string nombreDoc;
	string especialidad;
	string nombress;
	string estadoos;
	string sintomas;
	string fecha;
	int cod;
	int cedula;
	int telefono;
	int opcion;
	
	//variables para el inicio de sesion 
	string nombreUs;
	string contraUs;
	bool banderaSwitch;
	bool status;
	bool extra;
	int opc;
	
	
	//ingreso de memoria inicial de la aplicacion
	IngresarFinal(list,"usuario1","12345678","admin","Activo",false);
	IngresarFinal(list,"usuario2","12345678", "usuario","Desactivado",false);
	IngresarFinal(list,"usuario3","12345678","usuario", "Activo",false);
	IngresarFinal(list,"usuario4","12345678","usuario", "Desactivado",false);
	ingresarDoctor(doctores,"Issac", "Urologo",007);
	ingresarDoctor(doctores,"Fabian", "Medico General",005);
	ingresarDoctor(doctores,"Ryan", "Cardiologo",003);
	ingresarCita(citas,"Juan","Isaac","Dolor de cabeza","Urologo",1,1,2022);
	ingresarCita(citas,"Pedro","Fabian","Dolor de cabeza","Medico General",2,1,2022);
	ingresarCita(citas,"Daniela","Ryan","Dolor de cabeza","Cardiologia",1,1,2022);
		
//mensaje de bienvenida para iniciar sesion
do
{
		cout << " Bienvenido" << endl;
		cout << " Por favor escoja el tipo de cuenta que usted tiene" <<endl;
		cout << "Tipo de cuenta" <<endl;
		cout << "1.- Administrador" <<endl;
		cout << "2.- Estandar" <<endl;
		cout << "0.- Salir del sistema"<<endl;
		cin >> opc;
		
	switch (opc){
		
		case 1:
		cout << "Escriba su usuario" << endl;
		cin >> nombreUs;
	//	verificarEstadoCuenta(list,nombre);
		extra = verificarEstadoCuenta(list,nombreUs);
		
		if (extra == true){
		
		cout << "Escriba su contrasena" << endl;
		cin >> contraUs;
		status = verificarPassword(list,nombreUs,contraUs);
		
			if( status == false){
								
			do{		
				cout<<"1.-Crear Usuario"<<endl; 
				cout<<"2.-Eliminar Usuario"<<endl; 
				cout<<"3.-Activar Cuenta"<<endl; 
				cout<<"4.-Desactivar Cuenta"<<endl; 
				cout<<"5.-Realizar Ingreso Doctor"<<endl; 
				cout<<"6.-Eliminar Doctor"<<endl;
				cout<<"7.-Modificar Doctor"<<endl;
				cout<<"8.-Ingreso Paciente"<<endl; 
				cout<<"9.-Eliminar"<<endl; 
				cout<<"10.-Modificar Paciente"<<endl; 
				cout<<"11.-Mostrar Paciente"<<endl;
				cout<<"12.-Mostrar Doctor"<<endl;
				cout<<"13.-Mostrar Citas"<<endl;
				cout<<"14.-Mostrar citas por Mes"<<endl;
				cout<<"15.- Mostrar cantidad pacientes atendidos por especialidad"<<endl;
				cout<<"16.- Mostar cantidad de pacientes atendidos por Doctor"<<endl;
				cout<<"17.- Buscar doctores por especialidad"<<endl;
				cout<<"18.- Buscar doctores por clinica"<<endl;
				cout<<"19.- Verificar Cita"<<endl;
				cout<<"0.- Salir"<<endl;
				cin>> opcion;
				switch(opcion)
					{
					case 1:
							
							cout << "Digite el nombre" << endl;
							cin >> nombre;
							
							cout << "Digite el codigo" << endl;
							cin >> codigo;
							
							cout << "Digite el tipo de usuario" << endl;
							cin >> tipoUsuario;
							
							cout << "Digite la cuenta del usuario" << endl;
							cin >> cuentaUsuario;
							
							cout << "Digite la contraseña" << endl;
							cin >> contra;
							
							estado = "activa"; 
							
							ingresarFinal(cuentas, nombre, codigo, tipoUsuario, cuentaUsuario, contra, estado);
							break;
							
					case 2: 
						 	cout << "Digite la cuenta que desea eliminar" << endl;
						 	cin >> cuenta;
						 	Eliminar(cuentas, cuenta);
							system("Pause");
							break;
					case 3: 
					
							cout << "Digite la cuenta a activar" <<endl;
							cin>>nombress;
							estadoos = "Activo";
							ModificarEstadoCuenta(list, nombress,estadoos);
							cout << "Cuenta ha sido Activada"<<endl;
							break;
							
					case 4: 
							cout << "Digite la cuenta a Desactivar" <<endl;
							cin>>nombress;
							estadoos = "Desactivado";
							ModificarEstadoCuenta(list,nombress,estadoos);
							cout << "Cuenta ha sido desactivada"<<endl;
							break;
					case 5:
							cout << "Digite el nombre del doctor" << endl;
							cin >> nombreDoc;
							
							cout << "Digite la especialidad" << endl;
							cin >> especialidad;
							
							codigo = rand();
							ingresarDoctor(doctores, nombreDoc, especialidad, codigo);
							system("Pause");
							break;
				
					case 6:
							cout << "Digite el doctor que desea eliminar" << endl;
						 	cin >> cod;
							EliminarDoctor(doctores, cod);
							system("Pause");
							break;
					
					case 7:
							cout << "Digite el doctor que desea modificar" << endl;
						 	cin >> cod;
						 	//no esta modificando
							ModificarInfoDoctor(doctores, cod);
							system("Pause");
							break;
					
					case 8:
							cout << "Digite el nombre" << endl;
							cin >> nombre;
							
							cout << "Digite la cedula" << endl;
							cin >> cedula;
							
							cout << "Digite el numero de telefono" << endl;
							cin >> telefono;
							
							cout << "Digite los sintomas" << endl;
							cin >> sintomas;
							
							cout << "Digite la fecha de ingreso" << endl;
							cin >> fecha;
						
							ingresarPaciente(pacientes, nombre, cedula, telefono, sintomas, fecha);
							system("Pause");
							break;
							
					case 9:
							cout << "Digite la cedula del paciente" << endl;
							cin >> cedula;
							EliminarPaciente(pacientes, cedula);
							system("Pause");
							break;
					
					case 10:
							cout << "Digite la cedula del paciente" << endl;
							cin >> cedula;
							//no esta modificando
							ModificarInfoPaciente(pacientes, cedula);
							system("Pause");
							break;
					
					case 11:
							MostrarPacientes(pacientes);
							system("Pause");
							break;
					
					case 12:
							MostrarDoctores(doctores);
							system("Pause");
							break;
					
					case 13:
						MostrarCitas(citas);
							system("Pause");
							break;
							
					case 14:
							cout << "Digite el mes" << endl;
							cin >> mes;
							MostrarCitasporMes(citas, mes);
							system("Pause");
							break;
					case 15:
							cout << "Digite la especialidad" << endl;
							cin >> especialidad;
							MostrarPacientesEspecialidad(citas, especialidad);
							system("Pause");
							break;
					case 16:
							cout << "Digite el nombre del Doctor" << endl;
							cin >> nombreDoctor;
							MostrarPacientesDoctor(citas, nombreDoctor);
							system("Pause");
							break;	
							
					case 17:
							cout << "Digite la especialidad del Doctor" << endl;
							cin >> especialidad;
							MostrarDoctoresEspecialidad(doctores, especialidad);
							system("Pause");
							break;	
					case 18:
							MostrarDoctoresClinica(doctores);
							system("Pause");
							break;	
					case 19:
							cout << "Digite el mes de la cita" << endl;
							cin >> mes;
							cout << "Digite el dia de la cita" << endl;
							cin >> dia;
							verificarCita(citas, mes,dia);
							system("Pause");
							break;				
					}
				}
			while(opcion!=0);
		}
			
			
			else{//else del menu 
				cout<<"Menu bloqueado"<<endl;
			}
		}
		else {
			cout<<" --------- " <<endl;
		}	
	
		break;
		
		case 2: 
		cout << "Escriba su usuario" << endl;
		cin >> nombreUs;
	//	verificarEstadoCuenta(list,nombre);
		extra = verificarEstadoCuenta(list,nombreUs);
		
		if (extra == true){
		
		cout << "Escriba su contrasena" << endl;
		cin >> contraUs;
		status = verificarPassword(list,nombreUs,contraUs);
		
			if( status == false){
				
		do{
			cout<<" "<<endl; 
			cout<<"1.-Realizar Ingreso Doctor"<<endl; 
			cout<<"2.-Eliminar Doctor"<<endl; 
			cout<<"3.-Ingreso Paciente"<<endl; 
			cout<<"4.-Eliminar Paciente"<<endl; 
			cout<<"5.-Modificar Paciente"<<endl; 
			cout<<"6.-Mostrar Paciente"<<endl;
			cout<<"7.-Mostrar Doctor"<<endl;
			cout<<"8. Ingresar citas" << endl;
			cout<<"9.-Mostrar Citas"<<endl;
			cout<<"10.- Mostrar Citas por Mes"<<endl;
			cout<<"11.- Mostrar cantidad pacientes atendidos por especialidad"<<endl;
			cout<<"12.- Mostar cantidad de pacientes atendidos por Doctor"<<endl;
			cout<<"13.- Buscar doctores por especialidad"<<endl;
			cout<<"14.- Buscar doctores por clinica"<<endl;
			cout<<"15.- Verificar Cita"<<endl;
			cout<<"0.- Salir"<<endl;
			cin>> opcion;
			
			switch (opcion){
				
				
				case 1:
						cout << "Digite el nombre del doctor" << endl;
						cin >> nombreDoc;
						
						cout << "Digite la especialidad" << endl;
						cin >> especialidad;
						
						codigo = rand();
						ingresarDoctor(doctores, nombreDoc, especialidad, codigo);
						system("Pause");
						break;
			
				case 2:
						cout << "Digite el doctor que desea eliminar" << endl;
					 	cin >> cod;
						EliminarDoctor(doctores, cod);
						system("Pause");
						break;
				
				case 3:
						cout << "Digite el nombre" << endl;
						cin >> nombre;
						
						cout << "Digite la cedula" << endl;
						cin >> cedula;
						
						cout << "Digite el numero de telefono" << endl;
						cin >> telefono;
						
						cout << "Digite los sintomas" << endl;
						cin >> sintomas;
						
						cout << "Digite la fecha de ingreso" << endl;
						cin >> fecha;
					
						ingresarPaciente(pacientes, nombre, cedula, telefono, sintomas, fecha);
						system("Pause");
						break;
						
				case 4:
						cout << "Digite la cedula del paciente" << endl;
						cin >> cedula;
						EliminarPaciente(pacientes, cedula);
						system("Pause");
						break;
				
				case 5:
						cout << "Digite la cedula del paciente" << endl;
						cin >> cedula;
						//no esta modificando
						ModificarInfoPaciente(pacientes, cedula);
						system("Pause");
						break;
				
				case 6:
						MostrarPacientes(pacientes);
						system("Pause");
						break;
				
				case 7:
						MostrarDoctores(doctores);
						system("Pause");
						break;
				case 8:
						cout << "Digite el nombre del paciente" << endl;
						cin >> nombrePaciente;
							cout << "Digite el nombre del doctor" << endl;
						cin >> nombreDoctor;
						
						cout << "Digite los sintomas" << endl;
						cin >> sintomas;
						
						cout << "Digite la especialidad deseada" << endl;
						cin >> especialidad;
						
						cout << "Digite el mes" << endl;
						cin >> mes;
						
						cout << "Digite el dia" << endl;
						cin >> dia;
						cout << "Digite el ano" << endl;
						cin >> ano;
					
						ingresarCita(citas,nombrePaciente, nombreDoctor, sintomas, especialidad, mes, dia,ano);
						system("Pause");
						break;
				
				case 9:
					MostrarCitas(citas);
						system("Pause");
						break;
				
				case 10:
						cout << "Digite el mes" << endl;
						cin >> mes;
						MostrarCitasporMes(citas, mes);
						system("Pause");
						break;
				case 11:
						cout << "Digite la especialidad" << endl;
						cin >> especialidad;
						MostrarPacientesEspecialidad(citas, especialidad);
						system("Pause");
						break;
				case 12:
						cout << "Digite el nombre del Doctor" << endl;
						cin >> nombreDoctor;
						MostrarPacientesDoctor(citas, nombreDoctor);
						system("Pause");
						break;
				case 13:
						cout << "Digite la especialidad del Doctor" << endl;
						cin >> especialidad;
						MostrarDoctoresEspecialidad(doctores, especialidad);
						system("Pause");
						break;
				case 14:
						MostrarDoctoresClinica(doctores);
						system("Pause");
						break;
				case 15:
						cout << "Digite el mes de la cita" << endl;
						cin >> mes;
						cout << "Digite el dia de la cita" << endl;
						cin >> dia;
						verificarCita(citas, mes,dia);
						system("Pause");
						break;	
				}
				
			}
			while(opcion!=0);
	}
			
			
			else{
				cout<<"Menu bloqueado"<<endl;
			}
		}
		else{
			cout<<" ----------- " <<endl;
		}
		break;
		
		}
	}while(opc!=0);
}
	
