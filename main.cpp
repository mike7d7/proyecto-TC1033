#include "banco.hpp"
#include <iostream>
#include <limits>
#include <ostream>
#include <sstream>
#include <string>

#if _WIN32
#include <windows.h>
void clear() {
  HANDLE hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD count;
  DWORD cellCount;
  COORD homeCoords = {0, 0};

  hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  if (hStdOut == INVALID_HANDLE_VALUE)
    return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo(hStdOut, &csbi))
    return;
  cellCount = csbi.dwSize.X * csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(hStdOut, (TCHAR)' ', cellCount, homeCoords,
                                  &count))
    return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount,
                                  homeCoords, &count))
    return;

  /* Move the cursor home */
  SetConsoleCursorPosition(hStdOut, homeCoords);
}
#else
void clear() {
  // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
  std::cout << "\x1B[2J\x1B[H";
}
#endif

void menu_principal() {
  clear();
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
        std::cout << "Ingresa el porcentaje de interes como decimal (ej. 0.19)."
                  << std::endl;
        float interes;
        interes = get_float();
        banco.abrirCuenta(titular, saldo, interes);
        break;
      case 2:
        std::cout << "Ingresa el valor de la línea de crédito." << std::endl;
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
    default:
      return 0;
    }
  }
  return 0;
}
