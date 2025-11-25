#include "cuentaBancaria.hpp"

class CuentaAhorro : public CuentaBancaria {
  private:
    float interes;

  public:
    CuentaAhorro(int id, std::string titular)
        : CuentaBancaria(id, titular, 0.0), interes(0.05) {};
    CuentaAhorro(int id, std::string titular, double sa, float in)
        : CuentaBancaria(id, titular, sa), interes(in) {};
    float getInteres();
    void setInteres(float);
    void generaInteres();
};
