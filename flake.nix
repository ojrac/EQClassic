{
  description = "EQClassic source code from 2010. EverQuest Trilogy Server Emulator";

  inputs = {
    # nixpkgs.url = "github:NixOS/nixpkgs/unstable";
    nixpkgs.url = "github:NixOS/nixpkgs/22.11";
  };

  outputs = { self, nixpkgs, ... }@inputs: inputs.utils.lib.eachSystem [
    # Add the system/architecture you would like to support here. Note that not
    # all packages in the official nixpkgs support all platforms.
    "x86_64-linux" # "i686-linux" "aarch64-linux" "x86_64-darwin"
  ] (system: let
    pkgs = import nixpkgs {
      inherit system;

      overlays = [ ];
    };
  in {
    devShells.default = pkgs.mkShell rec {
      name = "eqclassic";

      packages = with pkgs; [
        # Development Tools
        llvmPackages_14.clang
        cmake
        cmakeCurses

        # Build time and Run time dependencies
        libmysqlclient.dev
      ];

      buildInputs = [
	pkgs.libmysqlclient.dev
      ];
      MYSQL = pkgs.libmysqlclient.dev.outPath;

      # Setting up the environment variables you need during
      # development.
      #shellHook = let
      #  icon = "f121";
      #in ''
      #  export PS1="$(echo -e '\u${icon}') {\[$(tput sgr0)\]\[\033[38;5;228m\]\w\[$(tput sgr0)\]\[\033[38;5;15m\]} (${name}) \\$ \[$(tput sgr0)\]"
      #'';
    };

    packages.default = pkgs.callPackage ./default.nix {};
  });
}
