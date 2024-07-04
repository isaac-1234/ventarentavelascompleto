#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <string>
#include <iomanip> 
//LIBRERIA PARA JALAR LOS DATOS EN EXCEL

using namespace std;

class Cliente {
public:
    int id;
    string nombre;
    string apellido;
    string telefono;
};

class Producto {
public:
    string nombre;
    string origen;
    double precio;
    int idConsecutivo;
    int disponibilidad;
    string tipoRenta;
};

class Venta {
public:
    int folio;
    Cliente cliente;
    Producto producto;
    int cantidad;
    double precioTotal;
};

vector<Cliente> clientes;
vector<Producto> productos;
vector<Venta> ventas;
int folio = 1;
int proximoIdConsecutivo = 1;

string usuarioAdmin = "isaac";
string contrasenaAdmin = "123";

void InicializarProductos() {
    Producto producto1;
    producto1.nombre = "Juego de 5 cirios/p";
    producto1.origen = "Compra";
    producto1.precio = 1450.00;
    producto1.idConsecutivo = proximoIdConsecutivo++;
    producto1.disponibilidad = 3;
    producto1.tipoRenta = "RENTA";
    productos.push_back(producto1);

    Producto producto2;
    producto2.nombre = "Juego de 10 cirios/p";
    producto2.origen = "Compra";
    producto2.precio = 2800.00;
    producto2.idConsecutivo = proximoIdConsecutivo++;
    producto2.disponibilidad = 3;
    producto2.tipoRenta = "RENTA";
    productos.push_back(producto2);
    
    Producto producto3;
    producto3.nombre = "Juego de 15 cirios/p";
    producto3.origen = "Compra";
    producto3.precio = 4050;
    producto3.idConsecutivo = proximoIdConsecutivo++;
    producto3.disponibilidad = 3;
    producto3.tipoRenta = "RENTA";
    productos.push_back(producto3);

    Producto producto4;
    producto4.nombre = "Juego de 20 cirios/p";
    producto4.origen = "Compra";
    producto4.precio = 5200;
    producto4.idConsecutivo = proximoIdConsecutivo++;
    producto4.disponibilidad = 3;
    producto4.tipoRenta = "RENTA";
    productos.push_back(producto4);

    Producto producto5;
    producto5.nombre = "Juego de 25 cirios/p";
    producto5.origen = "Compra";
    producto5.precio = 6250;
    producto5.idConsecutivo = proximoIdConsecutivo++;
    producto5.disponibilidad = 3;
    producto5.tipoRenta = "RENTA";
    productos.push_back(producto5);

    Producto producto6;
    producto6.nombre = "Juego de 30 cirios/p";
    producto6.origen = "Compra";
    producto6.precio = 7200;
    producto6.idConsecutivo = proximoIdConsecutivo++;
    producto6.disponibilidad = 3;
    producto6.tipoRenta = "RENTA";
    productos.push_back(producto6);

    Producto producto7;
    producto7.nombre = "Juego de 35 cirios/p";
    producto7.origen = "Compra";
    producto7.precio = 8050;
    producto7.idConsecutivo = proximoIdConsecutivo++;
    producto7.disponibilidad = 3;
    producto7.tipoRenta = "RENTA";
    productos.push_back(producto7);

    Producto producto8;
    producto8.nombre = "Juego de 40 cirios/p";
    producto8.origen = "Compra";
    producto8.precio = 8800;
    producto8.idConsecutivo = proximoIdConsecutivo++;
    producto8.disponibilidad = 3;
    producto8.tipoRenta = "RENTA";
    productos.push_back(producto8);

    Producto producto9;
    producto9.nombre = "Juego de 45 cirios/p";
    producto9.origen = "Compra";
    producto9.precio = 9450;
    producto9.idConsecutivo = proximoIdConsecutivo++;
    producto9.disponibilidad = 3;
    producto9.tipoRenta = "RENTA";
    productos.push_back(producto9);

    Producto producto10;
    producto10.nombre = "Vela colgante/G";
    producto10.origen = "WO";
    producto10.precio = 28;
    producto10.idConsecutivo = proximoIdConsecutivo++;
    producto10.disponibilidad = 3;
    producto10.tipoRenta = "RENTA";
    productos.push_back(producto10);

    Producto producto11;
    producto11.nombre = "Vela colgante chica";
    producto11.origen = "WO";
    producto11.precio = 18;
    producto11.idConsecutivo = proximoIdConsecutivo++;
    producto11.disponibilidad = 3;
    producto11.tipoRenta = "RENTA";
    productos.push_back(producto11);

    Producto producto12;
    producto12.nombre = "Vela votivo/G (250ml/8.45oz)";
    producto12.origen = "Stoco";
    producto12.precio = 16;
    producto12.idConsecutivo = proximoIdConsecutivo++;
    producto12.disponibilidad = 3;
    producto12.tipoRenta = "RENTA";
    productos.push_back(producto12);

    Producto producto13;
    producto13.nombre = "Vela votivo/G Rell(250ml/8.45oz)";
    producto13.origen = "WO";
    producto13.precio = 13;
    producto13.idConsecutivo = proximoIdConsecutivo++;
    producto13.disponibilidad = 3;
    producto13.tipoRenta = "RENTA";
    productos.push_back(producto13);

    Producto producto14;
    producto14.nombre = "Vela votivo/ch (142ml/5.0oz)";
    producto14.origen = "Stock";
    producto14.precio = 14;
    producto14.idConsecutivo = proximoIdConsecutivo++;
    producto14.disponibilidad = 3;
    producto14.tipoRenta = "RENTA";
    productos.push_back(producto14);

    Producto producto15;
    producto15.nombre = "Vela votivo/ch Rell (142ml/5.0oz)";
    producto15.origen = "WO";
    producto15.precio = 11;
    producto15.idConsecutivo = proximoIdConsecutivo++;
    producto15.disponibilidad = 3;
    producto15.tipoRenta = "RENTA";
    productos.push_back(producto15);

    Producto producto16;
    producto16.nombre = "Vela votivo/G color (250ml/8.45oz)";
    producto16.origen = "WO";
    producto16.precio = 19;
    producto16.idConsecutivo = proximoIdConsecutivo++;
    producto16.disponibilidad = 3;
    producto16.tipoRenta = "RENTA";
    productos.push_back(producto16);

    Producto producto17;
    producto17.nombre = "Vela votivo/G Rell color (250ml/8.45oz)";
    producto17.origen = "WO";
    producto17.precio = 16;
    producto17.idConsecutivo = proximoIdConsecutivo++;
    producto17.disponibilidad = 3;
    producto17.tipoRenta = "RENTA";
    productos.push_back(producto17);

    Producto producto18;
    producto18.nombre = "Vela votivo/ch color (142ml/5.0oz)";
    producto18.origen = "WO";
    producto18.precio = 17;
    producto18.idConsecutivo = proximoIdConsecutivo++;
    producto18.disponibilidad = 3;
    producto18.tipoRenta = "RENTA";
    productos.push_back(producto18);

    Producto producto19;
    producto19.nombre = "Vela votivo/ch Rell color (142ml/5.0oz)";
    producto19.origen = "WO";
    producto19.precio = 14;
    producto19.idConsecutivo = proximoIdConsecutivo++;
    producto19.disponibilidad = 3;
    producto19.tipoRenta = "RENTA";
    productos.push_back(producto19);

    Producto producto20;
    producto20.nombre = "Cirio de mesa 5x6cm";
    producto20.origen = "WO";
    producto20.precio = 14;
    producto20.idConsecutivo = proximoIdConsecutivo++;
    producto20.disponibilidad = 3;
    producto20.tipoRenta = "RENTA";
    productos.push_back(producto20);

    Producto producto21;
    producto21.nombre = "Cirio de mesa 6.5x6cm";
    producto21.origen = "WO";
    producto21.precio = 20;
    producto21.idConsecutivo = proximoIdConsecutivo++;
    producto21.disponibilidad = 3;
    producto21.tipoRenta = "RENTA";
    productos.push_back(producto21);

    Producto producto22;
    producto22.nombre = "Cirio de mesa 7x6cm";
    producto22.origen = "WO";
    producto22.precio = 30;
    producto22.idConsecutivo = proximoIdConsecutivo++;
    producto22.disponibilidad = 3;
    producto22.tipoRenta = "RENTA";
    productos.push_back(producto22);

    Producto producto23;
    producto23.nombre = "Cirio de mesa 9x6cm";
    producto23.origen = "WO";
    producto23.precio = 25;
    producto23.idConsecutivo = proximoIdConsecutivo++;
    producto23.disponibilidad = 3;
    producto23.tipoRenta = "RENTA";
    productos.push_back(producto23);

    Producto producto24;
    producto24.nombre = "Cirio de mesa 10x6cm";
    producto24.origen = "WO";
    producto24.precio = 30;
    producto24.idConsecutivo = proximoIdConsecutivo++;
    producto24.disponibilidad = 3;
    producto24.tipoRenta = "RENTA";
    productos.push_back(producto24);

    Producto producto25;
    producto25.nombre = "Cirio de mesa 10x10cm";
    producto25.origen = "WO";
    producto25.precio = 35;
    producto25.idConsecutivo = proximoIdConsecutivo++;
    producto25.disponibilidad = 3;
    producto25.tipoRenta = "RENTA";
    productos.push_back(producto25);
    
    

    
    //Jalar los datos de una base de datos 
    //(ULR LAptop/ EXCEL =   )
    
}

void ListaClientes() {
	
		cout << "Listado de Clientes:" << endl;
		cout << left << setw(5) << "ID"
		<< setw (40) << "Nombre"
        << setw (20) << "Apellido"
        << setw (15) << "Telefono"<< endl;
        
		for (size_t i = 0; i < clientes.size(); ++i) {
		cout << left << setw(5) << clientes[i].id
		    << setw (40) << clientes[i].nombre
            << setw (20) << clientes[i].apellido
            << setw (15) << clientes[i].telefono << endl;

    }
    cout << "Presione cualquier tecla para continuar." << endl;
    cin.get();
    cin.get();

}

void AgregarCliente() {
    Cliente nuevoCliente;
    cout << "Nombre: ";
    cin >> nuevoCliente.nombre;
    cout << "Apellido: ";
    cin >> nuevoCliente.apellido;
    cout << "Telefono: ";
    cin >> nuevoCliente.telefono;
    nuevoCliente.id = folio++;
    clientes.push_back(nuevoCliente);
    cout << "Cliente agregado exitosamente." << endl;
    cout << "Presione cualquier tecla para continuar." << endl;
    cin.get();
    cin.get();
}

void GestionarClientes() {
    cout << "Gestion de Clientes:" << endl;
    cout << "1. Lista Clientes" << endl;
    cout << "2. Agregar Cliente" << endl;
    cout << "Seleccione una opcion: ";
    int opcion;
    cin >> opcion;
    switch (opcion) {
        case 1:
            ListaClientes();
            break;
        case 2:
            AgregarCliente();
            break;
        default:
            cout << "Opcion no valida." << endl;
            break;
    }
}

void ListarProductos() {
	cout << "Listado de Productos:" << endl;
    cout << left << setw(7) << "ID"
         << setw(40) << "Nombre"
         << setw(20) << "Origen"
         << setw(10) << "Precio"
         << setw(15) << "Disponibilidad"
         << setw(10) << "Tipo Renta" << endl;

    for (size_t i = 0; i < productos.size(); ++i) {
        cout << left << setw(7) << productos[i].idConsecutivo
             << setw(40) << productos[i].nombre
             << setw(20) << productos[i].origen
             << setw(10) << productos[i].precio
             << setw(15) << productos[i].disponibilidad
             << setw(10) << productos[i].tipoRenta << endl;

    }
    cout << "Presione cualquier tecla para continuar." << endl;
    cin.get();
    cin.get();
}

void AgregarProducto() {
    Producto nuevoProducto;
    cout << "Nombre: ";
    cin >> nuevoProducto.nombre;
    cout << "Origen: ";
    cin >> nuevoProducto.origen;
    cout << "Precio: ";
    cin >> nuevoProducto.precio;
    cout << "Disponibilidad: ";
    cin >> nuevoProducto.disponibilidad;
    cout << "Tipo Renta: ";
    cin >> nuevoProducto.tipoRenta;
    nuevoProducto.idConsecutivo = proximoIdConsecutivo++;
    productos.push_back(nuevoProducto);
    cout << "Producto agregado exitosamente." << endl;
    cout << "Presione cualquier tecla para continuar." << endl;
    cin.get();
    cin.get();
}

void GestionarProductos() {
    cout << "Gestion de Productos:" << endl;
    cout << "1. Listar Productos" << endl;
    cout << "2. Agregar Producto" << endl;
    cout << "Seleccione una opcion: ";
    int opcion;
    cin >> opcion;
    switch (opcion) {
        case 1:
            ListarProductos();
            break;
        case 2:
            AgregarProducto();
            break;
        default:
            cout << "Opcion no valida." << endl;
            break;
    }
}

void MostrarPedido() {
    cout << "Funcionalidad de realizar un pedido no implementada." << endl;
    cout << "Presione cualquier tecla para continuar." << endl;
    cin.get();
    cin.get();
}

void MostrarVentas() {
    cout << "Listado de Ventas:" << endl;
    cout << "ID   Cliente             Producto                           Cantidad   Precio Total" << endl;
    for (size_t i = 0; i < ventas.size(); ++i) {
        cout << ventas[i].folio << "    " << ventas[i].cliente.nombre << " " << ventas[i].cliente.apellido << "       " << ventas[i].producto.nombre << "     " << ventas[i].cantidad << "     " << ventas[i].precioTotal << endl;
    }
    cout << "Presione cualquier tecla para continuar." << endl;
    cin.get();
    cin.get();
}

void MostrarMenuPrincipal() {
    // Obtener el tamaño de la consola
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int anchoConsola;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    anchoConsola = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    // El texto principal del menú
    const char* menuTitle = "__________Menu:_________";
    int titleLength = strlen(menuTitle);
    
    // Calcular el espacio de relleno para centrar el título del menú
    int padding = (anchoConsola - titleLength) / 2;
    string paddingSpaces = string(padding, ' ');

    // Imprimir el título del menú centrado
    cout << paddingSpaces << menuTitle << endl;

    // Imprimir las opciones del menú con el mismo padding para alinear a la izquierda
    cout << paddingSpaces << "1. Clientes" << endl;
    cout << paddingSpaces << "2. Productos" << endl;
    cout << paddingSpaces << "3. Realizar Pedido" << endl;
    cout << paddingSpaces << "4. Ventas" << endl;
    cout << paddingSpaces << "5. Salir" << endl;
    cout << paddingSpaces << "Seleccione una opcion, por favor: ";
}

int main() {
	
	
    InicializarProductos();

    bool autenticado = false;

    while (!autenticado) {
        cout << "Por favor, inicie sesion." << endl;
        cout << "Usuario: ";
        string usuario;
        cin >> usuario;
        cout << "Contrasena: ";
        string contrasena;
        cin >> contrasena;

        if (usuario == usuarioAdmin && contrasena == contrasenaAdmin) {
            autenticado = true;
            cout << "Inicio de sesion exitoso." << endl;
            cout << "Presione cualquier tecla para continuar." << endl;
            cin.get();
            cin.get();
        } else {
            cout << "Usuario o contrasena incorrectos. Intente nuevamente." << endl;
            cout << "Datos incorrectos, vuelva a intentarlo" << endl;
            cin.get();
            cin.get();
        }

        cout << " INICIO DE SECION ACTIVADA "; // Limpiar pantalla
    }

    bool salir = false;

    while (!salir) {
        MostrarMenuPrincipal();

        char opcion;
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case '1':
                GestionarClientes();
                break;
            case '2':
                GestionarProductos();
                break;
            case '3':
                MostrarPedido();
                break;
            case '4':
                MostrarVentas();
                break;
            case '5':
                salir = true;
                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
    }

    return 0;
}

