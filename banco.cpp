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
    ahorros[num_ahorro] = CuentaAhorro(num_ahorro + 100, titular);
    num_ahorro++;
    break;
  case 2:
    corrientes[num_corriente] = CuentaCorriente(num_corriente + 200, titular);
    num_corriente++;
    break;
  case 3:
    inversiones[num_inversiones] =
        CuentaInversion(num_inversiones + 300, titular, 0.0, &activos[1]);
    num_inversiones++;
    break;
  }
}

std::stringstream Banco::printCuentas() {
  std::stringstream output_string;
  output_string << "Cuentas de Ahorro" << std::endl;
  for (int i = 0; i < num_ahorro; i++) {
    output_string << ahorros[i].getTitular() << " | " << ahorros[i].getId()
                  << " | " << ahorros[i].getSaldo() << std::endl;
  }
  output_string << std::endl;

  output_string << "Cuentas Corrientes" << std::endl;
  for (int i = 0; i < num_corriente; i++) {
    output_string << corrientes[i].getTitular() << " | "
                  << corrientes[i].getId() << " | " << corrientes[i].getSaldo()
                  << std::endl;
  }
  output_string << std::endl;

  output_string << "Cuentas de Inversion" << std::endl;
  for (int i = 0; i < num_inversiones; i++) {
    output_string << inversiones[i].getTitular() << " | "
                  << inversiones[i].getId() << " | "
                  << inversiones[i].getSaldo() << std::endl;
  }
  output_string << std::endl;
  return output_string;
}
