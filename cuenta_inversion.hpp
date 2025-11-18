#include "cuenta_bancaria.hpp"

class CuentaInversion : public CuentaBancaria {
  private:
    float rendimiento;
    std::string tipo_activo;

  public:
    CuentaInversion(int id, std::string ti)
        : CuentaBancaria(id, ti, 0.0), rendimiento(0.1),
          tipo_activo("acciones") {};
    CuentaInversion(int id, std::string ti, double sa, float re, std::string ta)
        : CuentaBancaria(id, ti, sa), rendimiento(re), tipo_activo(ta) {};
    float getRendimiento();
    void setRendimiento(float);
    void generaRendimiento();
};
