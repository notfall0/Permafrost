add_executable(permafrost_bin
    main.cc
    minecraft_server.h
    minecraft_server.cc)

target_link_libraries(permafrost_bin PRIVATE asio)

string(TOLOWER "permafrost-${CMAKE_SYSTEM_PROCESSOR}-${CMAKE_SYSTEM_NAME}" BINARY_NAME)
set_target_properties(permafrost_bin PROPERTIES OUTPUT_NAME ${BINARY_NAME})
