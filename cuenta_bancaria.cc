#include "cuenta_bancaria.hh"

int CuentaBancaria::getId() { return id; }
double CuentaBancaria::getSaldo() { return saldo; }
void CuentaBancaria::setSaldo(double sa) {
    saldo = sa;
}
double CuentaBancaria::retirar(double cantidad) {
  if (cantidad <= saldo) {
    saldo -= cantidad;
    return cantidad;
  } else {
    return 0.0;
  }
}
void CuentaBancaria::depositar(double cantidad) { saldo += cantidad; }
