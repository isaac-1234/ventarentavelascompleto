#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Cliente {
public:
    int id;
    string nombre;
    string apellido;
    string domicilio;
    string municipio;
    string estado;
    string telefono;
    string RFC;
    string tipo;
};

class Producto {
public:
    string nombre;
    string origen;
    double precio;
    int disponibilidad;
    string tipo;
    int idConsecutivo;
    int cantidad;
    double precioUnitario; // Añadido para cotización
};

class Venta {
public:
    int folio;
    Cliente cliente;
    Producto producto;
    int cantidad;
    double precioTotal;
    string fecha;
    string tiempo_entrega;
    string RFC;
    int id_pedido;
};

class Pedido {
public:
    int id;
    string fecha;
    string nombreApellido;
    string nombrePedidoCliente;
    string estatus;
    int cantidad;
    string nombreProducto;
    double precio;
    double monto;
    double total;
};

vector<Pedido> pedidos; // Variable global para almacenar pedidos

void ListarPedidos() {
    ifstream archivo("PEDIDOS.txt");
    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();
}

void GuardarPedidoEnArchivo(const Pedido& pedido) {
    ofstream archivo("PEDIDOS.txt", ios::app);
    archivo << pedido.id << " | " << pedido.fecha << " | " << pedido.nombreApellido 
            << " | " << pedido.nombrePedidoCliente << " | " << pedido.estatus 
            << " | " << pedido.cantidad << " | " << pedido.nombreProducto 
            << " | " << pedido.precio << " | " << pedido.monto << " | " << pedido.total << endl;
    archivo.close();
}

void LevantarPedido() {
    Pedido nuevoPedido;
    char agregarOtroProducto;

    cout << "Ingrese la fecha: ";
    cin >> nuevoPedido.fecha;
    cout << "Ingrese el nombre y apellido: ";
    cin.ignore();
    getline(cin, nuevoPedido.nombreApellido);
    cout << "Ingrese el nombre del pedido cliente: ";
    getline(cin, nuevoPedido.nombrePedidoCliente);
    nuevoPedido.estatus = "En Proceso";
    nuevoPedido.total = 0;

    do {
        cout << "Ingrese la cantidad: ";
        cin >> nuevoPedido.cantidad;
        cout << "Ingrese el nombre del producto: ";
        cin.ignore();
        getline(cin, nuevoPedido.nombreProducto);
        cout << "Ingrese el precio: ";
        cin >> nuevoPedido.precio;

        nuevoPedido.monto = nuevoPedido.cantidad * nuevoPedido.precio;
        nuevoPedido.total += nuevoPedido.monto;

        nuevoPedido.id = (pedidos.empty()) ? 1 : pedidos.back().id + 1;
        pedidos.push_back(nuevoPedido);

        GuardarPedidoEnArchivo(nuevoPedido);

        cout << "Producto agregado al pedido exitosamente.\n";
        cout << "Monto actual del pedido: " << nuevoPedido.total << endl;

        cout << "¿Desea agregar otro producto? (s/n): ";
        cin >> agregarOtroProducto;

    } while (agregarOtroProducto == 's' || agregarOtroProducto == 'S');

    cout << "Pedido levantado exitosamente.\n";
    cout << "Monto total del pedido: " << nuevoPedido.total << endl;
}

bool AutenticarUsuario() {
    string usuario, contrasena;
    cout << "Ingrese su usuario: ";
    cin >> usuario;
    cout << "Ingrese su contrasena: ";
    cin >> contrasena;
    return (usuario == "isaac" && contrasena == "123");
}

void EsperarYLimpiarPantalla() {
    cout << "Presione cualquier tecla para continuar...";
    cin.ignore().get(); // Espera hasta que se presione una tecla
    system("cls"); // Para Windows
    // system("clear"); // Para Unix/Linux
}

void MostrarMenuPrincipal();
void MostrarMenuClientes();
void MostrarMenuProductos();
void MostrarMenuPedidos();
void MostrarMenuVentas();
void MostrarMenuCotizacion();

void ListarClientes();
void AgregarCliente();
void ListarProductos();
void AgregarProducto();
void ModificarPedido();
void ListarVentas();
void ModificarVenta();
void generarCotizacion(); // Corregida

int main() {
    if (!AutenticarUsuario()) {
        cout << "Usuario o contrasena incorrecta." << endl;
        return 1;
    }
    EsperarYLimpiarPantalla();
    MostrarMenuPrincipal();
    return 0;
}

void MostrarMenuPrincipal() {
    int opcion;
    do {
        cout << "__________Menu:_________" << endl;
        cout << "1. Clientes" << endl;
        cout << "2. Productos" << endl;
        cout << "3. Pedidos" << endl;
        cout << "4. Ventas" << endl;
        cout << "5. Cotizacion" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion, por favor: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                MostrarMenuClientes();
                break;
            case 2:
                MostrarMenuProductos();
                break;
            case 3:
                MostrarMenuPedidos();
                break;
            case 4:
                MostrarMenuVentas();
                break;
            case 5:
                MostrarMenuCotizacion();
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida, intente nuevamente." << endl;
        }
        EsperarYLimpiarPantalla();
    } while (opcion != 6);
}

void MostrarMenuClientes() {
    int opcion;
    do {
        cout << "__________Menu Clientes:_________" << endl;
        cout << "1. Lista de Clientes" << endl;
        cout << "2. Agregar Cliente" << endl;
        cout << "3. Regresar al menu principal" << endl;
        cout << "Seleccione una opcion, por favor: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                ListarClientes();
                break;
            case 2:
                AgregarCliente();
                break;
            case 3:
                return;
            default:
                cout << "Opcion no valida, intente nuevamente." << endl;
        }
        EsperarYLimpiarPantalla();
    } while (opcion != 3);
}

void MostrarMenuProductos() {
    int opcion;
    do {
        cout << "__________Menu Productos:_________" << endl;
        cout << "1. Lista de Productos" << endl;
        cout << "2. Agregar Producto" << endl;
        cout << "3. Regresar al menu principal" << endl;
        cout << "Seleccione una opcion, por favor: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                ListarProductos();
                break;
            case 2:
                AgregarProducto();
                break;
            case 3:
                return;
            default:
                cout << "Opcion no valida, intente nuevamente." << endl;
        }
        EsperarYLimpiarPantalla();
    } while (opcion != 3);
}

void MostrarMenuPedidos() {
    int opcion;
    do {
        cout << "__________Menu Pedidos:_________" << endl;
        cout << "1. Lista de Pedidos" << endl;
        cout << "2. Levantar Pedido" << endl;
        cout << "3. Modificar Pedido" << endl;
        cout << "4. Regresar al menu principal" << endl;
        cout << "Seleccione una opcion, por favor: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                ListarPedidos();
                break;
            case 2:
                LevantarPedido();
                break;
            case 3:
                ModificarPedido();
                break;
            case 4:
                return;
            default:
                cout << "Opcion no valida, intente nuevamente." << endl;
        }
        EsperarYLimpiarPantalla();
    } while (opcion != 4);
}

void MostrarMenuVentas() {
    int opcion;
    do {
        cout << "__________Menu Ventas:_________" << endl;
        cout << "1. Lista de Ventas" << endl;
        cout << "2. Modificar Venta" << endl;
        cout << "3. Regresar al menu principal" << endl;
        cout << "Seleccione una opcion, por favor: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                ListarVentas();
                break;
            case 2:
                ModificarVenta();
                break;
            case 3:
                return;
            default:
                cout << "Opcion no valida, intente nuevamente." << endl;
        }
        EsperarYLimpiarPantalla();
    } while (opcion != 3);
}

void MostrarMenuCotizacion() {
    int opcion;
    do {
        cout << "Menu principal:" << endl;
        cout << "1. Generar cotizacion" << endl;
        cout << "2. Otra opcion del menú" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                generarCotizacion(); // Llamar a la función para generar la cotización
                break;
            case 2:
                // Otra opción del menú
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }

    } while (opcion != 3);
}

void ListarClientes() {
    ifstream archivo("clientes.txt");
    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();
}

void AgregarCliente() {
    ofstream archivo("clientes.txt", ios::app);
    Cliente nuevoCliente;
    cout << "Ingrese el nombre del cliente: ";
    cin >> nuevoCliente.nombre;
    cout << "Ingrese el apellido del cliente: ";
    cin >> nuevoCliente.apellido;
    cout << "Ingrese el domicilio del cliente: ";
    cin >> nuevoCliente.domicilio;
    cout << "Ingrese el municipio del cliente: ";
    cin >> nuevoCliente.municipio;
    cout << "Ingrese el estado del cliente: ";
    cin >> nuevoCliente.estado;
    cout << "Ingrese el telefono del cliente: ";
    cin >> nuevoCliente.telefono;
    cout << "Ingrese el ID del cliente: ";
    cin >> nuevoCliente.id;
    cout << "Ingrese el RFC del cliente: ";
    cin >> nuevoCliente.RFC;
    cout << "Ingrese el tipo del cliente: ";
    cin >> nuevoCliente.tipo;
    archivo << nuevoCliente.nombre << " | " << nuevoCliente.apellido << " | " 
            << nuevoCliente.domicilio << " | " << nuevoCliente.municipio << " | "
            << nuevoCliente.estado << " | " << nuevoCliente.telefono << " | "
            << nuevoCliente.id << " | " << nuevoCliente.RFC << " | " 
            << nuevoCliente.tipo << endl;
    archivo.close();
}

void ListarProductos() {
    ifstream archivo("productos.txt");
    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();
}

void AgregarProducto() {
    ofstream archivo("productos.txt", ios::app);
    Producto nuevoProducto;
    cout << "Ingrese el nombre del producto: ";
    cin >> nuevoProducto.nombre;
    cout << "Ingrese el origen del producto: ";
    cin >> nuevoProducto.origen;
    cout << "Ingrese el precio del producto: ";
    cin >> nuevoProducto.precio;
    cout << "Ingrese el ID consecutivo del producto: ";
    cin >> nuevoProducto.idConsecutivo;
    cout << "Ingrese la disponibilidad del producto: ";
    cin >> nuevoProducto.disponibilidad;
    cout << "Ingrese el tipo del producto: ";
    cin >> nuevoProducto.tipo;
    archivo << nuevoProducto.nombre << " | " << nuevoProducto.origen << " | " 
            << nuevoProducto.precio << " | " << nuevoProducto.disponibilidad 
            << " | " << nuevoProducto.tipo << endl;
    archivo.close();
}

void ModificarPedido() {
    int id;
    string nuevoEstatus;

    cout << "Ingrese el ID del pedido a modificar: ";
    cin >> id;

    cout << "Ingrese el nuevo estatus del pedido: ";
    cin >> nuevoEstatus;

    for (size_t i = 0; i < pedidos.size(); ++i) {
        if (pedidos[i].id == id) {
            pedidos[i].estatus = nuevoEstatus;
            cout << "Pedido modificado exitosamente.\n";
            return;
        }
    }

    cout << "Pedido no encontrado.\n";
}

void ListarVentas() {
    ifstream archivo("ventas.txt");
    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();
}

void ModificarVenta() {
    // Implementación para modificar el estado de una venta
}

void generarCotizacion() {
    int idCotizacion;
    string nombreApellido;
    string domicilio;
    string municipio;
    string estado;
    string telefono;
    vector<Producto> productos;

    cout << "ID cotizacion: ";
    cin >> idCotizacion;
    cin.ignore(); // Limpiar el buffer de entrada

    cout << "Nombre y Apellido: ";
    getline(cin, nombreApellido);

    cout << "DOMICILIO: ";
    getline(cin, domicilio);

    cout << "MUNICIPIO: ";
    getline(cin, municipio);

    cout << "ESTADO: ";
    getline(cin, estado);

    cout << "TELEFONO: ";
    getline(cin, telefono);

    cout << "(DESCRIPCION)" << endl;
    cout << "//A continuación ponemos a su consideración la cotización de los productos que nos solicitó y quedamos a sus órdenes//" << endl;
    cout << endl;

    char continuar;
    do {
        Producto producto;
        cout << "Producto #" << (productos.size() + 1) << ":" << endl;
        cout << "Nombre del producto: ";
        getline(cin, producto.nombre);

        cout << "Cantidad: ";
        cin >> producto.cantidad;

        cout << "Precio unitario: ";
        cin >> producto.precioUnitario;
        cin.ignore(); // Limpiar el buffer de entrada después de leer el precio

        productos.push_back(producto);

        cout << "Agregar otro producto? (s/n): ";
        cin >> continuar;
        cin.ignore(); // Limpiar el buffer de entrada
    } while (continuar == 's' || continuar == 'S');

    double total = 0.0;
    for (size_t i = 0; i < productos.size(); ++i) {
        const Producto& producto = productos[i];
        double monto = producto.cantidad * producto.precioUnitario;
        total += monto;
    }

    string tiempoEntrega;
    cout << "Tiempo de entrega: ";
    getline(cin, tiempoEntrega);

    ofstream archivo("cotizacion.txt");
    if (archivo.is_open()) {
        archivo << "ID cotizacion: " << idCotizacion << endl;
        archivo << "Nombre y Apellido: " << nombreApellido << endl;
        archivo << "DOMICILIO: " << domicilio << endl;
        archivo << "MUNICIPIO: " << municipio << endl;
        archivo << "ESTADO: " << estado << endl;
        archivo << "TELEFONO: " << telefono << endl;
        archivo << endl;
        archivo << "(DESCRIPCION)" << endl;
        archivo << "//A continuación ponemos a su consideración la cotización de los productos que nos solicitó y quedamos a sus órdenes//" << endl;
        archivo << endl;
        archivo << "------------------------------------------------------------------" << endl;
        archivo << "| Cantidad | Nombre del producto   | Precio unitario | Monto     |" << endl;
        archivo << "------------------------------------------------------------------" << endl;

        for (size_t i = 0; i < productos.size(); ++i) {
            const Producto& producto = productos[i];
            double monto = producto.cantidad * producto.precioUnitario;
            archivo << "| " << setw(9) << producto.cantidad << " | "
                    << setw(21) << producto.nombre << " | "
                    << setw(15) << fixed << setprecision(2) << producto.precioUnitario << " | "
                    << setw(10) << monto << " |" << endl;
        }

        archivo << "----------------------------------------------------------------" << endl;
        archivo << "TOTAL : " << setw(47) << total << endl;
        archivo << endl;
        archivo << "Tiempo de entrega: " << tiempoEntrega << endl;

        cout << "La cotizacion ha sido guardada exitosamente en el archivo 'cotizacion.txt'." << endl;

        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo 'cotizacion.txt' para guardar la cotizacion." << endl;
    }
}
