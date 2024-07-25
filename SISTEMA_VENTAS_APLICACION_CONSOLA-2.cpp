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
    int id;
    string nombre;
    string origen;
    double precio;
    int disponibilidad;
    string tipo;
    int cantidad;
};

class Pedido {
public:
    int id;
    string fecha;
    Cliente cliente;
    string ordenConsecutivaCliente;
    vector<Producto> productos;
    double total;
    string estatusPedido;
    string estatusCobranza;
    string folioFactura;
};

vector<Cliente> clientes;
vector<Producto> productos;
vector<Pedido> pedidos;

void InicializarClientes() {
    // Agregar clientes
    clientes.push_back({1, "Bellaterra Salon de eventos", "       ", "Av.Naciones Unidas 8600", "San Juan de Ocotan", "Jalisco", "3336416380", "RFC123456", "Recurrente"});
    clientes.push_back({2, "Luis ", "Rosete", "Zapopan", "Jalisco", "3313410747", "RFC123457", "Recurrente"});
    clientes.push_back({3, "Michelle Pourroy", "     ", "Zapopan", "Jalisco", "3323437579", "RFC123458", "Recurrente"});
    clientes.push_back({4, "Capilla de Guadalupe", "      ", "Tepatitlan de Morelos", "Jalisco", "3787828033", "RFC123459", "Nuevo"});
    clientes.push_back({5, "Fabiola", "Ruiz Barba", "Guadalajara", "Jalisco", "3311554981", "RFC123460", "Nuevo"});
    clientes.push_back({6, "Michelle ", "Mendez", "Zapopan", "Jalisco", "3331577577", "RFC123461", "Recurrente"});
    clientes.push_back({7, "La Gotera Salon de Eventos", "      ", "Jilgueros 77", "La Venta del Astillero", "Jalisco", "3327898280", "RFC123462", "Recurrente"});
    clientes.push_back({8, "Valeria Navarro", "        ", "Guadalajara", "Jalisco", "3313009393", "RFC123463", "Nuevo"});
    clientes.push_back({9, "La Bendita Espacio Eventos", "Evento", "Circunvalacion del Bosque 2001", "Zapopan", "Jalisco", "3328338832", "RFC123464", "Recurrente"});
    clientes.push_back({10, "Quinta Marina Salon Eventos", "Evento", "Av. Serafin Vazquez E 619", "Cd. Guzman", "Jalisco", "3411123842", "RFC123465", "Recurrente"});
    clientes.push_back({11, "Banana Production", "Production", "Guadalajara", "Jalisco", "3318501281", "RFC123466", "Recurrente"});
    clientes.push_back({12, "Alejandro Duarte", "Lopez", "Zapopan", "Jalisco", "3321595786", "RFC123467", "Recurrente"});
    clientes.push_back({13, "Fraida Valle", "Garcia", "Zapopan", "Jalisco", "3318932335", "RFC123468", "Nuevo"});
    clientes.push_back({14, "Entre Flores", "Flores", "Chihuahua", "Chihuahua", "6141279112", "RFC123469", "Recurrente"});
    clientes.push_back({15, "Naviva", "Eventos", "Carr. Federal 200, Km.19.5", "Punta Mita", "Nayarit", "3292916100", "RFC123470", "Nuevo"});
    clientes.push_back({16, "Andrea Escamilla", "Garcia", "Zapopan", "Jalisco", "3321836603", "RFC123471", "Nuevo"});
    clientes.push_back({17, "Maricruz Elizondo", "Perez", "Los Mochis", "Sinaloa", "3316999403", "RFC123472", "Nuevo"});
    clientes.push_back({18, "Art & Flowers", "Arte", "Zapopan", "Jalisco", "3331798990", "RFC123473", "Nuevo"});
    clientes.push_back({19, "Benavento Salon de Eventos", "Evento", "Lopez Mateos Sur 2550", "Tlajomulco de Zuniga", "Jalisco", "3331885845", "RFC123474", "Recurrente"});
    clientes.push_back({20, "Entre Flores", "Flores", "Cancun", "Quintana Roo", "9983182595", "RFC123475", "Recurrente"});
    clientes.push_back({21, "Benazuza", "Eventos", "Boulevard Kukulcan km 16.5", "Cancun", "Quintana Roo", "9986424573", "RFC123476", "Recurrente"});
    clientes.push_back({22, "Lago del Rey", "Eventos", "Zapopan", "Jalisco", "3331655873", "RFC123477", "Recurrente"});
    clientes.push_back({23, "Tizate Sea Garden", "Jardin", "Camino al Tizate 4", "Cruz de Huanacaxtle", "Nayarit", "3222205348", "RFC123478", "Recurrente"});
    clientes.push_back({24, "Rancho La Razon", "Rancho", "Guadalajara", "Jalisco", "3318432366", "RFC123479", "Recurrente"});
    clientes.push_back({25, "Banquetes La Benazuza", "Banquete", "Administradores 5376", "Zapopan", "Jalisco", "3331650590", "RFC123480", "Recurrente"});
    clientes.push_back({26, "Terrabambino", "     ", "Toscana SN", "Zapopan", "Jalisco", "3331106318", "RFC123481", "Recurrente"});
    clientes.push_back({27, "Florida Eventos", "  ", "Av. 5 de mano 6601", "San Juan de Ocotan", "Jalisco", "3336821130", "RFC123482", "Recurrente"});
    clientes.push_back({28, "La Escoba", "Eventos", "Carr. Colotran Km 1.7", "Zapopan", "Jalisco", "3338971775", "RFC123483", "Nuevo"});
}

void InicializarProductos() {
    // Agregar productos
    productos.push_back({1, "Juego de 5 cirios de piso", "Compra", 1450, 3, "Renta"});
    productos.push_back({2, "Juego de 10 cirios de piso", "Compra", 2800, 3, "Renta"});
    productos.push_back({3, "Juego de 15 cirios de piso", "Compra", 4050, 3, "Renta"});
    productos.push_back({4, "Juego de 20 cirios de piso", "Compra", 5200, 3, "Renta"});
    productos.push_back({5, "Juego de 25 cirios de piso", "Compra", 6250, 3, "Renta"});
    productos.push_back({6, "Juego de 30 cirios de piso", "Compra", 7200, 3, "Renta"});
    productos.push_back({7, "Juego de 35 cirios de piso", "Compra", 8050, 3, "Renta"});
    productos.push_back({8, "Juego de 40 cirios de piso", "Compra", 8800, 3, "Renta"});
    productos.push_back({9, "Juego de 45 cirios de piso", "Compra", 9450, 3, "Renta"});
    productos.push_back({10, "Vela colgante grande", "WO", 28, 3, "Renta"});
    productos.push_back({11, "Vela colgante chica", "WO", 18, 3, "Renta"});
    productos.push_back({12, "Vela votivo/g (250ml/8.45oz)", "Stock", 16, 0, "Renta"});
    productos.push_back({13, "Vela votivo/g Re (250ml/8.45oz)", "WO", 13, 3, "Renta"});
    productos.push_back({14, "Vela votivo/ch (142ml/5.0oz)", "Stock", 14, 0, "Renta"});
    productos.push_back({15, "Vela votivo/ch Re (142ml/5.0oz)", "WO", 11, 3, "Renta"});
    productos.push_back({16, "Vela votivo/g color (250ml/8.45oz)", "WO", 19, 3, "Renta"});
    productos.push_back({17, "Vela votivo/g Re color (250ml/8.45oz)", "WO", 16, 3, "Renta"});
    productos.push_back({18, "Vela votivo/ch color (142ml/5.0oz)", "WO", 17, 3, "Renta"});
    productos.push_back({19, "Vela votivo/ch Re color (142ml/5.0oz)", "WO", 14, 3, "Renta"});
    productos.push_back({20, "Cirio de mesa 5x6cm", "WO", 14, 3, "Renta"});
    productos.push_back({21, "Cirio de mesa 6.5x6cm", "WO", 20, 3, "Renta"});
    productos.push_back({22, "Cirio de mesa 7x6cm", "WO", 30, 3, "Renta"});
    productos.push_back({23, "Cirio de mesa 7x10cm", "WO", 39, 3, "Renta"});
    productos.push_back({24, "Cirio de mesa 7x12cm", "WO", 43, 3, "Renta"});
    productos.push_back({25, "Cirio de mesa 7x14cm", "WO", 46, 3, "Renta"});
    productos.push_back({26, "Vela flotante 4.5x2.5 cm", "WO", 11, 3, "Venta"});
    productos.push_back({27, "Vela flotante 7x2.5 cm", "WO", 18, 3, "Venta"});
    productos.push_back({28, "Vela flotante 12x2.5 cm", "WO", 22, 3, "Venta"});
    productos.push_back({29, "Vela larga conica Beige 42 cm", "WO", 26, 3, "Venta"});
    productos.push_back({30, "Vela larga conica Color 42 cm", "WO", 29, 3, "Venta"});
    productos.push_back({31, "Vela larga conica Beige 22 cm", "WO", 15, 3, "Venta"});
    productos.push_back({32, "Vela larga conica Color 22 cm", "WO", 18, 3, "Venta"});
    productos.push_back({33, "Vela floral artesanal 30cm", "WO", 300, 3, "Venta"});
    productos.push_back({34, "Vela floral artesanal 25cm", "WO", 250, 3, "Venta"});
    productos.push_back({35, "Vela floral artesanal 20cm", "WO", 220, 3, "Venta"});
}

Cliente ObtenerClientePorID(int id) {
    for (const auto& cliente : clientes) {
        if (cliente.id == id) {
            return cliente;
        }
    }
    return {};
}

Producto ObtenerProductoPorID(int id) {
    for (const auto& producto : productos) {
        if (producto.id == id) {
            return producto;
        }
    }
    return {};
}

void GuardarPedidosYVentasEnArchivos() {
    ofstream archivoPedidos("PEDIDOS.txt", ios::trunc); // Usar ios::trunc para sobrescribir el archivo
    ofstream archivoVentas("VENTAS.txt", ios::trunc); // Usar ios::trunc para sobrescribir el archivo
    
    // Encabezados de las tablas
    archivoPedidos << setw(3) << "ID" << " | " << setw(10) << "FECHA" << " | " << setw(30) << "NOMBRE DEL CLIENTE" << " | "
                   << setw(2) << "C" << " | " << setw(6) << "TOTAL" << " | " << setw(10) << "ESTATUS" << " | "
                   << setw(7) << "EST/COBZ" << " | " << setw(12) << "FolioFactura" << " | " << setw(7) << "OC CLIE" << " | " 
                   << setw(2) << "C" << " | " << setw(25) << "NOMBRE DEL PRODUCTO" << " | " << setw(6) << "TOTAL" << endl;

    archivoVentas << setw(3) << "ID" << " | " << setw(10) << "FECHA" << " | " << setw(30) << "NOMBRE DEL CLIENTE" << " | "
                  << setw(2) << "C" << " | " << setw(6) << "TOTAL" << " | " << setw(10) << "ESTATUS" << " | "
                  << setw(7) << "EST/COBZ" << " | " << setw(12) << "FolioFactura" << " | " << setw(7) << "OC CLIE" << " | " 
                  << setw(2) << "C" << " | " << setw(25) << "NOMBRE DEL PRODUCTO" << " | " << setw(6) << "TOTAL" << endl;
    
    for (const auto& pedido : pedidos) {
        for (const auto& producto : pedido.productos) {
            archivoPedidos << setw(3) << pedido.id << " | " << setw(10) << pedido.fecha << " | " << setw(30) << pedido.cliente.nombre << " " << pedido.cliente.apellido << " | "
                           << setw(2) << producto.cantidad << " | " << setw(6) << pedido.total << " | " << setw(10) << pedido.estatusPedido << " | "
                           << setw(7) << pedido.estatusCobranza << " | " << setw(12) << pedido.folioFactura << " | " << setw(7) << pedido.ordenConsecutivaCliente << " | "
                           << setw(2) << producto.cantidad << " | " << setw(25) << producto.nombre << " | " << setw(6) << producto.precio * producto.cantidad << endl;
                           
            archivoVentas << setw(3) << pedido.id << " | " << setw(10) << pedido.fecha << " | " << setw(30) << pedido.cliente.nombre << " " << pedido.cliente.apellido << " | "
                          << setw(2) << producto.cantidad << " | " << setw(6) << pedido.total << " | " << setw(10) << pedido.estatusPedido << " | "
                          << setw(7) << pedido.estatusCobranza << " | " << setw(12) << pedido.folioFactura << " | " << setw(7) << pedido.ordenConsecutivaCliente << " | "
                          << setw(2) << producto.cantidad << " | " << setw(25) << producto.nombre << " | " << setw(6) << producto.precio * producto.cantidad << endl;
        }
    }
    
    archivoPedidos.close();
    archivoVentas.close();
}

void LevantarPedido() {
    Pedido nuevoPedido;
    cout << "Ingrese la fecha: ";
    cin >> nuevoPedido.fecha;
    cin.ignore(); // Ignorar el carácter de nueva línea dejado en el búfer

    int idCliente;
    cout << "Ingrese el ID del cliente: ";
    cin >> idCliente;
    nuevoPedido.cliente = ObtenerClientePorID(idCliente);
    cin.ignore(); // Ignorar el carácter de nueva línea dejado en el búfer

    cout << "Ingrese la orden consecutiva del cliente: ";
    getline(cin, nuevoPedido.ordenConsecutivaCliente);

    char agregarOtroProducto;
    nuevoPedido.total = 0;

    do {
        int idProducto;
        cout << "Ingrese el ID del producto: ";
        cin >> idProducto;
        Producto producto = ObtenerProductoPorID(idProducto);

        cout << "Ingrese la cantidad: ";
        cin >> producto.cantidad;

        nuevoPedido.total += producto.precio * producto.cantidad;
        nuevoPedido.productos.push_back(producto);

        cout << "Producto agregado al pedido exitosamente.\n";
        cout << "Monto actual del pedido: " << nuevoPedido.total << endl;

        cout << "¿Desea agregar otro producto? (s/n): ";
        cin >> agregarOtroProducto;
    } while (agregarOtroProducto == 's' || agregarOtroProducto == 'S');

    nuevoPedido.id = (pedidos.empty()) ? 1 : pedidos.back().id + 1;
    nuevoPedido.estatusPedido = "EN PROCESO";
    nuevoPedido.estatusCobranza = "SIN PAGAR";
    nuevoPedido.folioFactura = "SIN FOLIO";
    pedidos.push_back(nuevoPedido);
    GuardarPedidosYVentasEnArchivos();

    cout << "Pedido levantado exitosamente.\n";
    cout << "Monto total del pedido: " << nuevoPedido.total << endl;
}

void ModificarPedido() {
    int id;
    cout << "Ingrese el ID del pedido a modificar: ";
    cin >> id;
    cin.ignore(); // Ignorar el carácter de nueva línea dejado en el búfer

    for (auto& pedido : pedidos) {
        if (pedido.id == id) {
            cout << "Ingrese el nuevo estatus del pedido (EN PROCESO o COMPLETADO): ";
            getline(cin, pedido.estatusPedido);

            cout << "Ingrese el nuevo estatus de la cobranza (SIN PAGAR o PAGADO): ";
            getline(cin, pedido.estatusCobranza);

            cout << "Ingrese el nuevo folio de factura: ";
            getline(cin, pedido.folioFactura);

            GuardarPedidosYVentasEnArchivos();  // Guardar todos los pedidos y ventas
            cout << "Pedido modificado exitosamente.\n";
            return;
        }
    }

    cout << "Pedido no encontrado.\n";
}

void ListarPedidos() {
    ifstream archivo("PEDIDOS.txt");
    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();
}

void ListarVentas() {
    ifstream archivo("VENTAS.txt");
    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();
}

void GenerarCotizacion() {
    int idCotizacion;
    int idCliente;
    string tiempoEntrega;
    vector<Producto> productosCotizados;

    cout << "ID cotizacion: ";
    cin >> idCotizacion;
    cin.ignore();

    cout << "Ingrese el ID del cliente: ";
    cin >> idCliente;
    cin.ignore();

    Cliente cliente = ObtenerClientePorID(idCliente);

    cout << "Tiempo de entrega: ";
    getline(cin, tiempoEntrega);

    char continuar;
    do {
        int idProducto;
        cout << "Ingrese el ID del producto: ";
        cin >> idProducto;
        Producto producto = ObtenerProductoPorID(idProducto);

        cout << "Cantidad: ";
        cin >> producto.cantidad;

        productosCotizados.push_back(producto);

        cout << "Agregar otro producto? (s/n): ";
        cin >> continuar;
        cin.ignore();
    } while (continuar == 's' || continuar == 'S');

    double total = 0.0;
    for (size_t i = 0; i < productosCotizados.size(); ++i) {
        const Producto& producto = productosCotizados[i];
        total += producto.precio * producto.cantidad;
    }

    ofstream archivo("cotizacion.txt");
    if (archivo.is_open()) {
        archivo << "ID cotizacion: " << idCotizacion << endl;
        archivo << "Nombre y Apellido: " << cliente.nombre << " " << cliente.apellido << endl;
        archivo << "DOMICILIO: " << cliente.domicilio << endl;
        archivo << "MUNICIPIO: " << cliente.municipio << endl;
        archivo << "ESTADO: " << cliente.estado << endl;
        archivo << "TELEFONO: " << cliente.telefono << endl;
        archivo << endl;
        archivo << "(DESCRIPCION)" << endl;
        archivo << "//A continuación ponemos a su consideración la cotización de los productos que nos solicitó y quedamos a sus órdenes//" << endl;
        archivo << endl;
        archivo << "------------------------------------------------------------------" << endl;
        archivo << "| Cantidad | Nombre del producto   | Precio unitario | Monto     |" << endl;
        archivo << "------------------------------------------------------------------" << endl;

        for (size_t i = 0; i < productosCotizados.size(); ++i) {
            const Producto& producto = productosCotizados[i];
            double monto = producto.cantidad * producto.precio;
            archivo << "| " << setw(9) << producto.cantidad << " | "
                    << setw(21) << producto.nombre << " | "
                    << setw(15) << fixed << setprecision(2) << producto.precio << " | "
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
    cin.ignore().get();
    system("cls"); // Para Windows
    // system("clear"); // Para Unix/Linux
}

void MostrarMenuPrincipal();
void MostrarMenuClientes();
void MostrarMenuPedidos();
void MostrarMenuCotizaciones();

void ListarClientes();
void AgregarCliente();
void ListarProductos();

int main() {
    InicializarClientes();
    InicializarProductos();

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
        cout << "4. Cotizaciones" << endl;
        cout << "5. Ventas" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion, por favor: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                MostrarMenuClientes();
                break;
            case 2:
                ListarProductos();
                break;
            case 3:
                MostrarMenuPedidos();
                break;
            case 4:
                MostrarMenuCotizaciones();
                break;
            case 5:
                ListarVentas();
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

void MostrarMenuCotizaciones() {
    int opcion;
    do {
        cout << "__________Menu Cotizaciones:_________" << endl;
        cout << "1. Generar Cotizacion" << endl;
        cout << "2. Regresar al menu principal" << endl;
        cout << "Seleccione una opcion, por favor: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                GenerarCotizacion();
                break;
            case 2:
                return;
            default:
                cout << "Opcion no valida, intente nuevamente." << endl;
        }
        EsperarYLimpiarPantalla();
    } while (opcion != 2);
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
    cout << "Ingrese el ID del cliente: ";
    cin >> nuevoCliente.id;
    cin.ignore(); // Ignorar el carácter de nueva línea dejado en el búfer

    cout << "Ingrese el nombre del cliente: ";
    getline(cin, nuevoCliente.nombre);

    cout << "Ingrese el apellido del cliente: ";
    getline(cin, nuevoCliente.apellido);

    cout << "Ingrese el domicilio del cliente: ";
    getline(cin, nuevoCliente.domicilio);

    cout << "Ingrese el municipio del cliente: ";
    getline(cin, nuevoCliente.municipio);

    cout << "Ingrese el estado del cliente: ";
    getline(cin, nuevoCliente.estado);

    cout << "Ingrese el telefono del cliente: ";
    getline(cin, nuevoCliente.telefono);

    cout << "Ingrese el RFC del cliente: ";
    getline(cin, nuevoCliente.RFC);

    cout << "Ingrese el tipo del cliente: ";
    getline(cin, nuevoCliente.tipo);

    archivo << nuevoCliente.id <<" | "<< nuevoCliente.nombre << " | " << nuevoCliente.apellido << " | " << nuevoCliente.domicilio << " | " << nuevoCliente.municipio << " | "<< nuevoCliente.estado << " | " << nuevoCliente.telefono << " | " << nuevoCliente.RFC << " | " << nuevoCliente.tipo << endl;
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

