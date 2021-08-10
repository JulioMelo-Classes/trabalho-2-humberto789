cmake_minimum_required(VERSION 3.5)
project(Keno VERSION 0.1 LANGUAGES CXX )

# set the compiling flags
# set ( CMAKE_CXX_FLAGS "-Wall -fsanitize=address" )

#--------------------------------
# This is for old cmake versions
set (CMAKE_CXX_STANDARD 14)
#--------------------------------

# configura o diretório contendo os .h, assim você pode incluílos apenas com include "arquivo.h"
include_directories( include )

# Cria um executável com nome "run_tests", adiciona neste executável os arquivos do test manager e o seu main.cpp
add_executable( concordo
                src/main.cpp
                src/Servicos.cpp
                src/CanalTexto.cpp
                src/Servidor.cpp
                src/Sistema.cpp
                src/Usuario.cpp
                src/Mensagem.cpp
                 )

# The end
