#include "banco.hpp"
#include "activo.hpp"
#include <sstream>

Banco::Banco() {
  num_ahorro = 0;
  num_corriente = 0;
  num_inversiones = 0;
  activos = {Activo(0, "Bonos", 0.1), Activo(1, "Bolsa", 0.15),
             Activo(2, "Bienes raíces", 0.07), Activo(3, "Pagarés", 0.05),
             Activo(4, "Criptomonedas", 0.25)};
}

int Banco::getNumAhorro() { return num_ahorro; }
int Banco::getNumCorriente() { return num_corriente; }
int Banco::getNumInversion() { return num_inversiones; }

int Banco::getIndice(int tipo) {
  switch (tipo) {
  case 1:
    return num_ahorro;
    break;
  case 2:
    return num_corriente;
    break;
  case 3:
    return num_inversiones;
    break;
  default:
    return -1;
    break;
  }
}

void Banco::abrirCuenta(int tipo, int id, std::string titular) {
  switch (tipo) {
  case 1:
    ahorros[num_ahorro] = CuentaAhorro(num_ahorro, titular);
    num_ahorro++;
    break;
  case 2:
    corrientes[num_corriente] = CuentaCorriente(num_corriente, titular);
    num_corriente++;
    break;
  case 3:
    inversiones[num_inversiones] =
        CuentaInversion(num_inversiones, titular, 0.0, &activos[1]);
    num_inversiones++;
    break;
  }
}

std::stringstream Banco::printCuentas() {
  std::stringstream output_string;
  output_string << "hello";
  output_string << " world";
  output_string << std::endl;
  return output_string;
}
