#include<iostream>
#include<stdexcept>

void lanzaExcepcion() {
    throw std::runtime_error("Error en la función lanzaExcepcion");
}

int main() {
    lanzaExcepcion();

    return 0;
}