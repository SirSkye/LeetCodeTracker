cmake_minimum_required(VERSION 3.29)
project(LeetcodeTracker)

add_subdirectory(external/ftxui)

add_executable(main src/main.cpp
  src/ui/tabs/LandingTab.cpp
  src/models/AppState.cpp
  src/ui/TabBar.cpp)

target_link_libraries(main
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)