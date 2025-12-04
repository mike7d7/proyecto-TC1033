// Clase CuentaCorriente, hereda de la clase CuentaBancaria y agrega el atributo
// "linea_credito", el cual se usa como si fuera saldo adicional.

#ifndef CORRIENTE_H
#define CORRIENTE_H

#include "cuentaBancaria.hpp"

class CuentaCorriente : public CuentaBancaria {
  private:
    // Atributo de la clase
    double linea_credito;

  public:
    // Constructor default, solo existe para la creación de los arreglos de
    // cuentas en clase Banco. No se usa para crear activos nuevos.
    CuentaCorriente()
        : CuentaBancaria(0, "nadie", 0.0), linea_credito(5000.0) {};

    // Constructor que recibe id, titular, saldo y línea de crédito. Los
    // primeros tres se pasan al constructor de la clase padre. Siempre se usa
    // este constructor para crear nuevas cuentas corrientes.
    CuentaCorriente(int id, std::string ti, double sa, double lc)
        : CuentaBancaria(id, ti, sa), linea_credito(lc) {};

    // Getter
    double getLineaCredito();

    // Setter
    void setLineaCredito(double);

    // Sobreescribir método retirar (proviene de la clase padre).
    int retirar(double);
};

#endif
