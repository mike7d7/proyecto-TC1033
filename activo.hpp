#ifndef ACTIVO_H
#define ACTIVO_H

#include <string>

class Activo {
  private:
    int id;
    std::string nombre;
    float rendimiento;

  public:
    Activo(int id, std::string nombre, float rendimiento)
        : id(id), nombre(nombre), rendimiento(rendimiento) {};
    int getId();
    std::string getNombre();
    float getRendimiento();
    void setRendimiento(float);
};

#endif
