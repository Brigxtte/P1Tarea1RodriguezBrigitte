#include <iostream>
#include <fstream>
using namespace std;

// VARIABLES GLOBALES PARA LAS CALIFICACIONES Y PROMEDIO
float Rodriguez_nota1, Rodriguez_nota2, Rodriguez_nota3, Rodriguez_promedio1;
int Rodriguez_num, Rodriguez_opcion;
string registros = ""; // Cadena para almacenar promedios

// FUNCION PARA REGISTRAR NOTAS
void Rodriguez_registronotas() {
    // SOLICITAR AL USUARIO CUANTAS PERSONAS DESEA INGRESAR
    cout << "¿Cuantas personas desea ingresar? (1-5): ";
    cin >> Rodriguez_num;
    // VALIDAR QUE EL NUMERO DE PERSONAS ESTE ENTRE 1 Y 5
    while (Rodriguez_num < 1 || Rodriguez_num > 5) {
        cout << "El limite de personas es 1 a 5, ingrese nuevamente: ";
        cin >> Rodriguez_num;
    }

    // INGRESAR CALIFICACIONES PARA CADA PERSONA
    for (int i = 0; i < Rodriguez_num; i++) {
        // SOLICITAR Y VALIDAR LA PRIMERA CALIFICACION
        cout << "Ingrese su primera calificacion (0-20): ";
        cin >> Rodriguez_nota1;
        while (Rodriguez_nota1 < 0 || Rodriguez_nota1 > 20) {
            cout << "Ingrese nuevamente solo de 0 a 20: ";
            cin >> Rodriguez_nota1;
        }

        // SOLICITAR Y VALIDAR LA SEGUNDA CALIFICACION
        cout << "Ingrese su segunda calificacion (0-20): ";
        cin >> Rodriguez_nota2;
        while (Rodriguez_nota2 < 0 || Rodriguez_nota2 > 20) {
            cout << "Ingrese nuevamente solo de 0 a 20: ";
            cin >> Rodriguez_nota2;
        }

        // SOLICITAR Y VALIDAR LA TERCERA CALIFICACION
        cout << "Ingrese su tercera calificacion (0-20): ";
        cin >> Rodriguez_nota3;
        while (Rodriguez_nota3 < 0 || Rodriguez_nota3 > 20) {
            cout << "Ingrese nuevamente solo de 0 a 20: ";
            cin >> Rodriguez_nota3;
        }

        // CALCULAR EL PROMEDIO DE LAS CALIFICACIONES
        Rodriguez_promedio1 = (Rodriguez_nota1 + Rodriguez_nota2 + Rodriguez_nota3) / 3;
        cout << "Su promedio es de: " << Rodriguez_promedio1 << endl;

        // ALMACENAR EL PROMEDIO
        registros += "Promedio: " + to_string(Rodriguez_promedio1) + "\n";

        // MENSAJE DE APROBACION O REPROBACION
        if (Rodriguez_promedio1 > 14) {
            cout << "Usted aprobo el curso" << endl;
        } else {
            cout << "Usted reprobo el curso" << endl;
        }
    }
}

// FUNCION PARA GUARDAR LAS NOTAS EN UN ARCHIVO
void Rodriguez_guardarnotas() {
    // ABRIR EL ARCHIVO EN MODO APPEND
    ofstream archivo("Registro_de_notas.txt", ios::app);
    // VALIDAR QUE EL ARCHIVO SE HAYA ABIERTO CORRECTAMENTE
    if (!archivo) {
        cout << "No se logra abrir el archivo, error" << endl;
        return;
    }
    // GUARDAR LAS CALIFICACIONES Y EL PROMEDIO EN EL ARCHIVO
    archivo << "----------------------------------" << endl;
    archivo << "Calificacion 1: " << Rodriguez_nota1 << endl;
    archivo << "Calificacion 2: " << Rodriguez_nota2 << endl;
    archivo << "Calificacion 3: " << Rodriguez_nota3 << endl;
    archivo << "Promedio: " << Rodriguez_promedio1 << endl;
    archivo << "----------------------------------" << endl;
    archivo.close();
    cout << "Sus calificaciones han sido guardadas en Registro_de_notas.txt" << endl;
}

// FUNCION PARA MOSTRAR EL MENU Y MANEJAR OPCIONES
void Rodriguez_menu() {
    do {
        cout << "----------------------------------" << endl;
        cout << "Bienvenido al menu de opciones: " << endl;
        cout << "1. Registrar notas" << endl;
        cout << "2. Ver promedios registrados" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> Rodriguez_opcion;

        // MANEJO DE OPCIONES DEL MENU
        switch (Rodriguez_opcion) {
            case 1:
                Rodriguez_registronotas(); // REGISTRAR NOTAS
                Rodriguez_guardarnotas();   // GUARDAR NOTAS EN ARCHIVO
                break;
            case 2:
                cout << "Promedios registrados:" << endl;
                cout << registros; // MOSTRAR TODOS LOS PROMEDIOS
                break;
            case 3:
                cout << "Gracias por usar el programa" << endl; // MENSAJE DE SALIDA
                break;
            default:
                cout << "Incorrecto, ingrese nuevamente" << endl; // MENSAJE DE OPCION INVALIDA
        }
    } while (Rodriguez_opcion != 3); // CONTINUAR HASTA QUE SE ELIJA SALIR
}

// FUNCION PRINCIPAL DEL PROGRAMA
int main() {
    Rodriguez_menu(); // LLAMAR AL MENU
    return 0; // FINALIZAR EL PROGRAMA
}
