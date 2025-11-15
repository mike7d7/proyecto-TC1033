#include "cuenta_ahorro.hh"
#include "cuenta_corriente.hh"
#include "cuenta_inversion.hh"
#include <iostream>

int main() {
  int generador_id = 0;

  std::cout << std::fixed;
  std::cout.precision(2);

  std::cout << "Simulador de banco" << std::endl;

  CuentaAhorro cuenta_ahorro(generador_id, "Persona Ahorro");
  generador_id++;

  std::cout << "Ahorro saldo: " << cuenta_ahorro.getSaldo() << std::endl;
  cuenta_ahorro.setSaldo(5000.0);
  std::cout << "Ahorro saldo: " << cuenta_ahorro.getSaldo() << std::endl;
  std::cout << "Ahorro intereses: " << cuenta_ahorro.getInteres() << std::endl;
  cuenta_ahorro.generaInteres();
  std::cout << "Ahorro saldo: " << cuenta_ahorro.getSaldo() << std::endl;

  CuentaAhorro cuenta_ahorro_2(generador_id, "Persona Ahorro 2", 10000, 0.2);
  generador_id++;

  std::cout << "Ahorro 2 saldo: " << cuenta_ahorro_2.getSaldo() << std::endl;
  std::cout << "Ahorro 2 intereses: " << cuenta_ahorro_2.getInteres()
            << std::endl;
  cuenta_ahorro_2.setInteres(0.1);
  std::cout << "Ahorro 2 intereses: " << cuenta_ahorro_2.getInteres()
            << std::endl;

  CuentaCorriente cuenta_corriente_1(generador_id, "Persona Corriente 1");
  generador_id++;

  std::cout << "Corriente 1 saldo: " << cuenta_corriente_1.getSaldo()
            << std::endl;
  std::cout << "Corriente 1 crédito: " << cuenta_corriente_1.getLineaCredito()
            << std::endl;

  cuenta_corriente_1.setSaldo(2000.0);
  cuenta_corriente_1.setLineaCredito(500.0);

  std::cout << "Corriente 1 saldo: " << cuenta_corriente_1.getSaldo()
            << std::endl;
  std::cout << "Corriente 1 crédito: " << cuenta_corriente_1.getLineaCredito()
            << std::endl;

  cuenta_corriente_1.retirar(2100);
  std::cout << "Corriente 1 retiro de 2100" << std::endl;
  std::cout << "Corriente 1 saldo: " << cuenta_corriente_1.getSaldo()
            << std::endl;
  std::cout << "Corriente 1 crédito: " << cuenta_corriente_1.getLineaCredito()
            << std::endl;

  CuentaInversion cuenta_inversion_1(generador_id, "Persona Inversion 1", 1000,
                                     0.15, "bonos");

  std::cout << "Inversion 1 saldo: " << cuenta_inversion_1.getSaldo()
            << std::endl;
  cuenta_inversion_1.depositar(1000);
  std::cout << "Inversion 1 saldo: " << cuenta_inversion_1.getSaldo()
            << std::endl;

  cuenta_inversion_1.retirar(500);
  std::cout << "Inversion 1 saldo: " << cuenta_inversion_1.getSaldo()
            << std::endl;

  cuenta_inversion_1.setRendimiento(0.17);
  std::cout << "Inversion 1 rendimiento: "
            << cuenta_inversion_1.getRendimiento() << std::endl;

  cuenta_inversion_1.generaRendimiento();
  std::cout << "Inversion 1 saldo: " << cuenta_inversion_1.getSaldo()
            << std::endl;

  return 0;
}
