#include<iostream>
#include <locale>

#include "ej1/Flags.h"
#include "ej2/EJ2.h"
#include "ej3/EJ3.h"
#include "ej4/EJ4.h"
#include "ej7/EJ7.h"

using namespace std;

int main() {
    int result = divide(5, 0);

    setlocale(LC_ALL, "es_ES.UTF-8");

    // Se verifica regularmente la bandera de error
    if (errorFlag) {
        cout << "Ocurrió un error: división por cero." << endl;
        // Se maneja el error y se reinicia la bandera
        errorFlag = false;
    }

    int resultError = divideError(5, 0);
    if (resultError == -1) {
        std::cout << "Error: división por cero." << std::endl;
    }

    // Uso de la versión que lanza una excepción
    try {
        int resultException = divideException(5, 0);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Excepción: " << e.what() << std::endl;
    }

    try {
        func1();
    }
    catch (const std::runtime_error& e) {
        std::cout << "Excepción capturada en main: " << e.what() << std::endl;
    }

    try {
        lanzaExcepcion();
    }
    catch (const MiExcepcion& e) {
        std::cout << "Excepción capturada: " << e.what() << std::endl;
    }

    //lanzaExcepcion();
    // EXCEPCION NO CONTROLADA -> TERMINA EL PROGRAMA

    std::ofstream file("archivo.txt");

    try {
        file.close(); // Cierra el archivo para simular un error
        escribeEnArchivo(file);
    }
    catch (const std::runtime_error& e) {
        std::cout << "Excepción capturada: " << e.what() << std::endl;
    }

    // Asegurarse de que el archivo esté cerrado
    if (file.is_open()) {
        file.close();
    }

    return 0;
}