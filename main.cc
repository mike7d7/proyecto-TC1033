#include "cuenta_ahorro.hh"
#include "cuenta_corriente.hh"
#include "cuenta_inversion.hh"
#include <print>

int main() {
  int generador_id = 0;
  std::println("Simulador de banco");

  CuentaAhorro cuenta_ahorro = CuentaAhorro(generador_id, "Persona Ahorro");
  generador_id++;
  std::println("Ahorro saldo: {:.2f}", cuenta_ahorro.getSaldo());
  cuenta_ahorro.setSaldo(5000.0);
  std::println("Ahorro saldo: {:.2f}", cuenta_ahorro.getSaldo());
  std::println("Ahorro intereses: {:.2f}", cuenta_ahorro.getInteres());
  cuenta_ahorro.generaInteres();
  std::println("Ahorro saldo: {:.2f}", cuenta_ahorro.getSaldo());

  CuentaAhorro cuenta_ahorro_2 =
      CuentaAhorro(generador_id, "Persona Ahorro 2", 10000, 0.2);
  generador_id++;
  std::println("Ahorro 2 saldo: {:.2f}", cuenta_ahorro_2.getSaldo());
  std::println("Ahorro 2 intereses: {:.2f}", cuenta_ahorro_2.getInteres());
  cuenta_ahorro_2.setInteres(0.1);
  std::println("Ahorro 2 intereses: {:.2f}", cuenta_ahorro_2.getInteres());

  CuentaCorriente cuenta_corriente_1 =
      CuentaCorriente(generador_id, "Persona Corriente 1");
  generador_id++;
  std::println("Corriente 1 saldo: {:.2f}", cuenta_corriente_1.getSaldo());
  std::println("Corriente 1 crédito: {:.2f}",
               cuenta_corriente_1.getLineaCredito());
  cuenta_corriente_1.setSaldo(2000.0);
  cuenta_corriente_1.setLineaCredito(500.0);
  std::println("Corriente 1 saldo: {:.2f}", cuenta_corriente_1.getSaldo());
  std::println("Corriente 1 crédito: {:.2f}",
               cuenta_corriente_1.getLineaCredito());
  cuenta_corriente_1.retirar(2100);
  std::println("Corriente 1 retiro de 2100");
  std::println("Corriente 1 saldo: {:.2f}", cuenta_corriente_1.getSaldo());
  std::println("Corriente 1 crédito: {:.2f}",
               cuenta_corriente_1.getLineaCredito());

  CuentaInversion cuenta_inversion_1 =
      CuentaInversion(generador_id, "Persona Inversion 1", 1000, 0.15, "bonos");
  std::println("Inversion 1 saldo: {:.2f}", cuenta_inversion_1.getSaldo());
  cuenta_inversion_1.depositar(1000);
  std::println("Inversion 1 saldo: {:.2f}", cuenta_inversion_1.getSaldo());
  cuenta_inversion_1.retirar(500);
  std::println("Inversion 1 saldo: {:.2f}", cuenta_inversion_1.getSaldo());
  cuenta_inversion_1.setRendimiento(0.17);
  std::println("Inversion 1 rendimiento: {:.2f}",
               cuenta_inversion_1.getRendimiento());
  cuenta_inversion_1.generaRendimiento();
  std::println("Inversion 1 saldo: {:.2f}", cuenta_inversion_1.getSaldo());

  return 0;
}
