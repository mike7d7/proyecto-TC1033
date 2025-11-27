#include "banco.hpp"
#include <iostream>
#include <limits>
#include <ostream>
#include <sstream>
#include <string>

void menu_principal() {
  std::cout << "Ingresa una opción" << std::endl;
  std::cout << "1.- Agregar cuenta" << std::endl;
  std::cout << "2.- Mostrar cuentas" << std::endl;
  std::cout << "3.- Salir" << std::endl;
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
    opcion = get_int(1, 3);

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
        float interes;
        interes = get_float();
        banco.abrirCuenta(titular, saldo, interes);
        break;
      case 2:
        double linea_credito;
        linea_credito = get_float();
        banco.abrirCuenta(titular, saldo, linea_credito);
        break;
      case 3:
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
    default:
      return 0;
    }
  }
  return 0;
}
