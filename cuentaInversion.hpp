#include "activo.hpp"
#include "cuentaBancaria.hpp"

class CuentaInversion : public CuentaBancaria {
  private:
    Activo *activo;

  public:
    CuentaInversion() : CuentaBancaria(0, "nadie", 0), activo() {};
    CuentaInversion(int id, std::string ti, double sa, Activo *act)
        : CuentaBancaria(id, ti, sa), activo(act) {};
    Activo getActivo();
    void generaRendimiento();
};
