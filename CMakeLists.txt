cmake_minimum_required(VERSION 3.27)
project(attack_le_fence)

set(CMAKE_CXX_STANDARD 17)

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
        Deck.h)
