// Clase CuentaBancaria, clase padre de todas las clases de Cuentas
// especializadas. Tiene un id único, un titular (persona dueña de la cuenta) y
// un saldo. Le permite a todas las cuentas hacer retiros y recibir depósitos.

#ifndef CUENTA_BANCARIA_H
#define CUENTA_BANCARIA_H

#include <string>

class CuentaBancaria {
  protected:
    // Atributos de la clase, los cuales también usan las clases hijas.
    int id;
    std::string titular;
    double saldo;

  public:
    CuentaBancaria(int id, std::string titular, double saldo)
        : id(id), titular(titular), saldo(saldo) {};
    int getId();
    double getSaldo();
    std::string getTitular();
    void setSaldo(double);
    int retirar(double);
    void depositar(double);
};

#endif
