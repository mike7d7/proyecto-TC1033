// Clase CuentaAhorro, hereda de la clase CuentaBancaria y agrega el atributo
// "interes", el cual se usa para que se genere un rendimiento en base al saldo
// de la cuenta.

#ifndef AHORRO_H
#define AHORRO_H

#include "cuentaBancaria.hpp"

class CuentaAhorro : public CuentaBancaria {
  private:
    // Atributo de la clase.
    float interes;

  public:
    // Constructores
    // Constructor default, solo existe para la creación de los arreglos de
    // cuentas en clase Banco. No se usa para crear activos nuevos.
    CuentaAhorro() : CuentaBancaria(0, "nadie", 0.0), interes(0) {};

    // Constructor que recibe id, titular, saldo e interés. Los primeros tres se
    // pasan al constructor de la clase padre. Siempre se usa este constructor
    // para crear nuevas cuentas de ahorro.
    CuentaAhorro(int id, std::string titular, double sa, float in)
        : CuentaBancaria(id, titular, sa), interes(in) {};

    // Getter
    float getInteres();

    // Setter
    void setInteres(float);

    // Aumenta el saldo de las cuentas que ganan intereses.
    void generaInteres();
};

#endif
