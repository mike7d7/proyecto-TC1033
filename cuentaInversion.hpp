// Clase CuentaInversion, hereda de la clase CuentaBancaria y agrega el atributo
// "activo", el cual se usa para conocer el instrumento de inversión que utiliza
// la cuenta.

#ifndef INVERSION_H
#define INVERSION_H

#include "activo.hpp"
#include "cuentaBancaria.hpp"

class CuentaInversion : public CuentaBancaria {
  private:
    // Atributo de la clase
    Activo *activo;

  public:
    // Constructor default, solo existe para la creación de los arreglos de
    // cuentas en clase Banco. No se usa para crear activos nuevos.
    CuentaInversion() : CuentaBancaria(0, "nadie", 0), activo(nullptr) {};

    // Constructor que recibe id, titular, saldo y activo. Los
    // primeros tres se pasan al constructor de la clase padre. Siempre se usa
    // este constructor para crear nuevas cuentas de inversión.
    CuentaInversion(int id, std::string ti, double sa, Activo *act)
        : CuentaBancaria(id, ti, sa), activo(act) {};

    // Getter
    Activo getActivo();

    // Aumenta el saldo de las cuentas que ganan intereses.
    void generaRendimiento();
};

#endif
