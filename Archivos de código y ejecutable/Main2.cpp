#include<iostream>
#include<algorithm>
#include<string>
#include"Carrito.cpp"
using namespace std;

void admin();
void usuario();

int main(){
	Inventario::abrir();
	int opc;
	int clave;
	
	do{				
		system("cls");
		cout<<"Bienvenido a PiicsaGift\n";
		cout<<"Es usted cliente o administrador?\n";
		cout<<"[1] Cliente\n";
		cout<<"[2] Administrador\n";
		cout<<"[3] Salir\n";
		cin>>opc;	
		
		if(opc == 1){
			usuario();//Se ejecuta el sistema del usuario
		}else if(opc == 2){
			system("cls");
			cout<<"Ingrese la clave de acceso\n";
			cout<<"(teclee 0 para regresar)\n";
			cin>>clave;
			
			if(clave == 1984){
				admin();//Se ejecuta el sistema del administrador
			}else if(clave == 0){
				opc = 5;//para que se vuelva a repetir el bucle
			}else{	
				system("cls");
				cout<<"Clave de acceso invalida\n";
				cout<<"Acceso denegado :(\n";
				system("pause");				
				opc = 5;//para que se vuelva a repetir el bucle
			}
		}else if(opc == 3){
			break;
		}else{			
			cout<<"Opcion fuera de rando X_X\n";
			system("pause");			
		}
	}while((opc != 1) || (opc != 2));//while opc!=3 queda mejor
	Inventario::escribir();
	return 0;
};

void admin(){	
	int opc;
	
	do{
		system("cls");
		cout<<"Usted ha ingresado como administrador\n";	
		cout<<"Teclee la opcion deseada...\n";	
		cout<<"[1] Dar de alta producto\n";	
		cout<<"[2] Modificar producto\n";	
		cout<<"[3] Dar de baja producto\n";	
		cout<<"[4] Consulta individual por ID\n";	
		cout<<"[5] Consulta general\n";	
		cout<<"[6] Salir\n";	
		cin>>opc;
		
		switch(opc){
			case 1:
				Inventario::agregarProducto();				
				break;
			case 2:
				Inventario::modificarProducto();
				break;
			case 3:
				Inventario::eliminarProducto();
				break;
			case 4:				
				Inventario::consultaId();
				break;
			case 5:
				Inventario::mostrar();				
				break;
			case 6:
				break;
			default:
				cout<<"Opcion fuera de rango X_X\n";
				system("pause");
		}
		
	}while(opc != 6);		
}
void usuario(){	
	int opc = 0;
	Carrito::setCliente();
	do{
		system("cls");
		cout<<"Existe un regalo para todo, para buscar el suyo\n";
		cout<<"ingrese el evento, fecha o tipo de persona correspondiente:\n";
		cout<<"[1] Dia de la madre    [6] 14 de febrero\n";
		cout<<"[2] Dia del padre      [7] Dia del maestro\n";
		cout<<"[3] Dia del nin~o      [8] Regalos comunes\n";
		cout<<"[4] Navidad            [9] Hombre\n";
		cout<<"[5] Baby shower        [10] Mujer\n\n";	
		cout<<"[11] Ir al carrito de compra\n";	
		cin>>opc;
		
		if(opc > 0 && opc < 11){
			system("cls");
			int op = 0;
			int cant = 0;
			cout<<"Ingrese el id del producto que\n";
			cout<<"desee agregar al carrito\n";
			cout<<"(teclee 0 para regresar)\n";
			cout<<"~~~~~ Productos recomendados ~~~~~\n";
			Inventario::consultaUsuario(to_string(opc));//se buscan los productos que coincidan con la cat.					
			cin>>op;
			if(op != 0){
				int op2;
				cout<<"Ingrese la cantidad de producto: ";
				cin>>cant;
				Carrito::agregarProducto(to_string(op), cant);//se busca el producto
				//encuentre o no el registro no hay pedo
				cout<<"Desea seguir comprando?\n";
				cout<<"[1] Si\n";
				cout<<"[2] No, finalizar compra\n";
				cin>>op2;
				if(op2 == 1){
					op = 0;//se vuelve a inicializar la variable
					//no pasa nada
				}else if(op2 == 2){//se muestra contenido del carrito
					int op3 = 4;
					do{
						Carrito::mostrarLista();					
						cout<<"Desea proceder con el pago?\n";
						cout<<"[1] Si\n";
						cout<<"[2] No, seguir comprando\n";					
						cout<<"[3] Quitar un producto del carrito\n";					
						cin>>op3;
						
						if(op3 == 1){
							system("cls");
							Carrito::generarTicket();
							cout<<"Su ticket ha sido generado\n";
							cout<<"Gracias por su compra, hasta luego :)\n";
							system("pause");
							opc = 11;
							break;
						}else if(op3 == 2){
							break;
						}else if(op3 == 3){
							Carrito::quitarProducto();
							op3 = 4;//para que se vuelva a mostrar
						}else{
							op3 = 4;//para que se vuelva a mostrar
							cout<<"Opcion fuera de rango X_X\n";
							system("pause");
						}
					}while(op3 > 3);					
					
				}else{
					cout<<"Opcion fuera de rango X_X\n";
					system("pause");
				}
			}									
		}else if( opc == 11){
			int op4 = 4;
			do{
				Carrito::mostrarLista();					
				cout<<"Desea proceder con el pago?\n";
				cout<<"[1] Si\n";
				cout<<"[2] No, seguir comprando\n";					
				cout<<"[3] Quitar un producto del carrito\n";					
				cin>>op4;
						
				if(op4 == 1){
					system("cls");
					Carrito::generarTicket();
					cout<<"Su ticket ha sido generado\n";
					cout<<"Gracias por su compra, hasta luego :)\n";
					system("pause");					
					break;
				}else if(op4 == 2){
					opc = 2;//para que se vuelva a mostrar el menu de inicio
					break;
				}else if(op4 == 3){
					Carrito::quitarProducto();
					op4 = 4;//para que se vuelva a mostrar
				}else{
					op4 = 4;//para que se vuelva a mostrar
					cout<<"Opcion fuera de rango X_X\n";
					system("pause");
				}
			}while(op4 > 3);			
		}else{
			cout<<"Opcion fuera de rango X_X\n";
			system("pause");
		}
	}while(opc != 11);
	
	Carrito::reiniciar();
}
