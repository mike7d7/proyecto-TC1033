#ifndef AHORRO_H
#define AHORRO_H

#include "cuentaBancaria.hpp"

class CuentaAhorro : public CuentaBancaria {
  private:
    float interes;

  public:
    CuentaAhorro() : CuentaBancaria(0, "nadie", 0.0), interes(0) {};
    CuentaAhorro(int id, std::string titular, double sa, float in)
        : CuentaBancaria(id, titular, sa), interes(in) {};
    float getInteres();
    void setInteres(float);
    void generaInteres();
};

#endif
