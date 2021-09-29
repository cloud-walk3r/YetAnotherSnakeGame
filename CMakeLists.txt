cmake_minimum_required(VERSION 3.10)
project(sfml VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall -Wextra -O2")

# Output files in bin directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Set SFML_DIR to point to path containing cmake config file for SFML
set(SFML_DIR "D:/Dev/opt/lib/cmake/SFML")
find_package(SFML COMPONENTS graphics window system REQUIRED)

set(SOURCES
  main.cpp game.cpp snake.cpp world.cpp
  mainmenustate.cpp gameplaystate.cpp gamepausestate.cpp gameoverstate.cpp
  mainmenutextbox.cpp screentextbox.cpp
)
set(HEADERS
  game.h snake.h world.h
  gamestate.h mainmenustate.h gameplaystate.h gamepausestate.h gameoverstate.h
  mainmenutextbox.h screentextbox.h
)

add_executable(snake ${SOURCES} ${HEADERS})
target_link_libraries(snake
    PRIVATE sfml-graphics sfml-window sfml-system
)
