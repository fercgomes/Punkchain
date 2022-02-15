add_executable(client client.cpp)
target_link_libraries(client Threads::Threads ${Boost_LIBRARIES})

add_executable(server server.cpp)
target_link_libraries(server Threads::Threads ${Boost_LIBRARIES})