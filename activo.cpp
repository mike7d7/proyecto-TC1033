#include "activo.hpp"

// Getters: devuelven una variable de la clase.
int Activo::getId() { return id; };
std::string Activo::getNombre() { return nombre; };
float Activo::getRendimiento() { return rendimiento; };

// Setters: asignan un nuevo valor a una variable de la clase.
void Activo::setRendimiento(float new_rendimiento) {
  rendimiento = new_rendimiento;
};
