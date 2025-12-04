#include "cuentaBancaria.hpp"
#include <string>

// Getters
int CuentaBancaria::getId() { return id; }
double CuentaBancaria::getSaldo() { return saldo; }
std::string CuentaBancaria::getTitular() { return titular; }

// Setter
void CuentaBancaria::setSaldo(double sa) { saldo = sa; }

// Movimientos
//
// Retirar recibe la cantidad a retirar como parámetro, en caso de que el saldo
// sea suficiente, se resta la cantidad a retirar, se asigna el nuevo saldo y la
// función regresa 0 para indicar éxito.
// Si el saldo es insuficiente, la función regresa 1 para indicar el fracaso en
// la transacción.
int CuentaBancaria::retirar(double cantidad) {
  if (cantidad <= saldo) {
    saldo -= cantidad;
    return 0;
  } else {
    return 1;
  }
}
// Depositar recibe una cantidad y la agrega al saldo de la cuenta.
void CuentaBancaria::depositar(double cantidad) { saldo += cantidad; }
