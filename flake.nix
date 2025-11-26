{
  description = "Simulador de Banco";

  # inputs.nixpkgs.url = "https://flakehub.com/f/NixOS/nixpkgs/0.1.*.tar.gz";
  inputs.nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";

  outputs =
    { self, nixpkgs }:
    let
      supportedSystems = [
        "x86_64-linux"
        "aarch64-linux"
        "x86_64-darwin"
        "aarch64-darwin"
      ];
      forEachSupportedSystem =
        f:
        nixpkgs.lib.genAttrs supportedSystems (
          system:
          f {
            pkgs = import nixpkgs { inherit system; };
          }
        );

    in
    {
      packages = forEachSupportedSystem (
        { pkgs }:
        {
          default = pkgs.stdenv.mkDerivation {
            pname = "banco";
            version = "0.0.1";
            src = self;
            nativeBuildInputs = with pkgs; [
              pkg-config
              gcc
            ];
            buildInputs = with pkgs; [
            ];
            buildPhase = ''
              g++ -std=c++11 main.cpp activo.cpp banco.cpp cuentaAhorro.cpp cuentaBancaria.cpp cuentaCorriente.cpp cuentaInversion.cpp -o banco
            '';
            installPhase = ''
              mkdir -p $out/bin
              cp banco $out/bin/
            '';
          };
        }
      );
      devShells = forEachSupportedSystem (
        { pkgs }:
        {
          default = pkgs.mkShell {
            packages =
              with pkgs;
              [
                gcc
                clang-tools
                cppcheck
                pkg-config
              ]
              ++ (if system == "aarch64-darwin" then [ ] else [ lldb ]);
            shellHook = ''
              export SHELL=/run/current-system/sw/bin/bash
            '';
          };
        }
      );
    };
}
