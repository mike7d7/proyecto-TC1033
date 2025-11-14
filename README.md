# Simulador de Banco

### Contexto

Un banco maneja distintos tipos de cuentas dependiendo de su uso y funcionalidad, en este programa existen cuentas corrientes, de ahorros y de inversión.
Este programa utiliza una estructura de clases para facilitar el manejo de los distintos tipos de cuentas. Todas las cuentas pueden hacer funciones como
depósitos y retiros, pero solo la de ahorros y la de inversión generan un interés. Solo la cuenta de inversión tiene accesso a instrumentos de inversión.

### Funcionalidad

El programa permite abrir nuevas cuentas y realizar operaciones con las distintas cuentas.
Se ejecuta en una terminal y cuenta con un menú inicial para seleccionar las distintas opciones.

### Consideraciones

El programa corre solamente en la terminal y esta escrito en [C++23](https://en.wikipedia.org/wiki/C%2B%2B23) por lo que corre en todos los sistemas operativos

Para la compilación se utiliza Cmake con los siguientes comandos en Linux:
`mkdir -p build`
`cd build`
`cmake ..`
`cd ..`
`cmake --build build`

Correr en linux: "./banco"

Correr en windows: "a.exe"
