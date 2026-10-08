add_library(permafrost_net STATIC
    network_server.h
    network_server.cc)

target_link_libraries(permafrost_net PUBLIC asio)
