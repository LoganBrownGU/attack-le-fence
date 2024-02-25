project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# adding the google_tests_run target
add_executable(google_tests_run DeckTest.cpp
        GameTests.cpp)

target_link_libraries(google_tests_run Deck_lib)
target_link_libraries(google_tests_run gtest gtest_main)