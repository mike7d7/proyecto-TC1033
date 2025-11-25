#include "cuentaAhorro.hpp"

float CuentaAhorro::getInteres() { return interes; }

void CuentaAhorro::setInteres(float in) { interes = in; }

void CuentaAhorro::generaInteres() { saldo += saldo * interes; }
