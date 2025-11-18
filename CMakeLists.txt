cmake_minimum_required(VERSION 3.26)

project(Banco)

add_executable(banco
    main.cpp
    cuenta_ahorro.cpp
    cuenta_bancaria.cpp
    cuenta_corriente.cpp
    cuenta_inversion.cpp
)

set_target_properties(banco PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
)

install(TARGETS banco
    RUNTIME DESTINATION bin
)
