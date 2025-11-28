#include "cuentaCorriente.hpp"

double CuentaCorriente::getLineaCredito() { return linea_credito; }

void CuentaCorriente::setLineaCredito(double lc) { linea_credito = lc; }

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
