cmake_minimum_required(VERSION 3.27)
project(attack_le_fence)

set(CMAKE_CXX_STANDARD 17)
set(SIMPLE2D_IBS -lsimple2d -I/usr/include/SDL2 -D_REENTRANT -lSDL2 -lGL -lm -lSDL2_image -lSDL2_mixer -lSDL2_ttf)


add_executable(attack_le_fence main.cpp
        Card.cpp
        Card.h
        player/Player.h
        player/Player.cpp
        CardFactory.cpp
        CardFactory.h
        Game.cpp
        Game.h
        player/LocalCLIPlayer.cpp
        player/LocalCLIPlayer.h
        Deck.cpp
        Deck.h
        gui/GUI_2D.cpp
        gui/GUI_2D.h
)

target_link_libraries(attack_le_fence ${SIMPLE2D_IBS})