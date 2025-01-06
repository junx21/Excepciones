# Link del Repositorio: https://github.com/junx21/Excepciones


# Enunciado de Ejercicios

## Los enfoques de bajo nivel: Banderas e interrupciones y tratamiento de los errores en lenguaje C++

### Ejercicio 1: Sistema con banderas de error
Implementa un programa en C++ que simule un sistema con banderas de error. Si ocurre un error, en lugar de lanzar una excepción, establece una bandera de error. Luego, comprueba regularmente la bandera de error para manejarla.

```cpp
#include <iostream>

// Variable global que actúa como bandera de error
bool errorFlag = false;

int divide(int a, int b) {
    if (b == 0) {
        // Si ocurre un error, se establece la bandera de error
        errorFlag = true;
        return 0;
    }
    return a / b;
}

int main() {
    int result = divide(5, 0);

    // Se verifica regularmente la bandera de error
    if (errorFlag) {
        std::cout << "Ocurrió un error: división por cero." << std::endl;
        // Se maneja el error y se reinicia la bandera
        errorFlag = false;
    }

    return 0;
}
```
Ejercicio 2: Excepciones vs errores
Implementa dos versiones de una función que pueda provocar un error (como la división por cero). La primera versión debe manejar el error devolviendo un valor de error, mientras que la segunda versión debe lanzar una excepción.

```cpp
#include <iostream>
#include <stdexcept>

// Versión de la función que devuelve un valor de error
int divideError(int a, int b) {
    if (b == 0) {
        return -1; // valor de error
    }
    return a / b;
}

// Versión de la función que lanza una excepción
int divideException(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("División por cero");
    }
    return a / b;
}

int main() {
    // Uso de la versión que devuelve un valor de error
    int resultError = divideError(5, 0);
    if (resultError == -1) {
        std::cout << "Error: división por cero." << std::endl;
    }

    // Uso de la versión que lanza una excepción
    try {
        int resultException = divideException(5, 0);
    } catch (const std::invalid_argument& e) {
        std::cout << "Excepción: " << e.what() << std::endl;
    }

    return 0;
}
```
Ejercicio 3: Propagación explícita de excepciones
Demuestra cómo una excepción se propaga a través de varias funciones.

```cpp

#include <iostream>
#include <stdexcept>

void func3() {
    throw std::runtime_error("Error en func3");
}

void func2() {
    func3();
}

void func1() {
    func2();
}

int main() {
    try {
        func1();
    } catch (const std::runtime_error& e) {
        std::cout << "Excepción capturada en main: " << e.what() << std::endl;
    }

    return 0;
}
```
Ejercicio 4: Excepciones personalizadas
Define clases de excepción personalizadas que heredan de std::exception.

```cpp
#include <iostream>
#include <exception>
#include <string>

class MiExcepcion : public std::exception {
private:
    std::string mensaje;
public:
    explicit MiExcepcion(const std::string& msg) : mensaje(msg) {}
    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

void lanzaExcepcion() {
    throw MiExcepcion("Ocurrió un error en la función lanzaExcepcion");
}

int main() {
    try {
        lanzaExcepcion();
    } catch (const MiExcepcion& e) {
        std::cout << "Excepción capturada: " << e.what() << std::endl;
    }

    return 0;
}
```
Ejercicio 5: Reactivación de excepciones
Manejo de una excepción y su reactivación.

```cpp
#include <iostream>
#include <stdexcept>

void lanzaExcepcion() {
    throw std::runtime_error("Error en la función lanzaExcepcion");
}

int main() {
    try {
        try {
            lanzaExcepcion();
        } catch (const std::runtime_error& e) {
            std::cout << "Excepción capturada y manejada. Reactivando..." << std::endl;
            throw; // Relanza la excepción
        }
    } catch (const std::runtime_error& e) {
        std::cout << "Excepción reactivada capturada: " << e.what() << std::endl;
    }

    return 0;
}
```
Ejercicio 6: Excepciones no interceptadas
Lanza una excepción que no sea capturada.

```cpp
#include <iostream>
#include <stdexcept>

void lanzaExcepcion() {
    throw std::runtime_error("Error en la función lanzaExcepcion");
}

int main() {
    lanzaExcepcion();

    return 0;
}
```
Ejercicio 7: Adquisición y liberación de recursos
Implementa una clase que adquiere recursos y los libera en caso de excepciones.

```cpp
#include <iostream>
#include <stdexcept>
#include <fstream>

void escribeEnArchivo(std::ofstream& file) {
    if (!file.is_open()) {
        throw std::runtime_error("No se puede escribir en un archivo cerrado");
    }
    file << "Hola, mundo!";
}

int main() {
    std::ofstream file("archivo.txt");
    
    try {
        file.close(); // Cierra el archivo para simular un error
        escribeEnArchivo(file);
    } catch (const std::runtime_error& e) {
        std::cout << "Excepción capturada: " << e.what() << std::endl;
    }

    // Asegurarse de que el archivo esté cerrado
    if (file.is_open()) {
        file.close();
    }

    return 0;
}
```
