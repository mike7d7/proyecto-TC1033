// Clase Activo, representa instrumentos de inversión.
// Solo se usa en las cuentas de tipo inversión.
// Tiene un id, su nombre, y el rendimiento que genera.

#ifndef ACTIVO_H
#define ACTIVO_H

#include <string>

class Activo {
  private:
    // Variables de la clase
    int id;
    std::string nombre;
    float rendimiento;

  public:
    // Constructor default, solo existe para la creación de los arreglos de
    // cuentas en clase Banco. No se usa para crear activos nuevos.
    Activo() : id(0), nombre("activo_default"), rendimiento(0.0) {};

    // Constructor que recibe id, nombre y rendimiento.
    // Siempre se usa este constructor para crear activos nuevos.
    Activo(int id, std::string nombre, float rendimiento)
        : id(id), nombre(nombre), rendimiento(rendimiento) {};

    // Métodos de acceso
    int getId();
    std::string getNombre();
    float getRendimiento();
    void setRendimiento(float);
};

#endif
