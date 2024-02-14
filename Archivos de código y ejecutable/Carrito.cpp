#include<iostream>
#include<vector>
#include<algorithm>
#include"Inventario.cpp"
using namespace std;

class Carrito{
	private:
		static string cliente;
		static vector<Producto> lista;
		static int precioTotal;
	public:
		static void setCliente(){
			system("cls");
			string nom;
			cout<<"Ingrese su nombre de cliente: ";
			cin>>nom;
			cliente = nom;
		}
		static void agregarProducto(string id, int cantidad){//sin cls
			Producto prod;
			prod = Inventario::consultaCarrito(id);
			
			if(prod.getNombre().empty()){
				cout<<"Producto no encontrado X_X\n";
			}else{
				if(prod.getCantidad() < cantidad){//checamos si hay suficiente stock
					cout<<"La cantidad ingresada supera el stock disponible del producto :(\n";
					cout<<"Stock disponible: "<<prod.getCantidad()<<"\n";
				}else{//hay suficiente stock					
					prod.setCantidad(cantidad);//Cantidad de producto en el CARRITO
					lista.push_back(prod);
					sumarPrecio(cantidad, prod.getPrecio());//Se suma el precio al total
					cout<<cantidad<<" pzs. de '"<<prod.getNombre()<<"' agregadas al carrito :)\n";
					cout<<"Total a pagar actual: "<<precioTotal<<"\n";				
				}
			}
			
			//system("pause"); estara en el main
		}
		static void sumarPrecio(int cant, int pre){
			precioTotal += pre*cant;
		}
		static void quitarProducto(){//sin cls
			bool aux = true;
			string id;			
			cout<<"Ingrese el ID del producto a eliminar:  ";
			cin>>id;
			
			for(int i = 0; i < lista.size(); i++){
				if(lista[i].getId() == id){
					aux = false;
					cout<<"Producto '"<<lista[i].getNombre()<<"' eliminado :)\n";					
					quitarPrecio(lista[i].getCantidad(), lista[i].getPrecio());//antes de eliminar se necesita remover del precio total
					lista.erase(lista.begin() + i);	
					cout<<"Total a pagar actual: "<<precioTotal<<"\n";					
					break;
				}
			}			
			if(aux == true){
				cout<<"Producto no encontrado X_X\n";
			}
			system("pause"); 
		}
		static void quitarPrecio(int cant, int pre){
			precioTotal -= pre*cant;
		}
		static void mostrarLista(){
			system("cls");
			cout<<"~~~~~~ Carrito ~~~~~~\n";
			for(int i = 0; i < lista.size(); i++){
				cout<<lista[i].getId()<<" "<<lista[i].getNombre()<<" x"<<lista[i].getCantidad()
				<<"pzs.-----: $"<<lista[i].getPrecio()<<"c/u \n";									
			}	
			cout<<"Total a pagar: "<<precioTotal<<"\n";
			//system("pause"); estara en el main
		}
		static void generarTicket(){
			ofstream archivo;
			archivo.open("Ticket.txt", ios::out);
			
			if(archivo.fail()){
				system("cls");
				cout<<"Ha ocurrido un error al crear el archivo de ticket X_X\n";
				system("pause");
				exit(1);
			}
			archivo<<"Cliente: "<<cliente<<"\n";
			archivo<<"~~~~~ Carrito ~~~~~\n";
			for(int i = 0; i < lista.size(); i++){
				archivo<<"Nombre-----: "<<lista[i].getNombre()<<"\n";				
				archivo<<"Precio-----: $"<<lista[i].getPrecio()<<"\n";
				archivo<<"Cantidad---: "<<lista[i].getCantidad()<<" pzs.\n";
				archivo<<"Total por producto: $"<<(lista[i].getPrecio()*lista[i].getCantidad())<<"\n\n";
				
				Inventario::restarStock(lista[i].getId(), lista[i].getCantidad());//resta stock en el inventario
			}			
			archivo<<"Total a pagar: $"<<precioTotal;
			archivo.close();
		}
		static void reiniciar(){
			lista = {};
			cliente = "";
			precioTotal = 0;
		}
};	
//Se inicializan las variables de la clase
vector<Producto> Carrito::lista = {};
string Carrito::cliente = "";
int Carrito::precioTotal = 0;