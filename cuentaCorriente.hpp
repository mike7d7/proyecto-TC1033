#include "cuentaBancaria.hpp"

class CuentaCorriente : public CuentaBancaria {
  private:
    double linea_credito;

  public:
    CuentaCorriente(int id, std::string ti)
        : CuentaBancaria(id, ti, 0.0), linea_credito(5000.0) {};
    CuentaCorriente(int id, std::string ti, double sa, double lc)
        : CuentaBancaria(id, ti, sa), linea_credito(lc) {};
    float getLineaCredito();
    void setLineaCredito(double);
    void retirar(double);
};
