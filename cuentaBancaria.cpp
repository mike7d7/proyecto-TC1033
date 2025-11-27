#include "cuentaBancaria.hpp"
#include <string>

int CuentaBancaria::getId() { return id; }
double CuentaBancaria::getSaldo() { return saldo; }
std::string CuentaBancaria::getTitular() { return titular; }
void CuentaBancaria::setSaldo(double sa) { saldo = sa; }
double CuentaBancaria::retirar(double cantidad) {
  if (cantidad <= saldo) {
    saldo -= cantidad;
    return cantidad;
  } else {
    return 0.0;
  }
}
void CuentaBancaria::depositar(double cantidad) { saldo += cantidad; }
