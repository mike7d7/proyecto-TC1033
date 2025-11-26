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

int get_int() {
  int number;
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
    std::cin >> opcion;

    std::string titular;
    std::stringstream cuentas;
    switch (opcion) {
    case 1:
      int tipo;
      tipo = get_int();
      std::cin.ignore();
      getline(std::cin, titular);
      banco.abrirCuenta(tipo, banco.getIndice(tipo), titular);
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
