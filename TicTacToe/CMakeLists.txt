# CMakeList.txt: проект CMake для TicTacToe; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (TicTacToe "main.cpp"  "TicTacToe/TicTacToe.h" "TicTacToe/TicTacToe.cpp" "Player/Player.h" "Player/RandomPlayer.h" "Player/RandomPlayer.cpp" "GameManager/GameManager.h" "GameManager/GameManager.cpp" "Player/SmartPlayer.h" "Player/SmartPlayer.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TicTacToe PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
