#include "cuentaInversion.hpp"
#include "activo.hpp"

// Getter
Activo CuentaInversion::getActivo() { return *activo; }

// Se aplica el rendimiento generado como intereses a la cuenta en base a su
// salario actual y el porcentaje de interes. El rendimiento es un atributo del
// activo asociado a la cuenta.
void CuentaInversion::generaRendimiento() {
  saldo += saldo * activo->getRendimiento();
}
