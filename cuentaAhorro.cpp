#include "cuentaAhorro.hpp"

// Getter
float CuentaAhorro::getInteres() { return interes; }

// Setter
void CuentaAhorro::setInteres(float in) { interes = in; }

// Se aplica el rendimiento generado como intereses a la cuenta en base a su
// salario actual y el porcentaje de interes.
void CuentaAhorro::generaInteres() { saldo += saldo * interes; }
