#include <string>

class CuentaBancaria {
  protected:
    int id;
    std::string titular;
    double saldo;

  public:
    CuentaBancaria(int id, std::string titular)
        : id(id), titular(titular), saldo(0.0) {};
    CuentaBancaria(int id, std::string titular, double saldo)
        : id(id), titular(titular), saldo(saldo) {};
    int getId();
    double getSaldo();
    void setSaldo(double);
    double retirar(double);
    void depositar(double);
};
