#include "cuenta_inversion.hh"

float CuentaInversion::getRendimiento() { return rendimiento; }

void CuentaInversion::setRendimiento(float re) { rendimiento = re; }

void CuentaInversion::generaRendimiento() { saldo += saldo * rendimiento; }
