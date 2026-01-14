cmake_minimum_required(VERSION 3.10)
project(bigbinary_projet C)

set(CMAKE_C_STANDARD 99)

# Fichiers sources
set(SOURCES
    main.c
    src/BigBinary.c
)

# Fichiers headers
set(HEADERS
    src/BigBinary.h
)

# Créer l'exécutable
add_executable(bigbinary ${SOURCES} ${HEADERS})

# Inclure le dossier src pour les headers
target_include_directories(bigbinary PRIVATE ${CMAKE_SOURCE_DIR}/src)
