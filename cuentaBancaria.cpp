#include "cuentaBancaria.hpp"
#include <string>

int CuentaBancaria::getId() { return id; }
double CuentaBancaria::getSaldo() { return saldo; }
std::string CuentaBancaria::getTitular() { return titular; }
void CuentaBancaria::setSaldo(double sa) { saldo = sa; }
int CuentaBancaria::retirar(double cantidad) {
  if (cantidad <= saldo) {
    saldo -= cantidad;
    return 0;
  } else {
    return 1;
  }
}
void CuentaBancaria::depositar(double cantidad) { saldo += cantidad; }
