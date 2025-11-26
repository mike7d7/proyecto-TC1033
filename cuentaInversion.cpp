#include "cuentaInversion.hpp"
#include "activo.hpp"

Activo CuentaInversion::getActivo() { return *activo; }
void CuentaInversion::generaRendimiento() {
  saldo += saldo * activo->getRendimiento();
}
