#include "banco.hpp"
#include "activo.hpp"
#include "cuentaAhorro.hpp"
#include "cuentaCorriente.hpp"
#include "cuentaInversion.hpp"
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
CuentaAhorro *Banco::getAhorros() { return ahorros; }
int Banco::getNumCorriente() { return num_corriente; }
CuentaCorriente *Banco::getCorrientes() { return corrientes; }
int Banco::getNumInversion() { return num_inversiones; }
CuentaInversion *Banco::getInversiones() { return inversiones; }

Activo *Banco::getActivo(int indice) { return &activos[indice]; }

void Banco::abrirCuenta(std::string titular, double saldo, float interes) {
  int id = 100 + num_ahorro;
  ahorros[num_ahorro] = CuentaAhorro(id, titular, saldo, interes);
  num_ahorro++;
}
void Banco::abrirCuenta(std::string titular, double saldo,
                        double linea_credito) {
  int id = 200 + num_corriente;
  corrientes[num_corriente] =
      CuentaCorriente(id, titular, saldo, linea_credito);
  num_corriente++;
}
void Banco::abrirCuenta(std::string titular, double saldo, Activo *activo) {
  int id = 300 + num_inversiones;
  inversiones[num_inversiones] = CuentaInversion(id, titular, saldo, activo);
  num_inversiones++;
}

std::stringstream Banco::printCuentas() {
  std::stringstream output_string;
  output_string << "Cuentas de Ahorro" << std::endl;
  output_string << "Titular | id | Saldo | Interés" << std::endl;
  for (int i = 0; i < num_ahorro; i++) {
    output_string << ahorros[i].getTitular() << " | " << ahorros[i].getId()
                  << " | " << ahorros[i].getSaldo() << " | "
                  << ahorros[i].getInteres() << std::endl;
  }
  output_string << std::endl;

  output_string << "Cuentas Corrientes" << std::endl;
  output_string << "Titular | id | Saldo | Línea de crédito" << std::endl;
  for (int i = 0; i < num_corriente; i++) {
    output_string << corrientes[i].getTitular() << " | "
                  << corrientes[i].getId() << " | " << corrientes[i].getSaldo()
                  << " | " << corrientes[i].getLineaCredito() << std::endl;
  }
  output_string << std::endl;

  output_string << "Cuentas de Inversion" << std::endl;
  output_string << "Titular | id | Saldo | Activo | Rendimiento" << std::endl;
  for (int i = 0; i < num_inversiones; i++) {
    output_string << inversiones[i].getTitular() << " | "
                  << inversiones[i].getId() << " | "
                  << inversiones[i].getSaldo() << " | "
                  << inversiones[i].getActivo().getNombre() << " | "
                  << inversiones[i].getActivo().getRendimiento() << std::endl;
  }
  output_string << std::endl;
  return output_string;
}

void Banco::aplicaIntereses() {
  for (int i = 0; i < num_ahorro; i++) {
    ahorros[i].generaInteres();
  }
  for (int i = 0; i < num_inversiones; i++) {
    inversiones[i].generaRendimiento();
  }
}
