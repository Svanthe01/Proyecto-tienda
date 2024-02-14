#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<string>
#include<sstream>
#include<cstdlib>
#include<stdlib.h>
#include"Producto.cpp"
using namespace std;

class Inventario{	
	private:
		static vector<Producto> vec;
	public:				
		static void agregarProducto(){
			system("cls");
			string nom;
			string id;
			string cat;
			int pre;
			int can;
			
			cout<<"Nombre:  ";
			cin.ignore();
			getline(cin, nom);//Validar logitud de la cadena
			cout<<"ID:  ";
			cin>>id;
			cout<<"Categoria/s:  ";
			cin>>cat;
			cout<<"Precio:  ";
			cin>>pre;
			cout<<"Cantidad:  ";
			cin>>can;
			Producto ob1;
			ob1.setNombre(nom);
			ob1.setId(id);
			ob1.setCategoria(cat);
			ob1.setPrecio(pre);
			ob1.setCantidad(can);
						
			vec.push_back(ob1);
			
			cout<<"Producto registrado :)\n";
			system("pause");
		}
		static void eliminarProducto(){
			bool aux = true;
			string id;
			system("cls");
			cout<<"Ingrese el ID del producto a eliminar:  ";
			cin>>id;
			
			for(int i = 0; i < vec.size(); i++){
				if(vec[i].getId() == id){
					aux = false;
					cout<<"Producto '"<<vec[i].getNombre()<<"' eliminado :)\n";					
					vec.erase(vec.begin() + i);
					break;
				}
			}			
			if(aux == true){
				cout<<"Producto no encontrado X_X\n";
			}
			system("pause");
		}
		static void consultaId(){
			bool aux = false;			
			system("cls");
			string id;
			cout<<"Ingrese el ID del producto a buscar:  ";
			cin>>id;
			
			for(int i = 0; i < vec.size(); i++){
				if(vec[i].getId() == id){
					aux = true;
					cout<<"-----Informacion del producto-----\n";
					vec[i].mostrarDatos();				
					break;
				}
			}
			if(aux == false){
				cout<<"Producto no encontrado X_X\n";
			}
			system("pause");
		}
		static void modificarProducto(){
			bool aux = true;						
			string id;
			system("cls");
			cout<<"Ingrese el ID del producto a modificar:  ";
			cin>>id;
			
			for(int i = 0; i < vec.size(); i++){
				if(vec[i].getId() == id){
					aux = false;
					int op;
					cout<<"Producto '"<<vec[i].getNombre()<<"' encontrado\n";
					cout<<"Seleccione el valor a modificar...\n";
					cout<<"[1] Nombre\n";
					cout<<"[2] ID\n";
					cout<<"[3] Categoria/s\n";
					cout<<"[4] Precio\n";
					cout<<"[5] Cantidad\n";
					cin>>op;
					
					switch(op){
						case 1:{
							
							string nuevoNom;
							cout<<"Ingrese el nuevo nombre:  ";
							cin.ignore();
							getline(cin, nuevoNom);
							
							vec[i].setNombre(nuevoNom);		
							cout<<"\nProducto modificado :)\n";					
							break;
						}
						case 2:{
							
							string nuevoId;
							cout<<"Ingrese el nuevo ID:  ";
							cin>>nuevoId;							
							
							vec[i].setId(nuevoId);
							cout<<"\nProducto modificado :)\n";
							break;
						}
						case 3:{
							
							string nuevaCat;
							cout<<"Ingrese la nueva categoria:  ";
							cin>>nuevaCat;							
							
							vec[i].setCategoria(nuevaCat);
							cout<<"\nProducto modificado :)\n";
							break;
						}
						case 4:{
							
							int nuevoPre;
							cout<<"Ingrese el nuevo precio:  ";
							cin>>nuevoPre;							
							
							vec[i].setPrecio(nuevoPre);
							cout<<"\nProducto modificado :)\n";
							break;
						}
						case 5:{
							
							int nuevaCan;
							cout<<"Ingrese el stock a sumar:  ";
							cin>>nuevaCan;														
							
							vec[i].setCantidad(vec[i].getCantidad() + nuevaCan);
							cout<<"\nStock actualizado: "<<vec[i].getCantidad();
							cout<<"\nProducto modificado :)\n";
							break;
						}
						default:
							cout<<"Opcion fuera de rango X_X\n";
					}										
					break;
				}
			}				
			if(aux == true){
				cout<<"Producto no encontrado X_X\n";
			}
			system("pause");
		}
		static void mostrar(){
			system("cls");
			cout<<"~~~~~~ Objetos ~~~~~~\n";
			for(int i = 0; i < vec.size(); i++){
				vec[i].mostrarDatos();						
			}	
			system("pause");
		}
		static void abrir(){			
			string archivo="Almacen.txt";		    
		    string linea;
		    ifstream entrada(archivo);
		    
		    if(!entrada.is_open()) {//ta mal :(
		    	system("cls");
		        cout<<"Error al abrir el archivo - '"<< archivo <<"' X_X\n";
		        cout<<"Inventario vacio\n";
		        system("pause");
		    }else{//ta bien :)
		    	while (getline(entrada, linea)){			    	
					vector<string> resultado;
					char delim = ' ';		        		        													
				    istringstream isstream(linea);
				    string palabra;
				
				    while(std::getline(isstream, palabra, delim)){
				        resultado.push_back(palabra);
				    }		
				    
					Producto ob;
					ob.setNombre(resultado[0]);
					ob.setCategoria(resultado[1]);
					ob.setId(resultado[2]);
					ob.setPrecio(atoi(resultado[3].c_str()));
					ob.setCantidad(atoi(resultado[4].c_str()));
					vec.push_back(ob);
		    	}
			}
			entrada.close();
		}
		static void escribir(){
			ofstream archivo;
			archivo.open("Almacen.txt", ios::out);
			
			if(archivo.fail()){
				system("cls");
				cout<<"Ha ocurrido un error al crear el archivo de inventario X_X\n";
				system("pause");
				exit(1);
			}
			
			for(int i = 0; i < vec.size(); i++){
				archivo<<vec[i].getNombre()<<" "<<vec[i].getCategoria()<<" "
				<<vec[i].getId()<<" "<<vec[i].getPrecio()<<" "<<vec[i].getCantidad();
				archivo<<"\n";
			}			
			archivo.close();
		}
		static Producto consultaCarrito(string id){			
			Producto prod;
			for(int i = 0; i < vec.size(); i++){
				if(vec[i].getId() == id){					
					prod = vec[i];				
					break;
				}
			}			
			return prod;//validar que no llegue nulo
		}
		static void consultaUsuario(string categ){						
			for(int i = 0; i < vec.size(); i++){
				size_t found = vec[i].getCategoria().find(categ);
			    if (found != string::npos){
			        cout<<"["<<vec[i].getId()<<"] "<<vec[i].getNombre()<<" $"<<vec[i].getPrecio()<<"\n";
				}
			}				
			//system("pause") estatra en el main
		}
		static void restarStock(string id, int cant){
			for(int i = 0; i < vec.size(); i++){
				if(vec[i].getId() == id){
					vec[i].setCantidad(vec[i].getCantidad() - cant);					
					break;
				}
			}
		}
};
//inicializa el inventario
vector<Producto> Inventario::vec = {};