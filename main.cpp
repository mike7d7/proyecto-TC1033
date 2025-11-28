#include "banco.hpp"
#include "cuentaAhorro.hpp"
#include "cuentaCorriente.hpp"
#include "cuentaInversion.hpp"
#include <iostream>
#include <limits>
#include <ostream>
#include <sstream>
#include <string>

void clear() {
  std::cout << "\x1B[2J\x1B[H";
  for (int i = 0; i < 100; i++) {
    std::cout << std::endl;
  }
}

void menu_principal() {
  // clear();
  std::cout << "Ingresa una opción" << std::endl;
  std::cout << "1.- Agregar cuenta" << std::endl;
  std::cout << "2.- Mostrar cuentas" << std::endl;
  std::cout << "3.- Realizar Operación" << std::endl;
  std::cout << "4.- Salir" << std::endl;
}

int get_int(int min_val, int max_val) {
  int number;
  while (!(std::cin >> number)) {
    // https://cplusplus.com/forum/beginner/283248/#msg1226145
    std::cout << "Entrada inválida, intenta otra vez." << std::endl;
    std::cin.clear(); // clear fail flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n'); // discard the whole line
  }
  if (number < min_val || number > max_val) {
    std::cout << "Entrada inválida, intenta otra vez." << std::endl;
    std::cin.clear(); // clear fail flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n'); // discard the whole line
    number = get_int(min_val, max_val);
  }
  return number;
}

float get_float() {
  float number;
  while (!(std::cin >> number)) {
    // https://cplusplus.com/forum/beginner/283248/#msg1226145
    std::cout << "Entrada inválida, intenta otra vez." << std::endl;
    std::cin.clear(); // clear fail flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n'); // discard the whole line
  }
  return number;
}

int main() {
  Banco banco;

  while (true) {
    menu_principal();
    int opcion;
    opcion = get_int(1, 4);

    std::string titular;
    std::stringstream cuentas;
    switch (opcion) {
      case 1:
        std::cout << "Ingresa el tipo de cuenta a abrir." << std::endl;
        std::cout << "1.- Ahorro" << std::endl;
        std::cout << "2.- Corriente" << std::endl;
        std::cout << "3.- Inversión" << std::endl;

        int tipo;
        tipo = get_int(1, 3);
        std::cin.ignore();

        std::cout << "Ingresa el saldo inicial." << std::endl;
        double saldo;
        saldo = get_float();
        std::cin.ignore();

        std::cout << "Ingresa el titular de la cuenta." << std::endl;
        getline(std::cin, titular);

        switch (tipo) {
          case 1:
            std::cout
                << "Ingresa el porcentaje de interes como decimal (ej. 0.19)."
                << std::endl;
            float interes;
            interes = get_float();
            banco.abrirCuenta(titular, saldo, interes);
            break;
          case 2:
            std::cout << "Ingresa el valor de la línea de crédito."
                      << std::endl;
            double linea_credito;
            linea_credito = get_float();
            banco.abrirCuenta(titular, saldo, linea_credito);
            break;
          case 3:
            std::cout << "Ingresa el tipo de activo." << std::endl;
            std::cout << "1.- Bonos" << std::endl;
            std::cout << "2.- Bolsa" << std::endl;
            std::cout << "3.- Bienes Raíces" << std::endl;
            std::cout << "4.- Pagarés" << std::endl;
            std::cout << "5.- Criptomonedas" << std::endl;
            int activo;
            activo = get_int(1, 5);
            activo = activo - 1;
            banco.abrirCuenta(titular, saldo, banco.getActivo(activo));
            break;
        }

        break;
      case 2:
        cuentas = banco.printCuentas();
        std::cout << cuentas.str();
        break;
      case 3:
        std::cout << "Ingresa el tipo de movimiento a realizar." << std::endl;
        std::cout << "1.- Retiro" << std::endl;
        std::cout << "2.- Depósito" << std::endl;
        std::cout << "3.- Transferencia" << std::endl;
        std::cout << "4.- Cancelar" << std::endl;
        int movimiento;
        movimiento = get_int(1, 4);
        switch (movimiento) {
          case 1:
            std::cout << "Ingresa la cantidad a retirar" << std::endl;
            double cantidad;
            cantidad = get_float();

            std::cout << "Ingresa el Id de la cuenta de donde retirar"
                      << std::endl;
            int id_general;
            id_general = get_int(100, 399);
            int tipo;
            tipo = id_general / 100;

            int id_tipo;
            id_tipo = id_general - (tipo * 100);
            switch (tipo) {
              case 1: {
                if (id_tipo < 0 || id_tipo > banco.getNumAhorro() - 1) {
                  std::cout << "Id inválido" << std::endl;
                  break;
                }
                CuentaAhorro *cuenta_ahorro;
                cuenta_ahorro = &banco.getAhorros()[id_tipo];
                if (!cuenta_ahorro->retirar(cantidad)) {
                  std::cout << "Retiro exitoso" << std::endl;
                } else {
                  std::cout << "Saldo insuficiente" << std::endl;
                };
                break;
              }
              case 2: {
                if (id_tipo < 0 || id_tipo > banco.getNumCorriente() - 1) {
                  std::cout << "Id inválido" << std::endl;
                  break;
                }
                CuentaCorriente *cuenta_corriente;
                cuenta_corriente = &banco.getCorrientes()[id_tipo];
                if (!cuenta_corriente->retirar(cantidad)) {
                  std::cout << "Retiro exitoso" << std::endl;
                } else {
                  std::cout << "Saldo insuficiente" << std::endl;
                };
                break;
              }
              case 3: {
                if (id_tipo < 0 || id_tipo > banco.getNumInversion() - 1) {
                  std::cout << "Id inválido" << std::endl;
                  break;
                }
                CuentaInversion *cuenta_inversion;
                cuenta_inversion = &banco.getInversiones()[id_tipo];
                if (!cuenta_inversion->retirar(cantidad)) {
                  std::cout << "Retiro exitoso" << std::endl;
                } else {
                  std::cout << "Saldo insuficiente" << std::endl;
                };
                break;
              }
            }
            break;
          // case 2:
          //   break;
          // case 3:
          //   break;
          default:
            break;
        }
        break;
      default:
        return 0;
    }
  }
  return 0;
}
