add_executable(nclutch main.cpp)
target_link_libraries(nclutch CppLinuxSerial xdo)

install(TARGETS nclutch DESTINATION bin)
