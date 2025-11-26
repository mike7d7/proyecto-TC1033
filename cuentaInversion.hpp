#include "activo.hpp"
#include "cuentaBancaria.hpp"

class CuentaInversion : public CuentaBancaria {
  private:
    Activo *activo;

  public:
    CuentaInversion(int id, std::string ti, double sa, Activo *act)
        : CuentaBancaria(id, ti, sa), activo(act) {};
    Activo getActivo();
    void generaRendimiento();
};
