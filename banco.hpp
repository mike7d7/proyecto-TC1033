// Clase Activo, representa instrumentos de inversión.
// Solo se usa en las cuentas de tipo inversión.
// Tiene un id, su nombre, y el rendimiento que genera.

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
    // Atributos de la clase
    // Arreglos de cada tipo de cuenta
    CuentaAhorro ahorros[100];
    CuentaCorriente corrientes[100];
    CuentaInversion inversiones[100];

    // Contadores de cada arreglo.
    int num_ahorro;
    int num_corriente;
    int num_inversiones;

    // Arreglo de activos disponibles
    std::array<Activo, 5> activos;

  public:
    // Constructor default, siempre se usa.
    Banco();

    // Métodos de acceso
    int getNumAhorro();
    CuentaAhorro *getAhorros();
    int getNumCorriente();
    CuentaCorriente *getCorrientes();
    int getNumInversion();
    CuentaInversion *getInversiones();
    Activo *getActivo(int indice);

    // Métodos para abrir cuentas nuevas
    // Cada método sirve para un tipo de cuenta distinto
    void abrirCuenta(std::string titular, double saldo, float interes);
    void abrirCuenta(std::string titular, double saldo, double linea_credito);
    void abrirCuenta(std::string titular, double saldo, Activo *activo);

    // Método para recuperar información de todas las cuentas
    std::stringstream printCuentas();

    // Aumenta el saldo de las cuentas que ganan intereses.
    void aplicaIntereses();
};
#endif
