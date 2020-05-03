/*EJERCICIO #2

Descripción de problema:  Escribir una función Salario que calcule los salarios de un trabajador para un número 
dado de horas trabajadas y un salario hora. Las horas que superen las 40 horas semanales se pagarán como extras 
con un salario hora 1,5 veces el salario ordinario. Así mismo se deberá calcular el monto a pagar de IGSS por 
cada trabajador.   El programa deberá mostrar un menú para:  1) Invocar dicha función y grabar datos a un 
archivo, 2) Adicionalmente deberá tener una opción para leer el archivo y grabar los datos en memoria.
3) Una opción para mostrar cuanto se paga de total de planilla e IGSS. */

#include <fstream>
#include <iostream>
#include <string>
void insertar();
void mp();
void reporte();
using namespace std;
int main(){
	
	mp();
}



void insertar(){
int horalabor,codigo;
float salario,horaextra,opera,horasextras,salariototal,iggs,nuevosueldo,nuevosueldo1;
string nombre;
ofstream db;

cout<<"-----------------------------"<<endl;
cout<<"INGRESO DE DATOS DE EMPLEADOS"<<endl;
cout<<"-----------------------------"<<endl;
cout<<"Ingrese identificacion del Empleado: "<<endl;
cin>>codigo;
fflush(stdin);
cout<<"Ingrese un nombre del empleado y un apellido de la siguiente forma (Jeffrey_Briones): "<<endl;
cin>>nombre;
fflush(stdin);
cout<<"Ingrese su Salario: "<<endl;
cin>>salario;
fflush(stdin);
cout<<"Ingrese cuantas horas laboro el empleado en la semana: "<<endl;
cin>>horalabor;	







if(horalabor>40){
	cout<<"-------------------------------------------------------------"<<endl;
	cout<<"El trabajador registro mas de 40 horas laboradas en la semana"<<endl;
	fflush(stdin);
	cout<<"Ingrese a que cantidad se pagara cada hora extra: "<<endl;
	cin>>horaextra;
	opera = horalabor - 40;
	horasextras = opera * horaextra;
	iggs = salario * 0.0483;
	nuevosueldo = horasextras + (salario - iggs);
}
else{
	salariototal = nuevosueldo;
	opera = 0;
	horasextras = 0;
	iggs = salario * 0.0483;
	nuevosueldo =  salario - iggs;
	
}	
	
	
 try{
 	db.open("Planilla.txt",ios::app);
	db<<codigo<<"\t"<<nombre<<"\t"<<salario<<"\t"<<horalabor<<"\t"<<opera<<"\t"<<horasextras<<"\t"<<iggs<<"\t"<<nuevosueldo<<endl;
	db.close();  
 }
 catch(exception X){
 	cout<<"Error";
 	system("Pause");
 }	
}

void reporte(){
int horalabor,codigo;
float salario,horaextra,opera,horasextras,salariototal,iggs,nuevosueldo,i,final,final2;
string nombre;
ifstream db;	

try{
 	cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"   CODIGO     /"<<"      NOMBRE       /" <<"   SUELDO   /"<<"   HORAS LABORADAS   /"<<"   HORAS EXTRAS   /"<<"   PAGO DE HORAS EXTRAS   /"<<"   DESCUENTO IGGS   /"<<"   TOTAL DEL SUELDO   /"<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl; 	
	db.open("Planilla.txt",ios::in);
	while(db>>codigo>>nombre>>salario>>horalabor>>opera>>horasextras>>iggs>>nuevosueldo){
		cout<<"      "<<codigo<<"\t""\t"<<nombre<<"\t""      ""Q"<<salario<<"\t""\t"<<horalabor<<"\t""\t""\t"<<opera<<"   ""\t""\t""     Q"<<horasextras<<"\t""\t""\t""    Q"<<iggs<<"\t""\t""Q"<<nuevosueldo<<endl;
		
		
		i++;
		final += nuevosueldo;
		final2 += iggs;
	}
	
		
	
	db.close(); 
	cout<<"                                           "<<endl;
	cout<<"-------------------------------------------"<<endl; 
	cout<<"El total a pagar de su planilla es de: Q"<<final<<endl;
	cout<<"-------------------------------------------"<<endl;
	cout<<"El total a pagar de IGGS es de: Q"<<final2<<endl;
	cout<<"-------------------------------------------"<<endl;
 }
 catch(exception X){
 	cout<<"Error";
 	system("Pause");
 }	
	
	
	
	
}	

void mp(){
		int resp;
	//string nombrearchivo;
	//cout<<"Indique nombre de archivo: ";
	//getline(cin,nombrearchivo);
	
	do {
		system("CLS");
		cout<<"-------------------------------"<<"\n";
		cout<<" Menu Principal De La Empresa"<<"\n";
		cout<<"-------------------------------"<<"\n";
		cout<<" 1 - Ingresar Empleados "<<"\n";
		cout<<" 2 - Reporte "<<"\n";
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			insertar();			
		}
		else if (resp==2){		
			system("CLS");
			reporte();
			system("Pause");
	}
		else if (resp==3)
			break;
		else 
			break;
		
	} while(resp!=5);	
}
		
	
	