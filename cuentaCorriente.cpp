#include "cuentaCorriente.hpp"

// Getter
double CuentaCorriente::getLineaCredito() { return linea_credito; }

// Setter
void CuentaCorriente::setLineaCredito(double lc) { linea_credito = lc; }

// Funciona como el método "retirar" de la clase cuentaBancaria, pero en lugar
// de checar solo el saldo, checa si completa la cantidad a retirar sumando el
// saldo y la línea de crédito.
int CuentaCorriente::retirar(double cantidad) {
  if (cantidad <= saldo + linea_credito) {
    linea_credito -= cantidad;
    if (linea_credito < 0) {
      saldo += linea_credito;
      linea_credito = 0;
    }
    return 0;
  } else {
    return 1;
  }
}
