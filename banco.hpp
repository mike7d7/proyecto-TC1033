#ifndef BANCO_H
#define BANCO_H
#include "activo.hpp"
#include "cuentaAhorro.hpp"
#include "cuentaCorriente.hpp"
#include "cuentaInversion.hpp"
#include <array>
#include <sstream>
#include <string>

class Banco {
  private:
    int num_ahorro;
    CuentaAhorro ahorros[100];
    int num_corriente;
    CuentaCorriente corrientes[100];
    int num_inversiones;
    CuentaInversion inversiones[100];
    std::array<Activo, 5> activos;

  public:
    Banco();
    int getNumAhorro();
    int getNumCorriente();
    int getNumInversion();
    int getIndice(int tipo);
    void abrirCuenta(int tipo, int id, std::string titular);
    std::stringstream printCuentas();
};
#endif
