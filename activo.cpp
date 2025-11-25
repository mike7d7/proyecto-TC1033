#include "activo.hpp"

int Activo::getId() { return id; };
std::string Activo::getNombre() { return nombre; };
float Activo::getRendimiento() { return rendimiento; };
void Activo::setRendimiento(float new_rendimiento) {
  rendimiento = new_rendimiento;
};
