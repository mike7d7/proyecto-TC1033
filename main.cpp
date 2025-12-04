#include "banco.hpp"
#include "cuentaAhorro.hpp"
#include "cuentaCorriente.hpp"
#include "cuentaInversion.hpp"
#include <iostream>
#include <limits>
#include <ostream>
#include <sstream>
#include <string>

void enter_to_continue() {
  std::cout << "Presiona enter para continuar" << std::endl;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
}

void clear() {
  for (int i = 0; i < 100; i++) {
    std::cout << std::endl;
  }
}

void menu_principal() {
  clear();
  std::cout << "Ingresa una opción" << std::endl;
  std::cout << "1.- Agregar cuenta" << std::endl;
  std::cout << "2.- Mostrar cuentas" << std::endl;
  std::cout << "3.- Realizar Operación" << std::endl;
  std::cout << "4.- Generar intereses" << std::endl;
  std::cout << "5.- Modificar rendimiento de activo" << std::endl;
  std::cout << "6.- Salir" << std::endl;
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

float get_float(float min_val, float max_val) {
  float number;
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
    number = get_float(min_val, max_val);
  }
  return number;
}

double get_double(double min_val, double max_val) {
  double number;
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
    number = get_double(min_val, max_val);
  }
  return number;
}

int main() {
  Banco banco;

  // Ciclo para menú de opciones
  while (true) {
    menu_principal();
    int opcion;
    opcion = get_int(1, 6);

    std::string titular;
    std::stringstream cuentas;
    // Switch para opciones del menú principal
    switch (opcion) {
      // Abrir cuenta
      case 1:
        clear();
        std::cout << "Ingresa el tipo de cuenta a abrir." << std::endl;
        std::cout << "1.- Ahorro" << std::endl;
        std::cout << "2.- Corriente" << std::endl;
        std::cout << "3.- Inversión" << std::endl;

        int tipo;
        tipo = get_int(1, 3);
        std::cin.ignore();

        std::cout << "Ingresa el saldo inicial (máximo 100000)." << std::endl;
        double saldo;
        saldo = get_double(0.0, 100000.0);
        std::cin.ignore();

        std::cout << "Ingresa el titular de la cuenta." << std::endl;
        getline(std::cin, titular);

        switch (tipo) {
          // Ahorro
          case 1:
            std::cout
                << "Ingresa el porcentaje de interes como decimal (ej. 0.19)."
                << std::endl;
            float interes;
            interes = get_float(0.0, 1.0);
            banco.abrirCuenta(titular, saldo, interes);
            break;
          // Corriente
          case 2:
            std::cout
                << "Ingresa el valor de la línea de crédito (máximo 100000)."
                << std::endl;
            double linea_credito;
            linea_credito = get_double(0.0, 100000.0);
            banco.abrirCuenta(titular, saldo, linea_credito);
            break;
          // Inversión
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
      // Mostrar cuentas
      case 2:
        clear();
        cuentas = banco.printCuentas();
        std::cout << cuentas.str();
        enter_to_continue();
        break;
      // Realizar movimiento
      case 3:
        clear();
        std::cout << "Ingresa el tipo de movimiento a realizar." << std::endl;
        std::cout << "1.- Retiro" << std::endl;
        std::cout << "2.- Depósito" << std::endl;
        std::cout << "3.- Cancelar" << std::endl;
        int movimiento;
        movimiento = get_int(1, 3);
        switch (movimiento) {
          // Retiro
          case 1:
            std::cout << "Ingresa la cantidad a retirar (máximo 100000)."
                      << std::endl;
            double cantidad;
            cantidad = get_double(0.0, 100000.0);

            std::cout << "Ingresa el Id de la cuenta de donde retirar"
                      << std::endl;
            int id_general;
            id_general = get_int(100, 399);
            int tipo;
            tipo = id_general / 100;

            int id_tipo;
            id_tipo = id_general - (tipo * 100);
            // Switch para cada tipo de cuenta
            switch (tipo) {
              // Ahorro
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
              // Corriente
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
              // Inversión
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
          // Depósito
          case 2:
            std::cout << "Ingresa la cantidad a depositar (máximo 100000)"
                      << std::endl;
            double cantidad2;
            cantidad2 = get_float(0.0, 100000.0);

            std::cout << "Ingresa el Id de la cuenta a la cual se depositará"
                      << std::endl;
            int id_general2;
            id_general2 = get_int(100, 399);
            int tipo2;
            tipo2 = id_general2 / 100;

            int id_tipo2;
            id_tipo2 = id_general2 - (tipo2 * 100);
            // Switch para tipos de cuentas
            switch (tipo2) {
              // Ahorro
              case 1: {
                if (id_tipo2 < 0 || id_tipo2 > banco.getNumAhorro() - 1) {
                  std::cout << "Id inválido" << std::endl;
                  break;
                }
                CuentaAhorro *cuenta_ahorro;
                cuenta_ahorro = &banco.getAhorros()[id_tipo2];
                cuenta_ahorro->depositar(cantidad2);
                std::cout << "Depósito exitoso" << std::endl;
                break;
              }
              // Corriente
              case 2: {
                if (id_tipo2 < 0 || id_tipo2 > banco.getNumCorriente() - 1) {
                  std::cout << "Id inválido" << std::endl;
                  break;
                }
                CuentaCorriente *cuenta_corriente;
                cuenta_corriente = &banco.getCorrientes()[id_tipo2];
                cuenta_corriente->depositar(cantidad2);
                std::cout << "Depósito exitoso" << std::endl;
                break;
              }
              // Inversión
              case 3: {
                if (id_tipo2 < 0 || id_tipo2 > banco.getNumInversion() - 1) {
                  std::cout << "Id inválido" << std::endl;
                  break;
                }
                CuentaInversion *cuenta_inversion;
                cuenta_inversion = &banco.getInversiones()[id_tipo2];
                cuenta_inversion->depositar(cantidad2);
                std::cout << "Depósito exitoso" << std::endl;
                break;
              }
            }
            break;
        }
        enter_to_continue();
        break;
      case 4:
        clear();
        banco.aplicaIntereses();
        std::cout << "Intereses aplicados correctamente." << std::endl;
        enter_to_continue();
        break;
      case 5:
        clear();
        std::cout << "Ingresa el activo a modificar" << std::endl;
        for (int i = 0; i < 5; i++) {
          std::cout << i + 1 << ".- " << banco.getActivo(i)->getNombre()
                    << std::endl;
        }
        int activo_a_modificar;
        activo_a_modificar = get_int(1, 5) - 1;
        std::cout << "El rendimiento actual del activo es de "
                  << banco.getActivo(activo_a_modificar)->getRendimiento()
                  << std::endl;
        std::cout << "Ingresa el nuevo rendimiento como un decimal entre 0 y 1 "
                     "(ej. 0.12)"
                  << std::endl;
        float nuevo_rendimiento;
        nuevo_rendimiento = get_float(0.0, 1.0);
        banco.getActivo(activo_a_modificar)->setRendimiento(nuevo_rendimiento);
        break;
      default:
        return 0;
    }
  }
  return 0;
}
