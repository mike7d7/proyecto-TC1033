#include "cuenta_corriente.hh"

float CuentaCorriente::getLineaCredito() { return linea_credito; }

void CuentaCorriente::setLineaCredito(double lc) { linea_credito = lc; }

void CuentaCorriente::retirar(double cantidad) {
    if (cantidad <= saldo + linea_credito) {
        linea_credito -= cantidad;
        if (linea_credito < 0) {
            saldo += linea_credito;
            linea_credito = 0;
        }
    }
}
