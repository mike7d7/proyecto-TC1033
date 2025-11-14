cmake_minimum_required(VERSION 3.26)

project(Banco)

add_executable(banco
    main.cc
    cuenta_ahorro.cc
    cuenta_bancaria.cc
    cuenta_corriente.cc
    cuenta_inversion.cc
)

set_target_properties(banco PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

install(TARGETS banco
    RUNTIME DESTINATION bin
)
