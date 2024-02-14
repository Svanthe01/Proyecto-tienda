#include<iostream>
using namespace std;

class Producto{
	private:
		string nombre;
		string id;
		string categoria;
		int precio;
		int cantidad;		
	public:
		//Setters
		void setNombre(string nom){
			nombre = nom;			
		}
		void setId(string ide){
			id = ide;			
		}
		void setCategoria(string cat){
			categoria = cat;			
		}
		void setPrecio(int pre){
			precio = pre;			
		}
		void setCantidad(int can){
			cantidad = can;			
		}	
		//Getters	
		string getNombre(){
			return nombre;
		}
		string getId(){
			return id;
		}
		string getCategoria(){
			return categoria;
		}
		int getPrecio(){
			return precio;
		}
		int getCantidad(){
			return cantidad;
		}
		void mostrarDatos(){
			cout<<"Nombre--------: "<<nombre<<"\n";
			cout<<"Id------------: "<<id<<"\n";
			cout<<"Categoria/s---: "<<categoria<<"\n";
			cout<<"Precio--------: $"<<precio<<"\n";
			cout<<"Cantidad------: "<<cantidad<<"pzs. \n\n";
		}
};