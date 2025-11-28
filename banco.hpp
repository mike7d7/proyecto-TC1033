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
    CuentaAhorro *getAhorros();
    int getNumCorriente();
    CuentaCorriente *getCorrientes();
    int getNumInversion();
    CuentaInversion *getInversiones();
    int getIndice(int tipo);
    Activo *getActivo(int indice);
    void abrirCuenta(std::string titular, double saldo, float interes);
    void abrirCuenta(std::string titular, double saldo, double linea_credito);
    void abrirCuenta(std::string titular, double saldo, Activo *activo);
    std::stringstream printCuentas();
};
#endif
